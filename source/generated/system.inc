;
;		Automatically generated.
;
;
;		** *[y] = r:S [s[Y]=R] **
;
L10000:
	.byte L10000_END-L10000-1
	sta  ($63),y
	iny
	txa
	sta  ($63),y
	dey
	lda  ($63),y
L10000_END:
;
;		** *[y] = a:S [s[Y]=A] **
;
L10001:
	.byte L10001_END-L10001-1
	sta  ($63),y
L10001_END:
;
;		** * = y:S [s=Y] **
;
L10002:
	.byte L10002_END-L10002-1
	sty  $63
L10002_END:
;
;		** * = r:S [s=R] **
;
L10003:
	.byte L10003_END-L10003-1
	sta  $63
L10003_END:
;
;		** * = a:S [s=A] **
;
L10004:
	.byte L10004_END-L10004-1
	sta  $63
L10004_END:
;
;		** *:P [p] **
;
L10005:
	.byte L10005_END-L10005-1
	.byte $a3,$00
L10005_END:
;
;		** * = r:L [l=R] **
;
L10006:
	.byte L10006_END-L10006-1
	sta  $7363
	stx  $7383
L10006_END:
;
;		** * = r:I [i=R] **
;
L10007:
	.byte L10007_END-L10007-1
	sta  $63
	stx  $83
L10007_END:
;
;		** * = y:C [c=Y] **
;
L10008:
	.byte L10008_END-L10008-1
	sty  $7363
L10008_END:
;
;		** * = r:C [c=R] **
;
L10009:
	.byte L10009_END-L10009-1
	sta  $7363
L10009_END:
;
;		** * = a:C [c=A] **
;
L10010:
	.byte L10010_END-L10010-1
	sta  $7363
L10010_END:
;
;		** y = *:S [Y=s] **
;
L10011:
	.byte L10011_END-L10011-1
	ldy  $63
L10011_END:
;
;		** y = *:C [Y=c] **
;
L10012:
	.byte L10012_END-L10012-1
	ldy  $7363
L10012_END:
;
;		** y = *:B [Y=b] **
;
L10013:
	.byte L10013_END-L10013-1
	ldy  #$63
L10013_END:
;
;		** y=r:* [Y=R] **
;
L10014:
	.byte L10014_END-L10014-1
	tay
L10014_END:
;
;		** y=a:* [Y=A] **
;
L10015:
	.byte L10015_END-L10015-1
	tay
L10015_END:
;
;		** word:* [WORD] **
;
L10016:
	.byte L10016_END-L10016-1
	.byte $a3,$01
L10016_END:
;
;		** until:* [UNTIL] **
;
L10017:
	.byte L10017_END-L10017-1
	.byte $a3,$02
L10017_END:
;
;		** r**:W [Rww] **
;
L10018:
	.byte L10018_END-L10018-1
	eor  #$63
	pha
	txa
	eor  #$73
	tax
	pla
L10018_END:
;
;		** r * *[y]:S [Rss[Y]] **
;
L10019:
	.byte L10019_END-L10019-1
	eor  ($63),y
	pha
	txa
	iny
	eor  ($63),y
	dey
	tax
	pla
L10019_END:
;
;		** r**:S [Rss] **
;
L10020:
	.byte L10020_END-L10020-1
	eor  $63
L10020_END:
;
;		** r**:L [Rll] **
;
L10021:
	.byte L10021_END-L10021-1
	eor  $7363
	pha
	txa
	eor  $7383
	tax
	pla
L10021_END:
;
;		** r**:I [Rii] **
;
L10022:
	.byte L10022_END-L10022-1
	eor  $63
	pha
	txa
	eor  $83
	tax
	pla
L10022_END:
;
;		** r**:C [Rcc] **
;
L10023:
	.byte L10023_END-L10023-1
	eor  $7363
L10023_END:
;
;		** r**:B [Rbb] **
;
L10024:
	.byte L10024_END-L10024-1
	eor  #$63
