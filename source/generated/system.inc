;
;		Automatically generated.
;
;
;		** *:W [w] **
;
L10000:
	.byte L10000_END-L10000-1
	lda  #$63
	ldx  #$73
L10000_END:
;
;		** *[y] = r:S [s[Y]=R] **
;
L10001:
	.byte L10001_END-L10001-1
	sta  ($63),y
	iny
	txa
	sta  ($63),y
	dey
	lda  ($63),y
L10001_END:
;
;		** *[y] = a:S [s[Y]=A] **
;
L10002:
	.byte L10002_END-L10002-1
	sta  ($63),y
L10002_END:
;
;		** * = y:S [s=Y] **
;
L10003:
	.byte L10003_END-L10003-1
	sty  $63
L10003_END:
;
;		** * = r:S [s=R] **
;
L10004:
	.byte L10004_END-L10004-1
	sta  $63
L10004_END:
;
;		** * = a:S [s=A] **
;
L10005:
	.byte L10005_END-L10005-1
	sta  $63
L10005_END:
;
;		** *:S [s] **
;
L10006:
	.byte L10006_END-L10006-1
	lda  $63
	ldx  #0
L10006_END:
;
;		** *:P [p] **
;
L10007:
	.byte L10007_END-L10007-1
	.byte $a3,$00
L10007_END:
;
;		** * = r:L [l=R] **
;
L10008:
	.byte L10008_END-L10008-1
	sta  $7363
	stx  $7383
L10008_END:
;
;		** *:L [l] **
;
L10009:
	.byte L10009_END-L10009-1
	lda  $7363
	ldx  $7383
L10009_END:
;
;		** * = r:I [i=R] **
;
L10010:
	.byte L10010_END-L10010-1
	sta  $63
	stx  $83
L10010_END:
;
;		** *:I [i] **
;
L10011:
	.byte L10011_END-L10011-1
	lda  $63
	ldx  $83
L10011_END:
;
;		** * = y:C [c=Y] **
;
L10012:
	.byte L10012_END-L10012-1
	sty  $7363
L10012_END:
;
;		** * = r:C [c=R] **
;
L10013:
	.byte L10013_END-L10013-1
	sta  $7363
L10013_END:
;
;		** * = a:C [c=A] **
;
L10014:
	.byte L10014_END-L10014-1
	sta  $7363
L10014_END:
;
;		** *:C [c] **
;
L10015:
	.byte L10015_END-L10015-1
	lda  $7363
	ldx  #0
L10015_END:
;
;		** *:B [b] **
;
L10016:
	.byte L10016_END-L10016-1
	lda  #$63
	ldx  #$73
L10016_END:
;
;		** ^r  pha:* [^RPHA] **
;
L10017:
	.byte L10017_END-L10017-1
	txa
	eor  #$ff
	tax
	pla
	eor  #$ff
L10017_END:
;
;		** ^a:* [^A] **
;
L10018:
	.byte L10018_END-L10018-1
	eor  #$ff
L10018_END:
;
;		** y = *:S [Y=s] **
;
L10019:
	.byte L10019_END-L10019-1
	ldy  $63
L10019_END:
;
;		** y = *:C [Y=c] **
;
L10020:
	.byte L10020_END-L10020-1
	ldy  $7363
L10020_END:
;
;		** y = *:B [Y=b] **
;
L10021:
	.byte L10021_END-L10021-1
	ldy  #$63
L10021_END:
;
;		** y=r:* [Y=R] **
;
L10022:
	.byte L10022_END-L10022-1
	tay
L10022_END:
;
;		** y=a:* [Y=A] **
;
L10023:
	.byte L10023_END-L10023-1
	tay
L10023_END:
;
;		** y->s:* [Y->S] **
;
L10024:
	.byte L10024_END-L10024-1
	phy
L10024_END:
;
;		** word:* [WORD] **
;
L10025:
	.byte L10025_END-L10025-1
	.byte $a3,$01
L10025_END:
;
;		** until:* [UNTIL] **
;
L10026:
	.byte L10026_END-L10026-1
	.byte $a3,$02
L10026_END:
;
;		** s->y:* [S->Y] **
;
L10027:
	.byte L10027_END-L10027-1
	ply
L10027_END:
;
;		** s->ray:* [S->RAY] **
;
L10028:
	.byte L10028_END-L10028-1
	ply
	plx
	pla
L10028_END:
;
;		** s->r:* [S->R] **
;
L10029:
	.byte L10029_END-L10029-1
	plx
	pla
L10029_END:
;
;		** s->a:* [S->A] **
;
L10030:
	.byte L10030_END-L10030-1
	pla
L10030_END:
;
;		** r**:W [Rww] **
;
L10031:
	.byte L10031_END-L10031-1
	eor  #$63
	pha
	txa
	eor  #$73
	tax
	pla
L10031_END:
;
;		** r * *[y]:S [Rss[Y]] **
;
L10032:
	.byte L10032_END-L10032-1
	eor  ($63),y
	pha
	txa
	iny
	eor  ($63),y
	dey
	tax
	pla
L10032_END:
;
;		** r**:S [Rss] **
;
L10033:
	.byte L10033_END-L10033-1
	eor  $63
L10033_END:
;
;		** r**:L [Rll] **
;
L10034:
	.byte L10034_END-L10034-1
	eor  $7363
	pha
	txa
	eor  $7383
	tax
	pla
L10034_END:
;
;		** r**:I [Rii] **
;
L10035:
	.byte L10035_END-L10035-1
	eor  $63
	pha
	txa
	eor  $83
	tax
	pla
L10035_END:
;
;		** r**:C [Rcc] **
;
L10036:
	.byte L10036_END-L10036-1
	eor  $7363
L10036_END:
;
;		** r**:B [Rbb] **
;
L10037:
	.byte L10037_END-L10037-1
	eor  #$63
L10037_END:
;
;		** repeat:* [REPEAT] **
;
L10038:
	.byte L10038_END-L10038-1
	.byte $a3,$03
L10038_END:
;
;		** remove.locals:* [REMOVE.LOCALS] **
;
L10039:
	.byte L10039_END-L10039-1
	.byte $a3,$04
L10039_END:
;
;		** ray->s:* [RAY->S] **
;
L10040:
	.byte L10040_END-L10040-1
	pha
	phx
	phy
