/**
 * Filename: testisEven.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the function isEven.
 * Date: April 11, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors.
 */

#include "pa1.h" /* For isEven() function prototype */
#include "test.h" /* For TEST() macro and stdio.h */

/*
 * int isEven( long value );
 *
 * If value is even, return 1. If value is odd, return 0.
 */

void testisEven(){
  (void) printf( "Testing isEven()\n" );

  /* Test even numbers */
  TEST( isEven(-4) == 1 );
  TEST( isEven(-2) == 1 );
  TEST( isEven(0) == 1 );
  TEST( isEven(2) == 1 );
  TEST( isEven(4) == 1 );

  /* Test odd numbers */
  TEST( isEven(-3) == 0 );
  TEST( isEven(-1) == 0 );
  TEST( isEven(1) == 0 );
  TEST( isEven(3) == 0 );

  /* Test large numbers */
  TEST( isEven(-1111111) == 0 );
  TEST( isEven(2222222) == 1 );

  (void) printf( "Finished running tests on isEven()\n" );
}

/*
 * main function for this tester, will call testisEven function
 */
int main( void ) {
  testisEven();
  return 0;
}
