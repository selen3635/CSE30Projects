/*
 * Filename: buildFileInfoTable.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function takes in a file/directory name and empty table
 *              of fileInfo structs (which should have been passed in as the 
 *              address of a pointer to a struct fileInfo). The purpose of
 *              this function is to populate the table with information about
 *              the argument file/directory.
 * Date: May 21, 2016
 * Source of Help: write up, tutors
 */


/*
 * Header files include here
 */
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pa4Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa4.h"
#include <errno.h>


/*
 * Function name: buildFileInfoTable()
 * Function prototype:
 * int buildFileInfoTable( const char *filename, struct fileInfo **tablePtr);
 * Description: This function takes in a file/directory name and an empty
 *              table of fileInfo struct. The purpose of this function is to
 *              populate the table with information about the argument file/
 *              directory.
 * Parameters:
 *   char *filename -- name of a file
 *   fileInfo **tablePtr --  a pointer to store address
 * Side Effects: None.
 * Error Conditions: lstat() encountered an error->print STR_LSTAT_ERR and
 *                   recal perror(), passing in the name of the file.
 *                   Memory allocation fails->print the error by calling
 *                   perror(), passing in STR_ALLOC_ERR.
 *                   Directory couldn't be opened->print STR_OPENDIR_ERR and
 *                   call perror(), passing in the name of the directory.
 * Return Value: The number of entries added to the table of fileInfo structs
 *               if no entries were added to the table, return 0.
 */

int buildFileInfoTable( const char *filename, struct fileInfo **tablePtr) {

  /* Create some new structs */
  char buffer[BUFSIZ];
  struct stat myBuffer;
  struct fileInfo *temp;
  struct dirent *mydp;
  /* instance variable to counter number of files */
  int numOfFiles = 0;
  /* set errno to 0 */
  errno = 0; 

  /* get information on passed in file */
  if ( lstat(filename, &myBuffer) == 0 ) {
  
    /* check whether it is a directory */
    if (S_ISDIR(myBuffer.st_mode)) {

      /* print the name of directory */
      (void)fprintf(stdout, STR_DIR_LABEL, filename);

      /* open the directory */
      DIR *myDir = opendir(filename);
     
      /* failed to open directory */
      if ( myDir == NULL ) {

        /* failed to open directory, print error message */
        (void)fprintf(stderr, STR_OPENDIR_ERR);
        perror(filename);
        return 0;
      }
    
      /* read one entry of the directory at a time */
      while ((mydp = readdir(myDir)) != NULL ) {

        /* construct the pathname */
        (void)snprintf(buffer, BUFSIZ, STR_BUILD_PATHNAME, filename
          , mydp->d_name);

        /* check if can get information from this filename */
        if( lstat(buffer, &myBuffer) != 0) {
          
          (void)fprintf(stderr, STR_LSTAT_ERR);
          perror(mydp->d_name);
          continue;
        }
        else {

          /* resize array */
          temp = (struct fileInfo *)realloc(*tablePtr,
            (numOfFiles + 1) * sizeof(struct fileInfo ));
  
          /* store name and its stat info */
          if ( temp != NULL ) {

            /* let table point to new size of array */
            *tablePtr = temp;
            /* copy name and set null terminator */
            (void)strncpy((*tablePtr)[numOfFiles].name, mydp->d_name,
              strlen(mydp->d_name) + 1);
            (*tablePtr)[numOfFiles].name[strlen(mydp->d_name)] = '\0';
            (*tablePtr)[numOfFiles].stbuf = myBuffer;

            /* increse number of files */
            numOfFiles++;
            
          }

          /* failed to reallocate memory */
          else {

            /* print appropriate message */
            perror(STR_ALLOC_ERR);

            /* check if there are any entries were successfully added*/
            if ( numOfFiles != 0 ) {
              /* print messsage */
              (void)fprintf(stderr,STR_PARTIAL_INFO);
            }
            (void)closedir(myDir);
            return numOfFiles;

          }

        }// end of else within while loop

      } // end of while
      (void)closedir(myDir);
      return numOfFiles;

    }// end of inner if
    /* it is not a directory */
    else {

      *tablePtr = (struct fileInfo *)malloc(sizeof(struct fileInfo ));
 
       /* check if it fails to allocate space */
      if ( *tablePtr == NULL ) {
   
        /* print error message and return */
        perror(STR_ALLOC_ERR);
        return 0;
      }

      /* copy filename and struct stat into the struct fileInfo */
      (void)strncpy((*tablePtr)[0].name, filename, strlen(filename) + 1);
      (*tablePtr)[0].name[strlen(filename)] = '\0';
      (*tablePtr)[0].stbuf = myBuffer;
      
      /* increase number of files */
      numOfFiles++;
    }

  }// end of outter if
  else {

    /* print error message */
    (void)fprintf(stderr, STR_LSTAT_ERR);
    perror(filename);

    return 0;
  }

  return numOfFiles;
}//end of function