L10040_END:
;
;		** r = *:W [R=w] **
;
L10041:
	.byte L10041_END-L10041-1
	lda  #$63
	ldx  #$73
L10041_END:
;
;		** r = *[y]:S [R=s[Y]] **
;
L10042:
	.byte L10042_END-L10042-1
	iny
	lda  ($63),y
	tax
	dey
	lda  ($63),y
L10042_END:
;
;		** r = *:S [R=s] **
;
L10043:
	.byte L10043_END-L10043-1
	lda  $63
	ldx  #0
L10043_END:
;
;		** r = *:L [R=l] **
;
L10044:
	.byte L10044_END-L10044-1
	lda  $7363
	ldx  $7383
L10044_END:
;
;		** r = *:I [R=i] **
;
L10045:
	.byte L10045_END-L10045-1
	lda  $63
	ldx  $83
L10045_END:
;
;		** r = *:C [R=c] **
;
L10046:
	.byte L10046_END-L10046-1
	lda  $7363
	ldx  #0
L10046_END:
;
;		** r = *:B [R=b] **
;
L10047:
	.byte L10047_END-L10047-1
	lda  #$63
	ldx  #$73
L10047_END:
;
;		** r=y:* [R=Y] **
;
L10048:
	.byte L10048_END-L10048-1
	tya
	ldx  #0
L10048_END:
;
;		** r=a:* [R=A] **
;
L10049:
	.byte L10049_END-L10049-1
	ldx  #0
L10049_END:
;
;		** r=?:* [R=?] **
;
L10050:
	.byte L10050_END-L10050-1
	cmp #0
	bne *+4
	cpx #0
	.byte $93
	beq *
L10050_END:
;
;		** r<>?:* [R<>?] **
;
L10051:
	.byte L10051_END-L10051-1
	cmp #0
	bne *+4
	cpx #0
	.byte $93
	bne *
L10051_END:
;
;		** r:*:W [R:w] **
;
L10052:
	.byte L10052_END-L10052-1
	ora  #$63
	pha
	txa
	ora  #$73
	tax
	pla
L10052_END:
;
;		** r : *[y]:S [R:s[Y]] **
;
L10053:
	.byte L10053_END-L10053-1
	ora  ($63),y
	pha
	txa
	iny
	ora  ($63),y
	dey
	tax
	pla
L10053_END:
;
;		** r:*:S [R:s] **
;
L10054:
	.byte L10054_END-L10054-1
	ora  $63
L10054_END:
;
;		** r:*:L [R:l] **
;
L10055:
	.byte L10055_END-L10055-1
	ora  $7363
	pha
	txa
	ora  $7383
	tax
	pla
L10055_END:
;
;		** r:*:I [R:i] **
;
L10056:
	.byte L10056_END-L10056-1
	ora  $63
	pha
	txa
	ora  $83
	tax
	pla
L10056_END:
;
;		** r:*:C [R:c] **
;
L10057:
	.byte L10057_END-L10057-1
	ora  $7363
L10057_END:
;
;		** r:*:B [R:b] **
;
L10058:
	.byte L10058_END-L10058-1
	ora  #$63
L10058_END:
;
;		** r.swap:* [R.SWAP] **
;
L10059:
	.byte L10059_END-L10059-1
	pha
	txa
	plx
L10059_END:
;
;		** r.for:* [R.FOR] **
;
L10060:
	.byte L10060_END-L10060-1
	.byte $a3,$05
L10060_END:
;
;		** r-*:W [R-w] **
;
L10061:
	.byte L10061_END-L10061-1
	sec
	sbc  #$63
	pha
	txa
	sbc  #$73
	tax
	pla
L10061_END:
;
;		** r - *[y]:S [R-s[Y]] **
;
L10062:
	.byte L10062_END-L10062-1
	sec
	sbc  ($63),y
	pha
	txa
	iny
	sbc  ($63),y
	dey
	tax
	pla
L10062_END:
;
;		** r-*:S [R-s] **
;
L10063:
	.byte L10063_END-L10063-1
	sec
	sbc  $63
	bcs  *+3
	dex
L10063_END:
;
;		** r-*:L [R-l] **
;
L10064:
	.byte L10064_END-L10064-1
	sec
	sbc  $7363
	pha
	txa
	sbc  $7383
	tax
	pla
L10064_END:
;
;		** r-*:I [R-i] **
;
L10065:
	.byte L10065_END-L10065-1
	sec
	sbc  $63
	pha
	txa
	sbc  $83
	tax
	pla
L10065_END:
;
;		** r-*:C [R-c] **
;
L10066:
	.byte L10066_END-L10066-1
	sec
	sbc  $7363
	bcs  *+3
	dex
L10066_END:
;
;		** r-*:B [R-b] **
;
L10067:
	.byte L10067_END-L10067-1
	sec
	sbc  #$63
	bcs  *+3
	dex
L10067_END:
;
;		** r-?:* [R-?] **
;
L10068:
	.byte L10068_END-L10068-1
	cpx #0
	.byte $93
	bmi *
L10068_END:
;
;		** r->s:* [R->S] **
;
L10069:
	.byte L10069_END-L10069-1
	pha
	phx
L10069_END:
;
;		** r+*:W [R+w] **
;
L10070:
	.byte L10070_END-L10070-1
	clc
	adc  #$63
	pha
	txa
	adc  #$73
	tax
	pla
L10070_END:
;
;		** r + *[y]:S [R+s[Y]] **
;
L10071:
	.byte L10071_END-L10071-1
	clc
	adc  ($63),y
	pha
	txa
	iny
	adc  ($63),y
	dey
	tax
	pla
L10071_END:
;
;		** r+*:S [R+s] **
;
L10072:
	.byte L10072_END-L10072-1
	clc
	adc  $63
	bcc  *+3
	inx
L10072_END:
;
;		** r+*:L [R+l] **
;
L10073:
	.byte L10073_END-L10073-1
	clc
	adc  $7363
	pha
	txa
	adc  $7383
	tax
	pla
L10073_END:
;
;		** r+*:I [R+i] **
;
L10074:
	.byte L10074_END-L10074-1
	clc
	adc  $63
	pha
	txa
	adc  $83
	tax
	pla
L10074_END:
;
;		** r+*:C [R+c] **
;
L10075:
	.byte L10075_END-L10075-1
	clc
	adc  $7363
	bcc  *+3
	inx
