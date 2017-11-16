/*
 * Filename: testcharCompare.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test function test charCompare
 * Date:  May 08, 2016
 * Source of Help: handout write up, tutors
 */

#include "test.h"
#include <stdlib.h>
#include "pa3.h"

/*
 * Unit test for charCompare
 * int charCompare( const void *p1, const void *p2);
 *
 * This function takes two pointers to characters and compare them.
 */
void testcharCompare() {

  /* initialize local variables */
  char *p1 = "a";
  char *p2 = "a";

  /* print message indicate that we will start test */
  (void)printf("Testing charCompare()\n");

  /* Test with same character */
  p1 = "z";
  p2 = "z";
  TEST(0 == charCompare(p1, p2));

  /* Test with p1 less than p2 */
  p1 = "t";
  p2 = "u";
  TEST( -1 == charCompare(p1, p2));

  /* Test with p1 less than p2 */
  p1 = "l";
  p2 = "f";
  TEST( 1 == charCompare(p1, p2));

  /* print message indicate that we finished test */
  (void)printf("Finished running tests on charCompare()\n");

}

/*
 * Main function for this program will call testcharCompare()
 */
int main() {
  testcharCompare();
  return 0;
}
