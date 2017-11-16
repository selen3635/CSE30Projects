/*
 * Filename: testmodTimeCompareRev.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Unit test program to test the funciton modTimeCompareRev.
 * Date:  May 22, 2016
 * Source of Help: write up , tutors
 */

#include "test.h"
#include "pa4.h"

/*
 * Unit test for modTimeCompareRev.s
 *
 * ---
 * int modTimeCompareRev( const void *p1, const void *p2);
 *
 * This function will be used with qsort() to sort based on the modification
 * time of two struct fileInfo.
 *
 * ---
 *
 * Return 0 on success, 1 on failure.
 */

void testmodTimeCompareRev() {

  struct fileInfo myInfo1;
  struct fileInfo myInfo2;

  /* print out message indicate starting test */
  (void)printf( "Testing modTimeCompareRev()\n");

  /*
   * Test #1
   * test with same time
   */
  myInfo1.stbuf.st_mtime = 0;
  myInfo2.stbuf.st_mtime = 0;
  TEST( modTimeCompareRev(&myInfo1, &myInfo2) == 0 );

  /*
   * Test #2:
   * test with first time is older
   */
  myInfo1.stbuf.st_mtime = 1245;
  myInfo2.stbuf.st_mtime = 1740;
  TEST( modTimeCompareRev(&myInfo1, &myInfo2) < 0 );

  /*
   * Test #3:
   * test with second time is older
   */
  myInfo1.stbuf.st_mtime = 1327;
  myInfo2.stbuf.st_mtime = 926;
  TEST( modTimeCompareRev(&myInfo1, &myInfo2) > 0 );

   /*
   * Test #2:
   * test with first time is older with second
   */
  myInfo1.stbuf.st_mtime = 124550;
  myInfo2.stbuf.st_mtime = 174033;
  TEST( modTimeCompareRev(&myInfo1, &myInfo2) < 0 );


  /*  print out message indicate finished test */
  (void)printf("Finished runningi tests on modTimeCompareRev()\n" );

}

/*
 * Main function for this tester, will call testmodTimeCompareRev()
 */
int main() {

  testmodTimeCompareRev();
  return 0;
}
