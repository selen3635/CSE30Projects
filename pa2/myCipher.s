/*
 * Filename: myCipher.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function is responsible for the encrption/decryptoin
 * 		of the user input using the 64-bit crypto mask created
 * 		from the command line arguments.
 * Date: April 28, 2016
 * Source of Help: wite up
 */

	.global myCipher		! Declares the symbol to be globally

	BUFSIZ = 1024			! constant
	OFFSET = 4			! constant
	OFFSET2 = 8

	.section ".text"		! The text segment begins here

/*
 * Function name: myCipher
 * Function prototype:
 * 	void myCipher( FILE * inFile, unsigned long mask[], long rotateValue);
 * Description: This function is respoinsible for the encription/decryption.
 * Parameters:
 * 	arg1: File *inFile -- a file to read
 * 	arg2: unsigned long mask[] -- a crypto mask
 * 	arg3: long rotateValue -- rotate value
 * Side Effects: None.
 * Error Condition: None.
 * Return Value: None.
 * Register Userd:
 * 	%o0 - arg1 -- first argument for the function
 * 	%o1 - arg2 -- second argument for the function
 * 	%o2 - arg3 -- third argument for the function
 * 	%o3 - arg3 -- fourth argument for the function
 * 	%l0 - local register store %fp - BUFSIZ 
 * 	%l1 - local register
 * 	%l2 - local register
 * 	%l3 - local register
 * 	%l4 - local register
 * 	%l5 - local register
 * 	%l6 - local register
 * 	%l7 - local register
 * 	%i0 - param 1 -- first parameter pass in function
 * 	%i1 - param 1 -- second paramter passin function
 *
 */
myCipher:

	save	%sp, -( 92 + BUFSIZ ) & -8, %sp		
						! Save caller's window

OuterLoop:

	clr	%l5
	sub	%fp, BUFSIZ, %l0		! allocate space for local var
	mov	%l0, %o0			! pass it as first arg
	mov	1, %o1				! each size of element
	mov	BUFSIZ, %o2			! number of element
	mov	%i0, %o3			! pointer to a file
	call	fread				! Make a function call
	nop

	mov	%o0, %l2
	cmp	0, %l2				! compare 0 with returned val
	be	End_Loop			! if return 0, end
	nop

	mov	%l2, %l6

	cmp	%l2, OFFSET2			! compare 8 with returned val
	bl	LessEightStart			! loop with less eight byte
	nop

InnerStart:
	clr	%l1
	clr	%l5

InnerLoop:
	
	mov	%i1, %o0			! move  mask to arg 1
	mov	%i2, %o1			! move rotate value to arg 2
	call	rotate				! Make a function call
	nop

	mov	%l1, %o0			! move counter to first arg
	mov	OFFSET, %o1			! move 4 to second arg
	call	.mul				! call multipily
	nop

	mov	%o0, %l7			! save result to local
	add	%l0, %l7, %l7
	ld	[%l7], %l3			! load first 4 byte
	ld	[%i1], %l4			! load first 4 byte of mask
	xor	%l3, %l4, %l4			! xor them stroe to %l4
	st	%l4, [%l7]			! store back to memory

	add	%l7, OFFSET, %l7	
	ld	[%l7], %l3			! load second 4 byte
	ld	[%i1 + OFFSET], %l4		! load second 4 byte of mask
	xor	%l3, %l4, %l4			! xor them store to %l6
	st	%l4, [%l7]			! store back to memory


	inc	%l1				! increment counter
	inc	%l1
	inc	%l5				! increment loop time
	sub	%l2, OFFSET2, %l2		! decrese %l2 with 8

	cmp	%l2, OFFSET2			! compare %l2 with 8
	bge	InnerLoop			! keep inner loop
	nop

	cmp	%l2, 0				! compare %l2 with 0
	be	End_Inner			! end inner loop
	nop

LessEightStart:

	clr	%l7
	mov	%i1, %o0			! move  mask to arg 1
	mov	%i2, %o1			! move rotate value to arg 2
	call	rotate				! Make a function call
	nop

	mov	%l5, %o0			! move loop time to arg 1
	mov	OFFSET2, %o1
	call	.mul				! Make a function call
	nop

	mov	%o0, %l5			! save result to %l5

LessEightByte:

	add	%l0, %l5, %l3			! get address loc
	ldub	[%l3], %l3			! load 1 character
	ldub	[%i1 + %l7], %l1		! load first character mask
	xor	%l3, %l1, %l4			! xor one byte
	add	%l0, %l5, %l3
	stb	%l4,[%l3]			! store back to memory

	inc	%l7				! increse counter
	inc	%l5				! go to next address of char
	dec	%l2				! decrese %l2

	cmp	%l2, 0				! compare %l2 with 0
	bg	LessEightByte			! keep loop
	nop

End_Inner:

	mov	%l0, %o0			! move buffer to arg1
	mov	1, %o1				! move 1 to arg2
	mov	%l6, %o2			! move BUFSIZ to arg3
	set	standardOut, %o3		
	ld	[%o3], %o3			! load it to arg4
	call	fwrite				! make a function call
	nop

	ba	OuterLoop			! check outer loop
	nop

End_Loop:
	ret					! return from subroutine
	restore					! restore caller's window
