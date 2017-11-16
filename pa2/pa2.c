/*
 * Filename: pa2.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: There are 4 expected user inputs, you will be parsing the
 *              command line arguments, check for errors. 
 * Date:     April 28, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

#include <stdlib.h>
#include "pa2Strings.h"
#include "pa2.h"
#include <errno.h>

#define SIZE 2
#define BASE 10

/*
 * Function name: pa2.c
 * Function prototype:  int main( int argc, char *argv[] );
 * Description: This function is the main driver for the program. It
 *              will first parse all of the command line arguments. If
 *              all valid, will create a mast and perform the encryption
 *              and decryption from stdin.
 * Parameters:
 *    arg1: passphrase -- an at least 8 characters
 *    arg2: key0 -- a key to create mask
 *    arg3: key1 -- another key to create mask
 *    arg4: rotatevalue --  rotate value
 * Side Effect: output message on terminal
 * Error Conditions:
 *   Incorrect number of command line arguments are passed in
 *   passphrase does not meet the minimum length requirement
 *   key0, key1, or rotateValue are too large to be converted to longs
 *   key0, key1, or rotateValue contain invalid characters and cannot
 *   be converted to longs
 *   rotateValues is not within the valid range
 * Return Value: If errors were encountered, return EXIT_FAILURE.
 *               Otherwise, return EXIT_SUCCESS.
 */

int main( int argc, char *argv[] ) {

  /* local variables */
  long parsePVal = 0;
  long parseKVal1 = 0;
  long parseKVal2 = 0;
  long parseRVal = 0;
  unsigned long myKey1 = 0;
  unsigned long myKey2 = 0;
  long val = 0;
  long *rotateVal = &val;

  /* create a buffer */
  char myBuffer[BUFSIZ];
  int errorNum = 0;

  /* help in matching the output of the test program */
  (void)setvbuf( stdout, NULL, _IONBF, 0);

  /* decrese arg num */
  --argc;

  /* Check whether number of arguments are in the range */
  if ( argc != EXPECTED_ARGS ) {

    /* print usage error message */
    (void)fprintf(stderr, STR_USAGE, argv[0], MIN_ROTATE, MAX_ROTATE);

    return EXIT_FAILURE;
  }
  
  /* initialize a character array */
  unsigned char myPhrase[PASSPHRASE_SIZE];

  int i = 0;
  /* assign value to each element */
  for( i = 0; i < PASSPHRASE_SIZE; i++ ) {

    myPhrase[i] = INIT_PASSPHRASE;
  }

  /*call function to parse phrase */
  parsePVal = parsePassphrase( argv[PASSPHRASE_INDEX], myPhrase);

  /* check value returned by parsePassphrase */
  if ( parsePVal == LENGTH_ERR ) {
    
    /* print appropriate error message */
    (void)fprintf(stderr, STR_ERR_BAD_PASSPHRASE, PASSPHRASE_SIZE);

    /* increse error number */
    ++errorNum;
  }

  /* parse first key from argument */
  parseKVal1 = parseKey( argv[KEY_ONE_INDEX], &myKey1);

  /* Check if there is error when parse key1 */
  if( parseKVal1 == ERANGE_ERR ) {

    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_ERR_CONVERTING, 
      argv[KEY_ONE_INDEX], DEF_BASE);

    /*print a descriptive error message to stderr */
    perror(myBuffer);

    /* increase error num */
    ++errorNum;
  }
  else if ( parseKVal1 == ENDPTR_ERR) {

    /* print appropriate error message */
    (void)fprintf(stderr, STR_ERR_NOTINT, argv[KEY_ONE_INDEX]);

    /* increase error num */
    ++errorNum;
  }

  parseKVal2 = parseKey( argv[KEY_TWO_INDEX], &myKey2);
  
  /* check if there is error when parse key2 */
  if ( parseKVal2 == ERANGE_ERR ) {

    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_ERR_CONVERTING,
      argv[KEY_TWO_INDEX], DEF_BASE);

    /* print a descriptive error message to stderr */
    perror(myBuffer);

    /* increase error number */
    ++errorNum;
  }
  else if( parseKVal2 == ENDPTR_ERR ) {

    /* print appropriate error message */
    (void)fprintf(stderr, STR_ERR_NOTINT, argv[KEY_TWO_INDEX]);

    /* increase error number */
    ++errorNum;
  }

  /* call function to parse rotate value */
  parseRVal = parseRotateValue( argv[ROTATE_VALUE_INDEX], rotateVal);

  /* check if there is a range error */
  if ( parseRVal == ERANGE_ERR ) {

    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_ERR_CONVERTING,
      argv[ROTATE_VALUE_INDEX], BASE);

    /* print a descriptive error message to stderr */
    perror(myBuffer);

    /* increase error number */
    ++errorNum;
  }
  else if ( parseRVal == ENDPTR_ERR ) {

    /* print appropriate error message */
    (void)fprintf(stderr, STR_ERR_NOTINT, argv[ROTATE_VALUE_INDEX]);

    /* increse error number */
    ++errorNum;
  }
  else if ( parseRVal == BOUND_ERR ) {

    /* print appropriate error message */
    (void)fprintf(stderr, STR_ERR_BAD_ROT, MIN_ROTATE, MAX_ROTATE);

    /* increase error number */
    ++errorNum;
  }

  /* if there are errors, print number and exit */
  if ( errorNum != 0 ) {

    (void)fprintf(stderr, STR_ERR_NUM_ERRORS, errorNum);

    return EXIT_FAILURE;
  }

  /* create a key array */
  unsigned long keys[SIZE];
  keys[0] = myKey1;
  keys[1] = myKey2;
  /* initialize a mask */
  unsigned long mask[SIZE] = {0, 0};

  /* call createMask and myCipher */
  createMask(keys, myPhrase, mask);
  myCipher(stdin, mask, *rotateVal);

  return EXIT_SUCCESS;
} //end of program
