/*
 * C file to define global variables across C and Assembly
 */

#include "pa4.h"
#include "pa4Strings.h"

int mtimeOffset = offsetof( struct fileInfo, stbuf.st_mtime );

char strGname[] = STR_GNAME;
char strGid[] = STR_GID;
