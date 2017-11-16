/*
 * Filename: testbuildFileInfoTable.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the function buildFileInfoTable
 * Date: May 22, 2016
 * Source of Help: write up, tutors
 */

#include "test.h"
#include "pa4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Unit test for buldFileInfoTable.c
 *
 * ---
 * int buildFileInfoTable( const char *filename, struct fileInfo **tablePtr);
 *
 * This function takes in a file/directory name and an empty table of fileInfo
 * struct.
 *
 * ---
 * Returns 0 on success, 1 on failure
 */

void testbuildFileInfoTable() {

  /* print out message indicate starting test */
  (void)printf("Test buildFileInfoTable()\n " );

  
  /* declare some files and structs */
  char *filename1 = "myDirtory";
  char *filename = "parseArgs.c";
  char filename2[BUFSIZ] = "myfile";
  struct fileInfo *myTable = NULL;
  struct fileInfo *myTable1 = NULL;
  struct fileInfo *myTable2 = NULL;

  char *filename3 = "/home/solaris/ieng9/cs30x/";
  struct fileInfo *myTable3 = NULL;

  TEST(buildFileInfoTable(filename3, &myTable3) == 599);

  /*
   * Test #1:
   *  test a file
   */
  TEST( buildFileInfoTable(filename, &myTable) == 1);
  TEST( strcmp(myTable->name, filename) == 0 );
  TEST( (myTable->stbuf).st_size == 2832 );

  /*
   * Test #2:
   *  test a diretory
   */
 TEST( buildFileInfoTable(filename1, &myTable2) == 5);
 TEST( strcmp(myTable2[1].name, "..") == 0 );
 TEST( strcmp(myTable2[2].name, "file1.c" ) == 0);
 TEST( strcmp(myTable2[4].name, "file3.c" ) == 0);
 TEST( (myTable2[2].stbuf).st_size == 12 );
 TEST( (myTable2[4].stbuf).st_size == 15);

  /*
   * Test #3:
   * test a invalid file
   */
  TEST( buildFileInfoTable(filename2, &myTable1) == 0);


  /* print out message indicate finished test*/
  (void)printf("Finished running tests on buildFileInfoTable()\n " );

}

/*
 * Main function for this tester, will call testbuildFileInfoTable.
 */
int main() {
 
  testbuildFileInfoTable();
  return 0;
}
