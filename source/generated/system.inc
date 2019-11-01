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
;		** ^r  pha:* [^RPHA] **
;
L10011:
	.byte L10011_END-L10011-1
	txa
	eor  #$ff
	tax
	pla
	eor  #$ff
L10011_END:
;
;		** ^a:* [^A] **
;
L10012:
	.byte L10012_END-L10012-1
	eor  #$ff
L10012_END:
;
;		** y>s:* [Y>S] **
;
L10013:
	.byte L10013_END-L10013-1
	phy
L10013_END:
;
;		** y = *:S [Y=s] **
;
L10014:
	.byte L10014_END-L10014-1
	ldy  $63
L10014_END:
;
;		** y = *:C [Y=c] **
;
L10015:
	.byte L10015_END-L10015-1
	ldy  $7363
L10015_END:
;
;		** y = *:B [Y=b] **
;
L10016:
	.byte L10016_END-L10016-1
	ldy  #$63
L10016_END:
;
;		** y=r:* [Y=R] **
;
L10017:
	.byte L10017_END-L10017-1
	tay
L10017_END:
;
;		** y=a:* [Y=A] **
;
L10018:
	.byte L10018_END-L10018-1
	tay
L10018_END:
;
;		** word:* [WORD] **
;
L10019:
	.byte L10019_END-L10019-1
	.byte $a3,$01
L10019_END:
;
;		** until:* [UNTIL] **
;
L10020:
	.byte L10020_END-L10020-1
	.byte $a3,$02
L10020_END:
;
;		** s>y:* [S>Y] **
;
L10021:
	.byte L10021_END-L10021-1
	ply
L10021_END:
;
;		** s>ray:* [S>RAY] **
;
L10022:
	.byte L10022_END-L10022-1
	ply
	plx
	pla
L10022_END:
;
;		** s>r:* [S>R] **
;
L10023:
	.byte L10023_END-L10023-1
	plx
	pla
L10023_END:
;
;		** s>a:* [S>A] **
;
L10024:
	.byte L10024_END-L10024-1
	pla
L10024_END:
;
;		** r**:W [Rww] **
;
L10025:
	.byte L10025_END-L10025-1
	eor  #$63
	pha
	txa
	eor  #$73
	tax
	pla
L10025_END:
;
;		** r * *[y]:S [Rss[Y]] **
;
L10026:
	.byte L10026_END-L10026-1
	eor  ($63),y
	pha
	txa
	iny
	eor  ($63),y
	dey
	tax
	pla
L10026_END:
;
;		** r**:S [Rss] **
;
L10027:
	.byte L10027_END-L10027-1
	eor  $63
L10027_END:
;
;		** r**:L [Rll] **
;
L10028:
	.byte L10028_END-L10028-1
	eor  $7363
	pha
	txa
	eor  $7383
	tax
	pla
L10028_END:
;
;		** r**:I [Rii] **
;
L10029:
	.byte L10029_END-L10029-1
	eor  $63
	pha
	txa
	eor  $83
	tax
	pla
L10029_END:
;
;		** r**:C [Rcc] **
;
L10030:
	.byte L10030_END-L10030-1
	eor  $7363
L10030_END:
;
;		** r**:B [Rbb] **
;
L10031:
	.byte L10031_END-L10031-1
	eor  #$63
L10031_END:
;
;		** repeat:* [REPEAT] **
;
L10032:
	.byte L10032_END-L10032-1
	.byte $a3,$03
L10032_END:
;
;		** remove.locals:* [REMOVE.LOCALS] **
;
L10033:
	.byte L10033_END-L10033-1
	.byte $a3,$04
L10033_END:
;
;		** ray>s:* [RAY>S] **
;
L10034:
	.byte L10034_END-L10034-1
	pha
	phx
	phy
L10034_END:
;
;		** r>s:* [R>S] **
;
L10035:
	.byte L10035_END-L10035-1
	pha
	phx
L10035_END:
;
;		** r = *:W [R=w] **
;
L10036:
	.byte L10036_END-L10036-1
	lda  #$63
	ldx  #$73
L10036_END:
;
;		** r = *[y]:S [R=s[Y]] **
;
L10037:
	.byte L10037_END-L10037-1
	iny
	lda  ($63),y
	tax
	dey
	lda  ($63),y
L10037_END:
;
;		** r = *:S [R=s] **
;
L10038:
	.byte L10038_END-L10038-1
	lda  $63
	ldx  #0
