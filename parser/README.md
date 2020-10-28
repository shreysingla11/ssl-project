
# Parser
## Basic functionality implemented till now
The current implementation removes all comments, extra white spaces and keywords. <br/>
We are tokenizing names of variables and functions while special chars remain unmodified. <br/>
The implementation makes use of k-grams to check for the percentage similarity among files. <br/>
A covariance matrix is being generated using the pair-wise percentage similarity between files. <br/>
For the visualization part a mesh-plot is generated using the similarity matrix. <br/>
The implementation takes into account the location as well as frequency of occurences of k-grams. <br/>
We have implemented basic bag-of-words functionality, as a backup for k gram implementation. <br/>

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

