"""!
@package core
This module describes the logic used to find plagiarism for code files.
We have used k-grams models for computing similarity scores.
Note that the logic autodetects Basefile efficiently and neutralises it's 
affect. Hence giving an option to add base file snippet is redundant
\n\n
Authors:\n
Bhavnoor Singh Marok	190050027\n
Jayesh Singla			190050053\n
Shrey Singla			190050114\n
Tanu Goyal				190050123\n
"""

import numpy as np
import argparse
import os
import re
from collections import defaultdict
import random

#Global Constants
##Special_char are non_alphanumeric characters which build the logic of the program
special_char=['+','-','=','*','/','<','>',':','.','!','"','\'','&','|','^',]
##These are non alphanumeric character that contain no/low logical information
other_chars=['(','{','}',')','[',']',',',';']
##Keywords are the list of reserved words of the language
keywords=[]
##Syntax for beginning of multiline comment in test data
multi_begin=''
##Syntax for ending of multiline comment in test data
multi_end=''
##Syntax for singleline comment in test data
onelinecomment=''
##Programming language of test code data
language=''

#Functions
def remove_comments(path):
	"""!Removes single and multiline comments from a code file
	
	@param path    path of code file
	@return text   code file data as string(after removing comments)
	"""
	print(path)
	file = open(path,"r")
	text = file.read()
	print(text)
	if multi_begin!='':
		#Regular Expression for multiline comments
		multi_exp=re.escape(multi_begin)+r'.+?'+re.escape(multi_end)
		pat=re.compile(multi_exp,re.DOTALL)
		text = re.sub(pat,'',text)

	if onelinecomment!='':
		text1=""
		#Regular Expression for singleline comments
		single_exp=re.escape(onelinecomment)
		for line in text.split("\n"):
			l=line.split(single_exp,1)
			text1+=l[0]+"\n"
		text=text1
	return text


def identify_special_characters(code, remove=False):
	"""!Either removes special characters from string or 
		adds a preceeding and trailing whitespace so that 
		each special character gets recognised as a separate 
		word in future.

		@param code   	 		code file data as string
		@param remove  			remove special characters if true, else add whitespaces as discribed
		@return processed_code	returns resulting string after processing
	"""
	processed_code=""
	for char in list(code):
		if char in special_char:
			if remove:
				e=" "
			else:
				e=" "+char+" "
			processed_code+=e
		elif char in other_chars:
			if remove:
				processed_code+=" "
		else:
			processed_code+=char
	return processed_code

def word_list(path):
	"""!Preprocess the code file whose path is provided i.e.
		removes comments, identifies special characters,
		removes keywords, encodes the file data and returns 
		the output as list  
		@param path    path of code file
	"""
	s1 = remove_comments(path)				#remove comments
	s2 = identify_special_characters(s1)	#identify special characters and add preceeding and trailing whitespace 
	
	sfinal=""
	for line in s2.split("\n"):
		for word in line.split():
			if word in keywords:
				pass						#remove keywords
			elif word in special_char:		
				sfinal+=(word+" ")			#special character remains as it is 
			else:
				sfinal+="r "				#all other words(variable names, function names etc) are encoded with character r
		sfinal+="\n"
	#print (sfinal)
	return sfinal.split()					#return encoded data as list


def kgram(words,k):
	'''!Takes the encoded list(representing a code file data) as input 
		and returns a set of k-grams of the encoded file. Note that K-grams 
		are stored as a set. Hence shuffling functions/ code blocks will 
		not affect the similarity score.

		@param words		encoded list (output of word_list function)
		@param k			k in k-grams
		@return kgram_set	set of kgrams
	'''
	kgram_set=set()
	for i in range(len(words)-k+1):
		s=""
		for j in range(k):
			s=s+words[i+j]
		kgram_set.add(s)
	return kgram_set


