from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib
import numpy as np
import argparse
import os
import re
from collections import defaultdict
import random


special_char=['+','-','=','*','/','<','>',':','.','!',',',';','"','\'','&','|','^','#']
other_chars=['(','{','}',')','[',']']
#digits=['0','1','2','3','4','5','6','7','8','9']
keywords=[]

def remove_comments(path):
	f = open(path,"r")

	pat=re.compile(r'(\/\*).+?(\*\/)',re.DOTALL)
	s = re.sub(pat,'',f.read())

	s1=""
	for line in s.split("\n"):
		l=line.split("//",1)
		s1=s1+l[0]+"\n"

	return s1


def identify_special_characters(s1, remove=False):
	s2=""
	for char in list(s1):
		
		if char in special_char:
			if remove:
				e=" "
			else:
				e=" "+char+" "
			s2+=e
		elif char in other_chars:
			if remove:
				s2+=" "
		else:
			s2+=char
	return s2

def word_list(path):
	s1 = remove_comments(path)
	
	#keywords=open("./ckeywords.txt").read().split()
	#keywords=[]
	#digits = ['0','1','2','3','4','5','6','7','8','9']
	s2=identify_special_characters(s1)
	
	sf=""
	for line in s2.split("\n"):
		for word in line.split():
			if word in keywords:
				pass
			elif word in special_char:
				sf+=(word+" ")
			else:
				sf+="r "
		sf+="\n"

	return sf.split()


def kgram(words,k):
	l=set()
	for i in range(len(words)-k+1):
		s=""
		for j in range(k):
			s=s+words[i+j]
		l.add(s)
	return l


def find_keywords(files_in_dir, sample_size):
	l=dict()
	sampling = random.choices(files_in_dir, k=min(sample_size,len(files_in_dir)))
	for i in sampling:
		s1=remove_comments(i)
		s2=identify_special_characters(s1, remove=True)
		current_set=set()
		for line in s2.split("\n"):
			for word in line.split():
				if len(word)==1:
					pass
				elif word in current_set:
					pass
				elif word in l.keys():
					l[word]+=1
					current_set.add(word)
				else:
					l[word]=1
					current_set.add(word)
	global keywords				
	keywords+=[i[0] for i in sorted(l.items(), key = lambda kv:(kv[1], kv[0]), reverse=True)[0:25]]
	keywords+=other_chars

def logic(path,user_id):
    dir=path+"/src/"+str(user_id)
    k=10
    final=dict()
    final["filenames"]=[]
    final["data"]=[]
    files_in_dir=[]
    # print("hello")
    for r, d, f in os.walk(dir):
        for item in f:
            if '.cpp' in item:
                files_in_dir.append(os.path.join(r, item))

    # print(files_in_dir)
    files_in_dir.sort(key=lambda x:int(x.split('/')[-1][0:-4]))

    for i in range(len(files_in_dir)):
        final["filenames"].append(files_in_dir[i].split('/')[-1])
        # print (i,files_in_dir[i].split('/')[-1])
    
    find_keywords(files_in_dir,50)

    kgrams=[]
    for x in range(len(files_in_dir)):
        kgrams.append(kgram(word_list(files_in_dir[x]),k))

    z=np.zeros((len(files_in_dir),len(files_in_dir)))
    common=dict()
    for xt in range(len(files_in_dir)):
        #l1=kgram(word_list(xt),k)
        for w in kgrams[xt]:
            if w in common.keys():
                common[w]+=1
            else:
                common[w]=1
    commonset=[{e for e in common.keys() if common[e]>0.5*len(files_in_dir)}]

    for xt in range(len(files_in_dir)):
        print (xt)
        for yt in range(xt+1,len(files_in_dir)):

            count=0
            common_words=0
            for w in kgrams[xt]:
                if w not in commonset:
                    if w in kgrams[yt]:
                        count+=1
                else:
                    common_words+=1
            try:
                z[xt][yt]=count/(min(len(kgrams[xt]),len(kgrams[yt]))-common_words)
            except:
                z[xt][yt]=0

    for xt in range(len(files_in_dir)):
        for yt in range(len(files_in_dir)):
            final["data"].append(z[xt][yt])
    
    return final
