/*
 * Filename: hashKeyMemberCompare.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function takes two pointers to struct anagrams( the 
 *              prototype uses two void pointers, but it can be assumed that
 *              they are struct anagram pointers) and compare their hash keys.
 * Date:  May 14, 2016
 * Source of Help: write up, tutors
 */

	.global hashKeyMemberCompare		! Declares the symbol to global

	.section ".text"			! text segment start here

/*
 * Function name: hashKeyMemberCompare()
 * Function prototype: 
 * 	int hashKeyMemberCompare(const void *p1, const void *p2);
 * Description: This function takes two pointers to struct anagrams and
 * 		compares their hash keys.
 * Parameters:
 * 	void *p1 -- first anagram pointer
 * 	void *p2 -- second anagram pointer
 * Side Effect: None.
 * Error Condition: None.
 * Return Value: -1 if the first anagram's hash key is smaller, 0 if the 
 * 		anagrams' hash keys are the same, or +1 if the first 
 * 		anagrams's hash key is larger.
 * Registers Used:
 * 	%i0 -- first argument passed in
 * 	%i1 -- second argument passed in
 * 	%l3 -- offset of hashKey val
 * 	%l4 -- first hash key value
 * 	%l5 -- second hash key value
 */

hashKeyMemberCompare:
	save	%sp, -92 & -8, %sp		! save caller's window

	set	AnagramStructHashKeyOffset, %l3	! address of offset
	ld	[%l3], %l3			! get value

	ld	[%i0 + %l3], %l4		! get first hash key value
	ld	[%i1 + %l3], %l5		! get second hash key value

	cmp	%l4, %l5			! compare two hash key
	bl	Less				! first key is smaller
	nop

	cmp	%l4, %l5			! compare two keys
	bg	Greater				! first key is greater
	nop

	ba	Equal				! two keys are equal
	nop

Less:
	mov	-1, %i0				! store return val to regis
	ret					! return from subroutine
	restore					! restore caller's window

Greater:
	mov	1, %i0				! store return val to regis
	ret					! return from subroutine
	restore					! restore caller's window

Equal:
	mov	0, %i0				! store return val to regis
	ret					! return from subroutine
	restore					! restore caller's window

