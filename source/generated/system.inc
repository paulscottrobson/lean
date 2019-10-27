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
	jsr $63
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
	sta $7363
	stx $7383
L10004_END:
;
;		** * = r:C [c=R] **
;
L10005:
	.byte L10005_END-L10005-1
	sta $63
L10005_END:
;
;		** * = a:C [c=A] **
;
L10006:
	.byte L10006_END-L10006-1
	sta $63
L10006_END:
;
;		** r>=*?:B [R>=b?] **
;
L10007:
	.byte L10007_END-L10007-1
	cpx #0
	.byte $53
	bpl *
	.byte $93
L10007_END:
;
;		** r+*:W [R+w] **
;
L10008:
	.byte L10008_END-L10008-1
	clc
	adc #$63
	pha
	txa
	adc #$73
	tax
	pla
L10008_END:
;
;		** r+*:S [R+s] **
;
L10009:
	.byte L10009_END-L10009-1
	clc
	adc $63
	bcc *+3
	inx
L10009_END:
;
;		** r+*:L [R+l] **
;
L10010:
	.byte L10010_END-L10010-1
	clc
	adc $7363
	pha
	txa
	adc $7383
	tax
	pla
L10010_END:
;
;		** r+*:I [R+i] **
;
L10011:
	.byte L10011_END-L10011-1
	clc
	adc $7363
	pha
	txa
	adc $7383
	tax
	pla
L10011_END:
;
;		** r+*:C [R+c] **
;
L10012:
	.byte L10012_END-L10012-1
	clc
	adc $63
	bcc *+3
	inx
L10012_END:
;
;		** r+*:B [R+b] **
;
L10013:
	.byte L10013_END-L10013-1
	clc
	adc #$63
	bcc *+3
	inx
L10013_END:
;
;		** proc:* [PROC] **
;
L10014:
	.byte L10014_END-L10014-1
L10014_END:
;
;		** endproc:* [ENDPROC] **
;
L10015:
	.byte L10015_END-L10015-1
L10015_END:
;
;		** a+*:S [A+s] **
;
L10016:
	.byte L10016_END-L10016-1
	clc
	adc $63
L10016_END:
;
;		** a+*:C [A+c] **
;
L10017:
	.byte L10017_END-L10017-1
	clc
	adc $63
L10017_END:
;
;		** a+*:B [A+b] **
;
L10018:
	.byte L10018_END-L10018-1
	clc
	adc# $63
L10018_END:
;
;		Vector Table for executable commands
;
ExecutableVectorTable:
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
;		**** R>=b? ****
;
	.byte	11
	.byte	'M'
	.word	L10007
	.byte	0
	.byte	5
	.byte	$d2,$be,$bd,$e2,$bf
;
;		**** R+w ****
;
	.byte	9
	.byte	'M'
	.word	L10008
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f7
;
;		**** R+s ****
;
	.byte	9
	.byte	'M'
	.word	L10009
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f3
;
;		**** R+l ****
;
	.byte	9
	.byte	'M'
	.word	L10010
	.byte	0
	.byte	3
	.byte	$d2,$ab,$ec
;
;		**** R+i ****
;
	.byte	9
	.byte	'M'
	.word	L10011
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e9
;
;		**** R+c ****
;
	.byte	9
	.byte	'M'
	.word	L10012
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e3
;
;		**** R+b ****
;
	.byte	9
	.byte	'M'
	.word	L10013
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e2
;
;		**** PROC ****
;
	.byte	10
	.byte	'M'
	.word	L10014
	.byte	0
	.byte	4
	.byte	$50,$52,$4f,$c3
;
;		**** ENDPROC ****
;
	.byte	13
	.byte	'M'
	.word	L10015
	.byte	0
	.byte	7
	.byte	$45,$4e,$44,$50,$52,$4f,$c3
;
;		**** A+s ****
;
	.byte	9
	.byte	'M'
	.word	L10016
	.byte	0
	.byte	3
	.byte	$c1,$ab,$f3
;
;		**** A+c ****
;
	.byte	9
	.byte	'M'
	.word	L10017
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e3
;
;		**** A+b ****
;
	.byte	9
	.byte	'M'
	.word	L10018
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e2
;
;		**** V_AB1 ****
;
	.byte	11
	.byte	'S'
	.word	$604
	.byte	0
	.byte	5
	.byte	$56,$5f,$41,$42,$b1
;
;		**** V_ZW2 ****
;
	.byte	11
	.byte	'I'
	.word	$64
	.byte	0
	.byte	5
	.byte	$56,$5f,$5a,$57,$b2
;
;		**** V_AW3 ****
;
	.byte	11
	.byte	'I'
	.word	$614
	.byte	0
	.byte	5
	.byte	$56,$5f,$41,$57,$b3
;
;		**** V_ZB4 ****
;
	.byte	11
	.byte	'S'
	.word	$f4
	.byte	0
	.byte	5
	.byte	$56,$5f,$5a,$42,$b4
;
;		**** PDEMO ****
;
	.byte	11
	.byte	'P'
	.word	$ffd2
	.byte	0
	.byte	5
	.byte	$50,$44,$45,$4d,$cf
;
	.byte	$00
