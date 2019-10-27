;
;		Automatically generated.
;
;
;		** * = r:S [s=R] **
;
L10000:
	.byte L10000_END-L10000-1
	sta $63
L10000_END:
;
;		** * = a:S [s=A] **
;
L10001:
	.byte L10001_END-L10001-1
	sta $63
L10001_END:
;
;		** *():P [p()] **
;
L10002:
	.byte L10002_END-L10002-1
	jsr $7363
L10002_END:
;
;		** * = r:L [l=R] **
;
L10003:
	.byte L10003_END-L10003-1
	sta $7363
	stx $7383
L10003_END:
;
;		** * = r:I [i=R] **
;
L10004:
	.byte L10004_END-L10004-1
	sta $63
	stx $83
L10004_END:
;
;		** * = r:C [c=R] **
;
L10005:
	.byte L10005_END-L10005-1
	sta $7363
L10005_END:
;
;		** * = a:C [c=A] **
;
L10006:
	.byte L10006_END-L10006-1
	sta $7363
L10006_END:
;
;		** word:* [WORD] **
;
L10007:
	.byte L10007_END-L10007-1
	.byte $a3,$00
L10007_END:
;
;		** until:* [UNTIL] **
;
L10008:
	.byte L10008_END-L10008-1
	.byte $a3,$01
L10008_END:
;
;		** repeat:* [REPEAT] **
;
L10009:
	.byte L10009_END-L10009-1
	.byte $a3,$02
L10009_END:
;
;		** remove.locals:* [REMOVE.LOCALS] **
;
L10010:
	.byte L10010_END-L10010-1
	.byte $a3,$03
L10010_END:
;
;		** r+*:W [R+w] **
;
L10011:
	.byte L10011_END-L10011-1
	clc
	adc #$63
	pha
	txa
	adc #$73
	tax
	pla
L10011_END:
;
;		** r+*:S [R+s] **
;
L10012:
	.byte L10012_END-L10012-1
	clc
	adc $63
	bcc *+3
	inx
L10012_END:
;
;		** r+*:L [R+l] **
;
L10013:
	.byte L10013_END-L10013-1
	clc
	adc $7363
	pha
	txa
	adc $7383
	tax
	pla
L10013_END:
;
;		** r+*:I [R+i] **
;
L10014:
	.byte L10014_END-L10014-1
	clc
	adc $63
	pha
	txa
	adc $83
	tax
	pla
L10014_END:
;
;		** r+*:C [R+c] **
;
L10015:
	.byte L10015_END-L10015-1
	clc
	adc $7363
	bcc *+3
	inx
L10015_END:
;
;		** r+*:B [R+b] **
;
L10016:
	.byte L10016_END-L10016-1
	clc
	adc #$63
	bcc *+3
	inx
L10016_END:
;
;		** r+?:* [R+?] **
;
L10017:
	.byte L10017_END-L10017-1
	cpx #0
	.byte $93
	bpl *
L10017_END:
;
;		** proc:* [PROC] **
;
L10018:
	.byte L10018_END-L10018-1
	.byte $a3,$04
L10018_END:
;
;		** next:* [NEXT] **
;
L10019:
	.byte L10019_END-L10019-1
	.byte $a3,$05
L10019_END:
;
;		** if:* [IF] **
;
L10020:
	.byte L10020_END-L10020-1
	.byte $a3,$06
L10020_END:
;
;		** endproc:* [ENDPROC] **
;
L10021:
	.byte L10021_END-L10021-1
	.byte $a3,$07
L10021_END:
;
;		** endif:* [ENDIF] **
;
L10022:
	.byte L10022_END-L10022-1
	.byte $a3,$08
L10022_END:
;
;		** else:* [ELSE] **
;
L10023:
	.byte L10023_END-L10023-1
	.byte $a3,$09
L10023_END:
;
;		** byte:* [BYTE] **
;
L10024:
	.byte L10024_END-L10024-1
	.byte $a3,$0a
L10024_END:
;
;		** a.for:* [A.FOR] **
;
L10025:
	.byte L10025_END-L10025-1
	.byte $a3,$0b
L10025_END:
;
;		** a+*:S [A+s] **
;
L10026:
	.byte L10026_END-L10026-1
	clc
	adc $63
L10026_END:
;
;		** a+*:C [A+c] **
;
L10027:
	.byte L10027_END-L10027-1
	clc
	adc $7363
L10027_END:
;
;		** a+*:B [A+b] **
;
L10028:
	.byte L10028_END-L10028-1
	clc
	adc# $63
L10028_END:
;
;		Vector Table for executable commands
;
ExecutableVectorTable:
	.word Action_wordvar                   ; 0
	.word Action_until                     ; 1
	.word Action_repeat                    ; 2
	.word Action_dictionarycrunch          ; 3
	.word Action_procedure_def             ; 4
	.word Action_next                      ; 5
	.word Action_if                        ; 6
	.word Action_endproc                   ; 7
	.word Action_endif                     ; 8
	.word Action_else                      ; 9
	.word Action_bytevar                   ; 10
	.word Action_afor                      ; 11
