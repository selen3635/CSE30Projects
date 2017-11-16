/**
 * Filename: isInRange.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: To check whether values are in ranges.
 * Date: April 10, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global isInRange	! Declares the symbol to be globally visible so
				! we can call this function from other modules.

	.section ".text"	! The text segment begins here

/*
 * Function name: isInRange()
 * Function prototype: int isInRange( long minRange, long maxRange,
 *                                    long value, long exclusive );
 * Description: Check whether values are in ranges.
 * Parameters:
 * 	arg 1: long minRange -- minimum value within range
 * 	arg 2: long maxRange -- maximum value within range
 * 	arg 3: long value -- number to check
 * 	arg 4: long exclusive -- if 0 then check inclusive range, otherwise
 * 	                         check exclusive range.
 * Side Effects: None.
 * Error Conditions: minRange is larger than maxRange, return -1.
 * Return Value: if minRange is larger than maxRange, return -1. Otherwise,
 *               return 1 to represent true, 0 to represent false.
 * Registers used:
 * 	%i0 - param 1 - first parameter to function isInRange
 * 	%i1 - param 2 - second parameter to function isInrange
 * 	%i2 - param 3 - third parameter to function isInrange
 *	%i3 - param 4 - forth parameter to function isInrange
 *	%l0, %l1, %l2, %l3 - local registers to store value of parameters
 */

isInRange:
	save	%sp, -96, %sp	! Save caller's window;
	mov	%i0, %l0	! Put a copy of the parameter in the registers.
	mov	%i1, %l1	! Put a copy of the parameter in the registers.
	mov	%i2, %l2	! Put a copy of the parameter in the registers.
	mov	%i3, %l3	! Put a copy of the parameter in the registers.

	cmp	%l0, %l1	! Compare minRange with maxRange
	bg	rangeNotValid	! if min is larger than max, return -1
	nop

	cmp	0, %l3		! check if it is inclusive
	be	isInclusive	! check inclusive range
	nop
	
	cmp	0, %l3		! check if it is exclusive
	bne	isExclusive	! check exclusive range
	nop

rangeNotValid:
	mov	-1, %i0		! range is not valid, return -1.

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

isInclusive:
	cmp	%l2, %l0	! compare value with minRange
	bl	outOfRange	! value is out of range
	nop

	cmp	%l2, %l1	! compare value with maxRange
	bg	outOfRange	! value is out of range
	nop

	mov	1, %i0		! value is in range, return 1

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

isExclusive:
	cmp	%l2, %l0	! compare value with minRange
	ble	outOfRange	! value is out of range
	nop

	cmp	%l2, %l1	!compare value with maxRange
	bge	outOfRange	! value is out of range
	nop

	mov	1, %i0		! value is in range, return 1

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

outOfRange:
	mov	0, %i0		! value is out of range, return 0.

	ret			! return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
