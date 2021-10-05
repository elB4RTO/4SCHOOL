#!/usr/bin/python3

from gmpy2 import *

class Loop(object):
	def __init__(self):
		self.choice = 0
		self.module = self.phase = self.real = self.immag = 0.0
	
	def pol2rec(self):
		self.module	= float(input("\033[0m\nSET THE MODULE : "))
		self.phase	= radians(float(input("SET THE PHASE : ")))
		
		self.aux	= str(rect(self.module,self.phase))
		
		if self.aux.find('+'):	self.aux = self.aux.split('+')
		else:					self.aux = self.aux.split('-')
		
		self.real	= float( self.aux[0] )
		self.immag	= float( self.aux[1].rstrip('j') )
		
		if self.immag >= 0:
			return "\n\033[1mRESULT :\033[0m {} + j{}".format( self.real, self.immag )
		else:
			return "\n\033[1mRESULT :\033[0m {} - j{}".format( self.real, self.immag*(-1) )

	def rec2pol(self):
		self.real	= float(input("\033[0m\nSET THE REAL NUMBER : "))
		self.immag	= float(input("SET THE IMAGINARY NUMBER : "))
		
		if self.immag >= 0:
			self.module, self.phase = polar(mpc("%s+%sj" %(self.real, self.immag)))
		else:
			self.module, self.phase = polar(mpc("%s%sj"  %(self.real, self.immag)))
		self.phase	= degrees(self.phase)
		
		return "\n\033[1mRESULT :\033[0m {} ∢ {}".format( self.module, self.phase )
	
	def mkChoice(self):
		print("\n\033[1mOPTIONS\033[0m\n[\033[1;35m1\033[0m] POLAR -> RECTANGULAR\n[\033[1;35m2\033[0m] RECTANGULAR -> POLAR")
		return int(input("\033[3mCHOOSE ONE :\033[0;1m "))
	
	
def main():
	loop = Loop()
	choice = loop.mkChoice()
	if   choice == 1:	print( loop.pol2rec() )
	elif choice == 2:	print( loop.rec2pol() )
	else:				print("\n\033[91mINVALID CHOICE\033[0m")
	input("\n\033[90mPress \033[3mENTER\033[0;90m to Redo or \033[3mCTRL+Z\033[0;90m to Exit ...\033[0m")


if __name__ == "__main__":
	print("\033[1;31mCONVERT POLAR TO RECTANGULAR COORDINATES AND VICE-VERSA\033[0m")
	while True:
		main()
