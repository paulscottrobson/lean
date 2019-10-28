# ******************************************************************************
# ******************************************************************************
#
#		Name : 		translate.py
#		Purpose : 	Converts translations to Matches
#		Author : 	Paul Robson (paul@robsons.org.uk)
#		Created : 	27th October 2019
#
# ******************************************************************************
# ******************************************************************************

import re,os,sys

# ******************************************************************************
#
#								Match class
#
# ******************************************************************************

class Match(object):
	def __init__(self,classType,match,code):
		classType = classType.upper()
		assert len(classType) == 1 and "PSICLBW*".find(classType) >= 0
		self.classType = classType
		self.match = match.lower()
		self.match = self.match.replace("<proc>","*").replace("<const>","*").replace("<var>","*")
		assert match != ""
		self.code = code.strip()
		self.label = None
		#print(self.classType,self.match,self.code,self.getEncodedMatch())
	#
	#		Encoded Match.
	#
	def getEncodedMatch(self):
		s = self.match.strip().upper().replace(" ","")
		s = s.replace("*",self.classType.lower())
		return s
	#
	#		Render.
	#
	def render(self,h,matchBook,labelID):
		self.label = "L{0:05}".format(labelID)
		h.write(";\n;\t\t** {0}:{1} [{2}] **\n;\n".format(self.getMatch(),self.getClassType(),self.getEncodedMatch()))
		h.write(self.label+":\n")		
		h.write("\t.byte {0}_END-{0}-1\n".format(self.label))
		for cmd in [x.strip().lower() for x in self.getCode().split(";") if x.strip() != ""]:
			if cmd == "[data]":
				h.write("\t.byte ${0:02x}\n".format(Match.C_SETDATA))
			elif cmd.startswith("[exec:") and cmd.endswith("]"):
				n = matchBook.addExecutable(cmd[6:-1])
				h.write("\t.byte ${0:02x},${1:02x}\n".format(Match.C_EXEC,n))
			else:
				absolute = (self.classType == "L" or self.classType == "C" or self.classType == "P")
				cmd = cmd.replace("<low>","${0:02x}".format(Match.C_LOW))
				cmd = cmd.replace("<high>","${0:02x}".format(Match.C_HIGH))
				addr = Match.C_LOW+Match.C_HIGH*256 if absolute else Match.C_LOW
				cmd = cmd.replace("<addr>","${0:x}".format(addr))
				addr = Match.C_LOWPLUS1+Match.C_HIGH*256 if absolute else Match.C_LOWPLUS1
				cmd = cmd.replace("<next>","${0:x}".format(addr))
				h.write("{0}{1}\n".format("" if cmd.endswith(":") else "\t",cmd))
		h.write(self.label+"_END:\n")
	#
	#		Accessor/Mutator
	#
	def getClassType(self):
		return self.classType
	def getMatch(self):
		return self.match
	def getCode(self):
		return self.code
	def getKey(self):
		return self.getEncodedMatch()
	def getLabel(self):
		return self.label
	#
	#		Information store (type BWISCL*), encoded match, label for match.
	#
	def getStore(self):
		return self.getClassType()+":"+self.getEncodedMatch()+":"+self.label

Match.C_ISZERO = 	0x53
Match.C_LOW = 		0x63
Match.C_HIGH = 		0x73
Match.C_LOWPLUS1 = 	0x83
Match.C_SETDATA = 	0x93
Match.C_EXEC = 		0xA3

# ******************************************************************************
#
#							A collection of matches
#
# ******************************************************************************

