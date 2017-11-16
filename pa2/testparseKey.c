/*
 * Filename: testparseKey.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test function parseKey
 * Date:     April 25, 2016
 * Source of Help: handout from lecture, cs30 webpase, tutors
 */

#include "test.h"           /* For TEST() macro ad stio.h */
#include <stdlib.h>         /* For rand() function prototype */
#include <limits.h>         /* For LONG_MIN and LONG_MAX */
#include "pa2.h"

/*
 * Unit test for parseKey.c
 *
 * long parseKey( char *str, unsigned long  *key);
 *
 * This module wil be used to parse the second and third command line
 * arguments, key0 and key1.
 */

void testparseKey() {

  /*  Local variable */
  unsigned long key1 = 0;
  unsigned long *key = &key1;

  (void)printf("Testing parseKey()\n");

  /* Test hexidecimal */
  char *myPtr = "0x11";
  TEST(parseKey( myPtr, key) == 0 ); 
  TEST( *key == 17);

  myPtr = "0xFFFFFFFF";
  TEST(parseKey( myPtr, key) == 0);
  TEST( *key == 0xFFFFFFFF );

  myPtr = "0x1A2B3C4D";
  parseKey( myPtr, key);
  TEST( *key == 439041101 ); 

  /* Check errors with out of range */
  myPtr = "9999999999999999999999999999";
  TEST( parseKey(myPtr, key) == ERANGE_ERR);

  /* Check error with invalid input */
  myPtr = "1234hh";
  TEST( parseKey(myPtr, key) == ENDPTR_ERR);

  /* Test decimal */
  myPtr = "1000000";
  TEST(parseKey( myPtr, key) == 0);
  TEST( *key == 1000000 );

  myPtr = "66";
  TEST(parseKey( myPtr, key) == 0);
  TEST( *key == 66 );
 
  /* Test Octal string value*/
  myPtr = "011";
  TEST(parseKey( myPtr, key) == 0);
  TEST( *key == 9 );

  /* Test Octal string value*/
  myPtr = "011";
  TEST(parseKey( myPtr, key) == 0);
  TEST( *key == 9 );

  /* Test empty string */
  myPtr = "";
  TEST(parseKey( myPtr, key) == 0);
  TEST( *key == 0 );

  /* Print message */
  (void)printf("Finished running tests on parseKey()\n");

}

/*
 * Main function will call testparseKey method 
 */
int main() {

  testparseKey();
  return 0;
}