L10038_END:
;
;		** r = *:L [R=l] **
;
L10039:
	.byte L10039_END-L10039-1
	lda  $7363
	ldx  $7383
L10039_END:
;
;		** r = *:I [R=i] **
;
L10040:
	.byte L10040_END-L10040-1
	lda  $63
	ldx  $83
L10040_END:
;
;		** r = *:C [R=c] **
;
L10041:
	.byte L10041_END-L10041-1
	lda  $7363
	ldx  #0
L10041_END:
;
;		** r = *:B [R=b] **
;
L10042:
	.byte L10042_END-L10042-1
	lda  #$63
	ldx  #$73
L10042_END:
;
;		** r=y:* [R=Y] **
;
L10043:
	.byte L10043_END-L10043-1
	tya
	ldx  #0
L10043_END:
;
;		** r=a:* [R=A] **
;
L10044:
	.byte L10044_END-L10044-1
	ldx  #0
L10044_END:
;
;		** r:*:W [R:w] **
;
L10045:
	.byte L10045_END-L10045-1
	ora  #$63
	pha
	txa
	ora  #$73
	tax
	pla
L10045_END:
;
;		** r : *[y]:S [R:s[Y]] **
;
L10046:
	.byte L10046_END-L10046-1
	ora  ($63),y
	pha
	txa
	iny
	ora  ($63),y
	dey
	tax
	pla
L10046_END:
;
;		** r:*:S [R:s] **
;
L10047:
	.byte L10047_END-L10047-1
	ora  $63
L10047_END:
;
;		** r:*:L [R:l] **
;
L10048:
	.byte L10048_END-L10048-1
	ora  $7363
	pha
	txa
	ora  $7383
	tax
	pla
L10048_END:
;
;		** r:*:I [R:i] **
;
L10049:
	.byte L10049_END-L10049-1
	ora  $63
	pha
	txa
	ora  $83
	tax
	pla
L10049_END:
;
;		** r:*:C [R:c] **
;
L10050:
	.byte L10050_END-L10050-1
	ora  $7363
L10050_END:
;
;		** r:*:B [R:b] **
;
L10051:
	.byte L10051_END-L10051-1
	ora  #$63
L10051_END:
;
;		** r-*:W [R-w] **
;
L10052:
	.byte L10052_END-L10052-1
	sec
	sbc  #$63
	pha
	txa
	sbc  #$73
	tax
	pla
L10052_END:
;
;		** r - *[y]:S [R-s[Y]] **
;
L10053:
	.byte L10053_END-L10053-1
	sec
	sbc  ($63),y
	pha
	txa
	iny
	sbc  ($63),y
	dey
	tax
	pla
L10053_END:
;
;		** r-*:S [R-s] **
;
L10054:
	.byte L10054_END-L10054-1
	sec
	sbc  $63
	bcs  *+3
	dex
L10054_END:
;
;		** r-*:L [R-l] **
;
L10055:
	.byte L10055_END-L10055-1
	sec
	sbc  $7363
	pha
	txa
	sbc  $7383
	tax
	pla
L10055_END:
;
;		** r-*:I [R-i] **
;
L10056:
	.byte L10056_END-L10056-1
	sec
	sbc  $63
	pha
	txa
	sbc  $83
	tax
	pla
L10056_END:
;
;		** r-*:C [R-c] **
;
L10057:
	.byte L10057_END-L10057-1
	sec
	sbc  $7363
	bcs  *+3
	dex
L10057_END:
;
;		** r-*:B [R-b] **
;
L10058:
	.byte L10058_END-L10058-1
	sec
	sbc  #$63
	bcs  *+3
	dex
L10058_END:
;
;		** r+*:W [R+w] **
;
L10059:
	.byte L10059_END-L10059-1
	clc
	adc  #$63
	pha
	txa
	adc  #$73
	tax
	pla
L10059_END:
;
;		** r + *[y]:S [R+s[Y]] **
;
L10060:
	.byte L10060_END-L10060-1
	clc
	adc  ($63),y
	pha
	txa
	iny
	adc  ($63),y
	dey
	tax
	pla
L10060_END:
;
;		** r+*:S [R+s] **
;
L10061:
	.byte L10061_END-L10061-1
	clc
	adc  $63
	bcc  *+3
	inx
