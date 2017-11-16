/**
 * Filename: pa1.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description:  This program will first perform input checking. If all
 *               input is valid, then it will call drawS(). If any of the
 *               input checks fail, print the corresponding error string.
 *               Otherwise this program will draw S charactor.
 * Date:      April 13, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors.
 */

/* Include header file */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pa1Strings.h"
#include "pa1.h"

/* define constant variables */
#define TWO 2
#define THREE 3
#define FOUR 4

/*
 * Function name: main()
 * Function prototype: int main( int argc, char * argv[] );
 * Descriptoion: This function will drive the rest of the program. It will
 *               first perform input checking. If all input is valid, it
 *               will call drawS(). If any of the input checks fail, print
 *               corresponding error strings.
 * Parameters: 4 ascii values to draw s
 * Side Effects: out put a pattern 'S'
 * Error Conditions: invalid input
 * Return Value: EXIT_FAILURE indicating failed execution, and EXIT_SUCCESS
 *               indicating successful execution
 */
int main( int argc, char * argv[] ) {

  /* local variables */
  char * endptr;
  char myBuffer[BUFSIZ];
  // char myBuffer = (char)malloc(sizeof(char));

  /* set initial values to 0 */
  long sWidth = 0;
  long sChar = 0;
  long fillerChar = 0;
  long borderChar = 0;

  /* local vairables to determine if there is error */
  long widthError = 1;
  long sError = 1;
  long fillerError = 1;
  long borderError = 1;

  /* before each conversion, set errno to 0 */
  errno = 0;

  /* check whether number of argument valid */
  if( argc != EXPECTED_ARGS) {
    
    /* Error messages are printed to stderr */
    (void)fprintf( stderr, STR_USAGE, argv[0], S_WIDTH_MIN, S_WIDTH_MAX,
      ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX);
  
  return EXIT_FAILURE;
  }

  /* First Convertion */

  /* convert first string to long */
  sWidth = strtol(argv[1], &endptr, BASE);

  /* check if errno has been set */
  if( errno != 0) {

    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_CONVERTING, argv[1], BASE);

    /* print a descriptive error message to stderr */
    perror(myBuffer);

    /* set to 0 mean we met an error */
    widthError = 0;
  }

  /* check if the end of pointer is \0 */
  else if( *endptr != '\0') {
    (void)fprintf(stderr, STR_NOTINT, argv[1]);
    widthError = 0;
    
  }
  else {
    
    /* check if there is no error until now */
    if( widthError == 1) {

      /* check if it is in range */
      if(isInRange(S_WIDTH_MIN, S_WIDTH_MAX, sWidth, INCLUSIVE) == 0){

        /* print stderr error message */
        (void)fprintf(stderr, STR_ERR_S_WIDTH_RANGE,
          sWidth, S_WIDTH_MIN, S_WIDTH_MAX);
        widthError = 0;
      }
    }

    /* check whether width is even */
    if( isEven(sWidth) != 1) {

      /* print stderr error message */
      (void)fprintf(stderr, STR_ERR_S_WIDTH_EVEN, sWidth);
      widthError = 0;
    }
  }
    
  /* Second Convertion */

  /* reset errno to 0 */
  errno = 0;

  /* convert second string to long */
  sChar = strtol(argv[TWO], &endptr, BASE);

  /* check if error has been set */
  if( errno !=0 ) {

    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_CONVERTING, argv[TWO], BASE);

    /* print descriptive error message to stderr */
    perror(myBuffer);
    sError = 0;
  }

  /* check whether end point is \0 */
  else if ( *endptr != '\0' ) {

    /* print stderr message */
    (void)fprintf(stderr, STR_NOTINT, argv[TWO]);
    sError = 0;
  }

  else {
    /* check if there is no error until now */
    if ( sError == 1 ) {
      /* check whether it within range */
      if( isInRange(ASCII_MIN, ASCII_MAX, sChar, INCLUSIVE) == 0) {

        /* print stderr message */
        (void)fprintf(stderr, STR_ERR_S_CHAR_RANGE, sChar, ASCII_MIN, ASCII_MAX);
        sError = 0;
      }
    }
  }

  /* Third Convertion */

  /* reset errno to 0 */
  errno = 0;

  /* convert third string to long */
  fillerChar = strtol(argv[THREE], &endptr, BASE);

  /* check if errno has been set */
  if( errno != 0) {
    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_CONVERTING, argv[THREE], BASE);

    /* print descriptive error message to stderr */
    perror(myBuffer);
    fillerError = 0;
  }

  /* check whether end pointer is \0 */
  else if ( *endptr !=  '\0' ) {
    
    /* print stderr message */
    (void)fprintf(stderr, STR_NOTINT, argv[THREE]);
    fillerError = 0;
  }

  else {
    
    /* check if there is no error until now */
    if ( fillerError == 1 ) {
      /* check if it is not in range */
      if( isInRange(ASCII_MIN, ASCII_MAX, fillerChar, INCLUSIVE) == 0 ) {

        /* print stderr error message */
        (void)fprintf(stderr, STR_ERR_FILLERCHAR_RANGE, fillerChar, ASCII_MIN,
          ASCII_MAX);
        fillerError = 0;
      }
    }

    /* check if they are equal */
    if ( fillerChar == sChar ) {

      /* print stderr message */
      (void)fprintf(stderr, STR_ERR_S_CHAR_FILLERCHAR_DIFF, sChar, fillerChar);
      fillerError = 0;
    }
  }

  /* Fourth Convertion */

  /* reset errno to 0 */
  errno = 0;

  /* convert fourth string to long */
  borderChar = strtol(argv[FOUR], &endptr, BASE);

  /* check if errno has been set */
  if( errno != 0 ) {
    
    /* redirect printf output to buffer */
    (void)snprintf( myBuffer, BUFSIZ, STR_CONVERTING, argv[FOUR], BASE);

    /* print descriptive error message to stderr */
    perror(myBuffer);
    borderError = 0;
  }

  /* check if end pointer is \0 */
  else if ( *endptr != '\0' ) {

    /* print stderr message */
    (void)fprintf(stderr, STR_NOTINT, argv[FOUR]);
    borderError = 0;
  }

  else {
    
    /* check if there is no error for this conversion for now */
    if ( borderError == 1 ) {

      /* check if it is not in range */
      if ( isInRange(ASCII_MIN, ASCII_MAX, borderChar, INCLUSIVE) == 0) {

        /* print stderr message */ 
        (void)fprintf(stderr, STR_ERR_BORDERCHAR_RANGE, borderChar, ASCII_MIN,
          ASCII_MAX);
        borderError = 0;
      }
    }

    /* check if they are equal */
    if ( borderChar == sChar ) {

      /* print stderr message */
      (void)fprintf(stderr, STR_ERR_S_CHAR_BORDERCHAR_DIFF, sChar, borderChar);
      borderError = 0;
    }
  }

  /* check if errors were encountered */
  if(widthError == 0 || sError == 0 || fillerError == 0 || borderError == 0) {
    return EXIT_FAILURE;
  }
  else
   
    drawS(sWidth, sChar, fillerChar, borderChar);
    return EXIT_SUCCESS;

}
