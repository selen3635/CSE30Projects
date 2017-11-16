/*
 * Filename: parseArgs.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function is responsible for parsing the command-line
 *              arguments and filling all the member fields of struct argInfo
 *              accordingly. This function must support the short options
 *              described in the long usage statement.
 * Date: May 07, 2016
 * Source of Help: handout, write up, tutors
 */

/*
 * Header files included here
 */
#include <stdio.h>
#include "pa3.h"
#include <errno.h>
#include <stdlib.h>
#include "pa3Strings.h"

#define BASE 10
#define MARK '?'

/*
 * Function name: parseArgs()
 * Function prototype:
 *     int parseArgs( int argc, char *const argv[], struct argInfo *argInfo);
 * Description: This function is responsible for parsing the command-line
 *              arguments and filling all the member fields of struct argInfo
 *              accordingly.
 * Parameters:
 *     int argc: a integer number
 *     char *const argv[]: an array of pointer to character
 *     struct argInfo* argInfo:  a defined structure
 * Side Effects: None.
 * Error Conditions: In this file, as soon as an error is detected, print
 *                   the appropriate error message and immediately return,
 *                   indicating failure.
 * Return Value: Zero on success, nonzero on failure.
 */

int parseArgs( int argc, char *const argv[], struct argInfo *argInfo) {

  /* flag enter by user */
  int myFlag = 0;
  /* a flag to check whether user user -f */
  int check = 0;
  char *endptr = NULL;
  char myBuffer[BUFSIZ];

  /*Initialize stucture */
  argInfo->flags = 0;
  argInfo->hashBits = 0;
  optind = 1;

  /* a loop to parse all arguments */
  while (( myFlag = getopt(argc, argv, ARG_STR)) != -1) {

    switch(myFlag) {

      /* case -f */
      case CHAR_AF_FLAG:
        check = 1;
        
        /* get af file */
        argInfo->afFileName = optarg;
        
      break;
      /* case -b */
      case CHAR_HASH_BITS_FLAG:
      
        /* set errno to 0 */
        errno = 0;
        
        /* convert string value to long */
        long myKey = strtol(optarg, &endptr, BASE);

        /* check if errno has been set */
        if( errno != 0 ) {

          /* redirect printf output to buffer */
          (void)snprintf(myBuffer, BUFSIZ, STR_ERR_CONVERTING, optarg, BASE);

          /* prin a descriptive error message to stderr */
          perror(myBuffer);
          return EXIT_FAILURE;
        }
        /* check if the end of pointer is \0 */
        else if ( *endptr != '\0') {
          (void)fprintf(stderr, STR_ERR_NOTINT, optarg);
          return EXIT_FAILURE;
        }

        /* check whether bit is in range */
        if ( isInRange(MIN_HASH_BITS, MAX_HASH_BITS, myKey, INCLUSIVE) == 0){

          /* print stderr message */
          (void)fprintf(stderr, STR_ERR_BAD_HASH_BITS, MIN_HASH_BITS,
            MAX_HASH_BITS);
            return EXIT_FAILURE;
        }

        /* store hashBit and flags */
        argInfo->hashBits = myKey;
        argInfo->flags |= HASH_BITS_FLAG;

      break;

      /* case -c */
      case CHAR_COLLISION_FLAG:

        /* store flags */
        argInfo->flags |= COLLISION_FLAG;
      break;

      /* case -h */
      case CHAR_HELP_FLAG:

        /* store flags */
        argInfo->flags |= HELP_FLAG;

        return EXIT_SUCCESS;

      /* case of unrecognized option */
      case MARK:
        return EXIT_FAILURE;
          
    }//end of switch

  }// end of while loop

  /* check whether user user flag -f */
  if ( check == 0 ) {
    return EXIT_FAILURE;
  }
  /* check if there is extra arguments */
  if ( optind < argc ) {

    /* print appropriate error message */
    (void)fprintf(stderr, STR_ERR_EXTRA_ARGS, argv[optind]);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}// end of function
