; ******************************************************************************
; ******************************************************************************
;
;		Name : 		generate.asm
;		Purpose : 	Generate code
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

GeneratorSearch:
		stz 	genPos 						; reset the generator pointer
		;
		;		Main Generator loop.
		;
_GSLoop:ldx 	genPos
		lda 	lineBuffer,x
		beq 	_GSExit
		lda 	genPos 						; point XY to the next thing
		clc
		adc 	#lineBuffer & $FF
		tax
		ldy 	#lineBuffer >> 8
		bcc 	_GSNoCarry
		iny
_GSNoCarry:
		jsr 	DictionarySearchSystemOnly 	; dictionary search
		bcs 	_GSFound
_GSError:			
		derror 	"SYNTAX?"
_GSFound:
		cmp 	#"M"						; check it's a match.
		bne 	_GSError		
		;
		ldy 	dirLength 					; advance to next
		ldx 	genPos 						; checking for a-z.
_GSCheckData:
		lda 	lineBuffer,x
		and 	#$7F
		cmp 	#'a'
		bcc 	_GSNotLC
		cmp 	#'z'+1
		bcs 	_GSNotLC
		txa
		jsr 	GenCopyData
_GSNotLC:		
		inx
		dey
		bne 	_GSCheckData
		stx 	genPos
		;
		;		Generate code / Handle special cases.
		;
		lda 	dirLowByte					; copy address to genPtr
		sta 	genPtr
		lda 	dirHighByte
		sta 	genPtr+1
		;
		lda 	(genPtr)					; count in A
		beq 	_GSNext 					; nothing !
		tax 								; X is count
		ldy 	#1
_GSGenerate:
		lda 	(genPtr),y 					; execute something
		cmp 	#CGEN_C_EXEC
		beq 	_GSExecute
		cmp 	#CGEN_C_SETDATA 			; set data ?
		bne 	_GSCopy
		;
		iny									; copy next two bytes out.
		lda 	(genPtr),y
		sta 	generateVar
		iny
		lda 	(genPtr),y
		sta 	generateVar+1
		dex
		dex
		bra 	_GSContinue
_GSCopy:
		jsr 	GenConvertByte 				; replace bytes
		jsr 	CodeWriteByte				; write out.
_GSContinue:		
		iny
		dex
		bne 	_GSGenerate
_GSNext:
		bra 	_GSLoop 		
_GSExit:
		rts
		;
		;		Code execution special case.
		;
_GSExecute:
		iny 								; grab one.
		dex 	
		phx 								; save XY
		phy
		lda 	(genPtr),y 					; read the execution ID
		asl 	a 							; index into table.
		tax
		lda 	ExecutableVectorTable,x 	; read jump vector
		sta 	zTemp0
		lda 	ExecutableVectorTable+1,x
		sta 	zTemp0+1
		jsr 	_GSCallzTemp0 				; call routine
		ply 								; restore XY
		plx
		bra 	_GSContinue

_GSCallzTemp0:
		jmp 	(zTemp0)

; ******************************************************************************
;
;		Replace the placeholder bytes in code - actually NOPs with data
;
; ******************************************************************************

GenConvertByte:
		cmp 	#CGEN_C_LOW
		beq 	_GCBLowByte
		cmp 	#CGEN_C_LOWPLUS1
		beq 	_GCBLowBytePlus1
		cmp 	#CGEN_C_HIGH
		beq 	_GCBHighByte
		rts
_GCBLowByte:
		lda 	elementData
		rts
_GCBLowBytePlus1:
		lda 	elementData
		inc 	a
		beq 	_GCBSystem
		rts
_GCBHighByte:
		lda 	elementData+1
		rts
_GCBSystem:
		derror 	"WORD OFF PAGE"
		
; ******************************************************************************
;
;					Copy data at offset A into elementData
;
; ******************************************************************************

GenCopyData:
		pha
		phx
		phy
		sta 	zTemp0
		ldx 	#256-4
_GCDLoop:
		inx 								; next slot
		inx
		inx
		inx
		lda 	valueBuffer,x 				; next in value buffer
		cmp 	#$FF
		beq 	_GCDError 					; system ?
		cmp 	zTemp0 						; match.
		bne 	_GCDLoop
		;
		ldy 	#0 							; copy assoc data back
_GCDCopy:		
		lda 	valueBuffer+1,x
		sta 	elementData,y
		inx
		iny
		cpy 	#3
		bne 	_GCDCopy
		ply
		plx
		pla
		rts
_GCDError:		
		derror 	"SYS0?"