; ******************************************************************************
; ******************************************************************************
;
;		Name : 		repeat.asm
;		Purpose : 	Repeat Until
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;								Handle Repeat
;
; ******************************************************************************

Action_Repeat:
		jsr 	StackPushPC 					; push loop position on stack
		lda 	#SCM_REPEAT 					; put a repeat marker on the stack.
		jsr 	StackPush
		rts

		
; ******************************************************************************
;
;								  Handle Until
;
; ******************************************************************************

Action_Until:
		lda 	#SCM_REPEAT 				; check corresponding repeat
		jsr 	StackCheckStructureMarker
		lda 	generateVar 				; branch to use.
		eor 	#$20 						; this makes it negative, e.g. branch if false
		ldy 	#1 							; stack at 1 (High) 2 (Low)
		jsr 	StackCompileBranch 			; compile a branch.
		lda 	#1+3 						; remove from stack.
		jsr 	StackPopStack
		rts