L10061_END:
;
;		** r+*:L [R+l] **
;
L10062:
	.byte L10062_END-L10062-1
	clc
	adc  $7363
	pha
	txa
	adc  $7383
	tax
	pla
L10062_END:
;
;		** r+*:I [R+i] **
;
L10063:
	.byte L10063_END-L10063-1
	clc
	adc  $63
	pha
	txa
	adc  $83
	tax
	pla
L10063_END:
;
;		** r+*:C [R+c] **
;
L10064:
	.byte L10064_END-L10064-1
	clc
	adc  $7363
	bcc  *+3
	inx
L10064_END:
;
;		** r+*:B [R+b] **
;
L10065:
	.byte L10065_END-L10065-1
	clc
	adc  #$63
	bcc  *+3
	inx
L10065_END:
;
;		** r&*:W [R&w] **
;
L10066:
	.byte L10066_END-L10066-1
	and  #$63
	pha
	txa
	and  #$73
	tax
	pla
L10066_END:
;
;		** r & *[y]:S [R&s[Y]] **
;
L10067:
	.byte L10067_END-L10067-1
	and  ($63),y
	pha
	txa
	iny
	and  ($63),y
	dey
	tax
	pla
L10067_END:
;
;		** r&*:S [R&s] **
;
L10068:
	.byte L10068_END-L10068-1
	and  $63
	ldx  #0
L10068_END:
;
;		** r&*:L [R&l] **
;
L10069:
	.byte L10069_END-L10069-1
	and  $7363
	pha
	txa
	and  $7383
	tax
	pla
L10069_END:
;
;		** r&*:I [R&i] **
;
L10070:
	.byte L10070_END-L10070-1
	and  $63
	pha
	txa
	and  $83
	tax
	pla
L10070_END:
;
;		** r&*:C [R&c] **
;
L10071:
	.byte L10071_END-L10071-1
	and  $7363
	ldx  #0
L10071_END:
;
;		** r&*:B [R&b] **
;
L10072:
	.byte L10072_END-L10072-1
	and  #$63
	ldx  #0
L10072_END:
;
;		** proc:* [PROC] **
;
L10073:
	.byte L10073_END-L10073-1
	.byte $a3,$05
L10073_END:
;
;		** next:* [NEXT] **
;
L10074:
	.byte L10074_END-L10074-1
	.byte $a3,$06
L10074_END:
;
;		** if:* [IF] **
;
L10075:
	.byte L10075_END-L10075-1
	.byte $a3,$07
L10075_END:
;
;		** endproc:* [ENDPROC] **
;
L10076:
	.byte L10076_END-L10076-1
	.byte $a3,$08
L10076_END:
;
;		** endif:* [ENDIF] **
;
L10077:
	.byte L10077_END-L10077-1
	.byte $a3,$09
L10077_END:
;
;		** else:* [ELSE] **
;
L10078:
	.byte L10078_END-L10078-1
	.byte $a3,$0a
L10078_END:
;
;		** byte:* [BYTE] **
;
L10079:
	.byte L10079_END-L10079-1
	.byte $a3,$0b
L10079_END:
;
;		** a * *[y]:S [Ass[Y]] **
;
L10080:
	.byte L10080_END-L10080-1
	eor  ($63),y
L10080_END:
;
;		** a**:S [Ass] **
;
L10081:
	.byte L10081_END-L10081-1
	eor  $63
L10081_END:
;
;		** a**:C [Acc] **
;
L10082:
	.byte L10082_END-L10082-1
	eor  $7363
L10082_END:
;
;		** a**:B [Abb] **
;
L10083:
	.byte L10083_END-L10083-1
	eor  #$63
L10083_END:
;
;		** a>s:* [A>S] **
;
L10084:
	.byte L10084_END-L10084-1
	pha
L10084_END:
;
;		** a = *[y]:S [A=s[Y]] **
;
L10085:
	.byte L10085_END-L10085-1
	lda  ($63),y
L10085_END:
;
;		** a = *:S [A=s] **
;
L10086:
	.byte L10086_END-L10086-1
	lda  $63
L10086_END:
;
;		** a = *:C [A=c] **
;
L10087:
	.byte L10087_END-L10087-1
	lda  $7363
L10087_END:
;
;		** a = *:B [A=b] **
;
L10088:
	.byte L10088_END-L10088-1
	lda  #$63
L10088_END:
;
;		** a=y:* [A=Y] **
;
L10089:
	.byte L10089_END-L10089-1
	tya
