; ******************************************************************************
; ******************************************************************************
;
;		Name : 		data.asm
;		Purpose : 	Data Allocation
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

		* = $00

ramBank = $9F61 							; RAM Memory bank register.

; ******************************************************************************
;
;							These need to be in page zero
;
; ******************************************************************************

scanPtr:	.word ?							; BASIC scan position.
aStackPtr:	.word ? 						; compiler stack.
dictPtr:	.word ? 						; dictionary pointer
genPtr:		.word ? 						; code generation pointer
varPtr: 	.word ?							; next free variable pointer.

zTemp0:		.word ? 						; temps.
zTemp1:		.word ? 
zTemp2:		.word ? 
zTemp3:		.word ? 

lastCreate:	.word ? 						; last created dictionary word

codePtr:	.word ? 						; code pointer

; ******************************************************************************
;
;						These do not need to be in page zero
;
; ******************************************************************************

codeBank:	.byte ?							; code bank

originalSP:			.byte ? 				; 6502 stack on entry.

lastDefine:			.fill 3 				; last defined word (addr/page)

lineNumber:			.word ? 				; current line number

identStart:			.byte ? 				; start offset of current identifier

dirLowByte:			.byte ?					; values returned from search
dirHighByte:		.byte ?
dirBank:			.byte ?
dirLength:			.byte ?

valueBufferPos:		.byte ? 				; position in value buffer.

genPos: 			.byte ? 				; position in line buffer, generation.

generateVar:		.word ? 				; variables used in set value

elementData:		.fill 3 				; data from matched constant/identifier

codeBackup:			.fill 3 				; backup code pointer.

varSize:			.byte ? 				; size of current variable.

matchCount:			.byte ? 				; successful line matches (for errors)

; ******************************************************************************
;
;								 C64 Basic Tokens
;
; ******************************************************************************

REM_TOKEN = $8F 							; C64 REM Token

; ******************************************************************************
;
;							Structure Control Markers
;
; ******************************************************************************

SCM_TOP = '*'								; top of stack marker.
SCM_PROC = 'P'								; procedure marker
SCM_REPEAT = 'R'							; repeat marker
SCM_FOR = 'F' 								; for marker (8 bit)
SCM_INTFOR = 'G'							; for marker (16 bit)
SCM_IF = 'I'								; if/else/endif marker.

; ******************************************************************************
;
;								65C02 opcodes
;	
; ******************************************************************************

CPU_RETURN = $60 							; RTS opcode.
CPU_PHA = $48 								; PHA
CPU_PLA = $68 								; PLA
CPU_DECA = $3A 								; DEC A
CPU_BNE = $D0								; BNE
CPU_BRA = $80								; BRA
CPU_JSR = $20 								; JSR 
CPU_PHX = $DA 								; PHX
CPU_PLX = $FA 								; PLX
CPU_CMPIM = $C9 							; CMP#
CPU_CPXIM = $E0 							; CPX#
CPU_DEX = $CA 								; DEX