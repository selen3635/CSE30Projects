/*
 * Filename: isort.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: PA2 Extra Credit. SPARC assembly code to be optimized by
 *              eliminating nops with existing useful instructions.
 *              Performs an insertion sort.
 *              Returns the difference between the largest and smallest
 *              values.
 * Date:   May 1, 2016
 * Sources of Help: write up
 */

	.global isort

	.section	".text"

isort:
	save	%sp, -96, %sp

	mov	1, %l0

	cmp	%l0, %i1
	bge,a	end
	add	%i1, -1, %l0		!FIRST

	mov	%l0, %l1
loop:

	cmp	%l1, %g0
	ble,a	end_inner
	inc	%l0			!second

	sll	%l1, 2, %l2
start_inner:

	add	%i0, %l2, %l2
	ld	[%l2], %l3
	ld	[%l2 - 4], %l4

	cmp	%l3, %l4
	bge,a	end_inner
	inc	%l0			!Third

	st	%l4, [%l2]
	st	%l3, [%l2 - 4]

	add	%l1, -1, %l1

	cmp	%l1, %g0
	bg,a	start_inner
	sll	%l1, 2, %l2		!fourth

	inc	%l0

end_inner:

	cmp	%l0, %i1
	bl,a	loop
	mov	%l0, %l1		!fifth

	add	%i1, -1, %l0
end:

	add	%i1, -1, %l0

	mov	4, %o1
	call	.mul
	mov	%l0, %o0		!sixth

	add	%i0, %o0, %l0
	ld	[%l0], %l0

	ld	[%i0], %i0
	sub	%l0, %i0, %i0

	ret
	restore

