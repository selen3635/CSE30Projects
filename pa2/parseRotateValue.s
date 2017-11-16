/*
 * Filename: parseRotateValue.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will convert the rotate value passed in as
 *              command line argument from a string to a long, and will check
 *              if it is in the required range.
 * Date:     April 26, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global parseRotateValue	! Declare the symbol to be globally

	OFFSET = 4			! constant variables
	BASE = 10	

	.section ".text"		! The text segment start here
/*
 * Function name: parseRotateValue()
 * Function prototype: long parseRotateValue( char *str, long *rotateValue);
 * Description: This function will convert the rotate value passed in as
 *              command line argument from a string to a long.
 * Parameters:
 * 	arg1: char *str -- string to be convert
 * 	arg2: long *rotateValue -- the rotate value
 * Side Effect: None.
 * Error Condition: If the number was too large to be successfully converted,
 * 	return ERANGE_ERR. If the number contained invalid characters,
 * 	return ENDPTR_ERR. If the number was outside the required range,
 * 	return BOUND_ERR.
 * Return Value: long. If the conversion was successful, the rotate value is
 * 	stored in the output parameter(rotateValue), and 0 is returned.
 * 	Otherwise, return appropriate error value.
 * Registers Used:
 * 	%l0 - local register -- represent errno
 * 	%l1 - local register -- store return value
 * 	%l2 - local register -- value of end pointer
 * 	%l3 - local register -- value of min range
 * 	%l4 - local register -- value of max range
 *	%l6 - local register -- value of endptr error
 *	%l7 - local register -- value of range error
 *	%o0 -- first argument passed in function
 *	%o1 -- second argument passed in function
 *	%o2 -- third argument passed in function
 *	%o4 -- fourth argument passed in function
 *	%i0 -- first parameter / return value
 *	%i1 -- second parameter
 */

parseRotateValue:

	save	%sp, -(92 + OFFSET)& -8, %sp
					! Save caller's window

	set	errno, %l0		! Address of where we can find errno
	st	%g0, [%l0]		! Dereference to set value to 0


	mov	%i0, %o0		! Put a copy of first arg to regis
	add	%fp, -OFFSET, %o1	! pass &endptr as 2nd param
	mov	BASE, %o2		! pass base to function
	call	strtol			! Make a function call
	nop

	mov	%o0, %l1		! store return value to local regis

	set	errno, %l0		! Load address of errno
	ld	[%l0], %l0		! get value of errno
	cmp	%l0, %g0		! compare errno with 0
	be	else			! function call then report errno error
	nop

rangeError:

	set	ERANGE_ERR_G, %l7	! Load address of range error
	ld	[%l7], %l7		! get value of range error
	mov	%l7, %i0		! put return value to i0
	ret				! Return from subroutine
	restore				! Restore caller's window

else:

	ld	[%fp - OFFSET], %l2	! get value of endptr
	ldub	[%l2], %l2		! dereference it to get char
	cmp	%l2, %g0		! compare it with '\n'
	be	else2			! if not '\n', error
	nop

endptrError:

	set	ENDPTR_ERR_G, %l6	! load address of endptr error
	ld	[%l6], %l6		! get value of endptr error
	mov	%l6, %i0		! put return value to i0
	ret				! return from subroutine
	restore				! restore caller's window

else2:

	set	MIN_ROTATE_G, %l3	! load address of min range
	ld	[%l3], %l3		! get value of min range
	set	MAX_ROTATE_G, %l4	! load address of max range
	ld	[%l4], %l4		! get value of max range
	
	mov	%l3, %o0		! pass first argument
	mov	%l4, %o1		! pass second argument
	mov	%l1, %o2		! pass third argument
	mov	0, %o3			! pass fourth argument
	call	isInRange		! Make function call
	nop

	cmp	%o0, %g0		! compare returned value with 0
	be	else3
	nop

valid:
	mov	0, %i0			! put a copy of 1 to i0
	st	%l1, [%i1]		! store value to second param
	ret				! return from subroutine
	restore				! restore caller's window

else3:

	set	BOUND_ERR_G, %l5	! load address of bound error
	ld	[%l5], %l5		! get value of it
	mov	%L5, %i0		! put a copy of value to i0
	ret				! return from subroutine
	restore				! restore caller's window
	