L10075_END:
;
;		** r+*:B [R+b] **
;
L10076:
	.byte L10076_END-L10076-1
	clc
	adc  #$63
	bcc  *+3
	inx
L10076_END:
;
;		** r+?:* [R+?] **
;
L10077:
	.byte L10077_END-L10077-1
	cpx #0
	.byte $93
	bpl *
L10077_END:
;
;		** r&*:W [R&w] **
;
L10078:
	.byte L10078_END-L10078-1
	and  #$63
	pha
	txa
	and  #$73
	tax
	pla
L10078_END:
;
;		** r & *[y]:S [R&s[Y]] **
;
L10079:
	.byte L10079_END-L10079-1
	and  ($63),y
	pha
	txa
	iny
	and  ($63),y
	dey
	tax
	pla
L10079_END:
;
;		** r&*:S [R&s] **
;
L10080:
	.byte L10080_END-L10080-1
	and  $63
	ldx  #0
L10080_END:
;
;		** r&*:L [R&l] **
;
L10081:
	.byte L10081_END-L10081-1
	and  $7363
	pha
	txa
	and  $7383
	tax
	pla
L10081_END:
;
;		** r&*:I [R&i] **
;
L10082:
	.byte L10082_END-L10082-1
	and  $63
	pha
	txa
	and  $83
	tax
	pla
L10082_END:
;
;		** r&*:C [R&c] **
;
L10083:
	.byte L10083_END-L10083-1
	and  $7363
	ldx  #0
L10083_END:
;
;		** r&*:B [R&b] **
;
L10084:
	.byte L10084_END-L10084-1
	and  #$63
	ldx  #0
L10084_END:
;
;		** proc:* [PROC] **
;
L10085:
	.byte L10085_END-L10085-1
	.byte $a3,$06
L10085_END:
;
;		** next:* [NEXT] **
;
L10086:
	.byte L10086_END-L10086-1
	.byte $a3,$07
L10086_END:
;
;		** if:* [IF] **
;
L10087:
	.byte L10087_END-L10087-1
	.byte $a3,$08
L10087_END:
;
;		** endproc:* [ENDPROC] **
;
L10088:
	.byte L10088_END-L10088-1
	.byte $a3,$09
L10088_END:
;
;		** endif:* [ENDIF] **
;
L10089:
	.byte L10089_END-L10089-1
	.byte $a3,$0a
L10089_END:
;
;		** else:* [ELSE] **
;
L10090:
	.byte L10090_END-L10090-1
	.byte $a3,$0b
L10090_END:
;
;		** cs?:* [CS?] **
;
L10091:
	.byte L10091_END-L10091-1
	.byte $93
	bcs  *
L10091_END:
;
;		** cc?:* [CC?] **
;
L10092:
	.byte L10092_END-L10092-1
	.byte $93
	bcc  *
L10092_END:
;
;		** byte:* [BYTE] **
;
L10093:
	.byte L10093_END-L10093-1
	.byte $a3,$0c
L10093_END:
;
;		** a * *[y]:S [Ass[Y]] **
;
L10094:
	.byte L10094_END-L10094-1
	eor  ($63),y
L10094_END:
;
;		** a**:S [Ass] **
;
L10095:
	.byte L10095_END-L10095-1
	eor  $63
L10095_END:
;
;		** a**:C [Acc] **
;
L10096:
	.byte L10096_END-L10096-1
	eor  $7363
L10096_END:
;
;		** a**:B [Abb] **
;
L10097:
	.byte L10097_END-L10097-1
	eor  #$63
L10097_END:
;
;		** a = *[y]:S [A=s[Y]] **
;
L10098:
	.byte L10098_END-L10098-1
	lda  ($63),y
L10098_END:
;
;		** a = *:S [A=s] **
;
L10099:
	.byte L10099_END-L10099-1
	lda  $63
L10099_END:
;
;		** a = *:C [A=c] **
;
L10100:
	.byte L10100_END-L10100-1
	lda  $7363
L10100_END:
;
;		** a = *:B [A=b] **
;
L10101:
	.byte L10101_END-L10101-1
	lda  #$63
L10101_END:
;
;		** a=y:* [A=Y] **
;
L10102:
	.byte L10102_END-L10102-1
	tya
L10102_END:
;
;		** a=r:* [A=R] **
;
L10103:
	.byte L10103_END-L10103-1
L10103_END:
;
;		** a=?:* [A=?] **
;
L10104:
	.byte L10104_END-L10104-1
	cmp #0
	.byte $93
	beq *
L10104_END:
;
;		** a<>?:* [A<>?] **
;
L10105:
	.byte L10105_END-L10105-1
	cmp #0
	.byte $93
	bne *
L10105_END:
;
;		** a : *[y]:S [A:s[Y]] **
;
L10106:
	.byte L10106_END-L10106-1
	ora  ($63),y
L10106_END:
;
;		** a:*:S [A:s] **
;
L10107:
	.byte L10107_END-L10107-1
	ora  $63
L10107_END:
;
;		** a:*:C [A:c] **
;
L10108:
	.byte L10108_END-L10108-1
	ora  $7363
L10108_END:
;
;		** a:*:B [A:b] **
;
L10109:
	.byte L10109_END-L10109-1
	ora  #$63
L10109_END:
;
;		** a.for:* [A.FOR] **
;
L10110:
	.byte L10110_END-L10110-1
	.byte $a3,$0d
L10110_END:
;
;		** a - *[y]:S [A-s[Y]] **
;
L10111:
	.byte L10111_END-L10111-1
	sec
	sbc  ($63),y
L10111_END:
;
;		** a-*:S [A-s] **
;
L10112:
	.byte L10112_END-L10112-1
	sec
	sbc  $63
L10112_END:
;
;		** a-*:C [A-c] **
;
L10113:
	.byte L10113_END-L10113-1
	sec
	sbc  $7363
L10113_END:
;
;		** a-*:B [A-b] **
;
L10114:
	.byte L10114_END-L10114-1
	sec
	sbc  #$63
L10114_END:
;
;		** a-?:* [A-?] **
;
L10115:
	.byte L10115_END-L10115-1
	cmp #0
	.byte $93
	bmi *
L10115_END:
;
;		** a->s:* [A->S] **
;
L10116:
	.byte L10116_END-L10116-1
	pha
L10116_END:
;
;		** a + *[y]:S [A+s[Y]] **
;
L10117:
	.byte L10117_END-L10117-1
	clc
	adc  ($63),y
