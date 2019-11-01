cp ../source/upload.prg .
cp ../source/lean.bin .
python ../source/scripts/makeboot.py && ../../x16-emulator/x16emu -prg code.prg -scale 2 -debug -run
