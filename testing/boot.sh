pushd ../source
sh build.sh
cp upload.prg lean.bin ../testing
popd
python3 ../source/scripts/makeboot.py && ../../x16-emulator/x16emu -prg code.prg -scale 2 -debug -run