L10024_END:
;
;		** repeat:* [REPEAT] **
;
L10025:
	.byte L10025_END-L10025-1
	.byte $a3,$03
L10025_END:
;
;		** remove.locals:* [REMOVE.LOCALS] **
;
L10026:
	.byte L10026_END-L10026-1
	.byte $a3,$04
L10026_END:
;
;		** r = *:W [R=w] **
;
L10027:
	.byte L10027_END-L10027-1
	lda  #$63
	ldx  #$73
L10027_END:
;
;		** r = *[y]:S [R=s[Y]] **
;
L10028:
	.byte L10028_END-L10028-1
	iny
	lda  ($63),y
	tax
	dey
	lda  ($63),y
L10028_END:
;
;		** r = *:S [R=s] **
;
L10029:
	.byte L10029_END-L10029-1
	lda  $63
	ldx  #0
L10029_END:
;
;		** r = *:L [R=l] **
;
L10030:
	.byte L10030_END-L10030-1
	lda  $7363
	ldx  $7383
L10030_END:
;
;		** r = *:I [R=i] **
;
L10031:
	.byte L10031_END-L10031-1
	lda  $63
	ldx  $83
L10031_END:
;
;		** r = *:C [R=c] **
;
L10032:
	.byte L10032_END-L10032-1
	lda  $7363
	ldx  #0
L10032_END:
;
;		** r = *:B [R=b] **
;
L10033:
	.byte L10033_END-L10033-1
	lda  #$63
	ldx  #$73
L10033_END:
;
;		** r=y:* [R=Y] **
;
L10034:
	.byte L10034_END-L10034-1
	tya
	ldx  #0
L10034_END:
;
;		** r=a:* [R=A] **
;
L10035:
	.byte L10035_END-L10035-1
	ldx  #0
L10035_END:
;
;		** r:*:W [R:w] **
;
L10036:
	.byte L10036_END-L10036-1
	ora  #$63
	pha
	txa
	ora  #$73
	tax
	pla
L10036_END:
;
;		** r : *[y]:S [R:s[Y]] **
;
L10037:
	.byte L10037_END-L10037-1
	ora  ($63),y
	pha
	txa
	iny
	ora  ($63),y
	dey
	tax
	pla
L10037_END:
;
;		** r:*:S [R:s] **
;
L10038:
	.byte L10038_END-L10038-1
	ora  $63
L10038_END:
;
;		** r:*:L [R:l] **
;
L10039:
	.byte L10039_END-L10039-1
	ora  $7363
	pha
	txa
	ora  $7383
	tax
	pla
L10039_END:
;
;		** r:*:I [R:i] **
;
L10040:
	.byte L10040_END-L10040-1
	ora  $63
	pha
	txa
	ora  $83
	tax
	pla
L10040_END:
;
;		** r:*:C [R:c] **
;
L10041:
	.byte L10041_END-L10041-1
	ora  $7363
L10041_END:
;
;		** r:*:B [R:b] **
;
L10042:
	.byte L10042_END-L10042-1
	ora  #$63
L10042_END:
;
;		** r-*:W [R-w] **
;
L10043:
	.byte L10043_END-L10043-1
	sec
	sbc  #$63
	pha
	txa
	sbc  #$73
	tax
	pla
L10043_END:
;
;		** r - *[y]:S [R-s[Y]] **
;
L10044:
	.byte L10044_END-L10044-1
	sec
	sbc  ($63),y
	pha
	txa
	iny
	sbc  ($63),y
	dey
	tax
	pla
L10044_END:
;
;		** r-*:S [R-s] **
;
L10045:
	.byte L10045_END-L10045-1
	sec
	sbc  $63
	bcs  *+3
	dex
L10045_END:
;
;		** r-*:L [R-l] **
;
L10046:
	.byte L10046_END-L10046-1
	sec
	sbc  $7363
	pha
	txa
	sbc  $7383
	tax
	pla
L10046_END:
;
;		** r-*:I [R-i] **
;
L10047:
	.byte L10047_END-L10047-1
	sec
	sbc  $63
	pha
	txa
	sbc  $83
	tax
	pla
