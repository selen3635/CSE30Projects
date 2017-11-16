/*
 * Filename: printPermissions.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This routine prints out the various rwx permissions for the 
 *              owner, group, and others when the -l flag is set.
 * Date: May 25, 2016
 * Source of Help: write up, tutors
 */

/*
 * Header files include here
 */
#include <sys/stat.h>
#include <stdio.h>

/*
 * Function name: printPermissions()
 * Function prototype: void printPermissions( const mode_t mode );
 * Description: This routine prints out the various rwx permissions for the
 *              owner, group, and other when the -l flag is set.
 * Parameters: 
 *   const mode_t mode -- permission mode.
 * Side Effect: None.
 * Error Condition: None.
 * Return Value: None.
 */

void printPermissions( const mode_t mode ) {

  /* print out the various rwx permission for the ugo */
  (void)printf("%s", (mode & S_IRUSR) ? "r" : "-");
  (void)printf("%s", (mode & S_IWUSR) ? "w" : "-");
  (void)printf("%s", (mode & S_IXUSR) ? "x" : "-");
  (void)printf("%s", (mode & S_IRGRP) ? "r" : "-");
  (void)printf("%s", (mode & S_IWGRP) ? "w" : "-");
  (void)printf("%s", (mode & S_IXGRP) ? "x" : "-");
  (void)printf("%s", (mode & S_IROTH) ? "r" : "-");
  (void)printf("%s", (mode & S_IWOTH) ? "w" : "-");
  (void)printf("%s", (mode & S_IXOTH) ? "x" : "-");


}// end of function
