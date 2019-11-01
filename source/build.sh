python3 scripts/translate.py
python scripts/makeprogram.py

rm lean.prg lean.bin upload.prg upload.bin
64tass -Wall -q -c -D loadbas=1 main.asm -o lean.prg -L lean.lst
64tass -Wall -q -c -b -D loadbas=0 main.asm -o lean.bin -L lean-bin.lst
64tass -Wall -q -c -D loadbas=0 upload.asm -o upload.prg -L upload.lst

if [ $? -eq 0 ]; then
	../../x16-emulator/x16emu -prg lean.prg -debug -scale 2 -run
fi
