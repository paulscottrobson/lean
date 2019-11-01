; ******************************************************************************
; ******************************************************************************
;
;		Name : 		for.asm
;		Purpose : 	For/Next
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;							 Handle For (A version)
;
; ******************************************************************************

Action_AFor:
		jsr 	StackPushPC 					; push loop position on stack
		lda 	#CPU_DECA 						; counts backwards from n-1 to 0.
		jsr 	CodeWriteByte
		lda 	#CPU_PHA 						; push index on stack
		jsr 	CodeWriteByte
		lda 	#SCM_FOR 						; put a for marker on the stack.
		jsr 	StackPush
		rts
		
; ******************************************************************************
;
;							 Handle For (R version)
;
; ******************************************************************************

Action_RFor:
		jsr 	StackPushPC 					; push loop position on stack
		;
		lda 	#CPU_CMPIM 						; dec XA code cmp #0
		jsr 	CodeWriteByte
		lda 	#0
		jsr 	CodeWriteByte
		lda 	#CPU_BNE 						; bne +1
		jsr 	CodeWriteByte
		lda 	#1
		jsr 	CodeWriteByte
		lda 	#CPU_DEX 						; dex
		jsr 	CodeWriteByte
		lda 	#CPU_DECA 						; dec a
		jsr 	CodeWriteByte
		lda 	#CPU_PHA 						; push index on stack
		jsr 	CodeWriteByte
		lda 	#CPU_PHX
		jsr 	CodeWriteByte
		;
		lda 	#SCM_INTFOR 					; put a for marker on the stack.
		jsr 	StackPush
		rts

; ******************************************************************************
;
;								  Handle Next
;
; ******************************************************************************

Action_Next:
		lda 	(aStackPtr) 				; check for R-Next
		cmp 	#SCM_INTFOR
		beq 	_AN16Bit
		;
		;		A.For version of Next.
		;
		lda 	#SCM_FOR 					; check corresponding for
		jsr 	StackCheckStructureMarker
		lda 	#CPU_PLA 					; pop index off stack.
		jsr 	CodeWriteByte
		lda 	#CPU_BNE 					; branch back if #0
		ldy 	#1 							; stack at 1 (High) 2 (Low)
		jsr 	StackCompileBranch 			; compile a branch.
		lda 	#1+3 						; remove from stack.
		jsr 	StackPopStack
		rts
		;
		;		R.For version of Next.
		;
_AN16Bit:
		lda 	#CPU_PLX 					; pop index on stack
		jsr 	CodeWriteByte
		lda 	#CPU_PLA 				
		jsr 	CodeWriteByte
		lda 	#CPU_BNE
		ldy 	#1 							; stack at 1 (High) 2 (Low)
		jsr 	StackCompileBranch 			; compile a branch (check LSB)
		lda 	#CPU_CPXIM  				; check MSB of index
		jsr 	CodeWriteByte
		lda 	#0
		jsr 	CodeWriteByte
		lda 	#CPU_BNE
		ldy 	#1 					
		jsr 	StackCompileBranch 
		lda 	#1+3 						; remove from stack.
		jsr 	StackPopStack
		rts