L10047_END:
;
;		** r-*:C [R-c] **
;
L10048:
	.byte L10048_END-L10048-1
	sec
	sbc  $7363
	bcs  *+3
	dex
L10048_END:
;
;		** r-*:B [R-b] **
;
L10049:
	.byte L10049_END-L10049-1
	sec
	sbc  #$63
	bcs  *+3
	dex
L10049_END:
;
;		** r+*:W [R+w] **
;
L10050:
	.byte L10050_END-L10050-1
	clc
	adc  #$63
	pha
	txa
	adc  #$73
	tax
	pla
L10050_END:
;
;		** r + *[y]:S [R+s[Y]] **
;
L10051:
	.byte L10051_END-L10051-1
	clc
	adc  ($63),y
	pha
	txa
	iny
	adc  ($63),y
	dey
	tax
	pla
L10051_END:
;
;		** r+*:S [R+s] **
;
L10052:
	.byte L10052_END-L10052-1
	clc
	adc  $63
	bcc  *+3
	inx
L10052_END:
;
;		** r+*:L [R+l] **
;
L10053:
	.byte L10053_END-L10053-1
	clc
	adc  $7363
	pha
	txa
	adc  $7383
	tax
	pla
L10053_END:
;
;		** r+*:I [R+i] **
;
L10054:
	.byte L10054_END-L10054-1
	clc
	adc  $63
	pha
	txa
	adc  $83
	tax
	pla
L10054_END:
;
;		** r+*:C [R+c] **
;
L10055:
	.byte L10055_END-L10055-1
	clc
	adc  $7363
	bcc  *+3
	inx
L10055_END:
;
;		** r+*:B [R+b] **
;
L10056:
	.byte L10056_END-L10056-1
	clc
	adc  #$63
	bcc  *+3
	inx
L10056_END:
;
;		** r&*:W [R&w] **
;
L10057:
	.byte L10057_END-L10057-1
	and  #$63
	pha
	txa
	and  #$73
	tax
	pla
L10057_END:
;
;		** r & *[y]:S [R&s[Y]] **
;
L10058:
	.byte L10058_END-L10058-1
	and  ($63),y
	pha
	txa
	iny
	and  ($63),y
	dey
	tax
	pla
L10058_END:
;
;		** r&*:S [R&s] **
;
L10059:
	.byte L10059_END-L10059-1
	and  $63
	ldx  #0
L10059_END:
;
;		** r&*:L [R&l] **
;
L10060:
	.byte L10060_END-L10060-1
	and  $7363
	pha
	txa
	and  $7383
	tax
	pla
L10060_END:
;
;		** r&*:I [R&i] **
;
L10061:
	.byte L10061_END-L10061-1
	and  $63
	pha
	txa
	and  $83
	tax
	pla
L10061_END:
;
;		** r&*:C [R&c] **
;
L10062:
	.byte L10062_END-L10062-1
	and  $7363
	ldx  #0
L10062_END:
;
;		** r&*:B [R&b] **
;
L10063:
	.byte L10063_END-L10063-1
	and  #$63
	ldx  #0
L10063_END:
;
;		** proc:* [PROC] **
;
L10064:
	.byte L10064_END-L10064-1
	.byte $a3,$05
L10064_END:
;
;		** next:* [NEXT] **
;
L10065:
	.byte L10065_END-L10065-1
	.byte $a3,$06
L10065_END:
;
;		** if:* [IF] **
;
L10066:
	.byte L10066_END-L10066-1
	.byte $a3,$07
L10066_END:
;
;		** endproc:* [ENDPROC] **
;
L10067:
	.byte L10067_END-L10067-1
	.byte $a3,$08
L10067_END:
;
;		** endif:* [ENDIF] **
;
L10068:
	.byte L10068_END-L10068-1
	.byte $a3,$09
L10068_END:
;
;		** else:* [ELSE] **
;
L10069:
	.byte L10069_END-L10069-1
	.byte $a3,$0a
