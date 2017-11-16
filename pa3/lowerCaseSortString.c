/*
 * Filename: lowerCaseSortString.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will take the src string ( of length n) and
 *              will store a copy in dest where all the characters are
 *              converted to lowercase and sorted in alphbetical order.
 * Date:  May 07, 2016
 * Sources of Help: handout, writeup, tutors
 */

/*
 * Header files included here
 */
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
#include "pa3.h"


/*
 * Function name: lowerCaseSortString()
 * Function prototype:
 *    void lowerCaseSortString( const char *src, int n, char *dest);
 * Description: This function will take the src string ( of length n) and will
 *              store a copy in dest where all the characters are converted
 *              to lowercase and sorted in alphabetical order.
 * Parameters:
 *    const char *src: string characters
 *    int n: length of character
 *    char *dest: where the copy of store in
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: None.
 */

void lowerCaseSortString( const char *src, int n, char *dest) {

  /* Make a copy of string of length n */
  (void)strncpy(dest, src, n);
  dest[n] = '\0';

  int i = 0;
  /* a loop to converted all characters to lowercase */
  while ( dest[i] != '\0') {

    dest[i] = (tolower(dest[i]));
    /* increase counter */
    ++i;
  }

  /* sort string character in alphabetical order */
  qsort(dest, n, sizeof(char), charCompare);

}// end of function
