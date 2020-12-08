# Core Logic
A K-gram based model for computing code similarity matrix capable of auto detecting keywords and base file snippets. Specialized for C++, the model is generalized for any language. As the logical part (example arithematic/logical operations) of code contributes the most towards score, the model is able to make accurate computations invariant of base file code and various plagiarism tactics.
## The Algorithm
<ol>
  <li>Keyword detection: The programme traverses through a number of file in the batch and computes the document frequency of each frequency of each word it traverses.
    Then selects the top 25 words with highest doc-frequency as keywords.</li>
  <li> Preprocessing: This involves 
    <ul>
      <li>Removing Comments</li>
      <li>Removing Keywords</li>
      <li>Tokenising variable/function names</li>
    </ul>
  </li>
  <li> K-gram modelling: The preprocessed string is then used to compute the set containing all k-grams of the string, which is the representative of a code</li>
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

## Citations
<ol>
<li> Using Visualization to detect Plagiarism in computer science classes - Randy L. Ribler </li>
<li> Winnowing : Local Algorithms for Document Fingerprinting - Saul Schleimer </li>
</ol>

## Note
The Algorithm uses k-gram model for encoding Code data. Values of k ranging from 5 to 10 work well. For small sized codes use small k (eg k=5 for <30 lines) for better performance.

