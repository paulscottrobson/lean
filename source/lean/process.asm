; ******************************************************************************
; ******************************************************************************
;
;		Name : 		process.asm
;		Purpose : 	Copy BASIC line, translated to lineBuffer
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

ProcessLineToBuffer:
		ldy 	#6 							; position in line
		ldx 	#0 							; position in buffer
		stz 	valueBufferPos 				; reset value buffer pos
		lda 	#$FF
		sta 	valueBuffer 				; erase value buffer (end marker $FF)
		;
		;		Main Loop
		;
_PLTConvert:
		lda 	(scanPtr),y 				; next character
		beq 	_PLTExit
		iny
		cmp 	#' ' 						; skip over spaces.
		beq 	_PLTConvert
		;
		jsr 	PLTCheckCharacter 			; identifier character.
		bcs 	_PLTIsIdentifier 			; it's an identifier.
		;
		;		puncutation character.
		;
		ora 	#$80 						; set bit 7
		sta 	lineBuffer,x 				; write out
		inx
		bra 	_PLTConvert
		;
		;		It's an identifier, first character in A
		;
_PLTIsIdentifier:
		stx 	identStart 					; save as start of identifier.
_PLTGetIdentifier:
		sta 	lineBuffer,x 				; write it out.
		inx
		lda 	(scanPtr),y	 				; get next character
		iny
		jsr 	PLTCheckCharacter 			; still identifier
		bcs 	_PLTGetIdentifier
		dey 								; undo last bump.
		;
_PLTGotIdentifier:
		lda 	lineBuffer-1,x 				; set bit 7 of last
		ora 	#$80
		sta 	lineBuffer-1,x
		;
		;		See if it is a known identifier or a constant.
		;		
		phy
		phx
		jsr 	PLTGetAddress 				; XY <= address of identifier.
		jsr 	DictionarySearch 			; is it in the dictionaries ?
		bcc 	_PLTTryConstant
		cmp 	#"P" 						; procedure, short or var ?
		beq 	_PLTFoundIdentifier
		cmp 	#"S"
		beq 	_PLTFoundIdentifier
		cmp 	#"I"
		beq 	_PLTFoundIdentifier
		;
		;		Try constant
		;
_PLTTryConstant:		
		jsr 	PLTGetAddress 				; try as a constant
		jsr 	StringToInt
		bcs 	_PLTAttachIdentifier 
		plx 								; leave as it is - unknown identifier
		ply
		bra 	_PLTConvert
		;
_PLTAttachIdentifier:		
		;
		;		Store the constant attached to position 'identStart'
		;
		lda 	#0
		jsr 	ProcessRecordData 			; record associated data
		;
		;		Figure whether to use b or w for constant
		;
		lda 	#"b"
		cpy 	#0
		beq 	_PLTRecord
		lda 	#"w"
		;
		;		Write A here, representing an address or constant.
		;
_PLTRecord:
		plx 								; restore XY position
		ply 								
		ldx 	identStart 					; overwrite the position with ident start
		ora 	#$80 						; bit 7, it's an element in its own right
		sta 	lineBuffer,x 				; write it out
		inx 								; bump the position
		bra		_PLTConvert 				; do the next one.
		;
		;		Exit
		;
_PLTExit:	
		stz 	lineBuffer,x 				; make it ASCIIZ	
		cpx		#LINEBUFFSIZE 				; line too long.
		bcs 	_PLTBuffer		
		rts
		;
		;		Found identifier, type in A (I or S)
		;
_PLTFoundIdentifier:
		pha 								; save type.
		ldx 	dirLowByte 					; get the dictionary AXY values
		ldy 	dirHighByte
		lda 	dirBank
		jsr 	ProcessRecordData 			; attached to identstart
		;
		pla 								; get type back, which is I or S or P
		ora 	#$20 						; make it lower case.
		cmp 	#"p"						; P goes untrammelled
		beq 	_PLTRecord 							
		cpy 	#0 							; if Y = 0, e.g. zero page, use that.				
		beq 	_PLTRecord 	
		eor 	#"i"^"l" 					; convert it to L
		cmp 	#"l"
		beq 	_PLTRecord
		lda 	#"c" 						; otherwise C
		bra 	_PLTRecord
_PLTError:
		derror 	"SYNTAX ?"
_PLTBuffer:
		derror 	"LINE SIZE"		


; ******************************************************************************
;
;						Get address of new identifier
;
; ******************************************************************************

PLTGetAddress:
		clc
		lda 	identStart
		adc 	#lineBuffer & $FF
		tax
		ldy 	#lineBuffer >> 8
		bcc 	_PLGANoCarry
		iny
_PLGANoCarry:
		rts

; ******************************************************************************
;
;				CS if A is identifier character A-Z 0-9 $ . _ %
;
; ******************************************************************************

PLTCheckCharacter:
		cmp 	#'%'
		beq 	_PLCCYes
		cmp 	#'_'
		beq 	_PLCCYes
		cmp 	#'$'
		beq 	_PLCCYes
		cmp 	#'.'
		beq 	_PLCCYes
		cmp 	#'0'
		bcc 	_PLCCNo
		cmp 	#'9'+1
		bcc 	_PLCCYes
		cmp 	#'A'
		bcc 	_PLCCNo
		cmp 	#'Z'+1
		bcs 	_PLCCNo
_PLCCYes:	
		sec
		rts
_PLCCNo:	
		clc
		rts

; ******************************************************************************
;
;			Record data in AXY linked to the position in identStart
;
; ******************************************************************************

ProcessRecordData:
		pha
		phx
		phy

		phx
		ldx 	valueBufferPos 				; get current position
		sta 	valueBuffer+3,x 			; copy data to it
		tya
		sta 	valueBuffer+2,x
		pla
		sta 	valueBuffer+1,x
		lda 	identStart
		sta 	valueBuffer+0,x
		inx 								; next position
		inx
		inx
		inx
		stx 	valueBufferPos 				; save
		lda 	#$FF 						; write end marker.
		sta 	valueBuffer,x

		cpx 	#VALBUFFSIZE
		bcs 	_PRDError
		ply
		plx
		pla
		rts

_PRDError:
		derror 	"COMPLEX ?"