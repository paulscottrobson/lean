; ******************************************************************************
; ******************************************************************************
;
;		Name : 		procedure.asm
;		Purpose : 	Proc/EndProc Actions
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************
		
; ******************************************************************************
;
;								Handle Procedures
;
; ******************************************************************************

Action_Procedure_Def:
		jsr 	EGetUnknownIdentifier 		; get an unknown identifier.
		lda 	#"P"
		jsr 	DictionaryCreate 			; create procedure dictionary entries
		lda 	codeBank 					; and assign it the current PC value.
		ldx 	codePtr
		ldy 	codePtr+1
		stx 	lastDefine 					; update last defined
		sty 	lastDefine+1
		jsr 	DictionarySet 				; set the dictionary values.

		lda 	#"("
		jsr 	EGetSyntaxCheck
		lda 	#")"
		jsr 	EGetSyntaxCheck
		
		lda 	#SCM_PROC 					; put a procedure marker on the stack.
		jsr 	StackPush
		rts

_APError:
		derror 	"PROCDEF"
		
; ******************************************************************************
;
;								  Handle ENDPROC
;
; ******************************************************************************

Action_EndProc:
		lda 	#SCM_PROC 					; check corresponding PROC
		jsr 	StackCheckStructureMarker
		lda 	#CPU_RETURN					; write out RTS
		jsr 	CodeWriteByte
		lda 	#1 							; remove from stack.
		jsr 	StackPopStack
		rts