def find_keywords(files_in_dir, sample_size):
	"""!Predicts keywords of test file programming language (general case)
		based on Documents Frequency scores of words occuring in test files

		@param files_in_dir		list of test files name
		@sample_size			 
	"""
	global keywords	
	if language=='C++':
		keywords=['asm','else','new','this','auto','enum','operator','throw','bool',\
				'explicit','private','true','break','export','protected','try','case',\
				'extern','public','typedef','catch','false','register','typeid',\
				'char','float','reinterpret_cast','typename','class','for','return',\
				'union','const','friend','short','unsigned','const_cast','goto','signed',\
				'using','continue','if','sizeof','virtual','default','inline','static',\
				'void','delete','int','static_cast','volatile','do','long','struct',\
				'wchar_t','double','mutable','switch','while','dynamic_cast','namespace',\
				'template','cin','cout','return','include','bits','stdc++','iostream',\
				'stdc++','[',']','{','}','(',')',',',';','vector','map','pair','typdef','define']
		return
	if language=='Python':
		keywords=['and','as','assert','break','class','continue','def','del','elif','else',\
				'except','False','finally','for','from','global','if','import','in','is',\
				'lambda','None','nonlocal','not','or','pass','raise','return','True','try',\
				'while','with','yield','[',']','{','}','(',')',',',';']
		return

	#map of words to their document frequency
	l=dict()
	sampling = random.choices(files_in_dir, k=min(sample_size,len(files_in_dir)))
	for i in sampling:
		s1=remove_comments(i)
		s2=identify_special_characters(s1, remove=True)
		#set of words in the current file
		current_set=set()
		for line in s2.split("\n"):
			for word in line.split():
				if len(word)==1:				#so that common variable names (eg:i,j) are not included in keywords
					pass
				elif word in current_set:
					pass
				elif word in l.keys():
					l[word]+=1
					current_set.add(word)
				else:
					l[word]=1
					current_set.add(word)			
	keywords+=[i[0] for i in sorted(l.items(), key = lambda kv:(kv[1], kv[0]), reverse=True)]
	keywords=keywords[0:min(25,len(keywords))] #top 25 potential keyword (enough)
	keywords+=other_chars					#other_chars(global variable)
	print(keywords)


def result(final, threshold):
	'''!returns pairs of files along with their scores, which are above a threshold
	set by the user in the form of a string which will be downloaded as a .txt file.

	@param final		output of logic function(score matrix and list of filenames)
	@param threshold	threshold for similarity score set by the user
	@return res			result string to be downloaded as .txt file
	'''
	l = []
	for i in range(len(final['data'])):
		if final["data"][i] >= threshold:
			l.append(i)
	resultlist=[]
	n = len(final["filenames"])
	for i in l:
		file1 = i//n
		file2 = i-file1*n
		resultlist.append((final["filenames"][file1],final["filenames"][file2],final["data"][i]*100))
	resultlist.sort(key=lambda x:x[2],reverse=True)
	
	res = "File1          File2          Score\n"
	for i in resultlist:
		res += i[0]+(15-len(i[0]))*' '+i[1]+(15-len(i[1]))*' '+str(i[2])+'%\n'
	return res

