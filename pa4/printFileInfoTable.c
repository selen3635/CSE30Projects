/*
 * Filename: printFileInfoTable.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function handles printing all the output, displaying the
 *              imformation of each file in the file info table.
 * Date:  May 25, 2016
 * Source of Help: write up, tutors
 */

/*
 * Header files include here
 */
#include "pa4.h"
#include "pa4Strings.h"
#include <libgen.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <sys/mkdev.h>
#include <sys/types.h>

#define FOUR 4
#define SEVEN 7
#define NINET 19
#define TWELVE 12
#define FIVE 5

/*
 * Function name: printFileInfoTable()
 * Function prototype: 
 *   void printFileInfoTable( struct fileInfo *table, int entries,
 *     int printMode);
 * Description: This function handles printing all the output, displaying the
 *              information of each file in the file info table.
 * Parameters:
 *   *table -- a table include a list of information about file
 *   entries -- number of entries within that directory
 *   printMode -- indicate which mode suppose to print
 * Side Effect: print output
 * Error Conditions: None.
 * Return Value: None.
 */

void printFileInfoTable( struct fileInfo *table, int entries, int printMode) {


  /* wif the  -t flag present */
  if ( (printMode & T_FLAG) == T_FLAG ) {

    /* if the  -r flag present */
    if( (printMode & R_FLAG) == R_FLAG ) {

      /* sort by reverse modification time */
      qsort( table, entries, sizeof(struct fileInfo), modTimeCompareRev);
    }

    /* sort by modification time */
    else {
      qsort( table, entries, sizeof(struct fileInfo), modTimeCompare);
    }
  }// end of outter if

  /* if the -t flag absent */
  else {
    
    /* if the -r flag present */
    if( (printMode & R_FLAG) == R_FLAG) {

      /* sort by name reverse alphabetical order */
      qsort( table, entries, sizeof(struct fileInfo), nameCompareRev);
    }
    /* default sort */
    else {
    
      /* sort by name */
      qsort( table, entries, sizeof(struct fileInfo), nameCompare);
    }
    
  } // end of else

  /* loop through eveery file */
  int i;
  for( i = 0; i < entries; i++ ) {

    /* get name of file */
    char *myName = basename(table[i].name);

    /* check if there is no a flag */
    if( (printMode & A_FLAG) != A_FLAG ) {

      /* check if file start with '.' */
      if( myName[0] == '.' ) {

        continue;
      }

    }// end of if
    
    /* check if there is a B flag */
    if( (printMode & B_FLAG) == B_FLAG) {
      /* get length of name */
      int myLength = strlen( myName);

      /* do not list implied entries ending with '~' */
      if( myName[myLength - 1] == '~' ) {

        continue;
      }
    }//end of if

    /* check if -l flag is set */
    if( (printMode & L_FLAG) == L_FLAG ) {

      /* check if it is a directory */
      if( S_ISDIR(table[i].stbuf.st_mode)) {
        /* print file type */
        //(void)printf("%s", S_ISDIR(table[i].stbuf.st_mode) ? "d" : "-");   
        (void)printf("%s", "d"); 
      }
 
      /* check if it is a link file */
      else if( S_ISLNK(table[i].stbuf.st_mode)) {

        /*print file type */
        (void)printf("%s", "l");
      }

      /* check if it is a block device */
      else if( S_ISBLK(table[i].stbuf.st_mode)) {

        /* print file type */
        (void)printf("%s", "b");
      }

      /* check if it is a character device */
      else if( S_ISCHR(table[i].stbuf.st_mode)) {

        /* print file type */
        (void)printf("%s", "c");
      }

      /* check if it is a regular file */
      else {
        /* print file type */
        (void)printf("%s", "-");
      }

      /* print permisssion */
      printPermissions(table[i].stbuf.st_mode);
      (void)printf("%s", " ");

      /* print number of links */
      (void)printf(STR_NLINK, table[i].stbuf.st_nlink);

      /* print the owner name */
      printOwnerName(table[i].stbuf.st_uid);

      /* print the group name */
      printGroupName(table[i].stbuf.st_gid);

      /* check if file is block or character device */
      if(S_ISBLK(table[i].stbuf.st_mode) || S_ISCHR(table[i].stbuf.st_mode)) {

        major_t major = major(table[i].stbuf.st_rdev);
        minor_t minor = minor(table[i].stbuf.st_rdev);
        /* print major and minor number */
        (void)fprintf(stdout, STR_MAJOR_MINOR, major, minor);
      }
      /* print file size */
      else {

        (void)fprintf(stdout, STR_SIZE, table[i].stbuf.st_size);
      }

      struct timeval tv;
      /* get current time */
      (void)gettimeofday(&tv, NULL);

      /* time of six month ago */
      int myTime = tv.tv_sec - SIX_MONTHS_SEC;

      char subString[BUFSIZ];
      char subString2[BUFSIZ];
      /* get modification time */
      char *mTime = ctime(&(table[i].stbuf.st_mtime));

      /* modification time is greater than six month ago */
      if( myTime > table[i].stbuf.st_mtime) {
   
        /* create format of  time */
        size_t n = 7;
        (void)strncpy(subString, &(mTime[FOUR]), n );
        (void)strncpy(subString + SEVEN, &(mTime[NINET]), FIVE);

        /* add null terminator at the end of string */
        subString[strlen(subString)] = '\0';

        /* print time with specified format */
        (void)printf("%s", subString);
        (void)printf("%s", " ");
      
      }
      /* modification is less than six month ago */
      else {

        /* copy needed part of time */
        (void)strncpy(subString2, &(mTime[FOUR]), TWELVE);
        subString2[strlen(subString2)] = '\0';

        /* print time with specified format */
        (void)printf("%s", subString2);
        (void)printf("%s", " ");
      }

    }//end of if for -l flag


    /* print the file name */
    (void)printf("%s", table[i].name);

    if( (printMode & F_FLAG) == F_FLAG ) {
      /* check if it is a directory */
      if( S_ISDIR(table[i].stbuf.st_mode)) {

        (void)printf("%s", "/");
      }

      /* check if it is a symbolic link */
      else if( S_ISLNK(table[i].stbuf.st_mode)) {

        (void)printf("%s", "@");
      }
   
      /* check if it is socket */
      else if( S_ISSOCK(table[i].stbuf.st_mode)) {

        (void)printf("%s", "=");
      }

      /* check if it is named pipe */
      else if( S_ISFIFO(table[i].stbuf.st_mode)) {

        (void)printf("%s", "|");
      }

      /* check if  it is a door */
      else if( S_ISDOOR(table[i].stbuf.st_mode)) {

        (void)printf("%s", ">");
      }

      /* check if it is executable */
      else if( (S_IXUSR & table[i].stbuf.st_mode) !=0 || 
        (S_IXGRP & table[i].stbuf.st_mode) != 0
        || (S_IXOTH & table[i].stbuf.st_mode) != 0) {

        (void)printf("%s", "*");
      }


    }// end of if to check -F 

    /* print new line */
    (void)printf("\n");

  }// end of for loop


}//end of function
