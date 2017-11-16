/*
 * Filename: pa3Globals.c
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Global variables for pa3.
 * Date:     May 01, 2016
 * Sources of Help: Given.
 */


/*
 * C standard library headers 
 */
#include <stddef.h> // offsetof

/*
 * Assignment header(s)
 */
#include "pa3.h"

// Used in hashKeyMemberCompare() and anagramCompare()
size_t AnagramStructHashKeyOffset = offsetof(struct anagram, hashKey);
size_t AnagramStructWordOffset = offsetof(struct anagram, word);

// Used in hashString()
int HashPrime = HASH_PRIME;
int HashStartVal = HASH_START_VAL;
