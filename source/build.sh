python3 scripts/translate.py
python3 scripts/makeprogram.py

rm lean.prg lean.bin upload.prg upload.bin 2>/dev/null
64tass -Wall -q -c -D loadbas=1 main.asm -o lean.prg -L lean.lst
64tass -Wall -q -c -b -D loadbas=0 main.asm -o lean.bin -L lean-bin.lst
64tass -Wall -q -c upload.asm -o upload.prg -L upload.lst

