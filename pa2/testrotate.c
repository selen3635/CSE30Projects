/*
 * Filename: testrotate.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the function rotate..
 * Date:     April 23, 2016
 * Sources of Help: handout from lecture, cs30 webpage, tutors
 */ 

#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"        /* For rotate() function prototype */


/* Need to include the function prototype because it's commented out in pa2.h */
void rotate( unsigned long mask[], long rotateValue );

/*
 * Unit Test for rotate.s
 *
 * void rotate( unsigned long mask[], long rotateValue );
 *
 * Takes mask[0] as high order 32 bits and mask[1] as low order 32 bits
 * and simulates a 64-bit rotate within these two words.
 *
 * Lower 6 bits of rotateCnt is masked to keep rotate range 0-63.
 *
 * Positive rotateCnt - rotate right
 * Negative rotateCnt - rotate left
 */

void testrotate() {
  unsigned long mask[2];

  (void)printf( "Testing rotate()\n" );

  /*
   * Test with rotateCnt of 0 - should be no change.
   */
  mask[0] = 0x01234567;
  mask[1] = 0x89ABCDEF;

  rotate( mask, 0 );
  TEST( mask[0] == 0x01234567 && mask[1] == 0x89ABCDEF );

  /*
   * Test rotating left 1 bit.
   */
  mask[0] = 0x7FFFFFFF;
  mask[1] = 0x7FFFFFFF;

  rotate ( mask, -1 );
  TEST( mask[0] == 0xFFFFFFFE );
  TEST( mask[1] == 0xFFFFFFFE );

  /*
   * Test rotating right 1 bit.
   */
  mask[0] = 0xFFFFFFFE;
  mask[1] = 0xFFFFFFFE;

  rotate ( mask, 1 );
  TEST( mask[0] == 0x7FFFFFFF );
  TEST( mask[1] == 0x7FFFFFFF );

  /*
   * Test: rotating right 11 bits
   */
  mask[0] = 0x1A2B3C4D;
  mask[1] = 0x5E6F7B9F;

  rotate ( mask, 11 );
  TEST( mask[0] == 0x73E34567 );
  TEST( mask[1] == 0x89ABCDEF );

  /*
   * Test: rotating right 3 bits
   */
  mask[0] = 0xABCDFFFF;
  mask[1] = 0xFFFFABCD;

  rotate ( mask, 3 );
  TEST( mask[0] == 0xB579BFFF );
  TEST( mask[1] == 0xFFFFF579 );

  /*
   * Test: rotating left 5 bits
   */
  mask[0] = 0x1A2B3C4D;
  mask[1] = 0x5E6F7B9F;

  rotate ( mask, -5 );
  TEST( mask[0] == 0x456789AB );
  TEST( mask[1] == 0xCDEF73E3 );

  /*
   * Test: rotating left 20 bits
   */
  mask[0] = 0x3356BBBB;
  mask[1] = 0xCCCC2289;

  rotate ( mask, -20 );
  TEST( mask[0] == 0xBBBCCCC2 );
  TEST( mask[1] == 0x2893356B );

  /*
   * Test: rotating left 63 bits
   */
  mask[0] = 0x8D4E66C2;
  mask[1] = 0x4FF23ACB;

  rotate ( mask, -63 );
  TEST( mask[0] == 0xC6A73361 );
  TEST( mask[1] == 0x27F91D65 );

 
  /* Print message */
  (void)printf( "Finished running tests on rotate()\n" );

}

/*
 * Main method for this function, will call testrotate()
 */
int main() {
  testrotate();

  return 0;
}

