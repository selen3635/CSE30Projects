/**
 * Filename: drawS.s
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: This function is the main driver of the program. It will
 *              provide all of the functionality for printing the 'S'
 *              character.
 * Date:  April 14, 2016
 * Source of Help: handout from lecture, cs30 webpage, tutors
 */

	.global drawS		! Declares the symbol to be globally visible

	MYBASE = 10		! Constant variable base
	THREE = 3		! Constant variable
	TWO = 2			! Constant variable
	TEN = 10		! Constant variable

	.section ".text"	! The text segment begins here

/*
 * Function name: drawS()
 * Function prototype: void drawS( long sWidth, long sChar, long fillerChar,
 * 			long borderChar);
 * Description: draw a character S by using argument entered by user.
 * Parameters:
 * 	arg1: long sWidth -- width of character S
 * 	arg2: long sChar -- The character that we going to draw
 * 	arg3: long fillerChar -- characters use to fill space beside of S
 * 	arg4: long borderChar -- characters use to build up border
 * Side Effects: print S on the teminal
 * Error Conditions: 
 * 	errno is set when parsing the argv values.
 * 	endptr points to a character other than the null character
 * 	sWidth is even or out of range
 * 	sChar, fillerChar, or borderChar are out of range
 * 	sChar is the same as fillerChar or borderChar
 * Return Value: None.
 * Registers Used:
 * 	%i0 - param 1 -- first parameter for the function
 * 	%i1 - param 2 -- second parameter for the function
 * 	$i2 - param 3 -- third parameter for the function
 * 	%i3 - param 4 -- fourth parameter for the function
 * 	%o0 - arg 1 -- first argument when call a function
 * 	%o1 - arg 2 -- second argument when call a funtion
 * 	%l0 - local register 1 -- represent line
 * 	%l1 - local register 2 -- represent section
 * 	%l3 - local register 3 -- represent borderWidth
 * 	%l4 - local register 4 -- represent addition
 * 	%l5 - local register 5 -- represent subtraction
 */

drawS:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated


	mov	%i0, %o0	! Put a copy of base to register
	mov	MYBASE, %o1	! Put a copy of parameter in the register
	call	numOfDigits	! Make function call
	nop

	clr	%l3
	mov	%o0, %l3	! map returned value to %l3 ( borderWidth)

	clr	%l0		! represent local variable line 
	cmp	%l0, %l3	! compare line with borderWidth
	bge	end_top_borLoop	! opposite logic test to skip over body loop
	nop

top_borLoop:
	
	mov	%l3, %o0	! Put a copy of borderWidth in the register
	mov	TWO, %o1	! Put a copy of 2 in the register
	call	.mul		! Make function call
	nop

	add	%o0, %i0, %l4	! Addition of sWidth and 2 times borderWidth

	mov	%i3, %o0	! Put a copy of borderChar in the register
	mov	%l4, %o1	! Put a copy of parameter in the register
	call	printSegment	! Make a function call
	nop

	mov	TEN, %o0	! Put a copy of 10 in the register
	call	printChar	! Make function call
	nop

	inc	%l0		! increment line

	cmp	%l0, %l3	! compare line with borderWidth
	bl	top_borLoop	! continue top_borLoop
	nop			! Delay slot

end_top_borLoop:

	clr	%l1		! represent local variable section 
	cmp	%l1, THREE	! condition for outer loop
	bge	end_outerLoop	! opposite logic test to skip over body loop
	nop			! delay slot

outerLoop:
	
	mov	%i3, %o0	! Put a copy of borderChar in the register
	mov	%l3, %o1	! Put a copy of borderWith in the register
	call	printSegment	! Make function call
	nop

	mov	%i2, %o0	! Put a copy of fillerChar in the register
	call	printChar	! Make function call
	nop

	sub	%i0, TWO, %l5	! subtract sWidth by 2 
	mov	%i1, %o0	! Put a copy of sChar in the register
	mov	%l5, %o1	! Put a copy of parameter in the register
	call	printSegment	! Make function call
	nop

	mov	%i2, %o0	! Put a copy of fillerChar in the register
	call	printChar	! Make function call
	nop

	mov	%i3, %o0	! Put a copy of borderChar in the register
	mov	%l3, %o1	! Put a copy of borderWidth in the register
	call	printSegment	! Make function call
	nop

	mov	TEN, %o0	! Put a copy of 10 in the register
	call	printChar	! Make function call
	nop

	cmp	%l1, TWO	! compare section with 2
	bne	innerStart	! if not equal, check inner loop condition
	nop

	ba	end_outerLoop	! break loop
	nop

innerStart:

	clr	%l0		! clear local register
	cmp	%l0, %l5	! compare line with (sWidth - 2)
	bge	end_innerLoop	! opposite logic test
	nop

innerLoop:
	
	inc	%l0		! increment line  
	mov	%i3, %o0	! Put a copy of borderChar in the register
	mov	%l3, %o1	! Put a copy of borderWidth in the register
	call	printSegment	! Make function call
	nop

	cmp	%l1, 0		! compare section with 0
	bne	else1		! if not equal call branch else1
	nop
	
	mov	%i1, %o0	! Put a copy of sChar in the register
	call	printChar	! Make function call
	nop

        ba	continue	! continue inner loop
	nop

else1:
	mov	%i2, %o0	! Put a copy of fillerChar in the register
	call	printChar	! Make function call
	nop

continue:
	mov	%i2, %o0	! Put a copy of fillerChar in the register
	mov	%l5, %o1	! Put a copy of (sWidth -2) in the register
	call	printSegment	! Make function call
	nop

	cmp	%l1, 0		! compare section with 0
	bne	else2		! if not equal call branch else2
	nop

	mov	%i2, %o0	! Put a copy of fillerChar in the register
	call	printChar	! Make function call
	nop

	ba	continue2	! continue rest of loop
	nop

else2:
	mov	%i1, %o0	! Put a copy of sChar in the register
	call	printChar	! Make function call
	nop

continue2:

	mov	%i3, %o0	! Put a copy of borderChar in the register
	mov	%l3, %o1	! Put borderWidther in the register
	call	printSegment	! Make function call
	nop

	mov	TEN, %o0	! Put 10 to register
	call	printChar	! Make function call
	nop

	cmp	%l0, %l5	! compare line with number 3
	bl	innerLoop	! keep inner loop
	nop

end_innerLoop:

	inc	%l1		! increment section
	cmp	%l1, THREE	! compare section with 3
	bl	outerLoop	! keep outerLoop
	nop

end_outerLoop:

	clr	%l0		! clear local variable
	
	cmp	%l0, %l3	! compare line with borderWidth
	bge	end_bottomLoop	! if greater or equal then end loop
	nop

bottomLoop:
	mov	%i3, %o0	! Put a copy of borderChar in the register
	mov	%l4, %o1	! Put a copy of parameter in the register
	call	printSegment	! Make function call
	nop

	mov	TEN, %o0	! Put a copy of 10 in the register
	call	printChar	! Make function call
	nop

	inc	%l0		! increment variable line

	cmp	%l0, %l3	! compare line with borderWidth
	bl	bottomLoop	! keep loop
	nop

end_bottomLoop:

	ret			! No return value
	restore			! Restore caller's window;
	
