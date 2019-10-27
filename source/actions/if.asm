; ******************************************************************************
; ******************************************************************************
;
;		Name : 		if.asm
;		Purpose : 	If/Else/Endif
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;									Handle IF
;	
; ******************************************************************************

Action_If:
		lda 	generateVar 				; branch to use.
		eor 	#$20 						; this makes it negative, e.g. branch if false
		jsr 	CodeWriteByte 				; output it
		jsr 	StackPushPC 				; push branch position on stack
		lda 	#$FF 						; dummy branch
		jsr 	CodeWriteByte
		lda 	#SCM_IF 					; put if marker on the stack.
		jsr 	StackPush
		rts

; ******************************************************************************
;
;									Handle ELSE
;	
; ******************************************************************************

Action_Else:
		lda 	#SCM_IF 					; check in IF
		jsr 	StackCheckStructureMarker
		lda 	#CPU_BRA 					; compile branch
		jsr 	CodeWriteByte
		;
		lda 	codePtr 					; push current position on the stack
		pha
		lda 	codePtr+1
		pha
		;
		lda 	#$FF 						; dummy branch
		jsr 	CodeWriteByte
		jsr 	BackPatchIf 				; do the backpatch.
		;
		pla 								; overwrite backpatch address
		ldy 	#1 							; with stacked position.
		sta 	(aStackPtr),y
		pla
		iny
		sta 	(aStackPtr),y
		rts

; ******************************************************************************
;
;									Handle ENDIF
;	
; ******************************************************************************

Action_Endif:
		lda 	#SCM_IF 					; check in IF
		jsr 	StackCheckStructureMarker
		jsr 	BackPatchIf 				; do the backpatch.
		lda 	#3+1 						; throw the stack.
		jsr 	StackPopStack
		rts

; ******************************************************************************
;
;		Patch the stacked address to point to current Code pointer
;
; ******************************************************************************

BackPatchIf:
			lda 	codePtr 					; save code pointer
		pha
		lda 	codePtr+1
		pha
		;
		ldy 	#3 							; AYX = address.
		lda 	(aStackPtr),y
		pha
		dey
		lda 	(aStackPtr),y
		tax
		dey
		lda 	(aStackPtr),y
		tay
		pla
		;
		jsr 	CodeSetPointer 				; set write position to that
		;
		ply 								; target address in YX
		plx
		jsr 	CodeWriteBranch 			; write the actual branch there
		jsr 	CodeRestorePointer 			; undo the set pointer.
		rts
