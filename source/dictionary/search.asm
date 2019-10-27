; ******************************************************************************
; ******************************************************************************
;
;		Name : 		search.asm
;		Purpose : 	Dictionary Search code
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;							Reset User Dictionary
;
; ******************************************************************************

DictionaryReset:
		set16 	dictPtr,UserDictionary
		stz 	UserDictionary
		rts

; ******************************************************************************
;
;		Scan dictionaries for element at XY. If found return A = type,
;		CS, data in dirLow/HighByte and dirBank. Not found, CC
;
; ******************************************************************************

DictionarySearchSystemOnly:
		sec
		bra 	DictionarySearchContinue
DictionarySearch:
		clc
DictionarySearchContinue:
		phx
		phy
		php 								; CS if user only
		txa 								; subtract 6 so can use offset Y
		sec
		sbc 	#6
		sta 	zTemp0
		tya
		sbc 	#0
		sta 	zTemp0+1 					; in zTemp0
		plp
		bcs 	_DSCOnly
		;
		;		Search user
		;
		ldx 	#UserDictionary & $FF
		ldy 	#UserDictionary >> 8
		jsr 	DSSearch
		bcs 	_DSCExit
		;
		;		Search system
		;
_DSCOnly:		
		ldx 	#SystemDictionary & $FF
		ldy 	#SystemDictionary >> 8
		jsr 	DSSearch
_DSCExit:		
		ply 								; restore YX
		plx
		rts
;
;
;
DSSearch:	
		stx 	zTemp1 						; save dictionary in zTemp1
		sty 	zTemp1+1
		;
_DSLoop:
		lda 	(zTemp1) 					; offset 0 ?
		beq 	_DSExit
		ldy 	#5 							; get length in X
		lda 	(zTemp1),y
		tax
_DSCompare:		
		iny 								; match next ?
		lda 	(zTemp1),y
		cmp 	(zTemp0),y
		bne 	_DSNext
		dex 								; done all
		bne 	_DSCompare
		;
		ldy 	#5 							; copy bank/address
		lda 	(zTemp1),y
		sta 	dirLength
		dey
		lda 	(zTemp1),y
		sta 	dirBank
		dey
		lda 	(zTemp1),y
		sta 	dirHighByte
		dey
		lda 	(zTemp1),y
		sta 	dirLowByte
		dey
		lda 	(zTemp1),y 					; return type
		sec
		rts
;
_DSNext:	
		clc 								; advance to next.
		lda 	(zTemp1)
		adc 	zTemp1
		sta 	zTemp1
		bcc 	_DSLoop
		inc 	zTemp1+1
		bra 	_DSLoop

_DSExit:				
		clc
		rts