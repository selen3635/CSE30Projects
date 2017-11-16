/**
 * Filename: testnumOfDigits.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the function numOfDigits.
 * Date: April 11, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors.
 */

#include "test.h" /* For TEST() macro and stdio.h */
#include "pa1.h" /* For numOfDigits() function prototype */

/*
 * int numOfDigits( long num, int base );
 * 
 * If base is not within the range, return -1.
 * If num is 0, return 0.
 * Otherwise return the number of digits in num.
 */

void testnumOfDigits() {
  (void) printf( "Testing numOfDigits()\n" );

  /* Test number 0 */
  TEST( numOfDigits(0, 2) == 0 );

  /* Test base 2 */
  TEST( numOfDigits(1, 2) == 1 );
  TEST( numOfDigits(2, 2) == 2 );
  TEST( numOfDigits(16, 2) == 5 );

  /* Test base 8 */
  TEST( numOfDigits(1, 8) == 1 );
  TEST( numOfDigits(8, 8) == 2 );
  TEST( numOfDigits(10, 8) == 2 );
  TEST( numOfDigits(67, 8) == 3 );

  /* Test base is not within the range */
  TEST( numOfDigits(5, 1) == -1 );
  TEST( numOfDigits(10, 38) == -1 );
  TEST( numOfDigits(20, 50) == -1 );

  /* Test negative numbers */
  TEST( numOfDigits(-5, 2) == 3 );
}

/*
 * main function for this tester, will call testnumOfDigits function
 */
int main( void ) {
  testnumOfDigits();
  return 0;
}
