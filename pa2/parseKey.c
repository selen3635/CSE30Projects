/*
 * Filename: parseKey.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This module will be used to parse the second and third
 *              command line arguments, key0 and key1. Parse the key passed
 *              in as str by converting the string to an unsigned long.
 * Date:     April 23, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

/*
 * Header file include here
 */

#include<stdlib.h>
#include "pa2.h"
#include <errno.h>
/*
 * Function name: parseKey()
 * Function prototype: long parseKey( char* str, unsigned long *key);
 * Description: This function will be used to parse the second and third
 *              command line arguments, key0 and key1.Parse the key passed
 *              in as str by converting the string to an unsigned long.
 * Parameters:
 *      arg1: char * str -- key passed in
 *      arg2: unsigned long *key -- will convert key to this unsigned long
 * Side Effects: output parameter key
 * Error Conditions: If the number was too large to be successfully converted,
 *                   return ERANGE_ERR. If the number contained invalid
 *                   characters, return ENDPTR_ERR.
 * Return Value: return long
 */

long parseKey( char *str, unsigned long *key) {

  /* local variables */
  char *endptr;
  unsigned long myKey = 0;

  /* set errno to 0 */
  errno = 0;

  /* convert str to unsigned long */
  myKey = strtoul(str, &endptr, DEF_BASE);
  /* check whether errno has been set */
  if( errno != 0 ) {
 
    return ERANGE_ERR;
  }

  /* check if it reaches endptr */
  else if ( *endptr != '\0') {

    return ENDPTR_ERR;
  }
  
  else {

    /* store in output parameter (key) */
    *key = myKey;

    return 0;
  }
}

