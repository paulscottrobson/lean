; ******************************************************************************
; ******************************************************************************
;
;		Name : 		uploader.asm
;		Purpose : 	Uploads binary into page 0 of $A000 RAM
;					RELOCATABLE - don't use JMP or JSR. Hence the first bit !
;		Author : 	Paul Robson (paul@robsons.org.uk)
;		Created : 	1st November 2019
;
; ******************************************************************************
; ******************************************************************************

		*=$2000
Upload:
		;
		;		Tiny routine to get current address into YX.
		;
		lda 	#$FA						; plx
		sta 	$00
		lda 	#$7A						; ply
		sta 	$01
		lda 	#$5A 						; phy
		sta 	$02
		lda 	#$DA 						; phx
		sta 	$03
		lda 	#$60 						; rts
		sta 	$04
		;
		jsr 	$0000 						; call it - puts Call00Returns-1 in YX.
Call00Returns:
		;
		;		Put address of upload data in $00,$01
		;
		txa
		sec 								; add 1 for RTS
		adc 	#(UploadData-Call00Returns) & $FF
		sta 	$00
		tya
		adc 	#(UploadData-Call00Returns) >> 8
		sta 	$01
		;
		;		Target address in $02,$03
		;
		stz 	$02
		lda 	#$A0
		sta 	$03
		stz 	$9FB1 						; copy it into bank 0.
		;
		;		Now block copy it
		;
		ldy 	#0 
CopyData:									; copy 1 page
		lda 	($00),y
		sta 	($02),y
		iny
		bne 	CopyData
		;
		inc 	$01 						; bump MSB
		inc 	$03
		lda 	$03 						; until copied 8k.
		cmp 	#$C0
		bne 	CopyData
		rts 								; and exit



UploadData:
		.binary 	"lean.bin"
UploadDataEnd:
