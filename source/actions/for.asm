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
;								Handle For
;
; ******************************************************************************

Action_AFor:
		jsr 	StackPushPC 					; push loop position on stack
		lda 	#CPU_PHA 						; push index on stack
		jsr 	CodeWriteByte
		lda 	#CPU_DECA 						; counts backwards from n-1 to 0.
		jsr 	CodeWriteByte
		lda 	#SCM_FOR 						; put a for marker on the stack.
		jsr 	StackPush
		rts
		
; ******************************************************************************
;
;								  Handle Next
;
; ******************************************************************************

Action_Next:
		lda 	#SCM_FOR 					; check corresponding for
		jsr 	StackCheckStructureMarker
		lda 	#CPU_PLA 					; pop index off stack and decrement
		jsr 	CodeWriteByte
		lda 	#CPU_DECA 		
		jsr 	CodeWriteByte

		lda 	#CPU_BNE 					; branch back if #0
		ldy 	#1 							; stack at 1 (High) 2 (Low)
		jsr 	StackCompileBranch 			; compile a branch.
		lda 	#1+3 						; remove from stack.
		jsr 	StackPopStack
		rts
