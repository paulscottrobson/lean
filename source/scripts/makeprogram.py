# ******************************************************************************
# ******************************************************************************
#
#		Name : 		makeprogram.py
#		Purpose : 	Creates a BASIC program for dotREM to run.
#		Author : 	Paul Robson (paul@robsons.org.uk)
#		Created : 	27th October 2019
#
# ******************************************************************************
# ******************************************************************************

class BasicProgram(object):
	def __init__(self,loadAddress = 0x801):
		self.code = [] 														# code buffer
		self.lineNumber = 1000 												# next line number
		self.loadAddress = loadAddress
		self.startCode()
	#
	#		Generate starting code
	#
	def startCode(self):
		self.addLine(chr(0x99)+chr(199)+"(14)")								# PRINT CHR$(14)
		self.addLine(chr(0x9E)+str(0xA000))									# SYS 40960
	#
	#		Add a line of code
	#
	def add(self,line):
		self.addLine(chr(0x8F)+". "+line.upper().strip())					# REM. <contents>
	#
	#		Add arbitrary line of code
	#
	def addLine(self,line):
		self.appendWord(self.loadAddress+len(self.code)+len(line)+5)		# link to next
		self.appendWord(self.lineNumber) 									# line number
		self.code += [ord(x) for x in line.upper()]							# add code
		self.code.append(0)													# trailing null
		self.lineNumber += 10												# bump line number
	#
	#		Append 2 byte word
	#
	def appendWord(self,n):
		self.code.append(n & 0xFF)
		self.code.append(n >> 8)
	#
	#		Append end word
	#
	def complete(self):
		self.appendWord(0)
	#
	#		Get name of target file
	#
	def getTarget(self):
		return "generated/test.prg"
	#
	#		Dump binary code.
	#
	def writeProgram(self):
		h = open(self.getTarget(),"wb")
		h.write(bytes([self.loadAddress & 0xFF,self.loadAddress >> 8]))
		h.write(bytes(self.code))
		h.close()
	#
	#		Convert text file to loadable binary (for testing.)
	#
	def convertFile(self,source):
		src = [x.upper() for x in open(source).readlines()]
		src = [x.strip() if x.find("//") < 0 else x[:x.find("//")] for x in src]
		for l in [x for x in src if x != ""]:
			self.add(l)
		self.complete()
		self.writeProgram()

if __name__ == '__main__':
	bp = BasicProgram()
	bp.convertFile("test.src")