L10117_END:
;
;		** a+*:S [A+s] **
;
L10118:
	.byte L10118_END-L10118-1
	clc
	adc  $63
L10118_END:
;
;		** a+*:C [A+c] **
;
L10119:
	.byte L10119_END-L10119-1
	clc
	adc  $7363
L10119_END:
;
;		** a+*:B [A+b] **
;
L10120:
	.byte L10120_END-L10120-1
	clc
	adc  #$63
L10120_END:
;
;		** a+?:* [A+?] **
;
L10121:
	.byte L10121_END-L10121-1
	cmp #0
	.byte $93
	bpl *
L10121_END:
;
;		** a & *[y]:S [A&s[Y]] **
;
L10122:
	.byte L10122_END-L10122-1
	and  ($63),y
L10122_END:
;
;		** a&*:S [A&s] **
;
L10123:
	.byte L10123_END-L10123-1
	and  $63
L10123_END:
;
;		** a&*:C [A&c] **
;
L10124:
	.byte L10124_END-L10124-1
	and  $7363
L10124_END:
;
;		** a&*:B [A&b] **
;
L10125:
	.byte L10125_END-L10125-1
	and  #$63
L10125_END:
;
;		** >>*:S [>>s] **
;
L10126:
	.byte L10126_END-L10126-1
	lsr  $63
L10126_END:
;
;		** >>*:L [>>l] **
;
L10127:
	.byte L10127_END-L10127-1
	lsr  $7383
	ror  $7363
L10127_END:
;
;		** >>*:I [>>i] **
;
L10128:
	.byte L10128_END-L10128-1
	lsr  $83
	ror  $63
L10128_END:
;
;		** >>*:C [>>c] **
;
L10129:
	.byte L10129_END-L10129-1
	lsr  $7363
L10129_END:
;
;		** >>r:* [>>R] **
;
L10130:
	.byte L10130_END-L10130-1
	pha
	txa
	lsr  a
	tax
	pla
	ror  a
L10130_END:
;
;		** >>a:* [>>A] **
;
L10131:
	.byte L10131_END-L10131-1
	lsr  a
L10131_END:
;
;		** <<*:S [<<s] **
;
L10132:
	.byte L10132_END-L10132-1
	asl  $63
L10132_END:
;
;		** <<*:L [<<l] **
;
L10133:
	.byte L10133_END-L10133-1
	asl  $7363
	rol  $7383
L10133_END:
;
;		** <<*:I [<<i] **
;
L10134:
	.byte L10134_END-L10134-1
	asl  $63
	rol  $83
L10134_END:
;
;		** <<*:C [<<c] **
;
L10135:
	.byte L10135_END-L10135-1
	asl  $7363
L10135_END:
;
;		** <<r:* [<<R] **
;
L10136:
	.byte L10136_END-L10136-1
	asl  a
	pha
	txa
	rol  a
	tax
	pla
L10136_END:
;
;		** <<a:* [<<A] **
;
L10137:
	.byte L10137_END-L10137-1
	asl  a
L10137_END:
;
;		** -r  pha:* [-RPHA] **
;
L10138:
	.byte L10138_END-L10138-1
	txa
	eor  #$ff
	tax
	pla
	eor  #$ff
	inc  a
	bne  *+3
	inx
L10138_END:
;
;		** -a:* [-A] **
;
L10139:
	.byte L10139_END-L10139-1
	eor  #$ff
	inc  a
L10139_END:
;
;		** --*:S [--s] **
;
L10140:
	.byte L10140_END-L10140-1
	dec  $63
L10140_END:
;
;		** --*:L [--l] **
;
L10141:
	.byte L10141_END-L10141-1
	pha
	lda  $7363
	bne  _noborrow
	dec  $7383
_noborrow:
	dec  $7363
	pla
L10141_END:
;
;		** --*:I [--i] **
;
L10142:
	.byte L10142_END-L10142-1
	pha
	lda  $63
	bne  _noborrow
	dec  $83
_noborrow:
	dec  $63
	pla
L10142_END:
;
;		** --*:C [--c] **
;
L10143:
	.byte L10143_END-L10143-1
	dec  $7363
L10143_END:
;
;		** --y:* [--Y] **
;
L10144:
	.byte L10144_END-L10144-1
	dey
L10144_END:
;
;		** --r:* [--R] **
;
L10145:
	.byte L10145_END-L10145-1
	cmp  #0
	bne  *+3
	dex
	dec  a
L10145_END:
;
;		** --a:* [--A] **
;
L10146:
	.byte L10146_END-L10146-1
	dec  a
L10146_END:
;
;		** ++*:S [++s] **
;
L10147:
	.byte L10147_END-L10147-1
	inc  $63
L10147_END:
;
;		** ++*:L [++l] **
;
L10148:
	.byte L10148_END-L10148-1
	inc  $7363
	bne  _nocarry
	inc  $7383
_nocarry:
L10148_END:
;
;		** ++*:I [++i] **
;
L10149:
	.byte L10149_END-L10149-1
	inc  $63
	bne  _nocarry
	inc  $83
_nocarry:
L10149_END:
;
;		** ++*:C [++c] **
;
L10150:
	.byte L10150_END-L10150-1
	inc  $7363
L10150_END:
;
;		** ++y:* [++Y] **
;
L10151:
	.byte L10151_END-L10151-1
	iny
L10151_END:
;
;		** ++r:* [++R] **
;
L10152:
	.byte L10152_END-L10152-1
	inc  a
	bne  *+3
	inx
L10152_END:
;
;		** ++a:* [++A] **
;
L10153:
	.byte L10153_END-L10153-1
	inc  a
L10153_END:
;
;		Vector Table for executable commands
;
ExecutableVectorTable:
	.word Action_call                      ; 0
	.word Action_wordvar                   ; 1
	.word Action_until                     ; 2
	.word Action_repeat                    ; 3
	.word Action_dictionarycrunch          ; 4
	.word Action_rfor                      ; 5
	.word Action_procedure_def             ; 6
	.word Action_next                      ; 7
	.word Action_if                        ; 8
	.word Action_endproc                   ; 9
	.word Action_endif                     ; 10
	.word Action_else                      ; 11
	.word Action_bytevar                   ; 12
	.word Action_afor                      ; 13