L10089_END:
;
;		** a=r:* [A=R] **
;
L10090:
	.byte L10090_END-L10090-1
L10090_END:
;
;		** a : *[y]:S [A:s[Y]] **
;
L10091:
	.byte L10091_END-L10091-1
	ora  ($63),y
L10091_END:
;
;		** a:*:S [A:s] **
;
L10092:
	.byte L10092_END-L10092-1
	ora  $63
L10092_END:
;
;		** a:*:C [A:c] **
;
L10093:
	.byte L10093_END-L10093-1
	ora  $7363
L10093_END:
;
;		** a:*:B [A:b] **
;
L10094:
	.byte L10094_END-L10094-1
	ora  #$63
L10094_END:
;
;		** a.for:* [A.FOR] **
;
L10095:
	.byte L10095_END-L10095-1
	.byte $a3,$0c
L10095_END:
;
;		** a - *[y]:S [A-s[Y]] **
;
L10096:
	.byte L10096_END-L10096-1
	sec
	sbc  ($63),y
L10096_END:
;
;		** a-*:S [A-s] **
;
L10097:
	.byte L10097_END-L10097-1
	sec
	sbc  $63
L10097_END:
;
;		** a-*:C [A-c] **
;
L10098:
	.byte L10098_END-L10098-1
	sec
	sbc  $7363
L10098_END:
;
;		** a-*:B [A-b] **
;
L10099:
	.byte L10099_END-L10099-1
	sec
	sbc  #$63
L10099_END:
;
;		** a + *[y]:S [A+s[Y]] **
;
L10100:
	.byte L10100_END-L10100-1
	clc
	adc  ($63),y
L10100_END:
;
;		** a+*:S [A+s] **
;
L10101:
	.byte L10101_END-L10101-1
	clc
	adc  $63
L10101_END:
;
;		** a+*:C [A+c] **
;
L10102:
	.byte L10102_END-L10102-1
	clc
	adc  $7363
L10102_END:
;
;		** a+*:B [A+b] **
;
L10103:
	.byte L10103_END-L10103-1
	clc
	adc  #$63
L10103_END:
;
;		** a & *[y]:S [A&s[Y]] **
;
L10104:
	.byte L10104_END-L10104-1
	and  ($63),y
L10104_END:
;
;		** a&*:S [A&s] **
;
L10105:
	.byte L10105_END-L10105-1
	and  $63
L10105_END:
;
;		** a&*:C [A&c] **
;
L10106:
	.byte L10106_END-L10106-1
	and  $7363
L10106_END:
;
;		** a&*:B [A&b] **
;
L10107:
	.byte L10107_END-L10107-1
	and  #$63
L10107_END:
;
;		** >>r:* [>>R] **
;
L10108:
	.byte L10108_END-L10108-1
	pha
	txa
	lsr  a
	tax
	pla
	ror  a
L10108_END:
;
;		** >>a:* [>>A] **
;
L10109:
	.byte L10109_END-L10109-1
	lsr  a
L10109_END:
;
;		** <<r:* [<<R] **
;
L10110:
	.byte L10110_END-L10110-1
	asl  a
	pha
	txa
	rol  a
	tax
	pla
L10110_END:
;
;		** <<a:* [<<A] **
;
L10111:
	.byte L10111_END-L10111-1
	asl  a
L10111_END:
;
;		** -r  pha:* [-RPHA] **
;
L10112:
	.byte L10112_END-L10112-1
	txa
	eor  #$ff
	tax
	pla
	eor  #$ff
	inc  a
	bne  *+3
	inx
L10112_END:
;
;		** -a:* [-A] **
;
L10113:
	.byte L10113_END-L10113-1
	eor  #$ff
	inc  a
L10113_END:
;
;		** --y:* [--Y] **
;
L10114:
	.byte L10114_END-L10114-1
	dey
L10114_END:
;
;		** --r:* [--R] **
;
L10115:
	.byte L10115_END-L10115-1
	cmp  #0
	bne  *+3
	dex
	dec  a
L10115_END:
;
;		** --a:* [--A] **
;
L10116:
	.byte L10116_END-L10116-1
	dec  a
L10116_END:
;
;		** ++y:* [++Y] **
;
L10117:
	.byte L10117_END-L10117-1
	iny
L10117_END:
;
;		** ++r:* [++R] **
;
L10118:
	.byte L10118_END-L10118-1
	inc  a
	bne  *+3
	inx
