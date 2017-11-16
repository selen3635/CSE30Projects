/*
 * Filename: anagramCompare.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function takes two pointers to struct anagrams and
 * 		compares their hash keys. If their hash keys are the same,
 * 		it then compares their words.
 * Date: May 15, 2016
 * Source of Help: write up, tutors
 */

	.global anagramCompare		! Delcare symbols to globally visiable

	.section ".text"		! The text segment begins here


/*
 * Function name: anagramCompare()
 * Function prototype:
 * 	int anagramCompare(const void *p1, const void *p2);
 * Description: This function takes two pointers to struct anagrams and
 * 		compares their hash keys. If their hash keys are the same,
 * 		it then compares their words.
 * Parameters:
 * 	const void *p1 -- first pointer point to struct anagram
 * 	const void *p2 -- second pointer point to struct anagram
 * Side Effects: None.
 * Error Condition: None.
 * Return Value: -1 if the first anagram is smaller, 0 if the anagrams are
 * 		the same, or +1 if the first anagram is larger.
 * Registers Used:
 * 	%i0 -- first paramter for function
 * 	%i1 -- second parameter for function
 * 	%o0 -- first argument passed in function
 * 	%o1 -- second argument passed in function
 * 	%l0 -- store return value for hashKeyMemberCompare
 * 	%l1 -- word offset value
 * 	%l2 -- address of first word
 * 	%l3 -- address of second word
 *	%l4 -- store return value of strcmp
 */

anagramCompare:

	save	%sp, -92 & -8, %sp	! save caller's window
	
	mov	%i0, %o0		! make a copy of first argument
	mov	%i1, %o1		! make a copy of second argument
	call	hashKeyMemberCompare	! Make a function call
	nop

	mov	%o0, %l0		! store return value to local regis

	cmp	%l0, -1			! compare with -1
	be	FirstSmall		! first hash key smaller
	nop

	cmp	%l0, 1			! compare with 1
	be	FirstGreater		! first hash key greater
	nop

CompareWord:
	
	set	AnagramStructWordOffset, %l1
					! load address of offset
	ld	[%l1], %l1		! get value of offset

	ld	[%i0 + %l1], %l2	! load address of word

	ld	[%i1 + %l1], %l3	! load addres of word

	mov	%l2, %o0		! make a copy of first word
	mov	%l3, %o1		! make a copy of second word
	call	strcmp			! compare these two words
	nop

	mov	%o0, %l4		! store return value to local regist

	cmp	%l4, %g0		! compare return value with 0
	bl	FirstSmall		! first word is smaller
	nop

	cmp	%l4, %g0		! compare return value with 0
	bg	FirstGreater		! first word
	nop

	ba	Equal			! two words are equal
	nop

FirstSmall:
	mov	-1, %i0			! store return value 
	ret				! return from subroutine
	restore				! restore caller's window

FirstGreater:
	mov	1, %i0			! store return value
	ret				! return from subroutine
	restore				! restore caller's window

Equal:
	mov	0, %i0			! store return value
	ret				! return from subroutine
	restore				! restore caller's window





