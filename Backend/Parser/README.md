# Parser
## Basic functionality implemented till now
The current implementation removes all comments, extra white spaces and keywords. <br/>
We are tokenizing names of variables and functions while special chars remain unmodified. <br/>
The implementation makes use of k-grams to check for the percentage similarity among files. <br/>
A covariance matrix is being generated using the pair-wise percentage similarity between files. <br/>
For the visualization part a mesh-plot is generated using the similarity matrix. <br/>
The implementation is independent of the location as well as frequency of occurences of k-grams, hence jumbled codes also get detected. <br/>
We have implemented basic bag-of-words functionality, as a backup for k gram implementation. <br/>

## The Algorithm
<ol>
  <li>Keyword detection: The programme traverses through a number of file in the batch and computes the document frequency of each frequency of each word it traverses.
    Then selects the top 25 words with highest doc-frequency as keywords.</li>
  <li>Preprocessing: This involves 
    <ul>
      <li>Removing Comments</li>
      <li>Removing Keywords</li>
      <li>Tokenising variable/function names</li>
    </ul>
  </li>
  <li>K-gram modelling: The preprocessed string is then used to compute the set containing all k-grams of the string, which is the representative of a code</li>
  <li> Score: For a pair of File, the number of matching K-grams multiplied by a normalizing factor gives the similarity score.</li>
</ol>

## Features
<ul>
  <li>Invariant to nomenclature of variables/functions</li>
  <li>Robust against keyword swapping (Eg int to long; for to while)</li>
  <li>Autodetects Basefile</li>
  <li>Autodetects Keywords from test Data using Document Frequency scores</li>
  <li>Robust against code shuffling</li> 
</ul>

## To be implemented
We aim to optimize the code for the functionalities implemented till now.  <br/>
We also aim to detect intelligent plagiarism eg. one using typedef & define or changing for loop to while with same core logic although we are not sure about its feasibility.  <br/>
We are yet to work on hypertuning the parameter k.  <br/>
## Usage
Clone the repository, navigate into the project directory and run the following commands

```
$ cd parser
$ python3 main.py -k <size of n-gram> -in <path to directory containing testfiles>
```
## Citations
<ol>
<li> Using Visualization to detect Plagiarism in computer science classes - Randy L. Ribler </li>
<li> Winnowing : Local Algorithms for Document Fingerprinting - Saul Schleimer </li>
</ol>

## Note
The Algorithm uses k-gram model for encoding Code data. Values of k ranging from 5 to 10 work well. For small sized codes use small k (eg k=5 for <30 lines) for better performance.

