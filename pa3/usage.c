/*
 * Filename: usage.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Print the appropriate usage message to the specified stream.
 *              If the usageMode is USAGE_SHORT, print the short usage 
 *              message. Ohterwise print the long usage message.
 * Date: May 14, 2016
 * Source of Help: write up, tutors
 */

/*
 * Header files included here
 */
#include <stdlib.h>
#include "pa3Strings.h"
#include "pa3.h"

/*
 * Function name: usage()
 * Function prototype:
 *     void usage( FILE *stream, enum usageMode u, const char*proName);
 * Description: Print the appropriate usage message to the specified stream.
 * Parameters:
 *     FILE *stream -- will print usage message to this file
 *     enum usageMode u -- the mode of usage
 *     char *progName -- name of program
 * Side Effect: None.
 * Error Condition: None.
 * Return Value: None.
 */

void usage(FILE *stream, enum usageMode u, const char *progName) {

  /* Check whether usage is short */
  if ( u == USAGE_SHORT) {
    
    /* print short usage */
    (void)fprintf(stream, STR_USAGE_SHORT, progName, progName);

  }
  /* Otherwise usage is long */
  else {

    /* print long usage */
    (void)fprintf(stream, STR_USAGE_LONG, progName, MIN_HASH_BITS,
      MAX_HASH_BITS);
  }

}//end of program
