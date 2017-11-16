/*
 * Filename: pa4.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function is the main driver for the program and will be
 *              delegating a majority of the functionality to the other 
 *              function we are writing.
 * Date:  May 25, 2016
 * Source of Help: write up tutors
 */

/*
 * Header files included here
 */
#include "pa4.h"
#include "pa4Strings.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>



/*
 * Function name: main()
 * Function prototype:  int main( int argc, char *argv[]);
 * Description: This function is the main driver for the program and will be
 *              delegating a majority of the functionality to the other
 *              function we are writing.
 * Parameters:
 *   int argc -- number of arguments passed in
 *   char *argv[] -- actual arguments passed in
 * Side Effects: None.
 * Error Conditions: errors returned from parseArgs()
 * Return Value: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main( int argc, char *argv[] ) {

  /* get flag returned by parseArgs */
  int myFlag = parseArgs(argc, argv);

  /* check if there is an error */
  if( (myFlag & ERR_FLAG) == ERR_FLAG ) {

    /* print short usage */
    (void)fprintf(stderr, STR_USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  if( (myFlag & H_FLAG) == H_FLAG ) {

    /* print long usage */
    (void)fprintf(stdout, STR_USAGE_LONG, argv[0]);
    return EXIT_SUCCESS;
  }

  struct fileInfo *tablePtr = NULL;
  int myFiles;
  /* check if there are more arguments */
  if( optind != argc ) {

    int i;

    /* a loop to check all file specified */
    for( i = optind; i < argc; i++ ) {

      /* build up file info table */
      myFiles = buildFileInfoTable( argv[i], &tablePtr);

      /* print all files with specific flags */
      printFileInfoTable(tablePtr, myFiles, myFlag);

    }

  }// end of if
  
  /* print all files in the current working directory */
  else {

    /* build up file info table */
    myFiles = buildFileInfoTable(".", &tablePtr);
    
    /* print all files with specific flags */
    printFileInfoTable(tablePtr, myFiles, myFlag);
  }

  int i;
  for( i = 0; i < myFiles; i++ ) {

    free(&(tablePtr[i]));
  }
  free(tablePtr);
  return EXIT_SUCCESS;
}//end of program
