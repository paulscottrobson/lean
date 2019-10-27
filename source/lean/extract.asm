; ******************************************************************************
; ******************************************************************************
;
;		Name : 		extract.asm
;		Purpose : 	Extract elements from the translated buffer
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;						Extract a following identifier -> YX
;
; ******************************************************************************

EGetUnknownIdentifier:
		ldx 	genPos 						; get next character
		lda 	lineBuffer,x
		and 	#$7F
		jsr 	PLTCheckCharacter 			; is it an identifier ?
		bcc 	_EUIError 					; no
		;
		phx 								; save start position on stack.
_EGetFindEnd: 								; skip past the identifier end
		lda 	lineBuffer,x
		inx
		asl 	a
		bcc 	_EGetFindEnd
		stx 	genPos 						; points to the next thing.
		;
		pla 								; offset
		ldy 	#lineBuffer >> 8 			; make address in YX
		clc
		adc 	#lineBuffer & $FF
		tax
		bcc 	_EGetNoCarry
		iny
_EGetNoCarry:
		rts

_EUIError:
		derror 	"IDENTIFIER ?"

; ******************************************************************************
;
;							Check the next character is A
;
; ******************************************************************************

EGetSyntaxCheck:
		pha
		phx
		ldx 	genPos 						; position of next
		eor 	lineBuffer,x 				; bits 0-6 will be zero if match
		and 	#$7F
		bne 	_EGSFail 					; different
		inc 	genPos 						; skip it and exit
		plx
		pla
		rts
_EGSFail:
		derror	"MISSING ?"

; ******************************************************************************
;
;					Get next character or whatever into A
;
; ******************************************************************************

EGLookNext:
		phx
		ldx 	genPos 						; position of next
		lda 	lineBuffer,x
		plx
		rts

; ******************************************************************************
;
;						 Skip over next character
;
; ******************************************************************************

EGSkipNext:
		inc 	genPos
		rts
		