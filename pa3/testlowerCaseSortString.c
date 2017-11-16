/*
 * Filename: testlowerCaseSortString.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test function lowerCaseSortString
 * Date:  May 08, 2016
 * Source of Help: handout, write up, tutors
 */

#include "test.h"
#include <stdlib.h>
#include "pa3.h"

/*
 * Unit test for lowerCaseSortString
 *
 * void lowerCaseSortString( const char *src, int n, char *dest);
 *
 * This function will take the src string and will store a copy in dest
 * where all the characters are conveted to lowercase and sorted in order.
 */

void testlowerCaseSortString() {

  /* initialize variables */
  char *mySrc = "";
  char dest[50];
  int n = 0;

  /*print message indicate that we will start test */
  (void)printf("Testing lowerCaseSortString()\n");

  /* test with copying length 0 */
  mySrc = "aaa";
  lowerCaseSortString(mySrc, n, dest);
  TEST( dest == dest);

  /* Test with ordered string char */
  mySrc = "abcdefg";
  n = 4;
  lowerCaseSortString(mySrc, n, dest);
  TEST( 'a' == dest[0]);
  TEST( 'b' == dest[1]);
  TEST( 'c' == dest[2]);
  TEST( 'd' == dest[3]);

  /* Test with unordered string char */
  mySrc = "ltgms";
  n = 4;
  lowerCaseSortString(mySrc, n, dest);
  TEST( 'g' == dest[0]);
  TEST( 'l' == dest[1]);
  TEST( 'm' == dest[2]);
  TEST( 't' == dest[3]);

  /* Test with UPPER CASE string */
  mySrc = "ZVTMDA";
  n = 5;
  lowerCaseSortString(mySrc, n, dest);
  TEST( 'd' == dest[0]);
  TEST( 'm' == dest[1]);
  TEST( 't' == dest[2]);
  TEST( 'v' == dest[3]);
  TEST( 'z' == dest[4]);

  /* Test mixed characters */
  mySrc = "UrfoB";
  n = 5;
  lowerCaseSortString(mySrc, n, dest);
  TEST( 'b' == dest[0]);
  TEST( 'f' == dest[1]);
  TEST( 'o' == dest[2]);
  TEST( 'r' == dest[3]);
  TEST( 'u' == dest[4]);

  /* print message indicate that we finished test */
  (void)printf("Finished running tests on truncateHashKey()\n");

}

/*
 * Main function for this program will cal testlowerCaseSortString() 
 */
int main() {
  testlowerCaseSortString();
  return 0;
}
