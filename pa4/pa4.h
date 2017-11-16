/*
 * Filename: pa4.h
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Header file for pa4 including constants and function protoypes.
 * Date:  May 22, 2016
 * Sources of Help: Given.
 */

#ifndef PA4_H
#define PA4_H

#include <dirent.h>   // For MAXNAMLEN - maximum filename length
#include <sys/stat.h> // For struct stat definition
#include <stddef.h>   // For offsetof macro

#define A_FLAG    0x00000001
#define L_FLAG    0x00000002
#define R_FLAG    0x00000004
#define T_FLAG    0x00000008
#define B_FLAG    0x00000010
#define F_FLAG    0x00000020
#define H_FLAG    0x00000040
#define ERR_FLAG  0x80000000

#define SIX_MONTHS_SEC 15724800  // Six months measured in seconds


struct fileInfo {
  char name[MAXNAMLEN];
  struct stat stbuf;
};

int parseArgs( int argc, char * argv[] );

int buildFileInfoTable( const char * filename, struct fileInfo ** tablePtr );

int modTimeCompare( const void * p1, const void * p2 );
int modTimeCompareRev( const void * p1, const void * p2 );
int nameCompare( const void * p1, const void * p2 );
int nameCompareRev( const void * p1, const void * p2 );

void printFileInfoTable( struct fileInfo * table, int entries, int printMode );

void printPermissions( const mode_t mode );
void printOwnerName( const uid_t uid );
void printGroupName( const gid_t gid );

#endif /* PA4_H */
