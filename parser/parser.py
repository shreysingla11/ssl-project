import numpy as np
import re
from collections import defaultdict

def word_list(path):
	f = open(path,"r")
	#w = open("temp","w")

	pat=re.compile(r'(\/\*).+?(\*\/)',re.DOTALL)
	s = re.sub(pat,'',f.read())

	s1=""
	for line in s.split("\n"):
		l=line.split("//",1)
		s1=s1+l[0]+"\n"


	special_char=['+','-','=','*','/','[',']','{','}','<','>','(',')',';','#',',',':']
	keywords=open("./ckeywords.txt").read().split()
	#digits = ['0','1','2','3','4','5','6','7','8','9']

	s2=""
	for char in list(s1):
		
		if char in special_char:
			e=" "+char+" "
			s2+=e
		else:
			s2+=char
		"""
		x=ord(char)
		if x>=65 and x<=90:
			s2+=char
		elif x>=97 and x<=122:
			s2+=char
		else:
			e=" "+char+" "
			s2+=e
	    """

	text = open("temp","r") 
	myword="r"
	sf=""
	for line in s2.split("\n"):
		#print(line)
		for word in line.split():
			if word not in keywords and word not in special_char:
				sf+="r "
			else:
				sf+=(word+" ")
		sf+="\n"

	#w.write(sf)
	return sf.split()