class MatchBook(object):
	def __init__(self):
		self.matches = {} 												# match -> Match()		
	#
	#		Load matches in.
	#
	def load(self,fileName):
		src = [x.replace("\t"," ") for x in open(fileName).readlines()]	# preprocess
		src = [x if x.find("//") < 0 else x[:x.find("//")] for x in src]
		src = [x.rstrip().upper() for x in src if x.rstrip() != ""]
		src = [x if x.startswith(" ") else "|"+x for x in src]			# | seperator
		src = ";".join(src)												# stick together
		src = re.split("(\\|[ZPSICLBW\\*]+\\s+.*?)\\;",src)					# split up
		src = [x for x in src if x != ""]								# remove blanks.
		while len(src) != 0:
			m = re.match("^\\|([ZPSICLBW\\*]+)\\s*(.*?)$",src[0])			# check the header.
			assert m is not None,"Bad Header "+src[0]
			src.pop(0)													# remove it
			body = ""
			if len(src) != 0 and not src[0].startswith("|"):			# is there a body
				body = src.pop(0)
			typeList = [x for x in m.group(1)]
			if m.group(1).find("S") >= 0: 								# append short/int
				typeList.append('C') 									# absolute versions.
			if m.group(1).find("I") >= 0:
				typeList.append('L')
			if typeList[0] == 'Z' and len(typeList) == 1:
				typeList = ['S']
			while len(typeList) != 0:
				match = Match(typeList.pop(),m.group(2),body) 			# get compressed
				key = match.getKey()									# store in matches
				assert key not in self.matches,"Duplicate "+key
				self.matches[key] = match
	#
	#		Add an executable.
	#
	def addExecutable(self,name):
		self.executables.append(name.lower().strip())
		return len(self.executables)-1
	#
	#		Generate assembly representation of definitions
	#
	def generateCodeList(self,h = sys.stdout):
		self.nextLabel = 10000 											# label allocation
		self.executables = []											# enumerated executables
		keys = [x for x in self.matches.keys()]							# keys in reverse order
		keys.sort()
		keys.reverse()
		for k in keys:
			self.matches[k].render(h,self,self.nextLabel)
			self.nextLabel += 1
	#
	#		Generate the executable vector table.
	#
	def generateExecutableTable(self,h = sys.stdout):
		h.write(";\n;\t\tVector Table for executable commands\n;\n")
		h.write("ExecutableVectorTable:\n")
		for i in range(0,len(self.executables)):
			h.write("\t.word {0:32} ; {1}\n".format("Action_"+self.executables[i],i))
	#
	#		Generate entire dictionary.
	#
	def generateDictionary(self,h = sys.stdout):
		keys = [x for x in self.matches.keys()]							# keys in reverse order
		keys.sort()
		keys.reverse()
		h.write("SystemDictionary:\n")		
		for k in keys:
			m = self.matches[k]
			self.generateDictionaryEntry(h,'M',m.getLabel(),"0",m.getEncodedMatch())
		#self.createTestVariable(h,'v_ab1','S',0x604)
		#self.createTestVariable(h,'v_zw2','I',0x64)
		#self.createTestVariable(h,'v_aw3','I',0x614)
		#self.createTestVariable(h,'v_zb4','S',0xF4)
		#self.createTestVariable(h,'pdemo','P',0xFFD2)
		h.write(";\n\t.byte\t$00\n")
	#
	#		Generate dictionary entry
	#
	def generateDictionaryEntry(self,h,typeByte,address,bank,key):
		h.write(";\n;\t\t**** {0} ****\n;\n".format(key))
		h.write("\t.byte\t{0}\n".format(len(key)+6))
		h.write("\t.byte\t'{0}'\n".format(typeByte))
		h.write("\t.word\t{0}\n".format(address))
		h.write("\t.byte\t{0}\n".format(bank))
		h.write("\t.byte\t{0}\n".format(len(key)))
		key = re.split("([A-Za-z0-9\\.\\_\\$\\%]+)",key)
		for i in range(0,len(key)):
			if re.match("^[A-Za-z0-9\\.\\_\\$\\%]+$",key[i]):
				key[i] = key[i][:-1]+chr(ord(key[i][-1])+0x80)
			else:
				key[i] = "".join([chr(ord(c)+0x80) for c in key[i]])
		key = "".join(key)
		assert ord(key[-1]) >= 0x80
		key = ",".join(["${0:02x}".format(ord(c)) for c in key])
		h.write("\t.byte\t{0}\n".format(key))
	#
	#		Create a test variable.
	#
	def createTestVariable(self,h,name,oType,address):
		self.generateDictionaryEntry(h,oType,"${0:x}".format(address),0,name.upper())
	#
	#
	#
	def createConstants(self,h):
		h.write(";\n;\t\tAutomatically generated.\n;\n")
		cgc = { "CGEN_C_ISZERO":Match.C_ISZERO, "CGEN_C_LOW":Match.C_LOW, 
				"CGEN_C_HIGH":Match.C_HIGH, "CGEN_C_LOWPLUS1":Match.C_LOWPLUS1, 
				"CGEN_C_SETDATA":Match.C_SETDATA, "CGEN_C_EXEC":Match.C_EXEC }
		for n in cgc.keys():
			h.write("{0} = ${1:02x}\n".format(n,cgc[n]))

m = MatchBook()
print("Processing definitions ...")
for root,dirs,files in os.walk("definitions"):
	for f in files:
		if f.endswith(".def"):
			print("\tProcessing {0}".format(root+os.sep+f))
			m.load(root+os.sep+f)

h = open("generated"+os.sep+"system.inc","w")			
h.write(";\n;\t\tAutomatically generated.\n;\n")
m.generateCodeList(h)
m.generateExecutableTable(h)
m.generateDictionary(h)
h.close()
m.createConstants(open("generated"+os.sep+"cgconst.inc","w"))