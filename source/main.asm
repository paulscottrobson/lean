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

ProgramStart = $0801 						; where source code starts.
UserDictionary = EndCode 					; user dictionary
CodeMemory = $A000 							; where object code goes.
CodePage = $01 								; page for code memory.
AssemblerStack = $063F 						; compiler stack space.
lineBuffer = $0640	 						; current line, match encoded.
valueBuffer = $0680 						; buffer for associated values.
VariableMemory = $0700 						; data memory allocaed from here
BankCode = $0700 							; bank handling code goes here.

LINEBUFFSIZE = 64
VALBUFFSIZE = 128


		.include 	"data.asm" 					; data & constants
		.include 	"generated/cgconst.inc" 	; constants shared with translator
		.include 	"macros.inc" 				; macros

		* = $A000

		tsx 									; save SP
		stx 	originalSP
		jsr 	LoadBasicCode

		jsr 	BankCopyCode 					; copy banked code to RAM space.
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
		.byte 	$FF
		lda 	lastDefine
		ora 	lastDefine+1
		ora 	lastDefine+2
		beq 	_NoExecute
		lda 	codePtr							; pass in byte after code.
		ldx 	codePtr+1
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
		.include  	"bank/banking.asm"			; banked code.
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
