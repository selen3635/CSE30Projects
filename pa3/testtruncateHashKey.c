/*
 * Filename: testtruncateHashKey.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test function testtruncateHashKey
 * Date: May 08, 2016
 * Source of Help: handout, write up, tutors
 */

#include "test.h"           /* For TEST() macro and stdio.h */
#include <stdlib.h>
#include "pa3.h"

/*
 * Unit test for truncateHashKey
 *
 * long truncateHashKey(long hashKey, long numBits);
 *
 * In this module we want to truncate the hashkey by extracting the lower
 * number of bits specified by numBits.
 */

void testtruncateHashKey() {

  /* initialize local variables */
  long myKey = 0;
  long numBits = 0;

  /* print message indicate that we will start test */
  (void)printf("Testing truncateHashKey()\n");

  /* test formal number */
  myKey = 12345;
  numBits = 6;

  TEST( 57 == truncateHashKey(myKey, numBits));

  /* keep 1 bits */
  myKey = 111111;
  numBits = 1;
  TEST( 1 == truncateHashKey(myKey, numBits));

  /* keep 10 bits */
  myKey = 88888888;
  numBits = 10;
  TEST( 568 == truncateHashKey(myKey, numBits));

  /* test with 0 hashkey value */
  myKey = 0;
  numBits = 20;
  TEST( 0 == truncateHashKey(myKey, numBits));

  /* Test with 32 bits hashkey value */
  myKey = 0xFFFFFFFF;
  numBits = 7;
  TEST( 127 == truncateHashKey(myKey, numBits));

  /* test with large numBits */
  myKey = 0xFFFFABCD;
  numBits = 30;
  TEST( 1073720269 == truncateHashKey(myKey, numBits));

  /* test with 32 numBits */
  myKey = 666;
  numBits = 32;
  TEST( 666 == truncateHashKey(myKey, numBits));

  /* print message indicate that we finished test */
  (void)printf("Finished running tests on truncateHashKey()\n");
}

/*
 * Main function will call testtruncateHashKey
 */
int main() {
  testtruncateHashKey();
  return 0;
}
