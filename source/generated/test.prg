���(14) ��40960 A��. BYTE VERA.HI@$9F22,VERA.DATA@$9F23 [�. WORD VERA.LO@$9F20 u�. PROC MAKE.SPRITE() ��. R=0 VERA.LO=R A=$11 VERA.HI=A �$�. A=64 A.FOR �.�. A = 64 A.FOR �8�. VERA.DATA=A �B�. NEXT �L�. NEXT �V�. ENDPROC 
	`�. BYTE POS 	j�. PROC DELAY() 6	t�. A=255 A.FOR NEXT E	~�. ENDPROC \	��. PROC MAIN.APP() q	��. MAKE.SPRITE() �	��. A=$F VERA.HI=A  R=$4000 VERA.LO=R A=1 VERA.DATA=A �	��. R=$5000 VERA.LO=R A=$1F VERA.HI=A �	��. A=0 VERA.DATA=A 
��. A=$88 VERA.DATA=A 
��. A = 20 VERA.DATA = A :
��. A = 0 VERA.DATA = A V
��. A = 40 VERA.DATA = A q
��. A = 0 VERA.DATA = A �
��. A = $0C VERA.DATA = A �
��. A = $A0 VERA.DATA = A �
 �. A=255 �

�. A.FOR �
�. A=255 A.FOR �
�. POS=A �
(�. R=$5002 2�. VERA.LO = R <�. A=POS 'F�. VERA.DATA=A 6P�. R=$5004 IZ�. VERA.LO = R Vd�. A=POS in�. VERA.DATA=A xx�. DELAY() ���. NEXT ���. NEXT ���. ENDPROC   