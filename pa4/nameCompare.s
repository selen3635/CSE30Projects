/*
 * Filename: nameCompare.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will be used with qsort() to sort based on the 
 * 		names of two struct fileInfo, in alphabetical order.
 * Date: May 21, 2016
 * Source of Help: write up, tutors
 */

	.global nameCompare		! Declare the symbol to be global

	.section ".text"		! The text segment begins here

/*
 * Function name: nameCompare()
 * Function prototype: int nameCompare( const void *p1, const void *p2);
 * Description: This function will be used with qsort() to sort based on the
 * 		names of two struct fileInfo, in alphabetical order.
 * Parameters:
 * 	void *p1 -- first pointer passed in  as a type of struct fileInfo
 * 	void *p2 -- second pointer passed in as a type of struct fileInfo
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: -1 if the first name is smaller, 0 if the names are the 
 * 		same, or +1 if the first name is larger.
 * Register Used:
 *   %l3 -- local register used to store result from strcmp function
 *   %i0 -- parameter - first parameter for this function
 *   %i1 -- parameter - second parameter for this function
 *   %o0 -- argument - first argument for function strcmp
 *   %o1 -- argument - second argument for function strcmp
 */

nameCompare:
	save	%sp, -92 & -8, %sp	! save caller's window

	mov	%i0, %o0		! make a copy of first name
	mov	%i1, %o1		! make a copy of second name
	call	strcmp			! Make a function call
	nop

	mov	%o0, %l3		! save return value to local regist

	cmp	%l3, %g0		! compare return value with 0
	bl	FirstSmall		! first name is smaller
	nop

	cmp	%l3, %g0		! compare return value with 0
	bg	FirstGreater		! first name is greater
	nop

	ba	Equal			! they are equal
	nop

FirstSmall:
	mov	-1, %i0			! save return value to %i0
	ret				! return from subroutine
	restore				! restore caller's window

FirstGreater:
	mov	1, %i0			! save return value to %i0
	ret				! return from subroutine
	restore				! restore from caller's window

Equal:
	mov	0, %i0			! save return value to %i0
	ret				! return from subroutine
	restore				! restore form caller's window

