; ******************************************************************************
; ******************************************************************************
;
;		Name : 		call.asm
;		Purpose : 	Procedure call.
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	28th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;								Call a procedure
;
; ******************************************************************************

Action_Call:
		;
		;		Save position of the procedure and check for (, then )
		;
		lda 	genPos 						; get position
		dec 	a 							; point to the <proc>
		pha 								; save it
		lda 	#'('						; check (
		jsr 	EGetSyntaxCheck
		;
		jsr 	EGLookNext 					; ) next ?
		cmp 	#')'+$80
		beq 	_ACNoParameters
		;
		;		Do Parameters
		;
		lda 	#"R" 	 					; do R=<something>
		jsr 	ACDoParameter 				; do the parameter.
		jsr 	EGSkipNext 					; skip the parameter
		;
		jsr 	EGLookNext 					; what follows 
		cmp 	#","+$80 					; if not comma
		bne 	_ACNoParameters 			; should be end of parameters
		jsr 	EGSkipNext 					; skip ,
		;
		lda 	#"Y"						; do Y=<something>			
		jsr 	ACDoParameter 				; do the parameter.
		jsr 	EGSkipNext 					; skip parameter.
		;
		;		End of Parameters. Compile call to routine
		;
_ACNoParameters:
		lda 	#')' 						; check closing bracket.
		jsr 	EGetSyntaxCheck
		;
		pla 								; restore procedure posiion.
		jsr 	GenCopyData					; get the data
		lda 	#CPU_JSR					; output a call to it.
		jsr 	CodeWriteByte 				
		lda 	elementData
		jsr 	CodeWriteByte 				
		lda 	elementData+1				
		jsr 	CodeWriteByte 				
		rts

; ******************************************************************************
;
;		Parameter. Check current buffer is a substition (e.g. lower case)
;		if so, place Y= or R= before it, then assemble that using the
;		generation code.
;
; ******************************************************************************

ACDoParameter:
		ldx 	genPos 						; save position
		phx 	
		;
		pha 								; save the target register		
		lda 	lineBuffer,x 				; what is there ?
		cmp 	#"a"+$80 					; check a-z
		bcc 	_ADPError
		cmp 	#"z"+$81
		bcs 	_ADPError
		dex 								; write = before it				
		lda 	#"="+$80
		sta 	lineBuffer,x
		dex
		pla 								; write Y/R before that
		ora 	#$80
		sta 	lineBuffer,x
		stx 	genPos 						; make genPos point to that.
		jsr 	GenerateOne 				; generate that.

		pla 								; restore position
		sta 	genPos
		rts
_ADPError:
		derror 	"PARAMETER?"