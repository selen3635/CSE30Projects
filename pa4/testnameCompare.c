/*
 * Filename: testnameCompare.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the assembly function nameCompare.
 * Date: May 21, 2016
 * Sources of Help:  write up, tutors
 */ 

#include <string.h>

#include "test.h"
#include "pa4.h"


/*
 * Unit Test for nameCompare.s
 *
 * ---
 * int nameCompare( const void *p1, const void *p2 )
 * 
 * Compares two file names for sorting purposes
 * ---
 * 
 * Returns 0 on success, 1 on failure.
 */

void testnameCompare() {
  (void)printf( "Testing nameCompare()\n" );

  /*
   * Test #1:
   * First name is alphabetically first
   */

  /* Set up arguments */
  char * nam0 = "helloWorld";
  char * nam1 = "jelloWorld";

  /* Check return value from nameCompare (negative for first name first) */
  TEST( nameCompare( nam0, nam1 ) < 0 );


  /*
   * Test #2: 
   * Same names but different file extension
   */

  /* Set up arguments */
  char * nam2 = "cse30.af";
  char * nam3 = "cse30.csv";

  /* Check return value from nameCompare (negative for first name first) */
  TEST( nameCompare( nam2, nam3 ) < 0 );


  /*
   * Test #3:
   * Names are identical
   */
  char * name4 = "xiaolong Zhou";
  char * name5 = "xiaolong Zhou";
  /* Check return value from nameCompare */
  TEST( nameCompare( name4, name5 ) == 0 );

 
  /*
   * Test #4:
   * Second name alphabatically first
   */
  char * name6 = "window";
  char * name7 = "door";
  /* Check return value from nameCompare */
  TEST( nameCompare( name6, name7 ) > 0 );

  /*
   * Test #5:
   * second name longer than first name
   */
  char * name8 = "This is too much";
  char * name9 = "This is too muchh";
  /* Check return value from nameCompare */
  TEST( nameCompare( name8, name9 ) < 0 );

  /*
   * Test #6:
   * first name longer than second name
   */
  char *name10 = "mytester";
  char *name11 = "myteste";
  /* Check return value from nameCompare */
  TEST( nameCompare( name10, name11 ) > 0 );

  /*
   * Test #6:
   * test with same numbers
   */
  char *name12 = "12345";
  char *name13 = "12345";
  /* Check return value from nameCompare */
  TEST( nameCompare( name12, name13 ) == 0 );

  /*
   * Test #7:
   * test with different length extension
   */
  char *name14 = "killer.Z";
  char *name15 = "killer.Z1";
  /* Check return value from nameCompare */
  TEST( nameCompare( name14, name15 ) < 0 );

  /*
   * Test #8:
   * test with same lenth extension
   */
  char *name16 = "shotgun.AK47";
  char *name17 = "shotgun.AK47";
  /* Check return value from nameCompare */
  TEST( nameCompare( name16, name17 ) == 0 );

  /*
   * Test #9:
   * test with empty string
   */
  char *name18 = " ";
  char *name19 = " ";
  /* Check return value from nameCompare */
  TEST( nameCompare( name18, name19 ) == 0 );

  (void)printf( "Finished running tests on nameCompare()\n" );
}


/*
 * Main function for this tester, will call testnameCompare
 */
int main() {
  testnameCompare();

  return 0;
}
