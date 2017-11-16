/**
 * Filename:  numOfDigits.s
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description:
 * Date: April 10, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global numOfDigits	! Declares the symbol to be globally visible so
				! we can call this function from other modules
	MIN = 2			! Constant variable
	MAX = 36		! Constant variable

	.section ".text"	! THe text segment begins here

/*
 * Function name: numOfDigits()
 * Function prototype: int numOfDigits( long num, int base );
 * Description: This program will find out the number of digits for a given
 * 		number.
 * Parameters:
 * 	arg 1: long num -- give number
 * 	arg 2: int base -- base which is between 2 to 36
 * Side Effects: None
 * Error Conditions: base is not within the range [2, 36] inclusive, return -1
 * Return Value: if base is out of range return -1. if num is 0, reuturn 0.
 *               Otherwise return digits in num.
 * Registers used:
 * 	%i0 - param 1 -- the number passed in to this function
 * 	%o0 - arg 1 to isInRange function
 * 	%o1 - arg 2 to isInRange function
 * 	%o2 - arg 3 to isInRange function
 * 	%o3 - arg 4 to isInRange function
 * 	%l0 - local register, worked as a counter
 */

numOfDigits:
	save	%sp, -96, %sp	! Save caller's window;
	mov	MIN, %o0	! Put a copy of the parameter in the register
	mov	MAX, %o1	! Put a copy of the parameter in the register
	mov	%i1, %o2	! Put a copy of the parameter in the register
	mov	0, %o3		! Put a copy of the parameter in the register
	call	isInRange	! Make function call
	nop			! Delay slot for call instruction

	mov	%o0, %l0	! map returned value to %l0

	cmp	0, %l0		! compare 0 with returned value
	be	errorCondi	! value is not in range
	nop

	cmp	0, %i0		! compare 0 with num
	be	zeroNum		! num is 0
	nop

	mov	0, %l0		! map 0 to %l0
	cmp	%i0, 0		! compare num with 0
	be	endLoop		! Opposite logic test to skip over body loop
	nop

loop:
	mov	%i0, %o0	! Put a copy of the parameter in the register
	mov	%i1, %o1	! Put a copy of the parameter in the register
	inc	%l0		! increments counter: ++i
	call	.div		! This is a trasfer of control instruction
	nop

	mov	%o0, %i0	! Update value of %i0
	cmp	%o0, 0		! .div's return value compare with 0
	bne	loop		! if it is bigger than 0 keep loop
	nop

endLoop:
	mov	%l0, %i0	! move counter to %i0
	
	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

errorCondi:
	mov	-1, %i0		! value is out of range, return -1

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

zeroNum:
	mov	0, %i0		! num is 0, return 0

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
		
