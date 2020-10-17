import re
from collections import defaultdict
#import numpy as np

# file1 = open('myfile.txt', 'r') 
# Lines = file1.readlines() 
ignore=False
count = 0
prev="-"
cty=False
op = open("o1.txt", "w") 
with open("sample1/2.cpp") as f:
    for line in f:
        if len(line.split()) == 0:
            continue
        l=len(line)
        i=-1
        for c in line :
            if cty:
                cty=False
                continue
            i+=1
            x=ord(c)
            
            if ignore:
                if i<( l-1) and c=='*' and line[i+1]=='/'  :
                    ignore=False
                    i=i+1
                    cty=True
                # prev=c    
                continue
            if i<( l-1) and c=='/' and line[i+1]=='*' :
                # prev=c
                ignore=True
                i+=1
                cty=True
                continue

            if  i<( l-1) and line[i+1]=='/' and c=='/' :
                prev=''
                break

            if x>=65 and x<=90 :
                print(c,end="",file=op)
            elif x>=97 and x<=122 :
                print(c,end="",file=op)
            else:
                # print(i)
                str=" "+c+" "
                print(str,end="",file=op)
            # prev=c

#close the file ---
op.close()
text = open("o1.txt", "r") 

d = dict() 
#myword="randomstring" # tag for all variables 
myword="r"
d[myword]=0;
# l=[x for x in line.split(" ") for line in open("./ckeywords.txt", 'r')]
l=open("./ckeywords.txt").read().split()
keydict= dict()
for k in l:
    keydict[k]=0
wordlist=[myword]
for line in text: 
    line = line.strip() 
    line = line.lower() 
    words = line.split(" ") 
    for word in words: 
        if len(word)==1:
            if x>=65 and x<=90 :
                wordlist.append(myword)
            elif x>=97 and x<=122 :
                wordlist.append(myword)
            else:
                wordlist.append(word)

        else:
            # print(word,end=" ")
            if word in keydict:
                 wordlist.append(word)
            else:     
                wordlist.append(myword)
 



        
print(wordlist)

# Strips the newline character 
#/**/