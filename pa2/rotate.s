/**
 * Filename:  rotate.s
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description: This function will rotate the bits in the 64-bit crypto mask.
 * 		The rotateValue indications how many bits to rotate by.
 * Date:      April 23, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global rotate		! Declare the symbol to be globally visible

	THIRTYONE = 31		! Constant variable
	OFFSET = 4		! COnstant variable

	.section ".text"	! The text segment start here

/*
 * Function name:  rotate()
 * Function prototype: void rotate( unsigned long mask[], long ratateValue);
 * Description: This function will rotate the bit in the 64-bit crypto mask.
 * Parameters:
 * 	arg1: unsigned long mask -- a crypto mask
 * 	arg2: long ratateValue -- indicates how many bits to rotate by
 * Side Effects: None
 * Error Condition: None
 * Return Value: None. Store the rotated mask in the output parameter mask
 * Registers Used:
 * 	%i0 - param 1 -- 1st parameter for this function
 * 	%i1 - param 2 -- 2nd parameter for this function
 * 	%o0 - arg 1 -- first argument which is mask
 * 	%o1 - arg 2 -- second argument which is rotate value
 * 	%l0 - local register -- fist half mask
 * 	%l1 - local register -- second half mask
 * 	%l2 - local register -- represent 1 with 31 zeros
 * 	%l3 - local register -- most value / least value
 * 	%l4 - local register -- most value / least value
 *	%l7 - local register -- rotate value
 */

rotate:
	save	%sp, -92 & -8, %sp	! Save caller's window

	ld	[%i0], %l0		! Dereference first half mask
	ld	[%i0 + OFFSET], %l1	! Dereference second half mask

	mov	%i1, %l7		! copy rotatevalue to local register
	cmp	%l7, %g0		! compare value with 0
	be	endFunc			! if it equals 0
	nop

	cmp	%l7, %g0		! compare value with 0
	bg	rightRotate		! rotate right
	nop

leftRotate:

	mov	1, %l2
	sll	%l2, THIRTYONE, %l2	! shift 1 to most position


	and	%l0, %l2, %l3		! get first half most value
	and	%l1, %l2, %l4		! get second half most value

	srl	%l3, THIRTYONE, %l3	! shift most to least
	srl	%l4, THIRTYONE, %l4	! shift most to least

	sll	%l0, 1, %l0		! shift left 1 bit
	sll	%l1, 1, %l1		! shift left 1 bit

	or	%l0, %l4, %l0		! get shifted first half
	or	%l1, %l3, %l1		! get shifted second half

	inc	%l7			! decrement

	cmp	%l7, %g0		! compare value with 0
	bl	leftRotate		! keep left shift
	nop

	ba	endFunc			! loop end
	nop

rightRotate:

	and	%l0, 1, %l2		! get first half least value
	and	%l1, 1, %l3		! get second half least value

	sll	%l2, THIRTYONE, %l2	! shift to most value
	sll	%l3, THIRTYONE, %l3	! shift to most value

	srl	%l0, 1, %l4		! shift right 1 bit
	srl	%l1, 1, %l5		! shift right 1 bit

	or	%l2, %l5, %l1		! get shifted second half mask
	or	%l3, %l4, %l0		! get shifted first half mask

	dec	%l7			! Decrement rotatevalue

	cmp	%l7, %g0		! compare rotatevalue with 0
	bg	rightRotate		! keep right shift
	nop

	ba	endFunc			! end of loop
	nop

endFunc:

	st	%l0, [%i0]		! store value back to mask
	st	%l1, [%i0 + OFFSET]	! store value back to mask

	ret				! Return from subroutine
	restore				! Restore caller's window