L10069_END:
;
;		** byte:* [BYTE] **
;
L10070:
	.byte L10070_END-L10070-1
	.byte $a3,$0b
L10070_END:
;
;		** a * *[y]:S [Ass[Y]] **
;
L10071:
	.byte L10071_END-L10071-1
	eor  ($63),y
L10071_END:
;
;		** a**:S [Ass] **
;
L10072:
	.byte L10072_END-L10072-1
	eor  $63
L10072_END:
;
;		** a**:C [Acc] **
;
L10073:
	.byte L10073_END-L10073-1
	eor  $7363
L10073_END:
;
;		** a**:B [Abb] **
;
L10074:
	.byte L10074_END-L10074-1
	eor  #$63
L10074_END:
;
;		** a = *[y]:S [A=s[Y]] **
;
L10075:
	.byte L10075_END-L10075-1
	lda  ($63),y
L10075_END:
;
;		** a = *:S [A=s] **
;
L10076:
	.byte L10076_END-L10076-1
	lda  $63
L10076_END:
;
;		** a = *:C [A=c] **
;
L10077:
	.byte L10077_END-L10077-1
	lda  $7363
L10077_END:
;
;		** a = *:B [A=b] **
;
L10078:
	.byte L10078_END-L10078-1
	lda  #$63
L10078_END:
;
;		** a=y:* [A=Y] **
;
L10079:
	.byte L10079_END-L10079-1
	tya
L10079_END:
;
;		** a=r:* [A=R] **
;
L10080:
	.byte L10080_END-L10080-1
L10080_END:
;
;		** a : *[y]:S [A:s[Y]] **
;
L10081:
	.byte L10081_END-L10081-1
	ora  ($63),y
L10081_END:
;
;		** a:*:S [A:s] **
;
L10082:
	.byte L10082_END-L10082-1
	ora  $63
L10082_END:
;
;		** a:*:C [A:c] **
;
L10083:
	.byte L10083_END-L10083-1
	ora  $7363
L10083_END:
;
;		** a:*:B [A:b] **
;
L10084:
	.byte L10084_END-L10084-1
	ora  #$63
L10084_END:
;
;		** a.for:* [A.FOR] **
;
L10085:
	.byte L10085_END-L10085-1
	.byte $a3,$0c
L10085_END:
;
;		** a - *[y]:S [A-s[Y]] **
;
L10086:
	.byte L10086_END-L10086-1
	sec
	sbc  ($63),y
L10086_END:
;
;		** a-*:S [A-s] **
;
L10087:
	.byte L10087_END-L10087-1
	sec
	sbc  $63
L10087_END:
;
;		** a-*:C [A-c] **
;
L10088:
	.byte L10088_END-L10088-1
	sec
	sbc  $7363
L10088_END:
;
;		** a-*:B [A-b] **
;
L10089:
	.byte L10089_END-L10089-1
	sec
	sbc  #$63
L10089_END:
;
;		** a + *[y]:S [A+s[Y]] **
;
L10090:
	.byte L10090_END-L10090-1
	clc
	adc  ($63),y
L10090_END:
;
;		** a+*:S [A+s] **
;
L10091:
	.byte L10091_END-L10091-1
	clc
	adc  $63
L10091_END:
;
;		** a+*:C [A+c] **
;
L10092:
	.byte L10092_END-L10092-1
	clc
	adc  $7363
L10092_END:
;
;		** a+*:B [A+b] **
;
L10093:
	.byte L10093_END-L10093-1
	clc
	adc  #$63
L10093_END:
;
;		** a & *[y]:S [A&s[Y]] **
;
L10094:
	.byte L10094_END-L10094-1
	and  ($63),y
L10094_END:
;
;		** a&*:S [A&s] **
;
L10095:
	.byte L10095_END-L10095-1
	and  $63
L10095_END:
;
;		** a&*:C [A&c] **
;
L10096:
	.byte L10096_END-L10096-1
	and  $7363
L10096_END:
;
;		** a&*:B [A&b] **
;
L10097:
	.byte L10097_END-L10097-1
	and  #$63
