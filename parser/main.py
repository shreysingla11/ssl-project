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
parser.add_argument("-in",dest="inn")  #name of directory with testfiles
args=parser.parse_args()

k=int(args.k)
files_in_dir=[]

for r, d, f in os.walk(args.inn):	#prepare a list of testfile names
   for item in f:
      if '.cpp' in item:
         files_in_dir.append(os.path.join(r, item))

for i in range(len(files_in_dir)):
	print (i,files_in_dir[i])	#print each filename with it's respective id

print(os.listdir(args.inn))
	
q=0
z=np.zeros((len(files_in_dir),len(files_in_dir)))  #will store similarity score
common=dict()					#stores the count of each k gram in the given batch of files
for xt in files_in_dir:
	l1=kgram(word_list(xt),k)
	for w in l1:
		if w in common.keys():
			common[w]+=1
		else:
			common[w]=1
commonset=[{e for e in common.keys() if common[e]>0.5*len(files_in_dir)}]  #store k grams which occur very often and hence are expected to be part of base file

for xt in range(len(files_in_dir)):
	print (xt)			#just to show progress
	for yt in range(xt+1,len(files_in_dir)):
		l1=kgram(word_list(files_in_dir[xt]),k)
		l2=kgram(word_list(files_in_dir[yt]),k)
		
		count=0			#number of common kgrams which are not in base file
		common_words=0
		for w in l1:
			if w not in commonset:
				if w in l2:
					count+=1
			else:
				common_words+=1
		try:
			z[xt][yt]=count/(min(len(l1),len(l2))-common_words)	#normalised similarity score
		except:
			z[xt][yt]=0

# num=len(files_in_dir)
# print("[",end="")
# for i in range(num):
# 	print("[",end="")
# 	for j in range(num):
# 		if j!=num-1:
# 			print(z[i][j],end=",")
# 		else:
# 			print(z[i][j],end="")
# 	print("]",end=",\n")
# print("]")

cmap=matplotlib.colors.ListedColormap(['green','red'])
bounds=[0,0.5,1]
norm = matplotlib.colors.BoundaryNorm(bounds, cmap.N)
img = plt.imshow(z,interpolation='nearest',cmap = cmap,norm=norm)
# plt.imshow(z,cmap="hot",interpolation="nearest")

# make a color bar
#plt.colorbar(img,cmap=cmap,norm=norm,boundaries=bounds,ticks=[0.2,0.4,0.6])
plt.show()