L10118_END:
;
;		** ++a:* [++A] **
;
L10119:
	.byte L10119_END-L10119-1
	inc  a
L10119_END:
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
;		**** ^RPHA ****
;
	.byte	11
	.byte	'M'
	.word	L10011
	.byte	0
	.byte	5
	.byte	$de,$52,$50,$48,$c1
;
;		**** ^A ****
;
	.byte	8
	.byte	'M'
	.word	L10012
	.byte	0
	.byte	2
	.byte	$de,$c1
;
;		**** Y>S ****
;
	.byte	9
	.byte	'M'
	.word	L10013
	.byte	0
	.byte	3
	.byte	$d9,$be,$d3
;
;		**** Y=s ****
;
	.byte	9
	.byte	'M'
	.word	L10014
	.byte	0
	.byte	3
	.byte	$d9,$bd,$f3
;
;		**** Y=c ****
;
	.byte	9
	.byte	'M'
	.word	L10015
	.byte	0
	.byte	3
	.byte	$d9,$bd,$e3
;
;		**** Y=b ****
;
	.byte	9
	.byte	'M'
	.word	L10016
	.byte	0
	.byte	3
	.byte	$d9,$bd,$e2
;
;		**** Y=R ****
;
	.byte	9
	.byte	'M'
	.word	L10017
	.byte	0
	.byte	3
	.byte	$d9,$bd,$d2
;
;		**** Y=A ****
;
	.byte	9
	.byte	'M'
	.word	L10018
	.byte	0
	.byte	3
	.byte	$d9,$bd,$c1
;
;		**** WORD ****
;
	.byte	10
	.byte	'M'
	.word	L10019
	.byte	0
	.byte	4
	.byte	$57,$4f,$52,$c4
;
;		**** UNTIL ****
;
	.byte	11
	.byte	'M'
	.word	L10020
	.byte	0
	.byte	5
	.byte	$55,$4e,$54,$49,$cc
;
;		**** S>Y ****
;
	.byte	9
	.byte	'M'
	.word	L10021
	.byte	0
	.byte	3
	.byte	$d3,$be,$d9
;
;		**** S>RAY ****
;
	.byte	11
	.byte	'M'
	.word	L10022
	.byte	0
	.byte	5
	.byte	$d3,$be,$52,$41,$d9
;
;		**** S>R ****
;
	.byte	9
	.byte	'M'
	.word	L10023
	.byte	0
	.byte	3
	.byte	$d3,$be,$d2
;
;		**** S>A ****
;
	.byte	9
	.byte	'M'
	.word	L10024
	.byte	0
	.byte	3
	.byte	$d3,$be,$c1
;
;		**** Rww ****
;
	.byte	9
	.byte	'M'
	.word	L10025
	.byte	0
	.byte	3
	.byte	$52,$77,$f7