L10097_END:
;
;		Vector Table for executable commands
;
ExecutableVectorTable:
	.word Action_call                      ; 0
	.word Action_wordvar                   ; 1
	.word Action_until                     ; 2
	.word Action_repeat                    ; 3
	.word Action_dictionarycrunch          ; 4
	.word Action_procedure_def             ; 5
	.word Action_next                      ; 6
	.word Action_if                        ; 7
	.word Action_endproc                   ; 8
	.word Action_endif                     ; 9
	.word Action_else                      ; 10
	.word Action_bytevar                   ; 11
	.word Action_afor                      ; 12
SystemDictionary:
;
;		**** s[Y]=R ****
;
	.byte	12
	.byte	'M'
	.word	L10000
	.byte	0
	.byte	6
	.byte	$f3,$db,$d9,$dd,$bd,$d2
;
;		**** s[Y]=A ****
;
	.byte	12
	.byte	'M'
	.word	L10001
	.byte	0
	.byte	6
	.byte	$f3,$db,$d9,$dd,$bd,$c1
;
;		**** s=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10002
	.byte	0
	.byte	3
	.byte	$f3,$bd,$d9
;
;		**** s=R ****
;
	.byte	9
	.byte	'M'
	.word	L10003
	.byte	0
	.byte	3
	.byte	$f3,$bd,$d2
;
;		**** s=A ****
;
	.byte	9
	.byte	'M'
	.word	L10004
	.byte	0
	.byte	3
	.byte	$f3,$bd,$c1
;
;		**** p ****
;
	.byte	7
	.byte	'M'
	.word	L10005
	.byte	0
	.byte	1
	.byte	$f0
;
;		**** l=R ****
;
	.byte	9
	.byte	'M'
	.word	L10006
	.byte	0
	.byte	3
	.byte	$ec,$bd,$d2
;
;		**** i=R ****
;
	.byte	9
	.byte	'M'
	.word	L10007
	.byte	0
	.byte	3
	.byte	$e9,$bd,$d2
;
;		**** c=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10008
	.byte	0
	.byte	3
	.byte	$e3,$bd,$d9
;
;		**** c=R ****
;
	.byte	9
	.byte	'M'
	.word	L10009
	.byte	0
	.byte	3
	.byte	$e3,$bd,$d2
;
;		**** c=A ****
;
	.byte	9
	.byte	'M'
	.word	L10010
	.byte	0
	.byte	3
	.byte	$e3,$bd,$c1
;
;		**** Y=s ****
;
	.byte	9
	.byte	'M'
	.word	L10011
	.byte	0
	.byte	3
	.byte	$d9,$bd,$f3
;
;		**** Y=c ****
;
	.byte	9
	.byte	'M'
	.word	L10012
	.byte	0
	.byte	3
	.byte	$d9,$bd,$e3
;
;		**** Y=b ****
;
	.byte	9
	.byte	'M'
	.word	L10013
	.byte	0
	.byte	3
	.byte	$d9,$bd,$e2
;
;		**** Y=R ****
;
	.byte	9
	.byte	'M'
	.word	L10014
	.byte	0
	.byte	3
	.byte	$d9,$bd,$d2
;
;		**** Y=A ****
;
	.byte	9
	.byte	'M'
	.word	L10015
	.byte	0
	.byte	3
	.byte	$d9,$bd,$c1
;
;		**** WORD ****
;
	.byte	10
	.byte	'M'
	.word	L10016
	.byte	0
	.byte	4
	.byte	$57,$4f,$52,$c4
;
;		**** UNTIL ****
;
	.byte	11
	.byte	'M'
	.word	L10017
	.byte	0
	.byte	5
	.byte	$55,$4e,$54,$49,$cc
;
;		**** Rww ****
;
	.byte	9
	.byte	'M'
	.word	L10018
	.byte	0
	.byte	3
	.byte	$52,$77,$f7
