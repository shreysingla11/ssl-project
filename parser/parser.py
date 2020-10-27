import numpy as np
import re
from collections import defaultdict

def word_list(path):
	f = open(path,"r")
	#w = open("temp","w")

	pat=re.compile(r'(\/\*).+?(\*\/)',re.DOTALL)	#remove multiline comments
	s = re.sub(pat,'',f.read())

	s1=""
	for line in s.split("\n"):
		l=line.split("//",1)   #remove single line comments
		s1=s1+l[0]+"\n"


	special_char=['+','-','=','*','/','<','>','#',':','.','!']
	keywords=open("./ckeywords.txt").read().split()
	#digits = ['0','1','2','3','4','5','6','7','8','9']

	s2=""
	for char in list(s1):			#add whitespace before and after a special character
		if char in special_char:
			e=" "+char+" "
			s2+=e
		else:
			s2+=char

	text = open("temp","r")
	myword="r"
	sf=""
	for line in s2.split("\n"):
		for word in line.split():	#remove keywords and replace all words except special_char with a signature letter 'r' 
			if word in keywords:
				pass
			elif word in special_char:
				sf+=(word+" ")
			else:
				sf+="r "
		sf+="\n"

	#w.write(sf)
	return sf.split()
