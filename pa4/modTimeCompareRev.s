/*
 * Filename: modTimeCompareRev.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will be used with qsort() to sort based on the 
 *              modification times (oldest first) of two struct fileInfo (
 *              which are passed in as void pointers).
 * Date:   May 21, 2016
 * Source of Help: write up, tutors
 */

	.global modTimeCompareRev	! Declare the symbol the be global

	.section ".text"		! The text segment begins here

/*
 * Function name: modTimeCompareRev()
 * Function prototype:
 *   int modTimeCompareRev( const void *p1, const void *p2);
 * Description: This function will be used with qsort() to sort based on the 
 		modification times(oldest first) of two struct fileInfo.
 * Parameters:
 * 	void *p1 -- first pointer passed in, represent struct fileInfo
 * 	void *p2 -- second pointer passed in, represent struct fileInfo
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: -1 if the first modification time is older, 0 if the 
 * 		modification times are the same, or +1 if the first
 * 		modification time is newer.
 * Register Used:
 * 	%o0 -- first argument passed in function
 * 	%o1 -- second argument passed in function
 * 	%o2 -- represent value of offset
 */

modTimeCompareRev:

	set	mtimeOffset, %o2	! load address of offset
	ld	[%o2], %o2		! get value of offset

	ld	[%o2 + %o0], %o0	! get first mod time
	ld	[%o2 + %o1], %o1	! get second mod time

	cmp	%o0, %o1		! compare two mod time
	bl	FirstOlder		! first modtification time older
	nop

	cmp	%o0, %o1		! compare two mod time
	bg	FirstNewer		! first modification time newer
	nop

	ba	Equal			! both are same
	nop

FirstOlder:
	mov	-1, %o0			! save return value to %o0
	retl				! return value
	nop	

FirstNewer:
	mov	1, %o0			! save return value to %o0
	retl				! return from leaf
	nop

Equal:
	mov	0, %o0			! save return value to %o0
	retl				! return from leaf
	nop

