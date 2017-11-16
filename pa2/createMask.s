/**
 * Filename:  createMask.s
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description: This module creates the 64-bits crypto mask that will later
 *              be used to encrypt the data.
 * Date:      April 23, 2016
 * Source of Help:  handout from lecture, cs30 webpage, tutors
 */

	.global createMask	! Declares the symbol to be globally visible
	
	OFFSET = 4
	
	.section ".text"	! The text segment start here

/*
 * Function name:  createMask()
 * Function prototype: void createMask( unsigned long keys[], 
 * 	unsigned char passphrase[]. unsigned long mask[] );
 * Description: creates the 64-bits crypto mask that will later be used to
 *              encrypt the data.
 * Parameters:
 * 	arg1: unsigned long keys -- a crypto key
 * 	arg2: unsigned char passphrase -- passphrase of at least 8 characters
 * 	arg3: unsigned long mask: a crypto mask
 * Side Effects: None
 * Error Condition: None
 * Return Value: None. Store the 64-bit crypto mask in the output paramter
 * Registers Used:
 * 	%i0 - param 1 -- first parameter represent key
 * 	%i1 - param 2 -- second parameter represent phrase
 * 	%l0 - local register -- represent fist key
 *	%l1 - local register -- represent second key
 *	%l2 - local register -- represent first half phrase
 *	%l3 - local register -- represent second half phrase
 */

createMask:

	save	%sp, -92 & -8, %sp	! Save caller's window;

	ld	[%i0], %l0		! Dereference first key to local reg
	ld	[%i0 + OFFSET], %l1	! Dereference second key into register
	ld	[%i1], %l2		! Put first half of passphrase into reg
	ld	[%i1 + OFFSET], %l3	! Put second half of phrase into regis

	xor	%l0, %l2, %l4		! xor key with first half phrase
	xor	%l1, %l3, %l5		! xor key with second half phrase

	st	%l4, [%i2]		! store value into parameter
	st	%l5, [%i2 + OFFSET]	! store value into parameter

	ret				! return from subroutine
	restore				! Restore caller's window;