SystemDictionary:
;
;		**** w ****
;
	.byte	7
	.byte	'M'
	.word	L10000
	.byte	0
	.byte	1
	.byte	$f7
;
;		**** s[Y]=R ****
;
	.byte	12
	.byte	'M'
	.word	L10001
	.byte	0
	.byte	6
	.byte	$f3,$db,$d9,$dd,$bd,$d2
;
;		**** s[Y]=A ****
;
	.byte	12
	.byte	'M'
	.word	L10002
	.byte	0
	.byte	6
	.byte	$f3,$db,$d9,$dd,$bd,$c1
;
;		**** s=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10003
	.byte	0
	.byte	3
	.byte	$f3,$bd,$d9
;
;		**** s=R ****
;
	.byte	9
	.byte	'M'
	.word	L10004
	.byte	0
	.byte	3
	.byte	$f3,$bd,$d2
;
;		**** s=A ****
;
	.byte	9
	.byte	'M'
	.word	L10005
	.byte	0
	.byte	3
	.byte	$f3,$bd,$c1
;
;		**** s ****
;
	.byte	7
	.byte	'M'
	.word	L10006
	.byte	0
	.byte	1
	.byte	$f3
;
;		**** p ****
;
	.byte	7
	.byte	'M'
	.word	L10007
	.byte	0
	.byte	1
	.byte	$f0
;
;		**** l=R ****
;
	.byte	9
	.byte	'M'
	.word	L10008
	.byte	0
	.byte	3
	.byte	$ec,$bd,$d2
;
;		**** l ****
;
	.byte	7
	.byte	'M'
	.word	L10009
	.byte	0
	.byte	1
	.byte	$ec
;
;		**** i=R ****
;
	.byte	9
	.byte	'M'
	.word	L10010
	.byte	0
	.byte	3
	.byte	$e9,$bd,$d2
;
;		**** i ****
;
	.byte	7
	.byte	'M'
	.word	L10011
	.byte	0
	.byte	1
	.byte	$e9
;
;		**** c=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10012
	.byte	0
	.byte	3
	.byte	$e3,$bd,$d9
;
;		**** c=R ****
;
	.byte	9
	.byte	'M'
	.word	L10013
	.byte	0
	.byte	3
	.byte	$e3,$bd,$d2
;
;		**** c=A ****
;
	.byte	9
	.byte	'M'
	.word	L10014
	.byte	0
	.byte	3
	.byte	$e3,$bd,$c1
;
;		**** c ****
;
	.byte	7
	.byte	'M'
	.word	L10015
	.byte	0
	.byte	1
	.byte	$e3
;
;		**** b ****
;
	.byte	7
	.byte	'M'
	.word	L10016
	.byte	0
	.byte	1
	.byte	$e2
;
;		**** ^RPHA ****
;
	.byte	11
	.byte	'M'
	.word	L10017
	.byte	0
	.byte	5
	.byte	$de,$52,$50,$48,$c1
;
;		**** ^A ****
;
	.byte	8
	.byte	'M'
	.word	L10018
	.byte	0
	.byte	2
	.byte	$de,$c1
;
;		**** Y=s ****
;
	.byte	9
	.byte	'M'
	.word	L10019
	.byte	0
	.byte	3
	.byte	$d9,$bd,$f3
;
;		**** Y=c ****
;
	.byte	9
	.byte	'M'
	.word	L10020
	.byte	0
	.byte	3
	.byte	$d9,$bd,$e3
;
;		**** Y=b ****
;
	.byte	9
	.byte	'M'
	.word	L10021
	.byte	0
	.byte	3
	.byte	$d9,$bd,$e2
;
;		**** Y=R ****
;
	.byte	9
	.byte	'M'
	.word	L10022
	.byte	0
	.byte	3
	.byte	$d9,$bd,$d2
;
;		**** Y=A ****
;
	.byte	9
	.byte	'M'
	.word	L10023
	.byte	0
	.byte	3
	.byte	$d9,$bd,$c1
;
;		**** Y->S ****
;
	.byte	10
	.byte	'M'
	.word	L10024
	.byte	0
	.byte	4
	.byte	$d9,$ad,$be,$d3
;
;		**** WORD ****
;
	.byte	10
	.byte	'M'
	.word	L10025
	.byte	0
	.byte	4
	.byte	$57,$4f,$52,$c4
;
;		**** UNTIL ****
;
	.byte	11
	.byte	'M'
	.word	L10026
	.byte	0
	.byte	5
	.byte	$55,$4e,$54,$49,$cc
;
;		**** S->Y ****
;
	.byte	10
	.byte	'M'
	.word	L10027
	.byte	0
	.byte	4
	.byte	$d3,$ad,$be,$d9
;
;		**** S->RAY ****
;
	.byte	12
	.byte	'M'
	.word	L10028
	.byte	0
	.byte	6
	.byte	$d3,$ad,$be,$52,$41,$d9
;
;		**** S->R ****
;
	.byte	10
	.byte	'M'
	.word	L10029
	.byte	0
	.byte	4
	.byte	$d3,$ad,$be,$d2
;
;		**** S->A ****
;
	.byte	10
	.byte	'M'
	.word	L10030
	.byte	0
	.byte	4
	.byte	$d3,$ad,$be,$c1
;
;		**** Rww ****
;
	.byte	9
	.byte	'M'
	.word	L10031
	.byte	0
	.byte	3
	.byte	$d2,$f7,$f7