SystemDictionary:
;
;		**** s=R ****
;
	.byte	9
	.byte	'M'
	.word	L10000
	.byte	0
	.byte	3
	.byte	$f3,$bd,$d2
;
;		**** s=A ****
;
	.byte	9
	.byte	'M'
	.word	L10001
	.byte	0
	.byte	3
	.byte	$f3,$bd,$c1
;
;		**** p() ****
;
	.byte	9
	.byte	'M'
	.word	L10002
	.byte	0
	.byte	3
	.byte	$f0,$a8,$a9
;
;		**** l=R ****
;
	.byte	9
	.byte	'M'
	.word	L10003
	.byte	0
	.byte	3
	.byte	$ec,$bd,$d2
;
;		**** i=R ****
;
	.byte	9
	.byte	'M'
	.word	L10004
	.byte	0
	.byte	3
	.byte	$e9,$bd,$d2
;
;		**** c=R ****
;
	.byte	9
	.byte	'M'
	.word	L10005
	.byte	0
	.byte	3
	.byte	$e3,$bd,$d2
;
;		**** c=A ****
;
	.byte	9
	.byte	'M'
	.word	L10006
	.byte	0
	.byte	3
	.byte	$e3,$bd,$c1
;
;		**** WORD ****
;
	.byte	10
	.byte	'M'
	.word	L10007
	.byte	0
	.byte	4
	.byte	$57,$4f,$52,$c4
;
;		**** UNTIL ****
;
	.byte	11
	.byte	'M'
	.word	L10008
	.byte	0
	.byte	5
	.byte	$55,$4e,$54,$49,$cc
;
;		**** REPEAT ****
;
	.byte	12
	.byte	'M'
	.word	L10009
	.byte	0
	.byte	6
	.byte	$52,$45,$50,$45,$41,$d4
;
;		**** REMOVE.LOCALS ****
;
	.byte	19
	.byte	'M'
	.word	L10010
	.byte	0
	.byte	13
	.byte	$52,$45,$4d,$4f,$56,$45,$2e,$4c,$4f,$43,$41,$4c,$d3
;
;		**** R+w ****
;
	.byte	9
	.byte	'M'
	.word	L10011
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f7
;
;		**** R+s ****
;
	.byte	9
	.byte	'M'
	.word	L10012
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f3
;
;		**** R+l ****
;
	.byte	9
	.byte	'M'
	.word	L10013
	.byte	0
	.byte	3
	.byte	$d2,$ab,$ec
;
;		**** R+i ****
;
	.byte	9
	.byte	'M'
	.word	L10014
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e9
;
;		**** R+c ****
;
	.byte	9
	.byte	'M'
	.word	L10015
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e3
;
;		**** R+b ****
;
	.byte	9
	.byte	'M'
	.word	L10016
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e2
;
;		**** R+? ****
;
	.byte	9
	.byte	'M'
	.word	L10017
	.byte	0
	.byte	3
	.byte	$d2,$ab,$bf
;
;		**** PROC ****
;
	.byte	10
	.byte	'M'
	.word	L10018
	.byte	0
	.byte	4
	.byte	$50,$52,$4f,$c3
;
;		**** NEXT ****
;
	.byte	10
	.byte	'M'
	.word	L10019
	.byte	0
	.byte	4
	.byte	$4e,$45,$58,$d4
;
;		**** IF ****
;
	.byte	8
	.byte	'M'
	.word	L10020
	.byte	0
	.byte	2
	.byte	$49,$c6
;
;		**** ENDPROC ****
;
	.byte	13
	.byte	'M'
	.word	L10021
	.byte	0
	.byte	7
	.byte	$45,$4e,$44,$50,$52,$4f,$c3
;
;		**** ENDIF ****
;
	.byte	11
	.byte	'M'
	.word	L10022
	.byte	0
	.byte	5
	.byte	$45,$4e,$44,$49,$c6
;
;		**** ELSE ****
;
	.byte	10
	.byte	'M'
	.word	L10023
	.byte	0
	.byte	4
	.byte	$45,$4c,$53,$c5
;
;		**** BYTE ****
;
	.byte	10
	.byte	'M'
	.word	L10024
	.byte	0
	.byte	4
	.byte	$42,$59,$54,$c5
;
;		**** A.FOR ****
;
	.byte	11
	.byte	'M'
	.word	L10025
	.byte	0
	.byte	5
	.byte	$41,$2e,$46,$4f,$d2
;
;		**** A+s ****
;
	.byte	9
	.byte	'M'
	.word	L10026
	.byte	0
	.byte	3
	.byte	$c1,$ab,$f3
;
;		**** A+c ****
;
	.byte	9
	.byte	'M'
	.word	L10027
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e3
;
;		**** A+b ****
;
	.byte	9
	.byte	'M'
	.word	L10028
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e2
;
	.byte	$00
