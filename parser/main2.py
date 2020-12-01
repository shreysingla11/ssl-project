from parser import word_list
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib
import numpy as np
import argparse
import os

def kgram(words,k):		#returns a set of kgrams from a list of words
	l=set()
	for i in range(len(words)-k+1):
		s=""
		for j in range(k):
			s=s+words[i+j]
		l.add(s)
	return l

parser = argparse.ArgumentParser()
parser.add_argument("-k",dest="k")	#value of k for kgrams (5 to 10 gives reasonable results)
parser.add_argument("-in1",dest="inn1")
parser.add_argument("-in2",dest="inn2")

args=parser.parse_args()

k=int(args.k)

l2 = kgram(word_list(args.inn1),k)
l1 = kgram(word_list(args.inn2),k)

# print(len(l1))

x = np.linspace(0,len(l1),len(l1)+1)
y = np.zeros(len(l1)+1)

num=0

for i,kgr in enumerate(l1):
    if kgr in l2:
        y[i]=1
        num+=1

plt.scatter(x,y,s=1)
plt.show()

# print(l1)

print(num/len(l1))


