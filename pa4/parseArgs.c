/*
 * Filename: parseArgs.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Parse the command-line options using getopt_long(), setting
 *              the user-specified flags in an int variable. One of the best
 *              resource for this function is the man page.
 * Date: May 20, 2016
 * Source Of Help: write up, tutors
 */

/*
 * Header files included here
 */
#include <getopt.h>
#include "pa4.h"
#include "pa4Strings.h"

/*
 * Function name: parseArgs()
 * Function prototype: int parseArgs(int argc, char *argv[] );
 * Description: Parse the command-line options using getopt_long(), setting
 *              the user-specified flags in an int variable.
 * Parameters:
 *    int argc -- number of arguments that passed in
 *    char * argv[] -- actual arguments that passed in
 * Side Effects: None.
 * Error Conditions: getopt_long() detects an invalid flag and automatically
 *                   prints an error message-> set the ERR_FLAG bit.
 * Return Value: An int variable with the specific bits set correspoinding 
 *               to the flags entered by the user.
 */

int parseArgs( int argc, char *argv[] ) {

  /* flag entered by user */
  int myFlag = 0;
  optind = 1;
  int c = 0;
  int temp = 1;

  /* a loop to parse all arguments */
  while (temp) {

    /* initialize a struct with options */
    struct option longopts[] = {
        {STR_A_LONG, no_argument, NULL, CHAR_A_FLAG},
        {STR_R_LONG, no_argument, NULL, CHAR_R_FLAG},
        {STR_B_LONG, no_argument, NULL, CHAR_B_FLAG},
        {STR_F_LONG, no_argument, NULL, CHAR_F_FLAG},
        {STR_H_LONG, no_argument, NULL, CHAR_H_FLAG},
        {0, 0, 0, 0}
    };

    /* call getopt_long to parse arguments */
    c = getopt_long ( argc, argv, ARG_STR, longopts, NULL);

    /* check if there is no arguments */
    if ( c == -1)
      break;

    /* switch cases */
    switch(c) {

      /* case with -a flag */
      case CHAR_A_FLAG:
        myFlag = myFlag | A_FLAG;
        break;

      /* case with -l flag */
      case CHAR_L_FLAG:
        myFlag = myFlag | L_FLAG;
        break;

      /* case with -r flag */
      case CHAR_R_FLAG:
        myFlag = myFlag | R_FLAG;
        break;

      /* case with -t flag */
      case CHAR_T_FLAG:
        myFlag = myFlag | T_FLAG;
        break;

      /* case with -B flag */
      case CHAR_B_FLAG:
        myFlag = myFlag | B_FLAG;
        break;

      /* case with -F flag */
      case CHAR_F_FLAG:
        myFlag = myFlag | F_FLAG;
        break;

      /* case with -h flag */
      case CHAR_H_FLAG:
        myFlag = myFlag | H_FLAG;
        break;
      
      /* case with error flag */
      case '?':
        myFlag = myFlag | ERR_FLAG;
        return myFlag;

      default:
        break;
    }
  }//end of while

  return myFlag;
  
}// end of function
