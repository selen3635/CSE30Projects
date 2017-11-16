/*
 * Filename: testhashString.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test function testhashString
 * Date:  May 08, 2016
 * Source of Help: handout, write up, tutors
 */

#include "test.h"              /* For TEST() macro and stdio.h */
#include <stdlib.h>
#include "pa3.h"
#include <string.h>

/*
 * A function to calculate hash value, use to compare will the other function
 *
 * long hashFunc(const char *myStr);
 */
long hashFunc(const char *myStr) {

  /* initialize hash value */
  long hash = HASH_START_VAL;
  /* get length of string */
  int strLen = strlen(myStr);

  int i = 0;
  /* a loop to calculate hash value */
  for( i = 0; i < strLen; i++) {
    hash = hash * HASH_PRIME + myStr[i];
  }

  return hash;
}



/*
 * Unit test for hashString
 *
 * long hashString( const char *str);
 *
 * This function will be used to create the hash key of an anagram.
 */

void testhashString() {


  /* print message indicate that we will start test */
  (void)printf("Testing hashString()\n");

  /* test 1 character */
  char *myChar = "a";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* test more character */
  myChar = "abcdefg";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* test string with same characters */
  myChar = "zzzzzzz";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* test a number as a character */
  myChar = "0";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* test more numbers */
  myChar = "2719847895732975";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* test with symbols */
  myChar = ",./~$&@*&$";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* test with long length of string */
  myChar = "jd23840239lsjgljsklfjlgjoidjlk*%#(*()#*%)*%)";
  TEST(hashFunc(myChar) ==  hashString(myChar));

  /* print message indicate that we finished test */
  (void)printf("Finished running tests on hashString()\n");

}

/*
 * Main function for this program will cal testhashString()
 */
int main() {
  testhashString();
  return 0;
}
