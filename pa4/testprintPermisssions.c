/*
 * Unit test printPermission.c
 */


#include "pa4.h"
#include "test.h"


void testprintPermissions() {

  struct fileInfo *myTable;

  char *filename = "testfile.c";

  buildFileInfoTable(filename, &myTable);

  printPermissions(myTable->stbuf.st_mode);


}

int main() {

  testprintPermissions();
  return 0;

}
