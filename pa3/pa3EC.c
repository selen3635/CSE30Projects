/*
 * Filename: pa3EC.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function is the main driver for the program and will be
 *              delegating a majority of the functionality to the other
 *              functions you are writing. In this function, whenever an error
 *              is encountered, immediately print theh appropriate error 
 *              message.
 * Date: May14, 2016
 * Source of Help: write up, tutors.
 */

/*
 * Header files included here
 */
#include <stdlib.h>
#include "pa3EC.h"
#include "pa3Strings.h"
#include <errno.h>
#include <string.h>


/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[]);
 * DescriptionL This function is the mian driver for the program and will be
 *              delegating a majority of the functionality to the other
 *              functions you are writing.
 * Parameters:
 *      argc -- number of argument that passed in
 *      argv -- arguments passed by user
 * Side Effects: Print appropriate error message, print the shor usage
 *               statement.
 * Error Conditions:
 *      Error returned from parseArgs()
 *      Errors returned from loadAF(), or findAnagrams()
 *      Anagram file is missing .af extension
 *      Anagram file cannot be opened due to a file permissioins error.
 *      Anagram file is otherwise invalid (as indicated by errno).
 * Return Value: EXIT_SUCCCESS on success, EXIT_FAILURE on failure.
 */

int main( int argc, char *argv[] ) {

  /* create two new struc */
  struct argInfo argInfo;
  struct anagramInfo anagramInfo;

  /* parse all the argument by user */
  int parseRet = parseArgs(argc, argv, &argInfo);

  /* check if it fails to parse arguments */
  if ( parseRet == EXIT_FAILURE ) {

    /* print out message and return */
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  /* check if help flag has been set */
  if ( (argInfo.flags & HELP_FLAG) == HELP_FLAG) {

    /* print out message and return */
    usage(stderr, USAGE_LONG, argv[0]);
    return EXIT_SUCCESS;
  }

  /* find file extension */
  char *myExtend = NULL;
  myExtend = strstr(argInfo.afFileName, FILE_EXTENSION);

  /* Check whether file has extension .af */
  if ( myExtend == NULL ) {

    (void)fprintf(stderr, STR_ERR_AF_EXTENSION);
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  /* set errno to 0 before calling function */
  errno = 0;
  /* open file */
  FILE *myFile = fopen(argInfo.afFileName, FILE_READ_MODE);

  /* check whether file has benn successfully opened */
  if ( myFile == NULL ) {

    /* check if user have permission to access file */
    if ( errno == EACCES ) {

      /* print out appropriate message and return */
      (void)fprintf(stderr, STR_ERR_AF_PERMISSION);
      usage(stderr, USAGE_SHORT, argv[0]);
      return EXIT_FAILURE;
    }
    /* file is invalid */
    else {

      (void)fprintf(stderr, STR_ERR_AF_INVALID);
      usage(stdout, USAGE_SHORT, argv[0]);
      return EXIT_FAILURE;
    }
  }

  /* load anagram file into memory */
  int myLoad = loadAF(myFile, &anagramInfo);

  /* check if it fails to load file */
  if ( myLoad == EXIT_FAILURE ) {

    (void)fprintf(stderr, STR_ERR_AF_LOAD);
    usage(stdout, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  /* check whether -b flag has been set */
  if(( argInfo.flags & HASH_BITS_FLAG) == HASH_BITS_FLAG ) {

    /* a loop to truncate all anagrams hashKey */
    int i = 0;
    for( i = 0; i < anagramInfo.numOfAnagrams; i++ ) {

      anagramInfo.anagramPtr[i].hashKey = truncateHashKey(
        anagramInfo.anagramPtr[i].hashKey, argInfo.hashBits);
  
    }//end of loop
  }

  /* sort the anagrams */
  qsort(anagramInfo.anagramPtr, anagramInfo.numOfAnagrams,
    sizeof(struct anagram), anagramCompare);

  /* find anagrams */
  int myAna = findAnagramsEC(&argInfo, &anagramInfo);

  /* check if it fails to find anagrams */
  if ( myAna == EXIT_FAILURE ) {

    (void)fprintf(stderr, STR_ERR_CREATE_ANAGRAM);
  }

  /* close file */
  (void)fclose(myFile);

  return EXIT_SUCCESS;
}// end of program
