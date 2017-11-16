/*
 * Filename: loadAnagram.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will load a single anagram from the anagrams
 *              file(stream) and will populate the fields of the passed in 
 *              anagram struct.
 * Date:  May 14, 2016
 * Source of Help: write up, tutors
 */


/*
 * Header files included here
 */
#include <string.h>
#include <stdio.h>
#include "pa3.h"
#include <stdlib.h>

/*
 * Function name: loadAnagram()
 * Function prototype: 
 *     int loadAnagram(File *stream, sturct anagram *anagram);
 * Description: This function will load a single anagram from the anagrams
 *              file(stream) and will populate the fields of the passed in 
 *              anagram struct.
 * Parameter: 
 *     FILE *stream -- a file contain anagrams
 *     struct anagram *anagram -- a struct to store anagram
 * Side Effect: None.
 * Error Conditions: Run out of memory(malloc() fails to allocate memory;
 *                   man -s3c malloc). If this happens, return right away.
 * Return Value: Positive if an anagram is successfully read from the file,
 *               zero if the end of file was reached, or negative if an error
 *               occurs.
 */

int loadAnagram( FILE *stream, struct anagram *anagram) {

  /* create a buffer */
  char myBuffer[BUFSIZ];
  char myBuffer2[BUFSIZ];

  /* Initialize local variable */
  size_t mySize = 0;

  /* read hash key from file stream */
  mySize = fread(myBuffer, MAX_HASH_BYTES, 1, stream);

  /* check whether successfully read hashkey*/
  if ( mySize != 1) {
    return EXIT_SUCCESS;
  }

  /* copy it to anagram struct member */
  (void)memcpy( &anagram->hashKey, myBuffer, MAX_HASH_BYTES);

  /* get word from stream file */
  char *myVal = fgets(myBuffer2, BUFSIZ, stream);

  /* check if word to get */
  if ( myVal == NULL ) {

    return EXIT_SUCCESS;
  }

  /* dynamically allocate space for word */
  anagram->word = (char *)malloc(strlen(myBuffer2) + 1);

  /* check if it fails to allocate memory */
  if ( anagram->word == NULL ) {

    /* free memory */
    free(anagram->word);
    return -1;
  }

  /* populate word into anagram struct */
  (void)strncpy( anagram->word, myBuffer2, strlen(myBuffer2) + 1);
  anagram->word[strlen(myBuffer2)] = '\0';

  return 1;
}//end of program
