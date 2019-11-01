; ******************************************************************************
; ******************************************************************************
;
;		Name : 		crunch.asm
;		Purpose : 	Remove locals from user dictionary
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	27th October 2019
;
; ******************************************************************************
; ******************************************************************************

; ******************************************************************************
;
;		Dictionary Crunch. Removes all locals (begin with underscore)
;
; ******************************************************************************

Action_DictionaryCrunch:
		set16 	zTemp0,UserDictionary 		; position in user dictionary.
		;
		;		Main Crunch loop.
		;
_ADCLoop:		
		lda 	(zTemp0) 					; reached end of dictionary
		beq 	_ADCExit
		ldy 	#6							; read first character
		lda 	(zTemp0),y
		and 	#$7F 						; is it a '_' ?
		cmp 	#'_'
		bne 	_ADCNext 					; if not, it's a global, skip to next.
		;
		lda 	zTemp0 						; work out copy from, into zTemp1
		pha
		clc
		adc 	(zTemp0)
		sta 	zTemp1
		lda 	zTemp0+1
		pha
		adc 	#0
		sta 	zTemp1+1
_ADCopyOverwrite:		
		lda 	(zTemp1) 					; byte copy
		sta 	(zTemp0)
		lda 	zTemp1 						; until the upper address = dictionary top
		cmp 	dictPtr
		bne 	_ADCNextCopy
		lda 	zTemp1+1
		cmp 	dictPtr+1
		beq 	_ADCRemoved
_ADCNextCopy:
		inc16 	zTemp0 						; bump pointers
		inc16 	zTemp1
		bra 	_ADCopyOverwrite
		;
_ADCRemoved:		
		lda 	zTemp0 						; copy from position is new top.
		sta 	dictPtr
		lda 	zTemp0+1
		sta 	dictPtr+1
		lda 	#0							; mark end as not copied in loop
		sta 	(dictPtr)
		;
		pla 								; restore original position.
		sta 	zTemp0+1
		pla
		sta 	zTemp0
		; 
		bra 	_ADCLoop 					; and continue from same position.
		;
		;		Go to next
		;
_ADCNext:
		clc 								; advance to next.
		lda 	zTemp0
		adc 	(zTemp0)
		sta 	zTemp0
		bcc 	_ADCLoop		
		inc 	zTemp0+1
		bra 	_ADCLoop
		;
_ADCExit:
		rts		
		