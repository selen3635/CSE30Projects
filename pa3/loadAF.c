/*
 * Filename: loadAF.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will load all the anagrams from the anagrams
 *              file(stream) into memeory, populating the passed in anagramInfo
 *              struct.
 * Date:  May 14. 2016
 * Source of Help: write up, tutors
 */


/*
 * Header files included here
 * 
 */
#include <stdlib.h>
#include "pa3.h"


/*
 * Function name: loadAF()
 * Function prototype: 
 *     int loadAF( FILE *stream, struct anagramInfo *anagramInfo);
 * Description: This function will load all the anagrams from the anagrams file
 *              (stream) into memory, populating the passed in anagramInfo
 *              struct.
 * Parameters:
 *     FILE *stream -- a file contains all anagrams
 *     struct anagramInfo -- a struct to store anagram
 * Side Effects: None.
 * Error Conditions: Run out of memory in loadAnagram() or when expanding the
 *                   array of anagram structs. If this happens, free() all
 *                   dynamically allocated memory and return right away.
 * Return Value: Zero on success, nonzero on failure
 */

int loadAF( FILE *stream, struct anagramInfo *anagramInfo) {

  /* Initialize num of anagrams */
  anagramInfo->numOfAnagrams = 0;

  /*create new anagram struct */
  struct anagram *tempPtr;
  struct anagram anagram;

  /* load an anagram */
  int myAnagram = loadAnagram(stream, &anagram);

  /* Check if there exist anagrams */
  while( myAnagram == 1 ) {

    /* realloc space for anagram */
    tempPtr = (struct anagram*)realloc(anagramInfo->anagramPtr,
      ((anagramInfo->numOfAnagrams) + 1) * sizeof(struct anagram));

    /* check if it successes to realloc space */
    if ( tempPtr != NULL) {

      /* append it to the array of anagrams */
      anagramInfo->anagramPtr = tempPtr;
      anagramInfo->anagramPtr[anagramInfo->numOfAnagrams] = anagram;
      anagramInfo->numOfAnagrams++;
    }
    /* if it fails free memory */
    else{

      /* a loop to free all of anagrams */
      int i = 0;
      for ( i = 0; i < anagramInfo->numOfAnagrams; i++) {

        /* free memory location */
        free(anagramInfo->anagramPtr[i].word);
      }
      free(anagramInfo->anagramPtr); 
      return EXIT_FAILURE;
    }

     /* load next anagram */
    myAnagram = loadAnagram(stream, &anagram);

  }//end of while

  /* check if it fails to load andgram */
  if ( myAnagram == -1 ) {
    
    /* a loop to free memory */
    int i = 0;
    for ( i = 0; i < anagramInfo->numOfAnagrams; i++) {
      /* free memory location */
      free(anagramInfo->anagramPtr[i].word);
    }
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
 
}//end of program
