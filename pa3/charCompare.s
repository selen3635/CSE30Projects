/*
 * Filename: charCompare.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function takes two pointers to characters( the prototype
 * 		uses two void pointers, but it can be assumed that they are
 * 		char pointers) and compares them.
 * Date:  May 07, 2016
 * Source of Help: handout, write up, tutors.
 */

	.global charCompare		! Declares the symbol to be global

	.section ".text"		! The text segment begins here

/*
 * Function name: charCompare()
 * Function prototype: int charCompare( const void *pl, const void *p2);
 * Description: This function takes two pointers to characters ( the prototype
 * 		uses two void pointers, but it can be assumed that they are
 * 		char pointers) and compares them.
 * Parameters:
 * 	arg 1: const void *p1 -- first pointer
 * 	arg 2: const void *p2 -- second pointer
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: -1 if the first char is smaller, 0 if the char's are the same
 * 		, or +1 if the first char is larger.
 * Registers Used:
 * 	%o0 - arg1 -- first argument passed in function
 * 	%o1 - arg2 -- second argument passed in function
 */

charCompare:

	ldub	[%o0], %o0		! load value of argument
	ldub	[%o1], %o1		! get value of arugment
	cmp	%o0, %o1		! compare first argument with second
	bl	less			! first less than second one
	nop
	
	cmp	%o0, %o1		! compare first argument with second
	be	equal			! first equal to second one
	nop

	ba	greater			! first greater than second one
	nop

less:
	mov	-1, %o0			! return -1
	retl				! since first less than second
	nop

equal:
	mov	0, %o0			! return 0 
	retl				! since they are equal
	nop

greater:
	mov	1, %o0			! return 1
	retl				! since first greater than second
	nop

