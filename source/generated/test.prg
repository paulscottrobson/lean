��40960 '��. WORD VERA.LOW@$9F20 C��. BYTE VERA.HIGH@$9F22 _�. BYTE VERA.DATA@$9F23 x�. WORD .SPRITE.BASE ��. BYTE .SPRITE.MODE �$�. WORD PTR@$10 �.�. PROC VERA.SET() �8�. VERA.LOW = R �B�. A=Y A&$0F A:$10 VERA.HIGH=A 	L�. ENDPROC 	V�. PROC VERA.PALETTE() +	`�. RAY->S X	j�. R->S R=Y <<R R:$1000 Y=$0F VERA.SET() �	t�. S->R VERA.DATA=A R.SWAP VERA.DATA=A �	~�. S->RAY �	��. ENDPROC �	��. PROC VERA.SPRITES.ENABLE() 
��. RAY->S .SPRITE.MODE=Y R<>? IF 1 ENDIF A->S VERA.SET($4000,$F) S->A VERA.DATA=A S->RAY .
��. ENDPROC H
��. PROC VERA.SELECT() �
��. RAY->S R&$7F <<A <<R <<R R:$5000 .SPRITE.BASE=R S->RAY �
��. ENDPROC �
��. PROC .VERA.ACCESS() �
��. Y->S R+.SPRITE.BASE Y=$0F VERA.SET() S->Y �
��. ENDPROC ��. PROC VERA.X() S��. RAY->S R->S .VERA.ACCESS(2) S->R VERA.DATA=A R.SWAP VERA.DATA=A S->RAY b �. ENDPROC w
�. PROC VERA.Y() ��. RAY->S R->S .VERA.ACCESS(4) S->R VERA.DATA=A R.SWAP VERA.DATA=A S->RAY ��. ENDPROC �(�. PROC VERA.CREATE() �2�. RAY->S <�. <<A <<A <<A <<A A->S SF�. .VERA.ACCESS(6) A = 12 VERA.DATA=A S->A VERA.DATA=A aP�. S->RAY pZ�. ENDPROC �d�. PROC VERA.GRAPHIC() �n�. RAY->S �x�. >>R R->S R->S .VERA.ACCESS(0) ���. S->R VERA.DATA=A 
��. S->R R.SWAP A&$0F A+.SPRITE.MODE VERA.DATA=A ��. S->RAY '��. ENDPROC :��. PROC MAIN() J��. PTR[Y]=A f��. VERA.PALETTE($F80,1) ���. VERA.PALETTE($000,6) ���. VERA.SPRITES.ENABLE(1,$00) ���. VERA.SET($4000,$01) ���. 4096 R.FOR >>A >>A VERA.DATA=A NEXT ���. 12 A.FOR ��. R->S �. VERA.SELECT() 3�. VERA.CREATE($0A) N�. VERA.GRAPHIC($1400) f"�. S->R <<R <<R <<R z,�. VERA.X() <<R �6�. VERA.Y() �@�. NEXT �J�. ENDPROC �T�. REMOVE.LOCALS   