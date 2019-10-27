; ******************************************************************************
; ******************************************************************************
;
;		Name : 		astack.asm
;		Purpose : 	Utility routines for compiler stack
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;							Reset the compiler stack
;
; ******************************************************************************

StackReset:
		set16 	aStackPtr,assemblerStack
		lda 	#SCM_TOP
		sta 	(aStackPtr)
		rts

; ******************************************************************************
;
;					Push current compile code PC on the stack
;
; ******************************************************************************

StackPushPC:
		lda 	codeBank
		jsr 	StackPush
		lda 	codePtr
		jsr 	StackPush
		lda 	codePtr+1
		jsr 	StackPush
		rts

; ******************************************************************************
;
;							Push A on the return stack
;
; ******************************************************************************

StackPush:
		dec 	aStackPtr 					; decrement TOS pointer.
		beq 	_SPStack
		sta 	(aStackPtr)					; write to new TOS
		rts
_SPStack:
		derror	"RETURN STACK"

; ******************************************************************************
;
;							Check top of stack = A
;
; ******************************************************************************

StackCheckStructureMarker:
		cmp 	(aStackPtr)					; check if tos matches
		bne 	_SCSError
		rts
_SCSError:
		derror 	"STRUCTURES"

; ******************************************************************************
;
;			 Compile <opcode>A to address (aStack),y as a 6502 Branch
;
; ******************************************************************************

StackCompileBranch:
		pha
		phx
		phy
		jsr 	CodeWriteByte 				; write the opcode.
		;
		iny
		lda 	(aStackPtr),y
		tax
		dey
		lda 	(aStackPtr),y
		tay
		jsr 	CodeWriteBranch 			; write a branch there.
		ply
		plx
		pla
		rts

; ******************************************************************************
;
;						Pop A bytes off Return Stack
;
; ******************************************************************************

StackPopStack:
		clc 								; return stack all in same page
		adc 	aStackPtr 					; so we don't carry out.
		sta 	aStackPtr
		rts

