python3 scripts/translate.py
python scripts/makeprogram.py

64tass -Wall -q -c main.asm -o lean.prg -L lean.lst
if [ $? -eq 0 ]; then
	../../x16-emulator/x16emu -prg lean.prg -debug -scale 2 -run
fi