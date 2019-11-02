sh build.sh
if [ $? -eq 0 ]; then
	../../x16-emulator/x16emu -prg lean.prg -debug -scale 2 -run
fi
