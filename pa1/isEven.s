/**
 * Filename: isEven.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Contains method which is going to check whether the value
 *              is even or not.
 * Date: April 10, 2016
 * Sources of Help: handout from lecture, cs30 webpage, tutors
 */

	.global isEven		!Declares the symbol to be globally visible so
				!we can call this function from other modules.
	FACTOR = 2		! constant variable

	.section ".text"	! The text segment begins here

/*
 * Function name: isEven()
 * Function prototype: int isEven( long value );
 * Description: Check whether value is even or not.
 * Parameters:
 * 	arg 1: long value -- number to check.
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: if value is even, return 1. If value is odd, return 0.
 * Registers used:
 * 	%i0 - param 1 -- 1st number to be determined; also used to return the
 * 	               result.
 *	%o0 - arg 1 to function isEven
 *	%o1 - arg 2 to function isEven
 */

isEven:
	save	%sp, -96, %sp	! Save caller's window;
	mov	%i0, %o0	! Put a copy of the parameter in the registers.
	mov	FACTOR, %o1	! %o0 and %o1 to be passed to .rem

	call	.rem		! This is a transfer of control instruction and
	nop			! must be followed by a nop instruction
      
        cmp	0, %o0		! .rem's return value is in %o0, compare it
				! with 0.
	be	even		! if it equals, then call even
	nop
        
	cmp	%o0, 1		! .rem's return value is in %o0, compare it
				! with 1
	be	odd		! if it equals, then call odd
	nop

	cmp	%o0, -1		! .rem's return value is in %o0, compare it
				! with -1
	be	odd		! if it equals, then call odd
	nop

even:
	mov	1, %i0		! the value is even, move 1 to %i0
				! to return that value from this function

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

odd:
	mov	0, %i0		! the value is odd, move 0 to %i0
				! to return that value from this function
	
	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot	
