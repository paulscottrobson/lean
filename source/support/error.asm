; ******************************************************************************
; ******************************************************************************
;
;		Name : 		error.asm
;		Purpose : 	Error Handler.
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

SyntaxError:		
		derror 	"SYNTAX"

; ******************************************************************************
;
;								Handle Errors
;
; ******************************************************************************

ErrorHandler:
		plx 								; pull address off.
		ply		
		inx 								; point to message
		bne 	_EHNoCarry
		iny
_EHNoCarry:		
		jsr 	PrintStringXY 				; print string at XY
		ldx 	#_EHMessage & $FF 			; print " AT "
		ldy 	#_EHMessage >> 8
		jsr 	PrintStringXY
		ldx 	lineNumber 					; convert line number
		ldy 	lineNumber+1
		jsr 	IntToString
		ldx 	#lineBuffer & $FF 			; print number
		ldy 	#lineBuffer >> 8
		jsr 	PrintStringXY
		stz 	lastDefine 					; disable running by zeroing last defined
		stz 	lastDefine+1
		ldx 	#_EHMessage2 & $FF 			; print " AT "
		ldy 	#_EHMessage2 >> 8
		jsr 	PrintStringXY		
		jmp 	ReturnCaller 				; exit the compiler.

_EHMessage:
		.text	" AT ",0
_EHMessage2:
		.text 	13,"    LEAN V0.1 (27-OCT-19)",0

; ******************************************************************************
;
;							Print String at (Y,X)
;
; ******************************************************************************

PrintStringXY:
		stx 	zTemp0
		sty 	zTemp0+1
		ldy 	#0
_PSLoop:lda 	(zTemp0),y
		beq 	_PSExit
		jsr 	PrintCharacter
		iny
		bra 	_PSLoop
_PSExit:rts

; ******************************************************************************
;
;							Print Character in A
;
; ******************************************************************************

PrintCharacter:
		pha
		phx
		phy
		jsr 	$FFD2
		ply
		plx
		pla
		rts
		