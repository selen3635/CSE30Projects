/**
 * Filename:  printChar.s
 * Author:    Xiaolong Zhou
 * Userid:    cs30xaeo
 * Description: This assembly module prints the character argument to stdout
 * Date:  April 14, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global printChar	! Declares the symbol to be globally visible

	.section ".data"	! The data segment begins here
fmt:
	.asciz	"%c"
	.section ".text"	! The text segment begins here

/*
 * Function name: printChar()
 * Function prototype: void printChar( char ch );
 * Description: This assembly module print the character argument to stdout
 * Parameters:
 * 	arg1: char ch -- character is going to be print
 * Registers Used:
 * 	%i0 - arg 1 -- the string (char *) passed in to this function
 * 	%o0 - param 1 to printf() -- format string
 * 	%o1 - param 2 to printf() -- copy of arg1 being passed in
 */

printChar:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated

	set	fmt, %o0	! Format string
	mov	%i0, %o1	! Copy of formal parameter to print
	call	printf		! Make function call
	nop			! Delay slot for call instruction

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
