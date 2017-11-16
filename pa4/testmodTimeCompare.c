/*
 * Unit test for modTimeCompare.c
 */

#include "test.h"
#include "pa4.h"


void testmodTimeCompare() {

  struct fileInfo myInfo1;
  struct fileInfo myInfo2;

  myInfo1.stbuf.st_mtime = 1245;
  myInfo2.stbuf.st_mtime = 1740;
  TEST( modTimeCompare( &myInfo1, &myInfo2) > 0 );

  myInfo1.stbuf.st_mtime = 1720;
  myInfo2.stbuf.st_mtime = 1459;
  TEST( modTimeCompare( &myInfo1, &myInfo2) < 0 );

  myInfo1.stbuf.st_mtime = 1111;
  myInfo2.stbuf.st_mtime = 1111;
  TEST( modTimeCompare( &myInfo1, &myInfo2) == 0 );



}

int main() {

  testmodTimeCompare();
  return 0;
}

