/*
 * Filename: testparseRotateValue.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test function parseRotateValue
 * Date:     April 26, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

#include "test.h"            /* For TEST() macro and stio.h*/
#include <stdlib.h>          /* For rand() function prototype */
#include <limits.h>          /* For LONG_MIN and LONG_MAX */
#include "pa2.h"

/*
 * Unit test for parseRotateValue.c
 *
 * long parseRotateValue( char *str, long *rotateValue );
 *
 * This function will convert the rotate value passed in as a command
 * line argument from a string to a long, and check range.
 */

void testparseRotateValue() {

  /* Local variable */
  long key1 = 0;
  long *key = &key1;

  /* print message */
  (void)printf("Testing parseRotateValue()\n");

  /* Check error with out of range, big number */
  char *myStr = "9999999999999999999999999";
  TEST(parseRotateValue(myStr, key) == ERANGE_ERR);

  /* check error with invalid input */
  myStr = "25666777LL";
  TEST(parseRotateValue(myStr, key) == ENDPTR_ERR);

  /* Check error with bound error */
  myStr = "999999";
  TEST(parseRotateValue(myStr, key) == BOUND_ERR);

  /* Check bound error edge */
  myStr = "-63";
  TEST(parseRotateValue(myStr, key) == 0);
  TEST( *key == -63 );

  myStr = "63";
  TEST(parseRotateValue(myStr, key) == 0);
  TEST( *key == 63 );

  /* Check empty string */
  myStr = "";
  TEST(parseRotateValue(myStr, key) == 0);
  TEST( *key == 0 );

  /* Check valid input */
  myStr = "10";
  TEST(parseRotateValue(myStr, key) == 0);
  TEST( *key == 10 );



  (void)printf("Finished running tests on parseRotateValue()\n");

}

/*
 * Main function for this method will call testparseRotateValue
 */
int main() {

  testparseRotateValue();
  return 0;
}
