/*
 * Filename: testparseArgs.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the function parseArgs.
 * Date: May 09, 2016
 * Sources of Help: handout, write up, tutors.
 */ 

#include <string.h>

#include "test.h"
#include "pa3.h"


/*
 * Unit Test for parseArgs.c
 *
 * int parseArgs(int argc, char * const argv[], struct argInfo * argInfo);
 * 
 * Parses the command line arguments using getopt() and sets the fields of the
 * argInfo struct accordingly.
 * 
 * Returns 0 on success, 1 on failure.
 */

void testparseArgs() {
  printf( "Testing parseArgs()\n" );

  /*
   * Test #1:
   * All flags are entered with no errors.
   */
  int argc = 3;
  char * argv[argc];
  optind = 1;



  /* Initialize command line arguments */
  argv[0] = "programName";
  argv[1] = "-f";
  argv[2] = "anagrams.af";
  argv[3] = "-c";
  argv[4] = "-b";
  argv[5] = "13";

  struct argInfo argInfo;

  /* Check return value from parseArgs (0 for success) */
  TEST( parseArgs( argc, argv, &argInfo ) == 0 );

  /* Check that the fields of argInfo were properly set */
  TEST( (argInfo.flags & COLLISION_FLAG) == COLLISION_FLAG );
  TEST( strncmp( argInfo.afFileName, "anagrams.af", BUFSIZ ) == 0 );
  TEST( argInfo.hashBits == 13 );


  /*
   * Test #2: with no args
   * Flgas are entered with errors.
   */
  argc = 1;
  char *argv1[argc];
  optind = 1;

  /*Initialize command line arguments */
  argv1[0] = "progName";

  struct argInfo argInfo1;

  /* Check return value from parseArgs (0 for success) */
  TEST( parseArgs( argc, argv1, &argInfo1 ) == 1 );

 
  /*
   * Test #3:
   * Flags are entered with errors
   */
  argc = 2;
  char *argv2[argc];
  optind = 1;

  /*Initialize command line arguments */
  argv2[0] = "progName";
  argv2[1] = "-f";

  struct argInfo argInfo2;

  /* Check that the fields of argInfo were properly set */
  TEST( parseArgs( argc, argv2, &argInfo2) == 1);

  /*
   * Test #4: with no f flags
   * Flags are entered with errors
   */
  argc = 3;
  char *argv3[argc];
  optind = 1;

  /* Initialize command line arguments */
  argv3[0] = "progName";
  argv3[1] = "-b";
  argv3[2] = "22";

  struct argInfo argInfo3;

  /* Check that the fields of argInfo were properly set */
  TEST( parseArgs( argc, argv3, &argInfo3 ) == 1 );
  TEST( argInfo3.flags == HASH_BITS_FLAG );
  TEST( argInfo3.hashBits == 22 );

  /*
   * Test #5: with too large hash bits 
   * Flags are entered with errors
   */
  argc = 5;
  char *argv4[argc];
  optind = 1;

  /* Initialize command line arguments */
  argv4[0] = "progName";
  argv4[1] = "-f";
  argv4[2] = "myFile.af";
  argv4[3] = "-b";
  argv4[4] = "99999999999999999999999999999";

  struct argInfo argInfo4;

  /* Check return value from parseArgs (0 for success) */
  TEST( parseArgs( argc, argv4, &argInfo4 ) == 1 );

  /* Check that the fields of argInfo were properly set */
  TEST( strncmp( argInfo4.afFileName, "myFile.af", BUFSIZ ) == 0 );

  /*
   * Test #6: with invalid hashbits 
   * Flags are entered with errors
   */
  argc = 5;
  char *argv5[argc];
  optind = 1;

  /* Initialize command line arguments */
  argv5[0] = "progName";
  argv5[1] = "-f";
  argv5[2] = "myFile.af";
  argv5[3] = "-b";
  argv5[4] = "111cd";

  struct argInfo argInfo5;

  /* Check return value from parseArgs (0 for success) */
  TEST( parseArgs( argc, argv5, &argInfo5 ) == 1 );

  /* Check that the fields of argInfo were properly set */
  TEST( strncmp( argInfo5.afFileName, "myFile.af", BUFSIZ ) == 0 );

  /*
   * Test #7: with outside range
   * Flags are entered with errors
   */
  argc = 5;
  char *argv6[argc];
  optind = 1;

  /* Initialize command line arguments */
  argv6[0] = "progName";
  argv6[1] = "-f";
  argv6[2] = "myFile.af";
  argv6[3] = "-b";
  argv6[4] = "12";

  struct argInfo argInfo6;

  /* Check return value from parseArgs (0 for success) */
  TEST( parseArgs( argc, argv6, &argInfo6 ) == 0 );

  /* Check that the fields of argInfo were properly set */
  TEST( strncmp( argInfo6.afFileName, "myFile.af", BUFSIZ ) == 0 );
  TEST( argInfo6.flags == HASH_BITS_FLAG );
  TEST( argInfo6.hashBits == 12 );

  /*
   * Test #8: with extra arguments
   * Flags are entered with errors
   */
  argc = 7;
  char *argv7[argc];
  optind = 1;

  /* Initialize command line arguments */
  argv7[0] = "progName";
  argv7[1] = "-f";
  argv7[2] = "myFile.af";
  argv7[3] = "-b";
  argv7[4] = "12";
  argv7[5] = "extra";
  argv7[6] = "anotherextra";

  struct argInfo argInfo7;

  /* Check return value from parseArgs (0 for success) */
  TEST( parseArgs( argc, argv7, &argInfo7 ) == 1 );

  /* Check that the fields of argInfo were properly set */
  TEST( strncmp( argInfo7.afFileName, "myFile.af", BUFSIZ ) == 0 );
  TEST( argInfo7.flags == HASH_BITS_FLAG );
  TEST( argInfo7.hashBits == 12 );

  /* print message indicate that finished test */
  printf( "Finished running tests on parseArgs()\n" );
}

/*
 * Main function for this tester will call testparseArgs()
 */
int main() {
  testparseArgs();

  return 0;
}
