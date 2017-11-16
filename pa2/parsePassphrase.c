/*
 * Filename:  parsePassphrase.c
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description: Parse the passphrase from the command line arguments by
 *              check if str contains at least PASSPHRASE_SIZE characters.
 * Date:      April 28, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

#include <string.h>
#include "pa2.h"

/*
 * Function name: parsePassphrase()
 * Function prototype:
 *    long parsePassphrase( char *str, unsigned char *passphrase);
 * Parameters:
 *      arg1: str -- string value that will be check
 *      arg2: passphrase -- use for store output parameter
 * Side Effects: None
 * Error Conditions: If the str is shorter than the minimum 
 *                   PASSPHRASE_SIZE, return LENGTH_ERR.
 * Return Value: long. If errors were encountered, return the appropriate
 *   error value as indicated in the reasons for error section. Otherwise,
 *   the passphrase is stored in the output parameter and 0 is returned.
 */

long parsePassphrase( char *str, unsigned char *passphrase) {

  /* Check if str less than 8 characters */
  if ( strlen(str) < PASSPHRASE_SIZE ) {

    /* return error value */
    return LENGTH_ERR;
  }
  else {

    int i = 0;
    /* a loop to copy first 8 characters */
    for ( i = 0; i < PASSPHRASE_SIZE; ++i) {

      passphrase[i] = str[i];

    }

    /* return 0 on success */
    return 0;
  }

}
