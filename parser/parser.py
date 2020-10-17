import numpy as np
import re

f = open("1.cpp","r")
w = open("temp","w+")

for line in f.readlines():
	l=line.split("//",1)
	w.write(l[0])
w.close()
w = open("temp","r")

special_char=['+','-','=','*','/','[',']','{','}']

f_com = re.sub('\n','\t',w.read())
f_com = re.sub(r'(\/\*).+?(\*\/)','',f_com)
w.close()
w = open("temp","w")

w.write(f_com)


"""
while(1):
	char=f.read(1)

	if not char:
		break
	if char=="\t":
		print("Yayy")
		continue
	w.write(char)
"""