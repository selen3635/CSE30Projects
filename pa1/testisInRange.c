/*
 * Filename: testisInRange.c
 * Author: Xiaolong Zhou
 * Userid: cs30xaeo
 * Description: Unit test program to test the function isInRange.
 * Date: April 10, 2016
 * Sources of Help: handout from lecture, cs30 webpage, tutors.
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For isInRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int isInRange( long minRange, long maxRange, long value, long exclusive );
 *
 * If exclusive is 0, check the inclusive range.
 * If exclusive is non-0, check the exclusive range.
 *
 * Returns -1 if minRange is greater than maxRange.
 * Returns 1 if value is within minRange and maxRange.
 * Returns 0 otherwise.
 */

void testisInRange() {
  (void) printf( "Testing isInRange()\n" );

  /* Test around 0 */
  TEST( isInRange( 0, 0, 0, EXCLUSIVE ) == 0 );
  TEST( isInRange( 0, 0, 0, INCLUSIVE ) == 1 );

  TEST( isInRange( -1, 1, 0, EXCLUSIVE ) == 1 );
  TEST( isInRange( -1, 1, 0, INCLUSIVE ) == 1 );


  /* Test if minRange is larger than maxRange */
  TEST( isInRange(8, 1, 5, EXCLUSIVE ) == -1 );
  TEST( isInRange(8, 1, 5, INCLUSIVE ) == -1 );
    
  /* Test if value is larger than maxRange */
  TEST( isInRange(0, 100, 200, EXCLUSIVE ) == 0 );
  TEST( isInRange(0, 100, 200, INCLUSIVE ) == 0 );

  /* Test if value is less than minRange */
  TEST( isInRange(0, 100, -200, EXCLUSIVE ) == 0 );
  TEST( isInRange(0, 100, -200, INCLUSIVE ) == 0 );

  /* Test value is equal to min or max */
  TEST( isInRange(0, 100, 100, EXCLUSIVE ) == 0 );
  TEST( isInRange(0, 100, 100, INCLUSIVE ) == 1 );
  TEST( isInRange(0, 100, 0, EXCLUSIVE ) == 0 );
  TEST( isInRange(0, 100, 0, INCLUSIVE ) == 1 );

  /* Test value is in range */
  TEST( isInRange(0, 100, 50, EXCLUSIVE ) == 1 );
  TEST( isInRange(0, 100, 50, INCLUSIVE ) == 1 );

  (void) printf( "Finished running tests on isInRange()\n" );
}

/*
 * main function for this tester, will call testisInRange function
 */
int main( void ) {
  testisInRange();
  return 0;
}
