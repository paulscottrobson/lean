# ******************************************************************************
# ******************************************************************************
#
#		Name : 		makeboot.py
#		Purpose : 	Creates a self booting installation of LEAN
#		Author : 	Paul Robson (paul@robsons.org.uk)
#		Created : 	1st Noveber 2019
#
# ******************************************************************************
# ******************************************************************************

from makeprogram import *

# ******************************************************************************
#
#							Extend Basic program class
#
# ******************************************************************************

class SelfBoot(BasicProgram):
	#
	#		Patch startcode to run uploader.
	#
	def startCode(self):
		self.addLine(chr(0x9E)+"01108")										# dummy SYS, will be patched.
		BasicProgram.startCode(self)										# standard code
		self.addLine(chr(0x9E)+"3")
	#
	#		End of program code.
	#
	def complete(self):
		BasicProgram.complete(self)											# default code (adds ending 00 00)
		for i in range(0,256):												# add 1/4k buffer
			self.code.append(0xFF)
		exePos = 0x801+len(self.code)+2										# where to run - +2 as its a .prg
		self.appendBinary("upload.prg")										# append the upload.prg file
		self.appendBinary("lean.bin")										# append the lean binary image.
		sysAddr = "{0:05}".format(exePos)									# the SYS to overwrite the dummy
		for i in range(0,5):												# patch in the dummy.
			self.code[i+5] = ord(sysAddr[i])
	#
	#		Add this binary.
	#
	def appendBinary(self,binFile):
		binAsm = [x for x in open(binFile,"rb").read(-1)]
		self.code += binAsm
	#
	#		Get target file
	#
	def getTarget(self):
		print("Target")
		return "code.prg"

if __name__ == '__main__':
	bp = SelfBoot()
	bp.convertFile("test1.src")

