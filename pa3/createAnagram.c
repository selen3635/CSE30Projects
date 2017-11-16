/*
 * Filename: createAnagram.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will create a new anagram by populating the
 *              passed in struct anagram. An anagram has two components:
 *              the word, and the hashkey.
 * Date: May 14, 2016
 * Source of Help: write up, tutors
 */


/*
 * Header files included here
 */
#include "pa3.h"
#include <stdlib.h>
#include <string.h>

/*
 * Function name: createAnagram()
 * Function prototype: 
 *     int creatAnagram( const char *src, struct anagram *anagram);
 * Parameters: 
 *     char *src -- character passed in
 *     anagram *anagram -- a anagram structure
 * Side Effects: None.
 * Error Condition: Runout of memoty(malloc() fails to allocate memory;)
 * Return value: Zero on success, nonzero on failure
 */

int createAnagram( const char *src, struct anagram *anagram) {

  /* length of source word*/
  int myLength = strlen(src);

  /* Dynamically allocate space for the word */
  anagram->word = (char *)malloc(sizeof(char) *(myLength + 1 ));

  /* Check if run out of memory */
  if( anagram->word == NULL ) {

    /* free memory location */
    free(anagram->word);
    return EXIT_FAILURE;

  }

  /* Initialize local vairables */
  char myDest[BUFSIZ];
  long myKey = 0;

  /* convert to lower case and store into myDest */
  lowerCaseSortString(src, myLength, myDest);

  /* populate word */  
  (void)strncpy( anagram->word, src, myLength);
  anagram->word[myLength] = '\0';
  
  /* get hash key value for my word */
  myKey = hashString(myDest);

  /* populate hashKey */
  anagram->hashKey = myKey;


  return EXIT_SUCCESS;


}//end of program
