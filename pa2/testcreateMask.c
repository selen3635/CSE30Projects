/**
 * Filename:  testcreateMask.c
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description:  Unit test program to test function createMask
 * Date:      April 23, 2016
 * Source of Help: handout from lecture, cs30 webpage, turos
 */

#include "test.h"          /* For TEST() macro and stdio.h */
#include <stdlib.h>        /* For rand() function prototype */
#include "pa2.h"           /* For createMask() function prototype */

/*
 * Unit Test for createMask.s
 *
 * void createMask( unsigned long keys[], unsigned char passphrase[],
 *                  unsigned long mask[]);
 *
 * Create the 64-bits cryto mask that will later be used to encrypt the data.
 */

void testcreateMask() {

  /* declare arrays */
  unsigned long keys[KEY_SIZE];
  unsigned char phrase[PASSPHRASE_SIZE];
  unsigned long mask[MASK_SIZE];

  /* print message */
  (void)printf("Testing rotate()\n");

  /*
   * Test with hexidecimal keys
   */
  keys[0] = 0x89ABCDEF;
  keys[1] = 0x5A6B7FD9;
  
  /* set characters */
  phrase[0] = '1';
  phrase[1] = '2';
  phrase[2] = '3';
  phrase[3] = '4';
  phrase[4] = '5';
  phrase[5] = '6';
  phrase[6] = '7';
  phrase[7] = '8';

  /* call function */
  createMask( keys, phrase, mask);
  TEST( mask[0] == 0xB899FEDB && mask[1] == 0x6F5D48E1);


  /*  Test with decimal keys */
  keys[0] = 5;
  keys[1] = 10;

  /* set characters */
  phrase[0] = 'a';
  phrase[1] = 'b';
  phrase[2] = 'c';
  phrase[3] = 'd';
  phrase[4] = 'e';
  phrase[5] = 'f';
  phrase[6] = 'g';
  phrase[7] = 'h';

  createMask( keys, phrase, mask);
  TEST( mask[0] == 0x61626361 && mask[1] == 0x65666762);

  /* Test with 0 key */
  keys[0] = 0;
  keys[1] = 0;

  /* set characters */
  phrase[0] = '1';
  phrase[1] = '2';
  phrase[2] = '3';
  phrase[3] = '4';
  phrase[4] = '5';
  phrase[5] = '6';
  phrase[6] = '7';
  phrase[7] = '8';

  createMask( keys, phrase, mask);
  TEST( mask[0] == 0x31323334 && mask[1] == 0x35363738);

  /* Test with 111111.... keys */
  keys[0] = 0xFFFFFFFF;
  keys[1] = 0xFFFFFFFF;

  /* set characters */
  phrase[0] = 'A';
  phrase[1] = 'B';
  phrase[2] = 'C';
  phrase[3] = 'D';
  phrase[4] = 'E';
  phrase[5] = 'F';
  phrase[6] = 'G';
  phrase[7] = 'H';

  createMask( keys, phrase, mask);
  TEST( mask[0] == 0xBEBDBCBB && mask[1] == 0xBAB9B8B7);

  /* print message indicate that we finished test */
  (void)printf("Finished running tests on createMask()\n");

}

/*
 * Main function will call tetcreateMask method */
int main() {
  testcreateMask();
  return 0;
}
