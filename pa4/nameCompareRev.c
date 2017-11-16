/*
 * Filename: nameCompareRev.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Descriptioin: This function will be used with qsort() to sort based on the
 *               names of two struct fileInfo, in reverse alphabetical order.
 * Date:  May 25, 2016
 * Source of Help: write up, tutors
 */


/*
 * Header files include here
 */
#include "pa4.h"



/*
 * Function name: nameCompareRev()
 * Function prototype: 
 *   int nameCompareRev( const void *p1, const void *p2);
 * Description: This function will be used with qsort() to sort based on the
 *              names of two struct fileInfo, in reverse alphabetical order.
 * Parameters:
 *   void *p1 -- first pointer passed in, point to struct fileInfo
 *   void *p2 -- second pointer passed in, point to struct fileInfo
 * Side Effect: None.
 * Error condition: None.
 * Return Value: -1 if the first name is larger, 0 if the names are the same,
 *               or +1 if the first name is smaller.
 */

int nameCompareRev( const void *p1, const void *p2) {

  /* get value of result by calling nameCompare */
  int myVal = nameCompare( p1, p2);

  /* reverse the return value*/
  if ( myVal == 1 ) {

    return -1;
  }
 
  /* reverse the return value */
  if( myVal == -1 ) {

    return 1;
  }

  /* return 0 if they are equal*/
  return 0;

}//end of function