;
;		**** Rss[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10026
	.byte	0
	.byte	6
	.byte	$52,$73,$f3,$db,$d9,$dd
;
;		**** Rss ****
;
	.byte	9
	.byte	'M'
	.word	L10027
	.byte	0
	.byte	3
	.byte	$52,$73,$f3
;
;		**** Rll ****
;
	.byte	9
	.byte	'M'
	.word	L10028
	.byte	0
	.byte	3
	.byte	$52,$6c,$ec
;
;		**** Rii ****
;
	.byte	9
	.byte	'M'
	.word	L10029
	.byte	0
	.byte	3
	.byte	$52,$69,$e9
;
;		**** Rcc ****
;
	.byte	9
	.byte	'M'
	.word	L10030
	.byte	0
	.byte	3
	.byte	$52,$63,$e3
;
;		**** Rbb ****
;
	.byte	9
	.byte	'M'
	.word	L10031
	.byte	0
	.byte	3
	.byte	$52,$62,$e2
;
;		**** REPEAT ****
;
	.byte	12
	.byte	'M'
	.word	L10032
	.byte	0
	.byte	6
	.byte	$52,$45,$50,$45,$41,$d4
;
;		**** REMOVE.LOCALS ****
;
	.byte	19
	.byte	'M'
	.word	L10033
	.byte	0
	.byte	13
	.byte	$52,$45,$4d,$4f,$56,$45,$2e,$4c,$4f,$43,$41,$4c,$d3
;
;		**** RAY>S ****
;
	.byte	11
	.byte	'M'
	.word	L10034
	.byte	0
	.byte	5
	.byte	$52,$41,$d9,$be,$d3
;
;		**** R>S ****
;
	.byte	9
	.byte	'M'
	.word	L10035
	.byte	0
	.byte	3
	.byte	$d2,$be,$d3
;
;		**** R=w ****
;
	.byte	9
	.byte	'M'
	.word	L10036
	.byte	0
	.byte	3
	.byte	$d2,$bd,$f7
;
;		**** R=s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10037
	.byte	0
	.byte	6
	.byte	$d2,$bd,$f3,$db,$d9,$dd
;
;		**** R=s ****
;
	.byte	9
	.byte	'M'
	.word	L10038
	.byte	0
	.byte	3
	.byte	$d2,$bd,$f3
;
;		**** R=l ****
;
	.byte	9
	.byte	'M'
	.word	L10039
	.byte	0
	.byte	3
	.byte	$d2,$bd,$ec
;
;		**** R=i ****
;
	.byte	9
	.byte	'M'
	.word	L10040
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e9
;
;		**** R=c ****
;
	.byte	9
	.byte	'M'
	.word	L10041
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e3
;
;		**** R=b ****
;
	.byte	9
	.byte	'M'
	.word	L10042
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e2
;
;		**** R=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10043
	.byte	0
	.byte	3
	.byte	$d2,$bd,$d9
;
;		**** R=A ****
;
	.byte	9
	.byte	'M'
	.word	L10044
	.byte	0
	.byte	3
	.byte	$d2,$bd,$c1
;
;		**** R:w ****
;
	.byte	9
	.byte	'M'
	.word	L10045
	.byte	0
	.byte	3
	.byte	$d2,$ba,$f7
;
;		**** R:s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10046
	.byte	0
	.byte	6
	.byte	$d2,$ba,$f3,$db,$d9,$dd
;
;		**** R:s ****
;
	.byte	9
	.byte	'M'
	.word	L10047
	.byte	0
	.byte	3
	.byte	$d2,$ba,$f3
;
;		**** R:l ****
;
	.byte	9
	.byte	'M'
	.word	L10048
	.byte	0
	.byte	3
	.byte	$d2,$ba,$ec
;
;		**** R:i ****
;
	.byte	9
	.byte	'M'
	.word	L10049
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e9
;
;		**** R:c ****
;
	.byte	9
	.byte	'M'
	.word	L10050
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e3
;
;		**** R:b ****
;
	.byte	9
	.byte	'M'
	.word	L10051
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e2
;
;		**** R-w ****
;
	.byte	9
	.byte	'M'
	.word	L10052
	.byte	0
	.byte	3
	.byte	$d2,$ad,$f7
;
;		**** R-s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10053
	.byte	0
	.byte	6
	.byte	$d2,$ad,$f3,$db,$d9,$dd
;
;		**** R-s ****
;
	.byte	9
	.byte	'M'
	.word	L10054
	.byte	0
	.byte	3
	.byte	$d2,$ad,$f3
;
;		**** R-l ****
;
	.byte	9
	.byte	'M'
	.word	L10055
	.byte	0
	.byte	3
	.byte	$d2,$ad,$ec
;
;		**** R-i ****
;
	.byte	9
	.byte	'M'
	.word	L10056
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e9
;
;		**** R-c ****
;
	.byte	9
	.byte	'M'
	.word	L10057
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e3
;
;		**** R-b ****
;
	.byte	9
	.byte	'M'
	.word	L10058
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e2
;
;		**** R+w ****
;
	.byte	9
	.byte	'M'
	.word	L10059
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f7
;
;		**** R+s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10060
	.byte	0
	.byte	6
	.byte	$d2,$ab,$f3,$db,$d9,$dd
;
;		**** R+s ****
;
	.byte	9
	.byte	'M'
	.word	L10061
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f3
;
;		**** R+l ****
;
	.byte	9
	.byte	'M'
	.word	L10062
	.byte	0
	.byte	3
	.byte	$d2,$ab,$ec
;
;		**** R+i ****
;
	.byte	9
	.byte	'M'
	.word	L10063
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e9
;
;		**** R+c ****
;
	.byte	9
	.byte	'M'
	.word	L10064
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e3
;
;		**** R+b ****
;
	.byte	9
	.byte	'M'
	.word	L10065
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e2
;
;		**** R&w ****
;
	.byte	9
	.byte	'M'
	.word	L10066
	.byte	0
	.byte	3
	.byte	$d2,$a6,$f7
;
;		**** R&s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10067
	.byte	0
	.byte	6
	.byte	$d2,$a6,$f3,$db,$d9,$dd
;
;		**** R&s ****
;
	.byte	9
	.byte	'M'
	.word	L10068
	.byte	0
	.byte	3
	.byte	$d2,$a6,$f3
;
;		**** R&l ****
;
	.byte	9
	.byte	'M'
	.word	L10069
	.byte	0
	.byte	3
	.byte	$d2,$a6,$ec
;
;		**** R&i ****
;
	.byte	9
	.byte	'M'
	.word	L10070
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e9
;
;		**** R&c ****
;
	.byte	9
	.byte	'M'
	.word	L10071
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e3
;
;		**** R&b ****
;
	.byte	9
	.byte	'M'
	.word	L10072
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e2
;
;		**** PROC ****
;
	.byte	10
	.byte	'M'
	.word	L10073
	.byte	0
	.byte	4
	.byte	$50,$52,$4f,$c3
;
;		**** NEXT ****
;
	.byte	10
	.byte	'M'
	.word	L10074
	.byte	0
	.byte	4
	.byte	$4e,$45,$58,$d4
;
;		**** IF ****
;
	.byte	8
	.byte	'M'
	.word	L10075
	.byte	0
	.byte	2
	.byte	$49,$c6
;
;		**** ENDPROC ****
;
	.byte	13
	.byte	'M'
	.word	L10076
	.byte	0
	.byte	7
	.byte	$45,$4e,$44,$50,$52,$4f,$c3
;
;		**** ENDIF ****
;
	.byte	11
	.byte	'M'
	.word	L10077
	.byte	0
	.byte	5
	.byte	$45,$4e,$44,$49,$c6
;
;		**** ELSE ****
;
	.byte	10
	.byte	'M'
	.word	L10078
	.byte	0
	.byte	4
	.byte	$45,$4c,$53,$c5
;
;		**** BYTE ****
;
	.byte	10
	.byte	'M'
	.word	L10079
	.byte	0
	.byte	4
	.byte	$42,$59,$54,$c5
;
;		**** Ass[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10080
	.byte	0
	.byte	6
	.byte	$41,$73,$f3,$db,$d9,$dd
;
;		**** Ass ****
;
	.byte	9
	.byte	'M'
	.word	L10081
	.byte	0
	.byte	3
	.byte	$41,$73,$f3
;
;		**** Acc ****
;
	.byte	9
	.byte	'M'
	.word	L10082
	.byte	0
	.byte	3
	.byte	$41,$63,$e3
;
;		**** Abb ****
;
	.byte	9
	.byte	'M'
	.word	L10083
	.byte	0
	.byte	3
	.byte	$41,$62,$e2
;
;		**** A>S ****
;
	.byte	9
	.byte	'M'
	.word	L10084
	.byte	0
	.byte	3
	.byte	$c1,$be,$d3
;
;		**** A=s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10085
	.byte	0
	.byte	6
	.byte	$c1,$bd,$f3,$db,$d9,$dd
;
;		**** A=s ****
;
	.byte	9
	.byte	'M'
	.word	L10086
	.byte	0
	.byte	3
	.byte	$c1,$bd,$f3
;
;		**** A=c ****
;
	.byte	9
	.byte	'M'
	.word	L10087
	.byte	0
	.byte	3
	.byte	$c1,$bd,$e3
;
;		**** A=b ****
;
	.byte	9
	.byte	'M'
	.word	L10088
	.byte	0
	.byte	3
	.byte	$c1,$bd,$e2
;
;		**** A=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10089
	.byte	0
	.byte	3
	.byte	$c1,$bd,$d9
;
;		**** A=R ****
;
	.byte	9
	.byte	'M'
	.word	L10090
	.byte	0
	.byte	3
	.byte	$c1,$bd,$d2
;
;		**** A:s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10091
	.byte	0
	.byte	6
	.byte	$c1,$ba,$f3,$db,$d9,$dd
;
;		**** A:s ****
;
	.byte	9
	.byte	'M'
	.word	L10092
	.byte	0
	.byte	3
	.byte	$c1,$ba,$f3
;
;		**** A:c ****
;
	.byte	9
	.byte	'M'
	.word	L10093
	.byte	0
	.byte	3
	.byte	$c1,$ba,$e3
;
;		**** A:b ****
;
	.byte	9
	.byte	'M'
	.word	L10094
	.byte	0
	.byte	3
	.byte	$c1,$ba,$e2
;
;		**** A.FOR ****
;
	.byte	11
	.byte	'M'
	.word	L10095
	.byte	0
	.byte	5
	.byte	$41,$2e,$46,$4f,$d2
;
;		**** A-s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10096
	.byte	0
	.byte	6
	.byte	$c1,$ad,$f3,$db,$d9,$dd
;
;		**** A-s ****
;
	.byte	9
	.byte	'M'
	.word	L10097
	.byte	0
	.byte	3
	.byte	$c1,$ad,$f3
;
;		**** A-c ****
;
	.byte	9
	.byte	'M'
	.word	L10098
	.byte	0
	.byte	3
	.byte	$c1,$ad,$e3
;
;		**** A-b ****
;
	.byte	9
	.byte	'M'
	.word	L10099
	.byte	0
	.byte	3
	.byte	$c1,$ad,$e2
;
;		**** A+s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10100
	.byte	0
	.byte	6
	.byte	$c1,$ab,$f3,$db,$d9,$dd
;
;		**** A+s ****
;
	.byte	9
	.byte	'M'
	.word	L10101
	.byte	0
	.byte	3
	.byte	$c1,$ab,$f3
;
;		**** A+c ****
;
	.byte	9
	.byte	'M'
	.word	L10102
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e3
;
;		**** A+b ****
;
	.byte	9
	.byte	'M'
	.word	L10103
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e2
;
;		**** A&s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10104
	.byte	0
	.byte	6
	.byte	$c1,$a6,$f3,$db,$d9,$dd
;
;		**** A&s ****
;
	.byte	9
	.byte	'M'
	.word	L10105
	.byte	0
	.byte	3
	.byte	$c1,$a6,$f3
;
;		**** A&c ****
;
	.byte	9
	.byte	'M'
	.word	L10106
	.byte	0
	.byte	3
	.byte	$c1,$a6,$e3
;
;		**** A&b ****
;
	.byte	9
	.byte	'M'
	.word	L10107
	.byte	0
	.byte	3
	.byte	$c1,$a6,$e2
;
;		**** >>R ****
;
	.byte	9
	.byte	'M'
	.word	L10108
	.byte	0
	.byte	3
	.byte	$be,$be,$d2
;
;		**** >>A ****
;
	.byte	9
	.byte	'M'
	.word	L10109
	.byte	0
	.byte	3
	.byte	$be,$be,$c1
;
;		**** <<R ****
;
	.byte	9
	.byte	'M'
	.word	L10110
	.byte	0
	.byte	3
	.byte	$bc,$bc,$d2
;
;		**** <<A ****
;
	.byte	9
	.byte	'M'
	.word	L10111
	.byte	0
	.byte	3
	.byte	$bc,$bc,$c1
;
;		**** -RPHA ****
;
	.byte	11
	.byte	'M'
	.word	L10112
	.byte	0
	.byte	5
	.byte	$ad,$52,$50,$48,$c1
;
;		**** -A ****
;
	.byte	8
	.byte	'M'
	.word	L10113
	.byte	0
	.byte	2
	.byte	$ad,$c1
;
;		**** --Y ****
;
	.byte	9
	.byte	'M'
	.word	L10114
	.byte	0
	.byte	3
	.byte	$ad,$ad,$d9
;
;		**** --R ****
;
	.byte	9
	.byte	'M'
	.word	L10115
	.byte	0
	.byte	3
	.byte	$ad,$ad,$d2
;
;		**** --A ****
;
	.byte	9
	.byte	'M'
	.word	L10116
	.byte	0
	.byte	3
	.byte	$ad,$ad,$c1
;
;		**** ++Y ****
;
	.byte	9
	.byte	'M'
	.word	L10117
	.byte	0
	.byte	3
	.byte	$ab,$ab,$d9
;
;		**** ++R ****
;
	.byte	9
	.byte	'M'
	.word	L10118
	.byte	0
	.byte	3
	.byte	$ab,$ab,$d2
;
;		**** ++A ****
;
	.byte	9
	.byte	'M'
	.word	L10119
	.byte	0
	.byte	3
	.byte	$ab,$ab,$c1
;
	.byte	$00
