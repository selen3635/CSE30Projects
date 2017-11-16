/**
 * Filename:  printSegment.s
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description: This assembly module utilizes printChar() to print
 *              character(to stdout) amount number of times.
 * Date: April 14, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global printSegment	! Declares the symbol to be globally visible
	.section ".text"	! The text segment begins here

/*
 * Function name: printSegment()
 * Function prototype: void printSegment( long character, long amount );
 * Description: This assembly module utilizes printChar() to print
 *              character(to stdout) amount number of times
 * Parameters:
 * 	arg 1: long character -- character to be print
 * 	arg 2: long amount -- number of characters
 * Side Effects: None
 * Error Condition: None
 * Return Value: None
 * Registers Used:
 * 	%l0 - local register -- as a counter
 * 	%i0 - param 1 -- first parameter
 * 	%i1 - param 2 -- second parameter
 * 	%o0 - arg 1 -- argument passed to printChar() function
 */

printSegment:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated

	clr	%l0		! map 0 to %l0, as a counter

	cmp	%l0, %i1	! compare %l0 with second parameter
	bge	endLoop		! opposite logic test to skip over body loop
	nop			! delay slot for call instruction

loop:
	mov	%i0, %o0	! Put a copy of the parameter in the register
	inc	%l0		! increment counter
	call	printChar	! Make function call
	nop			! delay slot for call instruction

	cmp	%l0, %i1	! compare %l0  with second parameter
	bl	loop		! it it is less than amount keep loop
	nop			! delay slot



endLoop:
	
	ret			! return from subroutine
	restore			! Restore caller's window; in "ret"delay slot