;
;		**** Rss[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10032
	.byte	0
	.byte	6
	.byte	$d2,$f3,$f3,$db,$d9,$dd
;
;		**** Rss ****
;
	.byte	9
	.byte	'M'
	.word	L10033
	.byte	0
	.byte	3
	.byte	$d2,$f3,$f3
;
;		**** Rll ****
;
	.byte	9
	.byte	'M'
	.word	L10034
	.byte	0
	.byte	3
	.byte	$d2,$ec,$ec
;
;		**** Rii ****
;
	.byte	9
	.byte	'M'
	.word	L10035
	.byte	0
	.byte	3
	.byte	$d2,$e9,$e9
;
;		**** Rcc ****
;
	.byte	9
	.byte	'M'
	.word	L10036
	.byte	0
	.byte	3
	.byte	$d2,$e3,$e3
;
;		**** Rbb ****
;
	.byte	9
	.byte	'M'
	.word	L10037
	.byte	0
	.byte	3
	.byte	$d2,$e2,$e2
;
;		**** REPEAT ****
;
	.byte	12
	.byte	'M'
	.word	L10038
	.byte	0
	.byte	6
	.byte	$52,$45,$50,$45,$41,$d4
;
;		**** REMOVE.LOCALS ****
;
	.byte	19
	.byte	'M'
	.word	L10039
	.byte	0
	.byte	13
	.byte	$52,$45,$4d,$4f,$56,$45,$2e,$4c,$4f,$43,$41,$4c,$d3
;
;		**** RAY->S ****
;
	.byte	12
	.byte	'M'
	.word	L10040
	.byte	0
	.byte	6
	.byte	$52,$41,$d9,$ad,$be,$d3
;
;		**** R=w ****
;
	.byte	9
	.byte	'M'
	.word	L10041
	.byte	0
	.byte	3
	.byte	$d2,$bd,$f7
;
;		**** R=s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10042
	.byte	0
	.byte	6
	.byte	$d2,$bd,$f3,$db,$d9,$dd
;
;		**** R=s ****
;
	.byte	9
	.byte	'M'
	.word	L10043
	.byte	0
	.byte	3
	.byte	$d2,$bd,$f3
;
;		**** R=l ****
;
	.byte	9
	.byte	'M'
	.word	L10044
	.byte	0
	.byte	3
	.byte	$d2,$bd,$ec
;
;		**** R=i ****
;
	.byte	9
	.byte	'M'
	.word	L10045
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e9
;
;		**** R=c ****
;
	.byte	9
	.byte	'M'
	.word	L10046
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e3
;
;		**** R=b ****
;
	.byte	9
	.byte	'M'
	.word	L10047
	.byte	0
	.byte	3
	.byte	$d2,$bd,$e2
;
;		**** R=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10048
	.byte	0
	.byte	3
	.byte	$d2,$bd,$d9
;
;		**** R=A ****
;
	.byte	9
	.byte	'M'
	.word	L10049
	.byte	0
	.byte	3
	.byte	$d2,$bd,$c1
;
;		**** R=? ****
;
	.byte	9
	.byte	'M'
	.word	L10050
	.byte	0
	.byte	3
	.byte	$d2,$bd,$bf
;
;		**** R<>? ****
;
	.byte	10
	.byte	'M'
	.word	L10051
	.byte	0
	.byte	4
	.byte	$d2,$bc,$be,$bf
;
;		**** R:w ****
;
	.byte	9
	.byte	'M'
	.word	L10052
	.byte	0
	.byte	3
	.byte	$d2,$ba,$f7
;
;		**** R:s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10053
	.byte	0
	.byte	6
	.byte	$d2,$ba,$f3,$db,$d9,$dd
;
;		**** R:s ****
;
	.byte	9
	.byte	'M'
	.word	L10054
	.byte	0
	.byte	3
	.byte	$d2,$ba,$f3
;
;		**** R:l ****
;
	.byte	9
	.byte	'M'
	.word	L10055
	.byte	0
	.byte	3
	.byte	$d2,$ba,$ec
;
;		**** R:i ****
;
	.byte	9
	.byte	'M'
	.word	L10056
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e9
;
;		**** R:c ****
;
	.byte	9
	.byte	'M'
	.word	L10057
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e3
;
;		**** R:b ****
;
	.byte	9
	.byte	'M'
	.word	L10058
	.byte	0
	.byte	3
	.byte	$d2,$ba,$e2
;
;		**** R.SWAP ****
;
	.byte	12
	.byte	'M'
	.word	L10059
	.byte	0
	.byte	6
	.byte	$52,$2e,$53,$57,$41,$d0
;
;		**** R.FOR ****
;
	.byte	11
	.byte	'M'
	.word	L10060
	.byte	0
	.byte	5
	.byte	$52,$2e,$46,$4f,$d2
;
;		**** R-w ****
;
	.byte	9
	.byte	'M'
	.word	L10061
	.byte	0
	.byte	3
	.byte	$d2,$ad,$f7
;
;		**** R-s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10062
	.byte	0
	.byte	6
	.byte	$d2,$ad,$f3,$db,$d9,$dd
;
;		**** R-s ****
;
	.byte	9
	.byte	'M'
	.word	L10063
	.byte	0
	.byte	3
	.byte	$d2,$ad,$f3
;
;		**** R-l ****
;
	.byte	9
	.byte	'M'
	.word	L10064
	.byte	0
	.byte	3
	.byte	$d2,$ad,$ec
;
;		**** R-i ****
;
	.byte	9
	.byte	'M'
	.word	L10065
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e9
;
;		**** R-c ****
;
	.byte	9
	.byte	'M'
	.word	L10066
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e3
;
;		**** R-b ****
;
	.byte	9
	.byte	'M'
	.word	L10067
	.byte	0
	.byte	3
	.byte	$d2,$ad,$e2
;
;		**** R-? ****
;
	.byte	9
	.byte	'M'
	.word	L10068
	.byte	0
	.byte	3
	.byte	$d2,$ad,$bf
;
;		**** R->S ****
;
	.byte	10
	.byte	'M'
	.word	L10069
	.byte	0
	.byte	4
	.byte	$d2,$ad,$be,$d3
;
;		**** R+w ****
;
	.byte	9
	.byte	'M'
	.word	L10070
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f7
;
;		**** R+s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10071
	.byte	0
	.byte	6
	.byte	$d2,$ab,$f3,$db,$d9,$dd
;
;		**** R+s ****
;
	.byte	9
	.byte	'M'
	.word	L10072
	.byte	0
	.byte	3
	.byte	$d2,$ab,$f3
;
;		**** R+l ****
;
	.byte	9
	.byte	'M'
	.word	L10073
	.byte	0
	.byte	3
	.byte	$d2,$ab,$ec
;
;		**** R+i ****
;
	.byte	9
	.byte	'M'
	.word	L10074
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e9
;
;		**** R+c ****
;
	.byte	9
	.byte	'M'
	.word	L10075
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e3
;
;		**** R+b ****
;
	.byte	9
	.byte	'M'
	.word	L10076
	.byte	0
	.byte	3
	.byte	$d2,$ab,$e2
;
;		**** R+? ****
;
	.byte	9
	.byte	'M'
	.word	L10077
	.byte	0
	.byte	3
	.byte	$d2,$ab,$bf
;
;		**** R&w ****
;
	.byte	9
	.byte	'M'
	.word	L10078
	.byte	0
	.byte	3
	.byte	$d2,$a6,$f7
;
;		**** R&s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10079
	.byte	0
	.byte	6
	.byte	$d2,$a6,$f3,$db,$d9,$dd
;
;		**** R&s ****
;
	.byte	9
	.byte	'M'
	.word	L10080
	.byte	0
	.byte	3
	.byte	$d2,$a6,$f3
;
;		**** R&l ****
;
	.byte	9
	.byte	'M'
	.word	L10081
	.byte	0
	.byte	3
	.byte	$d2,$a6,$ec
;
;		**** R&i ****
;
	.byte	9
	.byte	'M'
	.word	L10082
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e9
;
;		**** R&c ****
;
	.byte	9
	.byte	'M'
	.word	L10083
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e3
;
;		**** R&b ****
;
	.byte	9
	.byte	'M'
	.word	L10084
	.byte	0
	.byte	3
	.byte	$d2,$a6,$e2
;
;		**** PROC ****
;
	.byte	10
	.byte	'M'
	.word	L10085
	.byte	0
	.byte	4
	.byte	$50,$52,$4f,$c3
;
;		**** NEXT ****
;
	.byte	10
	.byte	'M'
	.word	L10086
	.byte	0
	.byte	4
	.byte	$4e,$45,$58,$d4
;
;		**** IF ****
;
	.byte	8
	.byte	'M'
	.word	L10087
	.byte	0
	.byte	2
	.byte	$49,$c6
;
;		**** ENDPROC ****
;
	.byte	13
	.byte	'M'
	.word	L10088
	.byte	0
	.byte	7
	.byte	$45,$4e,$44,$50,$52,$4f,$c3
;
;		**** ENDIF ****
;
	.byte	11
	.byte	'M'
	.word	L10089
	.byte	0
	.byte	5
	.byte	$45,$4e,$44,$49,$c6
;
;		**** ELSE ****
;
	.byte	10
	.byte	'M'
	.word	L10090
	.byte	0
	.byte	4
	.byte	$45,$4c,$53,$c5
;
;		**** CS? ****
;
	.byte	9
	.byte	'M'
	.word	L10091
	.byte	0
	.byte	3
	.byte	$43,$d3,$bf
;
;		**** CC? ****
;
	.byte	9
	.byte	'M'
	.word	L10092
	.byte	0
	.byte	3
	.byte	$43,$c3,$bf
;
;		**** BYTE ****
;
	.byte	10
	.byte	'M'
	.word	L10093
	.byte	0
	.byte	4
	.byte	$42,$59,$54,$c5
;
;		**** Ass[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10094
	.byte	0
	.byte	6
	.byte	$c1,$f3,$f3,$db,$d9,$dd
;
;		**** Ass ****
;
	.byte	9
	.byte	'M'
	.word	L10095
	.byte	0
	.byte	3
	.byte	$c1,$f3,$f3
;
;		**** Acc ****
;
	.byte	9
	.byte	'M'
	.word	L10096
	.byte	0
	.byte	3
	.byte	$c1,$e3,$e3
;
;		**** Abb ****
;
	.byte	9
	.byte	'M'
	.word	L10097
	.byte	0
	.byte	3
	.byte	$c1,$e2,$e2
;
;		**** A=s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10098
	.byte	0
	.byte	6
	.byte	$c1,$bd,$f3,$db,$d9,$dd
;
;		**** A=s ****
;
	.byte	9
	.byte	'M'
	.word	L10099
	.byte	0
	.byte	3
	.byte	$c1,$bd,$f3
;
;		**** A=c ****
;
	.byte	9
	.byte	'M'
	.word	L10100
	.byte	0
	.byte	3
	.byte	$c1,$bd,$e3
;
;		**** A=b ****
;
	.byte	9
	.byte	'M'
	.word	L10101
	.byte	0
	.byte	3
	.byte	$c1,$bd,$e2
;
;		**** A=Y ****
;
	.byte	9
	.byte	'M'
	.word	L10102
	.byte	0
	.byte	3
	.byte	$c1,$bd,$d9
;
;		**** A=R ****
;
	.byte	9
	.byte	'M'
	.word	L10103
	.byte	0
	.byte	3
	.byte	$c1,$bd,$d2
;
;		**** A=? ****
;
	.byte	9
	.byte	'M'
	.word	L10104
	.byte	0
	.byte	3
	.byte	$c1,$bd,$bf
;
;		**** A<>? ****
;
	.byte	10
	.byte	'M'
	.word	L10105
	.byte	0
	.byte	4
	.byte	$c1,$bc,$be,$bf
;
;		**** A:s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10106
	.byte	0
	.byte	6
	.byte	$c1,$ba,$f3,$db,$d9,$dd
;
;		**** A:s ****
;
	.byte	9
	.byte	'M'
	.word	L10107
	.byte	0
	.byte	3
	.byte	$c1,$ba,$f3
;
;		**** A:c ****
;
	.byte	9
	.byte	'M'
	.word	L10108
	.byte	0
	.byte	3
	.byte	$c1,$ba,$e3
;
;		**** A:b ****
;
	.byte	9
	.byte	'M'
	.word	L10109
	.byte	0
	.byte	3
	.byte	$c1,$ba,$e2
;
;		**** A.FOR ****
;
	.byte	11
	.byte	'M'
	.word	L10110
	.byte	0
	.byte	5
	.byte	$41,$2e,$46,$4f,$d2
;
;		**** A-s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10111
	.byte	0
	.byte	6
	.byte	$c1,$ad,$f3,$db,$d9,$dd
;
;		**** A-s ****
;
	.byte	9
	.byte	'M'
	.word	L10112
	.byte	0
	.byte	3
	.byte	$c1,$ad,$f3
;
;		**** A-c ****
;
	.byte	9
	.byte	'M'
	.word	L10113
	.byte	0
	.byte	3
	.byte	$c1,$ad,$e3
;
;		**** A-b ****
;
	.byte	9
	.byte	'M'
	.word	L10114
	.byte	0
	.byte	3
	.byte	$c1,$ad,$e2
;
;		**** A-? ****
;
	.byte	9
	.byte	'M'
	.word	L10115
	.byte	0
	.byte	3
	.byte	$c1,$ad,$bf
;
;		**** A->S ****
;
	.byte	10
	.byte	'M'
	.word	L10116
	.byte	0
	.byte	4
	.byte	$c1,$ad,$be,$d3
;
;		**** A+s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10117
	.byte	0
	.byte	6
	.byte	$c1,$ab,$f3,$db,$d9,$dd
;
;		**** A+s ****
;
	.byte	9
	.byte	'M'
	.word	L10118
	.byte	0
	.byte	3
	.byte	$c1,$ab,$f3
;
;		**** A+c ****
;
	.byte	9
	.byte	'M'
	.word	L10119
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e3
;
;		**** A+b ****
;
	.byte	9
	.byte	'M'
	.word	L10120
	.byte	0
	.byte	3
	.byte	$c1,$ab,$e2
;
;		**** A+? ****
;
	.byte	9
	.byte	'M'
	.word	L10121
	.byte	0
	.byte	3
	.byte	$c1,$ab,$bf
;
;		**** A&s[Y] ****
;
	.byte	12
	.byte	'M'
	.word	L10122
	.byte	0
	.byte	6
	.byte	$c1,$a6,$f3,$db,$d9,$dd
;
;		**** A&s ****
;
	.byte	9
	.byte	'M'
	.word	L10123
	.byte	0
	.byte	3
	.byte	$c1,$a6,$f3
;
;		**** A&c ****
;
	.byte	9
	.byte	'M'
	.word	L10124
	.byte	0
	.byte	3
	.byte	$c1,$a6,$e3
;
;		**** A&b ****
;
	.byte	9
	.byte	'M'
	.word	L10125
	.byte	0
	.byte	3
	.byte	$c1,$a6,$e2
;
;		**** >>s ****
;
	.byte	9
	.byte	'M'
	.word	L10126
	.byte	0
	.byte	3
	.byte	$be,$be,$f3
;
;		**** >>l ****
;
	.byte	9
	.byte	'M'
	.word	L10127
	.byte	0
	.byte	3
	.byte	$be,$be,$ec
;
;		**** >>i ****
;
	.byte	9
	.byte	'M'
	.word	L10128
	.byte	0
	.byte	3
	.byte	$be,$be,$e9
;
;		**** >>c ****
;
	.byte	9
	.byte	'M'
	.word	L10129
	.byte	0
	.byte	3
	.byte	$be,$be,$e3
;
;		**** >>R ****
;
	.byte	9
	.byte	'M'
	.word	L10130
	.byte	0
	.byte	3
	.byte	$be,$be,$d2
;
;		**** >>A ****
;
	.byte	9
	.byte	'M'
	.word	L10131
	.byte	0
	.byte	3
	.byte	$be,$be,$c1
;
;		**** <<s ****
;
	.byte	9
	.byte	'M'
	.word	L10132
	.byte	0
	.byte	3
	.byte	$bc,$bc,$f3
;
;		**** <<l ****
;
	.byte	9
	.byte	'M'
	.word	L10133
	.byte	0
	.byte	3
	.byte	$bc,$bc,$ec
;
;		**** <<i ****
;
	.byte	9
	.byte	'M'
	.word	L10134
	.byte	0
	.byte	3
	.byte	$bc,$bc,$e9
;
;		**** <<c ****
;
	.byte	9
	.byte	'M'
	.word	L10135
	.byte	0
	.byte	3
	.byte	$bc,$bc,$e3
;
;		**** <<R ****
;
	.byte	9
	.byte	'M'
	.word	L10136
	.byte	0
	.byte	3
	.byte	$bc,$bc,$d2
;
;		**** <<A ****
;
	.byte	9
	.byte	'M'
	.word	L10137
	.byte	0
	.byte	3
	.byte	$bc,$bc,$c1
;
;		**** -RPHA ****
;
	.byte	11
	.byte	'M'
	.word	L10138
	.byte	0
	.byte	5
	.byte	$ad,$52,$50,$48,$c1
;
;		**** -A ****
;
	.byte	8
	.byte	'M'
	.word	L10139
	.byte	0
	.byte	2
	.byte	$ad,$c1
;
;		**** --s ****
;
	.byte	9
	.byte	'M'
	.word	L10140
	.byte	0
	.byte	3
	.byte	$ad,$ad,$f3
;
;		**** --l ****
;
	.byte	9
	.byte	'M'
	.word	L10141
	.byte	0
	.byte	3
	.byte	$ad,$ad,$ec
;
;		**** --i ****
;
	.byte	9
	.byte	'M'
	.word	L10142
	.byte	0
	.byte	3
	.byte	$ad,$ad,$e9
;
;		**** --c ****
;
	.byte	9
	.byte	'M'
	.word	L10143
	.byte	0
	.byte	3
	.byte	$ad,$ad,$e3
;
;		**** --Y ****
;
	.byte	9
	.byte	'M'
	.word	L10144
	.byte	0
	.byte	3
	.byte	$ad,$ad,$d9
;
;		**** --R ****
;
	.byte	9
	.byte	'M'
	.word	L10145
	.byte	0
	.byte	3
	.byte	$ad,$ad,$d2
;
;		**** --A ****
;
	.byte	9
	.byte	'M'
	.word	L10146
	.byte	0
	.byte	3
	.byte	$ad,$ad,$c1
;
;		**** ++s ****
;
	.byte	9
	.byte	'M'
	.word	L10147
	.byte	0
	.byte	3
	.byte	$ab,$ab,$f3
;
;		**** ++l ****
;
	.byte	9
	.byte	'M'
	.word	L10148
	.byte	0
	.byte	3
	.byte	$ab,$ab,$ec
;
;		**** ++i ****
;
	.byte	9
	.byte	'M'
	.word	L10149
	.byte	0
	.byte	3
	.byte	$ab,$ab,$e9
;
;		**** ++c ****
;
	.byte	9
	.byte	'M'
	.word	L10150
	.byte	0
	.byte	3
	.byte	$ab,$ab,$e3
;
;		**** ++Y ****
;
	.byte	9
	.byte	'M'
	.word	L10151
	.byte	0
	.byte	3
	.byte	$ab,$ab,$d9
;
;		**** ++R ****
;
	.byte	9
	.byte	'M'
	.word	L10152
	.byte	0
	.byte	3
	.byte	$ab,$ab,$d2
;
;		**** ++A ****
;
	.byte	9
	.byte	'M'
	.word	L10153
	.byte	0
	.byte	3
	.byte	$ab,$ab,$c1
;
	.byte	$00
