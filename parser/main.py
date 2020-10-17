from parser import word_list
import matplotlib.pyplot as plt
import numpy as np
import argparse

def kgram(words,k):
	l=[]
	for i in range(len(words)-k+1):
		s=""
		for j in range(k):
			s=s+words[i+j]
		l.append(s)
	return l

parser = argparse.ArgumentParser()
parser.add_argument("-k",dest="k")
args=parser.parse_args()

k=int(args.k)

l1=kgram(word_list('./1.cpp'),k)
l2=kgram(word_list('./2.cpp'),k)

#print(kgram(l1,k))

x = np.arange(len(l1))
y = np.zeros(len(l1))

for i,w in enumerate(l1):
	if w in l2:
		y[i]=1
	else:
		y[i]=0

plt.scatter(x,y,s=1)
plt.show()

