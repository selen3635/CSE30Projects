/*
 * Filename: truncateHashKey.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: In this module we want to truncate the hashKey by extracting
 * 		the lower number of bits specified by numBits.
 * Date: May 07, 2016
 * Source of Help: handout from lecture, write up, tutors
 */

	.global truncateHashKey		! Declare the symbol to be global

	LENGTH	= 32			! constant
	
	.section ".text"		! The text segment start here

/*
 * Function name: truncateHashKey()
 * Function prototype: long truncateHashKey( long hashKey, long numBits);
 * Description: This function will truncate the hashKey bu extracting the
 * 		lower number of bits specified by numBits.
 * Parameters:
 * 	arg 1: long hashKey -- hash key value
 * 	arg 2: long numBits -- number of bits
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: Truncated hashkey.
 * Registers Used:
 * 	%i0 - arg 1 -- first parameter, represent hashkey
 * 	%i1 - arg 2 -- second parameter, represent numofbits
 * 	%l0 -- local register to store value
 * 	%l1 -- local register to store value
 * 	%l7 -- local register to store value
 */

truncateHashKey:

	save	%sp, -92 & -8, %sp	! Save caller's window

	mov	LENGTH, %l7		! make a copy of length to local
	sub	%l7, %i1, %l0		! sub length by num of bits
	sll	%i0, %l0, %l1		! shift hashkey to left
	srl	%l1, %l0, %i0		! shift hashkey to right

	ret				! Return from subroutine
	restore				! Restore caller's window