;
;		**** Rss[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10019
	.byte	0
	.byte	6
	.byte	$52,$73,$f3,$db,$d9,$dd
;
;		**** Rss ****
;
	.byte	9
	.byte	'M'
	.word	L10020
	.byte	0
	.byte	3
	.byte	$52,$73,$f3
;
;		**** Rll ****
;
	.byte	9
	.byte	'M'
	.word	L10021
	.byte	0
	.byte	3
	.byte	$52,$6c,$ec
;
;		**** Rii ****
;
	.byte	9
	.byte	'M'
	.word	L10022
	.byte	0
	.byte	3
	.byte	$52,$69,$e9
;
;		**** Rcc ****
;
	.byte	9
	.byte	'M'
	.word	L10023
	.byte	0
	.byte	3
	.byte	$52,$63,$e3
;
;		**** Rbb ****
;
	.byte	9
	.byte	'M'
	.word	L10024
	.byte	0
	.byte	3
	.byte	$52,$62,$e2
;
;		**** REPEAT ****
;
	.byte	12
	.byte	'M'
	.word	L10025
	.byte	0
	.byte	6
	.byte	$52,$45,$50,$45,$41,$d4
;
;		**** REMOVE.LOCALS ****
;
	.byte	19
	.byte	'M'
	.word	L10026
	.byte	0
	.byte	13
	.byte	$52,$45,$4d,$4f,$56,$45,$2e,$4c,$4f,$43,$41,$4c,$d3
;
;		**** R=w ****
;
	.byte	9
	.byte	'M'
	.word	L10027
	.byte	0
	.byte	3
	.byte	$d2,$bd,$f7
;
;		**** R=s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10028
	.byte	0
	.byte	6
	.byte	$d2,$bd,$f3,$db,$d9,$dd
;
;		**** R=s ****
;
	.byte	9
	.byte	'M'
	.word	L10029
	.byte	0
	.byte	3
	.byte	$d2,$bd,$f3
;
;		**** R=l ****
;
	.byte	9
	.byte	'M'
	.word	L10030
	.byte	0
	.byte	3
	.byte	$d2,$bd,$ec
;
;		**** R=i ****
;
	.byte	9
	.byte	'M'
	.word	L10031
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e9
;
;		**** R=c ****
;
	.byte	9
	.byte	'M'
	.word	L10032
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e3
;
;		**** R=b ****
;
	.byte	9
	.byte	'M'
	.word	L10033
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e2
;
;		**** R=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10034
	.byte	0
	.byte	3
	.byte	$d2,$bd,$d9
;
;		**** R=A ****
;
	.byte	9
	.byte	'M'
	.word	L10035
	.byte	0
	.byte	3
	.byte	$d2,$bd,$c1
;
;		**** R:w ****
;
	.byte	9
	.byte	'M'
	.word	L10036
	.byte	0
	.byte	3
	.byte	$d2,$ba,$f7
;
;		**** R:s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10037
	.byte	0
	.byte	6
	.byte	$d2,$ba,$f3,$db,$d9,$dd
;
;		**** R:s ****
;
	.byte	9
	.byte	'M'
	.word	L10038
	.byte	0
	.byte	3
	.byte	$d2,$ba,$f3
;
;		**** R:l ****
;
	.byte	9
	.byte	'M'
	.word	L10039
	.byte	0
	.byte	3
	.byte	$d2,$ba,$ec
;
;		**** R:i ****
;
	.byte	9
	.byte	'M'
	.word	L10040
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e9
;
;		**** R:c ****
;
	.byte	9
	.byte	'M'
	.word	L10041
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e3
;
;		**** R:b ****
;
	.byte	9
	.byte	'M'
	.word	L10042
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e2
;
;		**** R-w ****
;
	.byte	9
	.byte	'M'
	.word	L10043
	.byte	0
	.byte	3
	.byte	$d2,$ad,$f7
;
;		**** R-s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10044
	.byte	0
	.byte	6
	.byte	$d2,$ad,$f3,$db,$d9,$dd
;
;		**** R-s ****
;
	.byte	9
	.byte	'M'
	.word	L10045
	.byte	0
	.byte	3
	.byte	$d2,$ad,$f3
;
;		**** R-l ****
;
	.byte	9
	.byte	'M'
	.word	L10046
	.byte	0
	.byte	3
	.byte	$d2,$ad,$ec
;
;		**** R-i ****
;
	.byte	9
	.byte	'M'
	.word	L10047
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e9
;
;		**** R-c ****
;
	.byte	9
	.byte	'M'
	.word	L10048
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e3
;
;		**** R-b ****
;
	.byte	9
	.byte	'M'
	.word	L10049
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e2
;
;		**** R+w ****
;
	.byte	9
	.byte	'M'
	.word	L10050
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f7
;
;		**** R+s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10051
	.byte	0
	.byte	6
	.byte	$d2,$ab,$f3,$db,$d9,$dd
;
;		**** R+s ****
;
	.byte	9
	.byte	'M'
	.word	L10052
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f3
;
;		**** R+l ****
;
	.byte	9
	.byte	'M'
	.word	L10053
	.byte	0
	.byte	3
	.byte	$d2,$ab,$ec
;
;		**** R+i ****
;
	.byte	9
	.byte	'M'
	.word	L10054
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e9
;
;		**** R+c ****
;
	.byte	9
	.byte	'M'
	.word	L10055
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e3
;
;		**** R+b ****
;
	.byte	9
	.byte	'M'
	.word	L10056
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e2
;
;		**** R&w ****
;
	.byte	9
	.byte	'M'
	.word	L10057
	.byte	0
	.byte	3
	.byte	$d2,$a6,$f7
;
;		**** R&s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10058
	.byte	0
	.byte	6
	.byte	$d2,$a6,$f3,$db,$d9,$dd
;
;		**** R&s ****
;
	.byte	9
	.byte	'M'
	.word	L10059
	.byte	0
	.byte	3
	.byte	$d2,$a6,$f3
;
;		**** R&l ****
;
	.byte	9
	.byte	'M'
	.word	L10060
	.byte	0
	.byte	3
	.byte	$d2,$a6,$ec
;
;		**** R&i ****
;
	.byte	9
	.byte	'M'
	.word	L10061
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e9
;
;		**** R&c ****
;
	.byte	9
	.byte	'M'
	.word	L10062
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e3
;
;		**** R&b ****
;
	.byte	9
	.byte	'M'
	.word	L10063
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e2
;
;		**** PROC ****
;
	.byte	10
	.byte	'M'
	.word	L10064
	.byte	0
	.byte	4
	.byte	$50,$52,$4f,$c3
;
;		**** NEXT ****
;
	.byte	10
	.byte	'M'
	.word	L10065
	.byte	0
	.byte	4
	.byte	$4e,$45,$58,$d4
;
;		**** IF ****
;
	.byte	8
	.byte	'M'
	.word	L10066
	.byte	0
	.byte	2
	.byte	$49,$c6
;
;		**** ENDPROC ****
;
	.byte	13
	.byte	'M'
	.word	L10067
	.byte	0
	.byte	7
	.byte	$45,$4e,$44,$50,$52,$4f,$c3
;
;		**** ENDIF ****
;
	.byte	11
	.byte	'M'
	.word	L10068
	.byte	0
	.byte	5
	.byte	$45,$4e,$44,$49,$c6
;
;		**** ELSE ****
;
	.byte	10
	.byte	'M'
	.word	L10069
	.byte	0
	.byte	4
	.byte	$45,$4c,$53,$c5
;
;		**** BYTE ****
;
	.byte	10
	.byte	'M'
	.word	L10070
	.byte	0
	.byte	4
	.byte	$42,$59,$54,$c5
;
;		**** Ass[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10071
	.byte	0
	.byte	6
	.byte	$41,$73,$f3,$db,$d9,$dd
;
;		**** Ass ****
;
	.byte	9
	.byte	'M'
	.word	L10072
	.byte	0
	.byte	3
	.byte	$41,$73,$f3
;
;		**** Acc ****
;
	.byte	9
	.byte	'M'
	.word	L10073
	.byte	0
	.byte	3
	.byte	$41,$63,$e3
;
;		**** Abb ****
;
	.byte	9
	.byte	'M'
	.word	L10074
	.byte	0
	.byte	3
	.byte	$41,$62,$e2
;
;		**** A=s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10075
	.byte	0
	.byte	6
	.byte	$c1,$bd,$f3,$db,$d9,$dd
;
;		**** A=s ****
;
	.byte	9
	.byte	'M'
	.word	L10076
	.byte	0
	.byte	3
	.byte	$c1,$bd,$f3
;
;		**** A=c ****
;
	.byte	9
	.byte	'M'
	.word	L10077
	.byte	0
	.byte	3
	.byte	$c1,$bd,$e3
;
;		**** A=b ****
;
	.byte	9
	.byte	'M'
	.word	L10078
	.byte	0
	.byte	3
	.byte	$c1,$bd,$e2
;
;		**** A=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10079
	.byte	0
	.byte	3
	.byte	$c1,$bd,$d9
;
;		**** A=R ****
;
	.byte	9
	.byte	'M'
	.word	L10080
	.byte	0
	.byte	3
	.byte	$c1,$bd,$d2
;
;		**** A:s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10081
	.byte	0
	.byte	6
	.byte	$c1,$ba,$f3,$db,$d9,$dd
;
;		**** A:s ****
;
	.byte	9
	.byte	'M'
	.word	L10082
	.byte	0
	.byte	3
	.byte	$c1,$ba,$f3
;
;		**** A:c ****
;
	.byte	9
	.byte	'M'
	.word	L10083
	.byte	0
	.byte	3
	.byte	$c1,$ba,$e3
;
;		**** A:b ****
;
	.byte	9
	.byte	'M'
	.word	L10084
	.byte	0
	.byte	3
	.byte	$c1,$ba,$e2
;
;		**** A.FOR ****
;
	.byte	11
	.byte	'M'
	.word	L10085
	.byte	0
	.byte	5
	.byte	$41,$2e,$46,$4f,$d2
;
;		**** A-s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10086
	.byte	0
	.byte	6
	.byte	$c1,$ad,$f3,$db,$d9,$dd
;
;		**** A-s ****
;
	.byte	9
	.byte	'M'
	.word	L10087
	.byte	0
	.byte	3
	.byte	$c1,$ad,$f3
;
;		**** A-c ****
;
	.byte	9
	.byte	'M'
	.word	L10088
	.byte	0
	.byte	3
	.byte	$c1,$ad,$e3
;
;		**** A-b ****
;
	.byte	9
	.byte	'M'
	.word	L10089
	.byte	0
	.byte	3
	.byte	$c1,$ad,$e2
;
;		**** A+s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10090
	.byte	0
	.byte	6
	.byte	$c1,$ab,$f3,$db,$d9,$dd
;
;		**** A+s ****
;
	.byte	9
	.byte	'M'
	.word	L10091
	.byte	0
	.byte	3
	.byte	$c1,$ab,$f3
;
;		**** A+c ****
;
	.byte	9
	.byte	'M'
	.word	L10092
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e3
;
;		**** A+b ****
;
	.byte	9
	.byte	'M'
	.word	L10093
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e2
;
;		**** A&s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10094
	.byte	0
	.byte	6
	.byte	$c1,$a6,$f3,$db,$d9,$dd
;
;		**** A&s ****
;
	.byte	9
	.byte	'M'
	.word	L10095
	.byte	0
	.byte	3
	.byte	$c1,$a6,$f3
;
;		**** A&c ****
;
	.byte	9
	.byte	'M'
	.word	L10096
	.byte	0
	.byte	3
	.byte	$c1,$a6,$e3
;
;		**** A&b ****
;
	.byte	9
	.byte	'M'
	.word	L10097
	.byte	0
	.byte	3
	.byte	$c1,$a6,$e2
;
	.byte	$00
