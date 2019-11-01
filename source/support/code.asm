; ******************************************************************************
; ******************************************************************************
;
;		Name : 		code.asm
;		Purpose : 	Code Write Functions
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;								Reset Code Pointer
;
; ******************************************************************************

CodeReset:
		ldx 	#CodeMemory & 255
		ldy 	#CodeMemory >> 8
		lda 	#CodePage
		bra 	CodeSetPointer

; ******************************************************************************
;
;						Set code Pointer to A (Bank) YX
;
; ******************************************************************************

CodeSetPointer:
		pha 								; copy old to backup
		lda 	codePtr
		sta 	codeBackup
		lda 	codePtr+1
		sta 	codeBackup+1
		lda 	codeBank
		sta 	codeBackup+2
		pla
		sta 	codeBank 					; update
		stx 	codePtr
		sty 	codePtr+1
		rts

; ******************************************************************************
;
;						Restore backed up code pointer
;
; ******************************************************************************

CodeRestorePointer:
		lda 	codeBackup
		sta 	codePtr
		lda 	codeBackup+1
		sta 	codePtr+1
		lda 	codeBackup+2
		sta 	codeBank
		rts


; ******************************************************************************
;
;					Write at codePtr a branch offset to YX
;
; ******************************************************************************

CodeWriteBranch:
		clc 								; borrow 1 as branch is from one on
		txa
		sbc 	codePtr		
		jsr 	CodeWriteByte 				; compile anyway.
		tax 								; actual result in X.
		tya
		sbc 	codePtr+1		
		;
		beq 	_CWBCheckPositive 			; 00xx
		cmp 	#$FF
		beq 	_CWBCheckNegative 			; FFxx
_CWBError:		
		derror 	"BRANCH?"					; too far.
		;
_CWBCheckPositive: 							; 0000-007F
		txa
		bmi 	_CWBError
		rts
_CWBCheckNegative:							; FF80-FFFF
		txa
		bpl 	_CWBError
		rts

