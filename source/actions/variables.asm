; ******************************************************************************
; ******************************************************************************
;
;		Name : 		variables.asm
;		Purpose : 	Byte/Word definitions
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;							Reset variable memory
;
; ******************************************************************************

VariableReset:
		set16	varPtr,VariableMemory
		rts

; ******************************************************************************
;
;							Define a byte/variable
;
; ******************************************************************************

Action_ByteVar:
		lda 	#1
		bra 	VariableDeclare
Action_WordVar:
		lda 	#2
VariableDeclare:
		sta 	varSize 					; save variable size.
		;
		;		Variable declaration loop
		;
_VDLoop:
		lda 	#"B"						; get W or B
		ldx 	varSize
		dex
		beq 	_VDNotWord
		lda 	#"W"
_VDNotWord:
		pha
		jsr 	EGetUnknownIdentifier 		; get an unknown identifier.
		pla
		jsr 	DictionaryCreate 			; create procedure dictionary entries
		jsr 	EGLookNext 					; what's next ?
		cmp 	#'@'|$80 					; if not @, use default
		bne 	_VDDefault
		;
		;		Variable followed by @<constant> specifies address.
		;
		jsr 	EGSkipNext 					; skip @
		jsr 	EGLookNext 					; get next
		cmp 	#'b'|$80 					; must be b/w constant
		beq 	_VDLegit
		cmp 	#'w'|$80
		bne 	_VDError
_VDLegit:
		lda 	genPos 						; position
		jsr 	GenCopyData					; access data
		lda 	#0 		 					; set the address
		ldx 	elementData
		ldy 	elementData+1
		jsr 	DictionarySet
		jsr 	EGSkipNext 					; consume the constant
		bra 	_VDTryNext
		;
		;		Default variable - allocated current variable pointer
		;
_VDDefault:		
		ldx 	varPtr 						; place at default position
		ldy 	varPtr+1
		lda 	#0
		jsr 	DictionarySet

		lda 	varSize 					; get count of bytes back
		clc
		adc 	varPtr
		sta 	varPtr
		bcc 	_VDNoCarry
		inc 	varPtr+1
_VDNoCarry:
		;
		;		See if , follows, if so consume and loop
		;
_VDTryNext:		
		jsr 	EGLookNext 					; what's next ?
		cmp 	#","|$80 					; is it a comma
		bne 	_VDExit 					; no, exit.
		jsr 	EGSkipNext
		bra 	_VDLoop
_VDExit:		
		rts

_VDError:
		derror 	"ADDRESS?"
		