/*
 * Filename: nops.s
 * Author: Xiaolong Zhou
 * Userid: cs30xaeo
 * Description: PA1 Extra Credit. SPARC assembly code to be optimized by
 *              eliminating nops with existing useful instructions.
 * Date: April 17, 2016
 * Sources of Help: handout from lecture
 */


	.section	".rodata"
strfmt:
	.asciz  "%4d: %d\n"


	.global	nops
	.section	".text"		! text section start here
nops:
	save	%sp, -96, %sp

	mov	%i0, %l0	! num
	clr	%l1		! sum
	mov	%l1, %l2	! i

	cmp	%l2, %l0
	bge	endloop		! opposite logic
	mov	%l1, %i0	! optimized delay slot

startloop:

	
	call	isEven
	mov	%l2, %o0	! optimized delay slot

	cmp	%o0, %g0
	be,a	isEvenElse	! opposite logic
	mov	%l1, %o0	!optimized delay slot

	add	%l1, %l2, %l1
	ba	isEvenEnd
	inc	%l2		! optimized delay slot

	mov	%l1, %o0	! make a copy of instruction

isEvenElse:
		
	call	.mul
	mov	%l2, %o1

	mov	%o0, %l1
	sra	%l1, 1, %l1

	inc	%l2		! make a copy of instruction
isEvenEnd:

	set	strfmt, %o0
	mov	%l2, %o1
	mov	%l1, %o2
	call	printf
	mov	%l2, %o1	! optimized delay slot

	cmp	%l2, %l0
	bl	startloop
	nop			! DO NOT FILL/REMOVE THIS NOP

	mov	%l1, %i0	! last inst
endloop:

	ret
	restore

