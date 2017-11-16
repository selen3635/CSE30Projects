/*
 * Filename: modTimeCompare.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will be used with qsort() to sort based on the
 *              modification times (newest first) of two struct fileInfo
 *              ( which are passed in as void pointers).
 * Date:  May 25, 2016
 * Source of Help: write up, tutors
 */

/*
 * Header files include here
 */
#include <sys/stat.h>
#include "pa4.h"

/*
 * Function name: modTimeCompare()
 * Function prototype: 
 *   int modTimeCompare( const void *p1, const void *p2);
 * Description: This function will be used with qsort() to sort based on the
 *              modification time of two struct fileInfo
 * Parameters:
 *   void *p1 -- first pointer passed in, point to struct fileInfo
 *   void *p2 --  second pointer passed in, point to struct fileInfo
 * Side Effect: None.
 * Error Condition: None.
 * Return Value: -1 if the first modification is newer, 0 if the modification
 *               time are the same, or +1 if the modification time is older.
 */

int modTimeCompare( const void *p1, const void *p2) {

  /* get time from struct fileInfo */
  int time1 = ((struct fileInfo *)p1)->stbuf.st_mtime;
  int time2 = ((struct fileInfo *)p2)->stbuf.st_mtime;
 
  /* check whether first modification is newer */
  if( time1 > time2 ) {

    return -1;
  }

  /* check whether first modification is older */
  if( time1 < time2 ) {

    return 1;
  }

  /* if both modification are same */
  return 0;

}// end of function
