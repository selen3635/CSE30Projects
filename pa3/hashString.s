/*
 * Filename: hashString.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will be used to create the hash key of an
 * 		anagram. This function creates an integer(long) hash key
 * 		from str by using an algorithm similar to Java's
 * 		String.hashCode().
 * Date:  May 07, 2016
 * Source of Help: handout, write up, tutors
 */

	.global hashString		! Declare the symbol to be global

	.section ".text"		! The text segment begins here

/*
 * Function name: hashString()
 * Function prototype: long hashString( const char * str);
 * Description: This functioin will be used to create the hash key of an
 * 		anagram. This function creates an integer(long) hash key
 * 		from str.
 * Parameters:
 * 	arg 1: const char * str -- the string value to be create the hash key
 * Side Effect: None.
 * Error Conditions: None.
 * Return Value: The hash key of str
 * Registers Used:
 * 	%o0 - arg 1 -- first argument for function
 * 	%o1 - arg 2 -- second argument for function
 * 	%i0 - param -- first parameter passed in function
 * 	%l0 - local register as a counter
 * 	%l1 - local register to store hash value
 * 	%l2 - local register to store string length
 * 	%l3 - local register to store HASH_PRIME value
 * 	%l4 - local register to store every character
 */

hashString:

	save	%sp, -92 & -8, %sp	! Save caller's window,
	clr	%l0			! set local regis to 0

	set	HashStartVal, %l1	! load address of hash_start_val
	ld	[%l1], %l1		! get the value of hash_start_val

	mov	%i0, %o0		! put a copy of parameter into reg
	call	strlen			! Make a function call
	nop

	mov	%o0, %l2		! save return value to local regis
	cmp	%l0, %l2		! compare %l0 with %l2
	bge	End_Loop		! if greater or equal, end loop
	nop

	set	HashPrime, %l3		! load address of HASH_PRIME
	ld	[%l3], %l3		! get value of HASH_PRIME

Loop:
	ldub	[%i0 + %l0], %l4	! load a character from %i0

	mov	%l1, %o0		! put a copy of parameter into reg
	mov	%l3, %o1		! put a copy of parameter into reg
	call	.mul			! Make a function call
	nop

	add	%o0, %l4, %l1		! get hash value
	inc	%l0			! increse %l0

	cmp	%l0, %l2		! compare %l0 with %l2
	bl	Loop			! keep loop if less
	nop

End_Loop:
	mov	%l1, %i0		! put hash value into regis
	ret				! return from subroutine
	restore				! Restore caller's window


