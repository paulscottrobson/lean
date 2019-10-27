; ******************************************************************************
; ******************************************************************************
;
;		Name : 		create.asm
;		Purpose : 	Create/Update Dictionary Entries
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;				Create dictionary entry. YX is identifier, A type.
;
; ******************************************************************************

DictionaryCreate:	
		stx 	zTemp0 						; save identifier position
		sty 	zTemp0+1
		ldy 	#1 							; write the type byte out.
		sta 	(dictPtr),y
		ldy 	#0 							; work out length.
_DCGetLength:
		lda 	(zTemp0),y
		iny
		asl 	a
		bcc 	_DCGetLength
		phy 								; save Y on stack.
		tya 								; save length +6 as offset
		clc 
		adc 	#6
		sta 	(dictPtr)
		;
		ldy 	#2 							; fill 2 to 4 with $FF
_DCFill:lda 	#$FF
		sta 	(dictPtr),y
		iny
		cpy 	#5
		bne 	_DCFill
		pla 								; get length, store in X
		tax
		sta 	(dictPtr),y 				; write length out.
		ldy 	#0
_DCCopy:
		lda 	(zTemp0),y 					; next identifier character
		iny 								; save +1 on stack
		phy
		iny 								; advance by 6 total
		iny
		iny
		iny
		iny
		sta 	(dictPtr),y 				; write out
		ply 								; restore +1
		dex
		bne 	_DCCopy 					; do that the required# times.
		;
		lda 	dictPtr 					; copy last created
		sta 	lastCreate
		lda 	dictPtr+1
		sta 	lastCreate+1
		;
		clc 								; advance dictionary pointer
		lda 	(dictPtr)			
		adc 	dictPtr
		sta 	dictPtr
		bcc 	_DCNoCarry
		inc 	dictPtr+1
_DCNoCarry:
		lda 	#$00 						; write end of dictionary marker
		sta 	(dictPtr)
		rts

; ******************************************************************************
;
;						Set last create data to A,X,Y
;
; ******************************************************************************

DictionarySet:
		pha
		phx
		phy

		phy 								; copy data out to 
		ldy 	#4 							; offset 2,3,4 => A X Y
		sta 	(lastCreate),y
		dey
		pla
		sta 	(lastCreate),y
		dey
		txa
		sta 	(lastCreate),y

		ply
		plx
		pla
		rts
		