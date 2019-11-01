; ******************************************************************************
; ******************************************************************************
;
;		Name : 		banking.asm
;		Purpose : 	Banked code
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	1st November 2019
;
; ******************************************************************************
; ******************************************************************************

BANKEDStart:

CodeWriteByte = BankCode

		bra 	BankedCodeWriteByte

; ******************************************************************************
;
;							Write a byte to code space
;
; ******************************************************************************

BankedCodeWriteByte:
		phx 								; save XY
		phy		
		ldx 	ramBank  					; save old RAM Bank# in X
		ldy 	codeBank 					; get code RAM bank and save code there.
		sty 	ramBank
		sta 	(codePtr) 					; save byte out
		inc 	codePtr 					; bump pointer
		bne 	_CWBNoCarry
		inc 	codePtr+1
_CWBNoCarry:
		stx 	ramBank 					; restore page
		ply 								; and exit.
		plx
		rts

BANKEDEnd:

; ******************************************************************************
;
;						   Copy Banked Code to Code Space
;
; ******************************************************************************

BankCopyCode:
		pha
		phx
		ldx 	#BANKEDEnd-BANKEDStart
_BCCCopy:		
		lda 	BANKEDStart,x
		sta 	BankCode,x
		dex
		cpx 	#$FF
		bne 	_BCCCopy
		plx
		pla
		rts
