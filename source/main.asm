; ******************************************************************************
; ******************************************************************************
;
;		Name : 		main.asm
;		Purpose : 	Main Program
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

		.include 	"data.asm" 					; data & constants
		.include 	"generated/cgconst.inc" 	; constants shared with translator
		.include 	"macros.inc" 				; macros

		* = $A000

		tsx 									; save SP
		stx 	originalSP
		jsr 	LoadBasicCode

		jsr 	StackReset 						; reset convert stack.
		jsr 	VariableReset 					; reset variable memory.
		jsr 	DictionaryReset 				; reset user dictionary
		jsr 	CodeReset 						; reset code output.
		jsr 	ScannerReset 					; reset scanner
		;
		;		Main Compiler Loop
		;	
AsmLoop:
		jsr 	ScannerFind 					; next thing in code
		bcc 	AsmEnd 							; nothing more
		jsr 	ProcessLineToBuffer 			; convert it.
		jsr 	GeneratorSearch 				; check it for generators
		bra 	AsmLoop 						; and keep going.
AsmEnd:	 
		lda 	#SCM_TOP 						; check structures are done
		jsr 	StackCheckStructureMarker
		;
		jsr 	CallCodeMemory	
		;
ReturnCaller:
		ldx		originalSP 						; restore XP and exit.
		txs
		rts

; ******************************************************************************
;
;					Call the last Defined procedure if no error
;
; ******************************************************************************

CallCodeMemory:
		lda 	lastDefine
		ora 	lastDefine+1
		beq 	_NoExecute
		lda 	codePtr							; pass in byte after code.
		ldx 	codePtr+1
		.byte 	$FF
		jmp 	(lastDefine)					; call last definition.
_NoExecute:
		rts

; ******************************************************************************
;
;									Source Files
;
; ******************************************************************************

		.include 	"lean/scanner.asm"			; scans BASIC code for dotREM code
		.include 	"lean/process.asm"			; process to line.
		.include 	"lean/generate.asm"			; generator searches.
		.include 	"lean/extract.asm"			; get translated objects.

		.include 	"dictionary/create.asm"		; dictionary create.
		.include 	"dictionary/search.asm" 	; dictionary search.

		.include 	"support/code.asm"			; code writing routines.
		.include 	"support/error.asm"			; error routines

		.include 	"actions/procedure.asm" 	; action : procedure define
		.include 	"actions/call.asm"			; action : procedure call
		.include 	"actions/if.asm"			; action : if
		.include 	"actions/repeat.asm"		; action : repeat
		.include 	"actions/for.asm"			; action : for
		.include 	"actions/variables.asm"		; action : byte/word
		.include 	"actions/crunch.asm" 		; action : dictionary crunch.

		.include 	"utility/tostring.asm"		; int -> str
		.include 	"utility/tointeger.asm"		; str -> int
		.include 	"utility/astack.asm"		; structure stack.

		.include 	"generated/system.inc"		; auto-generated data from translate.py

		.include 	"utility/loadcode.asm"		; loads BASIC automatically
EndCode:		