def logic(path,user_id, lang='',one_line_comment='',multiline_begin='',multiline_end=''):
    """!The core functionality is defined in this function. It first removes single-line and multiline comments, 
    Identifies special characters, tokenises the code and stores kgrams of each code file. 
    Next it identifies kgrams which are common to most of the files (They represent our base code file).
    So, we take each pair of files and calculate the k-grams which are common to the files but not common to most 
    of the files.
    They form our suspicious set and will be used to calculate a score lying in 0-1, a metric
    which quantifies the probability that the pair is plagiarised.
    @param path					path to the target directory
    @param user_id				to identify the user
    @param language 			language input by user
    @param one_line_comment 	language specific symbol to remove single line comments
    @param multiline_begin 		language specific symbol to remove multiline comments
    @param multiline_end		language specific symbol to remove muliline comments
    @return final 				The final dictionary containing the filenames and resultant 2-D matrix
    """
    global multi_begin,multi_end,onelinecomment,language
    #Set Global variables
    language=lang
    if lang=='C++':
        multi_begin='/*'
        multi_end='*/'
        onelinecomment='//'
    elif lang=='Python':
        multi_begin='"""'
        multi_end='"""'
        onelinecomment='#'
    else:
        multi_begin=multiline_begin
        multi_end=multiline_end
        onelinecomment=one_line_comment
        

    dir=os.path.join(path,"src",str(user_id))
    ##k in Kgrams
    k=10
    ##Final result
    final=dict()

    ##Stores the list of filenames
    final["filenames"]=[]
    ##Store the list of file paths
    files_in_dir=[]
    ##stores the list of pairwise scores
    final["data"]=[]

    for r, d, f in os.walk(dir):
        for item in f:
            files_in_dir.append(os.path.join(r, item))

    # print(files_in_dir)
    files_in_dir.sort(key=lambda x:x.split(os.path.sep)[-1])

    for i in range(len(files_in_dir)):
        final["filenames"].append(files_in_dir[i].split(os.path.sep)[-1])
        print (i,files_in_dir[i].split('/')[-1])
    
    ## Set the global list keywords
    find_keywords(files_in_dir,50)

    ##list of sets of k-grams corresponding to each file
    kgrams=[]
    for x in range(len(files_in_dir)):
        kgrams.append(kgram(word_list(files_in_dir[x]),k))

    ##result_matrix
    z=np.zeros((len(files_in_dir),len(files_in_dir)))

    '''!This part of code is dedecated for autodetection of base file.
    If we had a base file then we would have computed its set of k-grams
	and subtracted this set from the set of common kgrams of two files
	which contribute towards similarity score. But here we are preparing 
	a list of most common k-grams(in terms of doc-frequency) which will 
	include the base file if any. It may also contain kgrams which were 
	not a part of base file. But as these k-grams are quite frequent, they 
	should be given less weightage for similarity, and hence excluding them 
	will also improve our accuracy. 
   '''
    ##map of k-grams to their doc-frequencies in the corpus
    common=dict()
    for xt in range(len(files_in_dir)):
        #l1=kgram(word_list(xt),k)
        for w in kgrams[xt]:
            if w in common.keys():
                common[w]+=1
            else:
                common[w]=1

    ##list of k-grams with high doc-frequency; these k-grams will likely come from the base file
    commonset=[{e for e in common.keys() if common[e]>0.5*len(files_in_dir)}]



    for xt in range(len(files_in_dir)):
        print (xt)						#just to get idea of progress/speed
        for yt in range(xt+1,len(files_in_dir)):
            ##number of common k-grams in file 'xt' and 'yt' which DONOT occur in commonset/basefile
            count=0
            ##number of common k-grams in file 'xt' and 'yt' which occur in commonset/basefile
            common_words=0
            for w in kgrams[xt]:
                if w not in commonset:
                    if w in kgrams[yt]:
                        count+=1
                elif w in kgrams[yt]:
                    common_words+=1
            try:
                '''!The Similarity score is proportional to the number of common/matching k-grams
                in the two files which are not present int the basefile i.e commonset. In other words,
                similarity is proportional to count. The denominator is the normalising constant.
                Ideally denominator should be the min(len(kgrams[xt]),len(kgrams[yt])-common_words,i.e.
                the maximum value 'count' could have attained. However it may cause unwanted cases 
                (eg two codes with large difference in lengths and one is subset of the other) to get high
                similarity score. Dividing by average surpresses such false positives but distorts the 
                normalising scale. However the order remains more or less the same and hence we prefer to 
                use average as divisor even though the result is not prefectly normalised.
                '''
                #But the choice is always yours to toggle and see the difference :)
                z[xt][yt]=count/((len(kgrams[xt])+len(kgrams[yt]))/2-common_words)
                #z[xt][yt]=count/(min(len(kgrams[xt]),len(kgrams[yt]))-common_words)
            except:
                z[xt][yt]=0

    for xt in range(len(files_in_dir)):
        for yt in range(len(files_in_dir)):
            final["data"].append(z[xt][yt])
    #print(result(final,0.35))
    return final
