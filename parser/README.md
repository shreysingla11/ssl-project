
# Red Plag
python3 main.py -k <argument for size of n-grams>
## Implemented till now
### Parser

The current implementation removes all comments and extra white spaces.
Tokenization of variables: We are tokenizing names of variables and functions while special chars and c++ keywords remain unmodified.
The implementation makes use of k-grams to check for the percentage similarity among files.
A covariance matrix is being generated using the pair-wise percentage similarity between files.
For the visualization part, we are generating a scatter plot using the covariance matrix.
The implementation takes into account the location as well as frequency of occurences of k-grams.
We have implemented basic of bag-of-words, as a backup for k gram implementation.

## To be implemented

### Parser
 We aim to optimize the code for the functionalities implemented till now.
We also aim to detect intelligent plagiarism eg. one using typedef & define or changing for loop to while with same core logic although we are not sure about feasibility.
We are yet to work on hypertuning the parameter k.
 
## Citations
<ol>
<li> Using Visualization to detect Plagiarism in computer science classes - Randy L. Ribler </li>
<li> Winnowing : Local Algorithms for Document Fingerprinting - Saul Schleimer </li>
</ol>

