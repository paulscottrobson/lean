��04553 '�΅ "SPRITES.BIN",1,1,0 2��40960 9�3 T�. WORD VERA.LOW@$9F20 p�. BYTE VERA.HIGH@$9F22 �$�. BYTE VERA.DATA@$9F23 �.�. WORD .SPRITE.BASE �8�. BYTE .SPRITE.MODE �B�. PROC VERA.SET() �L�. VERA.LOW = R 	V�. A=Y A&$0F A:$10 VERA.HIGH=A 	`�. ENDPROC 6	j�. PROC VERA.PALETTE() D	t�. RAY->S q	~�. R->S R=Y <<R R:$1000 Y=$0F VERA.SET() �	��. S->R VERA.DATA=A R.SWAP VERA.DATA=A �	��. S->RAY �	��. ENDPROC �	��. PROC VERA.SPRITES.ENABLE() 8
��. RAY->S .SPRITE.MODE=Y R<>? IF 1 ENDIF A->S VERA.SET($4000,$F) S->A VERA.DATA=A S->RAY G
��. ENDPROC a
��. PROC VERA.SELECT() �
��. RAY->S R&$7F <<A <<R <<R R:$5000 .SPRITE.BASE=R S->RAY �
��. ENDPROC �
��. PROC .VERA.ACCESS() �
��. Y->S R+.SPRITE.BASE Y=$0F VERA.SET() S->Y 	��. ENDPROC  �. PROC VERA.X() l
�. RAY->S R->S .VERA.ACCESS(2) S->R VERA.DATA=A R.SWAP VERA.DATA=A S->RAY {�. ENDPROC ��. PROC VERA.Y() �(�. RAY->S R->S .VERA.ACCESS(4) S->R VERA.DATA=A R.SWAP VERA.DATA=A S->RAY �2�. ENDPROC <�. PROC VERA.CREATE() F�. RAY->S 1P�. <<A <<A <<A <<A A->S lZ�. .VERA.ACCESS(6) A = 12 VERA.DATA=A S->A VERA.DATA=A zd�. S->RAY �n�. ENDPROC �x�. PROC VERA.GRAPHIC() ���. RAY->S ���. >>R R->S R->S .VERA.ACCESS(0) ���. S->R VERA.DATA=A #��. S->R R.SWAP A&$0F A+.SPRITE.MODE VERA.DATA=A 1��. S->RAY @��. ENDPROC R��. WORD P@$10 g��. WORD FREE.MEM ���. BYTE COUNT,CURRENT ���. PROC SET.PTR() ���. <<A <<A R=A R+FREE.MEM P=R ���. ENDPROC ���. PROC XI.FLIP() ��. .VERA.ACCESS(6)  �. Y=2 �. 0 R-P[Y] "�. P[Y]=R ),�. R-? T6�. IF A=13 ELSE A=12 ENDIF VERA.DATA=A c@�. ENDPROC vJ�. PROC MAIN() �T�. FREE.MEM = R �^�. A=24 COUNT=A �h�. VERA.SPRITES.ENABLE(1,0) �r�. A=COUNT A.FOR �|�. CURRENT=A ���. SET.PTR() ��. Y=0 R=32 P[Y] = R 0��. Y=2 R=CURRENT ++R P[Y] = R O��. A=CURRENT VERA.SELECT() g��. VERA.CREATE($0F) ���. VERA.GRAPHIC($1000) ���. R=CURRENT <<R <<R <<R <<R VERA.Y() ���. NEXT ���. 10000 R.FOR ���. A=COUNT A.FOR ���. CURRENT = A SET.PTR() ��. A=CURRENT VERA.SELECT() 7��. Y=0 R=P[Y] VERA.X() T�. Y=2 R+P[Y] Y=0 P[Y]=R ��. Y=0 R=P[Y] R>=608? IF XI.FLIP() ENDIF ��.  �&�. NEXT �0�. NEXT �:�. ENDPROC �D�. REMOVE.LOCALS   ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������  ��� �z��Z��څ�`�   �8i(� �i �d������� � �����������`L!�LV�    LEAN V0.3 (01-NOV-19) ��'�� �� �� �� � '� � �� t� w�� �� ���* ��'�`�()*� ��L �LEAN:NO CODE d`H�Z��
��������$��������+ȱ�,ȱɏ��ȱ��.��8z�h`�� d2������z�� �� ���	��@��-�@�� ����?	��?Z� �� ,���P�K�S�G�I�C �� S���z�����z��-� ���Zڦ��  ʡ�b� ��w�z�-	��@耂�@�@�1`H�.�/�0 ʡh	 �p��� ��I�l�ѩc�� �LEAN:SYNTAX ?  �LEAN:LINE SIZE 8� ��� ��`�-i@����`�%��_��$��.��0��:��A��[�8``H�Zڦ2�����h���-������2�������z�h` �LEAN:COMPLEX ? d3d=�3�@� ��=��`�3i@���� )�� �LEAN:SYNTAX? �M��1�3�@)�a��{�� Ԣ���3�.��/���%���ɣ�ɓ�ȱ�4ȱ�5�ʀ ��  ����`���Z�
��2���3�� ��z���l �c�	Ƀ��s�
`�6`�6�`�7` �LEAN:WORD OFF PAGE H�Z������轀������ ���6 �����z�h` �LEAN:SYS0? �3�@) ���ڽ@�
���3h�i@���` �LEAN:IDENTIFIER ? Hڦ3]@)��3�h` �LEAN:MISSING ? ڦ3�@�`�3`�!� �a�H�*�a��(��)��$�%   h�a�`�Z�a��&�a��$�$��%�a�z�`Hڢ;�m�� ������h`����� ��
��Z�i���������h��� ��Z����ȑz����"��#�e���� �`H�ZZ��"�h�"���"z�h`�A�����A�`8��Z�8���� �(�	�A�� Q���N�� Q�z�`����6���ȱ��������1���0���/���.��8`�e������`� ���� H�$�9�%�:�&�;h�&�$�%`�9�$�:�%�;�&`��$  ���%���� �LEAN:BRANCH? �0�`��` �LEAN:SYNTAX �z��� ?��+,�(�:�� ?��+�, ��@� ?��: P��=�  ��@� ?�d(d)d*��� ?�LR� AT  ��� �� P�Ȁ�`H�Z ��z�h` 
��P ���&�$�%�(�)�* 	��( @��) @��P  �` �LEAN:PROCDEF �P ��`  � I�`�3:H�( @� b�ɩ��R � j� b�ɬ� j��Y � j��) @�h Ԣ�   �6  �7  `�3�H�@�����ʩ��@�h	��@�3 �h�3` �LEAN:PARAMETER? �4I    ��  �I  �`�I ���  �$H�%H��   a�h��hȑ`�I � a�� I�`�$H�%H��H������h ��z� �� ��` �R  �`�R ��4I � 4�� I�` �:  �H  �F  �` ��  �   ��  �  ��  �:  �H  ��  �G  �`��G��F ��h  �Р 4�� I�`��  �h  �Р 4���  �   �Р 4�� I�`� ���`����<�S�<���IH 
�h �� b����! j� b�������4�3 Ԣ� �6�7 	� j�����  	��<e��� b�ɬ� j���` �LEAN:ADDRESS? �A������X��)�.�A�Hr��Hi ��������������������� �h�h����r������`��� � d8��K�H��L��	�h����h��� �	0�@�����ҥ	0�@� �A`'�d 
 � �!��� �$���
�-�� |���I���I���8��`�� �_dd����dd��J���e��e�&� �� )�0�+�:��A�#�G�8�8�0���e���� �
����8``�?����*�`�&  ��$  ��%  �`���` �LEAN:RETURN STACK ��` �LEAN:STRUCTURES H�Z  ȱ���� ��z�h`e�`�c�s�c�c�c�c� � 	�cȊ�c��c�c�cs��s�cs��s	�cȊ�c��c�c�c���c���cs�cs�cs�cs� �c�s�I��hI�I��c�cs�c��Z��zz�h�hh��H�Z
�cH��sh����c�s�c� ȱc���c�cs��sȱc���c�c���cs� �c�s�� � 	� �� ���	� �� ���	cH�	s�hc
cH��c��h
csH��s�h
cH��c��hcH���hcs	cH���	8�cH��s�h8�c��8�cH���c��h8�csH��s�h8�cH���c��h	8�cH�僪h8�cs��8�c��� �0�H�	icH�is�hec��qcH��qc��hmcsH�m�s�hqcH��qc��h	ecH�e��hmcs��ic��� ��IcH�Is�hEc
QcH��Qc��h
McsH�M�s�h
QcH��Qc��hEcH�E��hMcsIc)cH�)s�h%c� 
1cH��1c��h
-csH�-�s�h
1cH��1c��h%cH�%��h-cs� )c� ����	�
����������c����cs����c����c����c�c�c�cs����cs�c����c� � ����c����cs����c����c����cs����c���� ���ccccs	c�8�c8�c8�c8�cs8�c� �0�Hecqcqcmcsic� ��EcQcQcMcsIc%c1c1c-cs)cFcN�sncsF�fcNcsH�J�hjJccs.�sc&�cs
H�*�h
�I��hI���I��cH�cs�΃s�csh
H�c�ƃ�ch�cs�� ��::�c�cs��s�c���cs�����4���������Z�����S�1�0���MO� �	MT� ��	MW� ��	MZ� ��M]� �Mb� �Me� ���ݽ�Mo� ���ݽ�	Mr� ��My� �M�� ���ݽ�M�� ���ݽ�	M�� ��M�� �	M�� ��	M�� ��	M�� ��M�� �M�� �M�� �RPH�M�� ��	M�� ٽ�	M�� ٽ�	M�� ٽ�	Mé ٽ�	Mũ ٽ�
Mǩ ٭��
Mɩ WOR�M̩ UNTI�
Mϩ ӭ��Mѩ ӭ�RA�
Mթ ӭ��
Mة ӭ��Mک REPEA�Mݩ REMOVE.LOCAL�M� RA٭��M� Ҿ���	M� ҽ�	M�� ҽ�M�� ҽ����	M� ҽ�M� ҽ����	M� ҽ�	M� ҽ�	M� ҽ�	M � ҽ�	M$� ҽ�	M'� ҽ�
M1� Ҽ��	M;� Һ�	MD� Һ�MG� Һ����	MR� Һ�M]� Һ����	Mh� Һ�	Mq� Һ�	Mu� Һ�Mx� R.SWA�M|� R.FO�	M� ҭ�	M�� ҭ�M�� ҭ����	M�� ҭ�M�� ҭ����	M�� ҭ�	M�� ҭ�	Mƪ ҭ�	Mͪ ҭ�
MӪ ҭ��	M֪ ҫ�	M� ҫ�M� ҫ����	M� ҫ�M�� ҫ����	M� ҫ�	M� ҫ�	M� ҫ�	M$� ҫ�	M*� Ҫ�	M3� Ҫ�M6� Ҫ����	MA� Ҫ�ML� Ҫ����	MW� Ҫ�	M`� Ҫ�	Md� Ҫ�	Mg� Ҧ�	Mp� Ҧ�Mu� Ҧ����	M�� Ҧ�M�� Ҧ����	M�� Ҧ�	M�� Ҧ�	M�� Ҧ�
M�� PRO�
M�� NEX�M�� I�M�� ENDPRO�M�� ENDI�
M�� ELS�	M�� Cӿ	M�� Cÿ
Mī BYT�Mǫ BREA�Mɫ ����Mϫ ����M֫ ����
Mܫ ���	M� ���M� ������M� ������
M� ���	M� ���
M�� ���	M�� ���	M�� ���	M� ���	M� ���
M� ���
M� ���
M� ���M� ����M!� ����M(� ����
M.� ����	M4� ���M7� ������M:� ������	M=� ���	MA� ���MD� A.FO�	MG� ���MK� ������MO� ������	MS� ���	MX� ���	M\� ���
Mb� ����	Md� ���Mh� ������Ml� ������	Mp� ���	Mu� ���	My� ���	M� ���M�� ������M�� ������	M�� ���	M�� ���	M�� ���M�� ������M�� ������	M�� ���	M�� ���	M�� ���	M�� ���	M�� ���	M�� ���	M�� ���	M�� ���	M�� ���	M�� ���	MŬ ���	Mʬ ���	Mά ���	Mլ ���M׬ �RPH�M� ��	M� ���	M� ���	M�� ���	M� ���	M� ���	M	� ���	M� ���	M� ���	M� ���	M� ���	M%� ���	M)� ���	M+� ���	M0� ��� 