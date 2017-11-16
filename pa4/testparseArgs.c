/*
 * Filename: testparseArgs.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the function parseArgs
 * Date: May 22, 2016
 * Source of Help: write up, tutors
 */


#include <string.h>

#include "test.h"
#include "pa4.h"
#include "pa4Strings.h"


/*
 * Unit test for parseArgs.c
 *
 * ---
 * int parseArgs( int argc, char *argv[]);
 *
 * Parse the command-line options using getopt_long().
 *
 * Returns 0 on success, 1 on failure
 */

void testparseArgs() {

  /* print message indicate starting tester */
  (void)printf( " Testing parseArgs()\n" );

  /*
   * Test #1
   * test with -a flag
   */
  int argc = 2;
  char *argv[argc];
  optind =1;

  argv[0] = "pa4";
  argv[1] = "-a";

  TEST( parseArgs(argc, argv) == A_FLAG);

  /*
   * Test #2
   * test with -l flag
   */
  argc = 2;
  char *argv1[argc];
  optind =1;

  argv1[0] = "pa4";
  argv1[1] = "-l";

  TEST( parseArgs(argc, argv1) == L_FLAG);

  /*
   * Test #3
   * test with -r flag
   */
  argc = 2;
  char *argv2[argc];
  optind =1;

  argv2[0] = "pa4";
  argv2[1] = "-r";

  TEST( parseArgs(argc, argv2) == R_FLAG);

  /*
   * Test #4
   * test with -t flag
   */
  argc = 2;
  char *argv3[argc];
  optind =1;

  argv3[0] = "pa4";
  argv3[1] = "-t";

  TEST( parseArgs(argc, argv3) == T_FLAG);

  /*
   * Test #5
   * test with -B flag
   */
  argc = 2;
  char *argv4[argc];
  optind =1;

  argv4[0] = "pa4";
  argv4[1] = "-B";

  TEST( parseArgs(argc, argv4) == B_FLAG);

   /*
   * Test #6
   * test with -F flag
   */
  argc = 2;
  char *argv5[argc];
  optind =1;

  argv5[0] = "pa4";
  argv5[1] = "-F";

  TEST( parseArgs(argc, argv5) == F_FLAG);

   /*
   * Test #7
   * test with -h flag
   */
  argc = 2;
  char *argv6[argc];
  optind =1;

  argv6[0] = "pa4";
  argv6[1] = "-h";

  TEST( parseArgs(argc, argv6) == H_FLAG);

  /*
   * Test #8
   * test with -all flag
   */
  argc = 2;
  char *argv7[argc];
  optind =1;

  argv7[0] = "pa4";
  argv7[1] = "--all";

  TEST( parseArgs(argc, argv7) == A_FLAG);

  /*
   * Test #9
   * test with -reverse flag
   */
  argc = 2;
  char *argv8[argc];
  optind =1;

  argv8[0] = "pa4";
  argv8[1] = "--reverse";

  TEST( parseArgs(argc, argv8) == R_FLAG);

  /*
   * Test #10
   * test with --ignore-backups flag
   */
  argc = 2;
  char *argv9[argc];
  optind =1;

  argv9[0] = "pa4";
  argv9[1] = "--ignore-backups";

  TEST( parseArgs(argc, argv9) == B_FLAG);

  /*
   * Test #11
   * test with --classify flag
   */
  argc = 2;
  char *argv10[argc];
  optind =1;

  argv10[0] = "pa4";
  argv10[1] = "--classify";

  TEST( parseArgs(argc, argv10) == F_FLAG);

  /*
   * Test #12
   * test with --help flag
   */
  argc = 2;
  char *argv11[argc];
  optind =1;

  argv11[0] = "pa4";
  argv11[1] = "--help";

  TEST( parseArgs(argc, argv11) == H_FLAG);

  /*
   * Test #13
   * test with multiple flags
   */
  argc = 2;
  char *argv12[argc];
  optind =1;

  argv12[0] = "pa4";
  argv12[1] = "-la";

  TEST( parseArgs(argc, argv12) == ( L_FLAG | A_FLAG) );

  /*
   * Test #14
   * test with multiple flags
   */
  argc = 2;
  char *argv13[argc];
  optind =1;

  argv13[0] = "pa4";
  argv13[1] = "-lr";

  TEST( parseArgs(argc, argv13) == ( L_FLAG | R_FLAG) );

  /*
   * Test #15
   * test with multiple flags
   */
  argc = 2;
  char *argv14[argc];
  optind =1;

  argv14[0] = "pa4";
  argv14[1] = "-lB";

  TEST( parseArgs(argc, argv14) == ( L_FLAG | B_FLAG) );

  /*
   * Test #16
   * test with multiple flags
   */
  argc = 2;
  char *argv15[argc];
  optind =1;

  argv15[0] = "pa4";
  argv15[1] = "-lar";

  TEST( parseArgs(argc, argv15) == ( L_FLAG | A_FLAG | R_FLAG) );

  /*
   * Test #17
   * test with multiple flags
   */
  argc = 2;
  char *argv16[argc];
  optind =1;

  argv16[0] = "pa4";
  argv16[1] = "-rF";

  TEST( parseArgs(argc, argv16) == ( R_FLAG | F_FLAG) );

  /*
   * Test #18
   * test with invalid flag
   */
  argc = 2;
  char *argv17[argc];
  optind =1;

  argv17[0] = "pa4";
  argv17[1] = "-Z";

  TEST( parseArgs(argc, argv17) == (int)ERR_FLAG );

  /* print message indicate finish tester */
  (void)printf( "Finished running tests on parseArgs()\n" );

}

/*
 * Main function for this tester, will call testparseArgs() 
 */
int main() {

  testparseArgs();
  return 0;
}
