; ******************************************************************************
; ******************************************************************************
;
;		Name : 		scanner.asm
;		Purpose : 	Search through BASIC code for curt code
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;								Reset the scanner
;
; ******************************************************************************

ScannerReset:	
		stz 	scanPtr+1 					; zero MSB means the start
		rts

; ******************************************************************************
;
;		Advance scanner pointer to next Brief code. CS if found,
;		CC if end of BASIC scan. scanPtr points to start of current line
; 		e.g. +0,1 offset +2,3 line# +4 REM +5 .
;
; ******************************************************************************

ScannerFind:
		pha 								; save registers
		phx
		phy
		lda 	scanPtr+1 					; reset the scanner pointer ?
		bne 	_SFScanForward 				; no, scan forward from current.
		set16 	scanPtr,ProgramStart 		; reset scan pointer
		bra 	_SFCheck 					; check if this one is a REM.
		;
		;		Move forward to next
		;
_SFScanForward:
		ldy 	#1 							; check if the offset is zero
		lda 	(scanPtr)		
		ora 	(scanPtr),y
		clc 								; if so exit with CC.
		beq 	_SFExit
		;
		lda 	(scanPtr) 					; forward to next.
		tax
		lda 	(scanPtr),y
		stx 	scanPtr
		sta 	scanPtr+1
		;
		;		Check current line is REM. , and save line number.
		;
_SFCheck:		
		ldy 	#2 								; copy line number.
		lda 	(scanPtr),y
		sta 	lineNumber
		iny
		lda 	(scanPtr),y
		sta 	lineNumber+1
		iny
		;									; read first character of BASIC program
		lda 	(scanPtr),y 				; is it a "REM." line ?
		cmp 	#REM_TOKEN
		bne 	_SFScanForward
		iny
		lda 	(scanPtr),y 				; is it followed by a '.'
		iny
		cmp 	#"."
		bne 	_SFScanForward
		sec 								; found something, exit with CS.
_SFExit:
		ply 								; load registers and exit.
		plx
		pla
		rts
