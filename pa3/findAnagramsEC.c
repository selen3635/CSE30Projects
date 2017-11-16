/*
 * Filename: findAnagrams.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function promts the user to enter a word to search for
 *              anagrams of. It then gets the word input from the user(from
 *              stdin) and prints any matching anagrams.
 * Date:  May 14, 2016
 * Source of Help: write up, tutors
 */


/* 
 * Header files included here
 */
#include <stdlib.h>
#include <stdio.h>
#include "pa3Strings.h"
#include "pa3EC.h"
#include <string.h>

/*
 * Function name: findAnagrams()
 * Function prototype:
 *     int findAnagrams( const struct argInfo *argInfo, 
 *                       const struct anagramInfo *anagramInfo);
 * Description: This function prompts the user to enter a word to search for
 *              anagrams of. It then gets the word inputs from the user
 *              (from stdin) and prints any matching anagram.
 * Parameters:
 *     argInfo -- a word entered by user
 *     anagramInfo -- a file that contains anagrams
 * Side Effects: None.
 * Error Conditions: Run out of memory when creating an anagram
 * Return Value: Zero on success, nonzero on failure
 */

int findAnagramsEC( const struct argInfo *argInfo,
                  const struct anagramInfo * anagramInfo) {

  /* create a anagram struct */
  struct anagram anagram;
  /* Initialize user input */
  char myInput[BUFSIZ];

  /* Initialize local variables */
  int myCollision = 0;
  int findAna = 0;
  char *myChar;
  char ch = '\n';

  /* Print user prompt */
  (void)fprintf(stdout, STR_USER_PROMPT);
  
  /* read word entered by user */
  while (fgets(myInput, BUFSIZ, stdin) != NULL ){

    /* reset collision/ findAna time */
    myCollision = 0;
    findAna = 0;
    /* replace '\n' with '\0' */
    myChar = strchr(myInput, ch);
    *myChar = '\0';

    /* check whether valid to create an anagram */
    if ( createAnagram(myInput, &anagram) == EXIT_FAILURE ) {

      return EXIT_FAILURE;
    }
  
    /* Check if -b flag has been set */
    if( (argInfo->flags & HASH_BITS_FLAG) == HASH_BITS_FLAG ) {
      
      /* truncate hash key */
      anagram.hashKey = truncateHashKey(anagram.hashKey, argInfo->hashBits);
    }

    /* search for word with same hash key value */
    struct anagram *mySearch = bsearch(&anagram,
      anagramInfo->anagramPtr, anagramInfo->numOfAnagrams,
      sizeof(struct anagram), hashKeyMemberCompare);

    /* check if there is no matching hash key */
    if ( mySearch != NULL ) {

      /* convert word to lowercase and sorted */
      lowerCaseSortString(anagram.word, strlen(anagram.word), anagram.word);

      /* check if previous anagram has the same hash key */
      while ( mySearch->word != anagramInfo->anagramPtr->word &&
        (mySearch - 1)->hashKey == anagram.hashKey ) {

        /* pointer to previous anagram */
        --mySearch;
      
      }// end of inner while

      /* from left to right to search for anagram */
      while ( mySearch->hashKey == anagram.hashKey) {

        /* local variable word */
        char myWord[BUFSIZ];
        char word[BUFSIZ];

        int result = strcmp(mySearch->word, anagram.word);
        if ( result == 0 ) {

          word = mySearch->word;
        }
        /* convert searched anagram to lowercase */
        lowerCaseSortString( mySearch->word, strlen(mySearch->word), myWord);

        /* compare two words */
        int cmp = strcmp(anagram.word, myWord);

        /* check whether two word are same */
        if ( cmp == 0 ) {

          if( findAna == 0) {
            /* print out message and set find flag to 1 */
            (void)fprintf(stdout, STR_FOUND_ANAGRAMS);
            findAna = 1;
          
            if( (int i =  strcmp(myWord, word)) != 0) {
          /*print out anagram */
            (void)fprintf(stdout, STR_ANAGRAM, mySearch->word);
            }
          }
        }
        else {
          /* increse number of collision */
          ++myCollision;
        }
        
        /* increament pointer */
        if ( mySearch->word != anagramInfo->anagramPtr[anagramInfo->
          numOfAnagrams -1].word ) {
          ++mySearch;
        }
        else
          break;

      }//end of inner while

    }//end of if  
    /* check if there is no anagram */
    if ( findAna == 0 ) {
    
      /* print out message */
      (void)fprintf(stdout, STR_NO_ANAGRAMS);
    }

    /* check whether -c flag has been set */
    if(( argInfo->flags & COLLISION_FLAG) == COLLISION_FLAG ) {

      (void)fprintf(stdout, STR_COLLISIONS, myCollision);
    }

    /* go to next line */
    (void)printf("\n");
    /* Print user prompt */
    (void)fprintf(stdout, STR_USER_PROMPT);
 
  }//end of while
 
  (void)printf("\n");
  return EXIT_SUCCESS;  
}//end of program
