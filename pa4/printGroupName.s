/*
 * Filename: printGroupName.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function will print the group name, given the gid. A
 *		call to getgrgid() will return a pointer to a struct group,
 *		from which we can determine the name of the group.
 * Date: May 25, 2016
 * Source of Help: write up, tutors
 */

	.global printGroupName		! Decalre the symbol to be globally

	.section ".text"		! The text segment begins here

/*
 * Function name: printGroupName()
 * Function prototype: 
 * 	void printGroupName( const gid_t gid );
 * Description: This function will print the group name, given the gid.
 * Parameters:
 * 	const gid_t gid -- a group name
 * Side Effects: None.
 * Error Condition: None.
 * Return Value: None.
 * Registers Used:
 * 	%i0 -- first parameter for the function
 * 	%l0 -- local register used to store first parameter
 * 	%o0 -- first argument for the function
 * 	%l1 -- local register used to store return value
 */

printGroupName:
	save	%sp, -92 & -8, %sp	!save caller's window

	mov	%i0, %l0		! save value of gib to local

	mov	%i0, %o0		! pass gid as a argument
	call	getgrgid		! make a function call
	nop

	mov	%o0, %l1		! save return value to local

	cmp	%l1, 0			! compare return value with 0
	be	NULL			! if it is NULL
	nop

Printname:
	
	set	strGname, %o0		! actual group name
	ld	[%l1], %o1		! get address of name
	call	printf			! make a function call
	nop

	ret				! return from subroutine
	restore				! restore caller's window

NULL:
	set	strGid, %o0		! format of gid
	mov	%l0, %o1		! put a copy of gid into parameter
	call	printf			! make a function call
	nop

	ret				! return from subroutine
	restore				! restore caller's window

