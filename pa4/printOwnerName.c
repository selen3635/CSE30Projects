/*
 * Filename: printOwnerName.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will print the file owner name, given the uid.
 *              A call to getpwuid(0 will return a pointer to a struct
 *              passwd, from which we can determine the user's login name.
 * Date:  May 25, 2016
 * Source of Help: write up, tutors
 */



/*
 * Header files include here
 */
#include <sys/types.h>
#include <pwd.h>
#include "pa4Strings.h"
#include <stdlib.h>

/*
 * Function name: printOwnerName()
 * Function prototype: void printOwnerName( const uid_t uid  );
 * Description: This function will print the file owner name, given the uid.
 * Parameters: 
 *   const uid_t uid -- a user id
 * Side Effect: None.
 * Error Condition: None.
 * Return Value: None.
 */

void printOwnerName( const uid_t uid ) {

  /* create a passwd struct */
  struct passwd *pwd;

  /* get user's login name/uid */
  pwd = getpwuid(uid);

  /* didn't find entry, print value of uid */
  if ( pwd == NULL ) {

    (void)fprintf(stdout, STR_UID, uid);
  }

  /* print out the owner name */
  else {

    (void)fprintf(stdout, STR_PWNAME, pwd->pw_name);
  }


}//end of function
