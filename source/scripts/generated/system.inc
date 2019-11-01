;
;		Automatically generated.
;
;
;		** inc *:S [INCs] **
;
L10000:
	.byte L10000_END-L10000-1
	inc $63
L10000_END:
;
;		** inc *:C [INCc] **
;
L10001:
	.byte L10001_END-L10001-1
	inc $7363
L10001_END:
;
;		Vector Table for executable commands
;
ExecutableVectorTable:
SystemDictionary:
;
;		**** INCs ****
;
	.byte	10
	.byte	'M'
	.word	L10000
	.byte	0
	.byte	4
	.byte	$49,$4e,$c3,$f3
;
;		**** INCc ****
;
	.byte	10
	.byte	'M'
	.word	L10001
	.byte	0
	.byte	4
	.byte	$49,$4e,$c3,$e3
;
	.byte	$00
