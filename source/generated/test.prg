��40960 ��. -A  ��. -R ;�. WORD VERA.LOW@$9F20 W�. BYTE VERA.HIGH@$9F22 s�. BYTE VERA.DATA@$9F23 �$�. WORD .SPRITE.BASE �.�. BYTE .SPRITE.MODE �8�. WORD PTR@$10 �B�. PROC VERA.SET() �L�. VERA.LOW = R 	V�. A=Y A&$0F A:$10 VERA.HIGH=A 	`�. ENDPROC 1	j�. PROC VERA.PALETTE() ?	t�. RAY->S l	~�. R->S R=Y <<R R:$1000 Y=$0F VERA.SET() �	��. S->R VERA.DATA=A R.SWAP VERA.DATA=A �	��. S->RAY �	��. ENDPROC �	��. PROC VERA.SPRITES.ENABLE() 3
��. RAY->S .SPRITE.MODE=Y R<>? IF 1 ENDIF A->S VERA.SET($4000,$F) S->A VERA.DATA=A S->RAY B
��. ENDPROC \
��. PROC VERA.SELECT() �
��. RAY->S R&$7F <<A <<R <<R R:$5000 .SPRITE.BASE=R S->RAY �
��. ENDPROC �
��. PROC .VERA.ACCESS() �
��. Y->S R+.SPRITE.BASE Y=$0F VERA.SET() S->Y ��. ENDPROC  �. PROC VERA.X() g
�. RAY->S R->S .VERA.ACCESS(2) S->R VERA.DATA=A R.SWAP VERA.DATA=A S->RAY v�. ENDPROC ��. PROC VERA.Y() �(�. RAY->S R->S .VERA.ACCESS(4) S->R VERA.DATA=A R.SWAP VERA.DATA=A S->RAY �2�. ENDPROC <�. PROC VERA.CREATE() F�. RAY->S ,P�. <<A <<A <<A <<A A->S gZ�. .VERA.ACCESS(6) A = 12 VERA.DATA=A S->A VERA.DATA=A ud�. S->RAY �n�. ENDPROC �x�. PROC VERA.GRAPHIC() ���. RAY->S ���. >>R R->S R->S .VERA.ACCESS(0) ���. S->R VERA.DATA=A ��. S->R R.SWAP A&$0F A+.SPRITE.MODE VERA.DATA=A ,��. S->RAY ;��. ENDPROC N��. PROC MAIN() ^��. PTR[Y]=A z��. VERA.PALETTE($F80,1) ���. VERA.PALETTE($000,6) ���. VERA.SPRITES.ENABLE(1,$00) ���. VERA.SET($4000,$01) ���. 4096 R.FOR >>A >>A VERA.DATA=A NEXT �. 12 A.FOR �. R->S /�. VERA.SELECT() G"�. VERA.CREATE($0A) b,�. VERA.GRAPHIC($1400) z6�. S->R <<R <<R <<R �@�. VERA.X() <<R �J�. VERA.Y() �T�. NEXT �^�. ENDPROC �h�. REMOVE.LOCALS   