# RedPlag
## About The Project 

A Web based plagiarism detection tool that allows authenticated users to upload testfiles and displays the pairwise similarity results in the form of graphical visualizations. Specialized for c++ codes, the tool is capable of autodetecting base file snippets.  
The Project has Three Parts:
* Core Logic: This part contains a parser and a k-gram modelling algorithm which is used to compute pairwise similarity for a given bunch of files
* WebApp: Built using Angular Web Framework
* Integrate: Used Django Rest Framework to manage userdata, batches and source code files  
Go to the respective folder for more detailed documentation.
## Progress
* Implemented and tested k-gram model to represent code files and compute pair-wise similarity
* Color Mesh visualization for similarity matrix. 
* Built a Web Login and Register Setup
* Built a file upload/download interface in WebApp
* Implemented a rest API in Django using Django Rest Framework to manage userdata, batches and source code files
        

## Usage
```
$ cd Backend && pip install -r requirments.txt &
$ cd Frontend && npm install & 
$ ./run.sh
```
Open your browser on http://localhost:4200/ 

## References
* https://www.django-rest-framework.org/
* https://angular.io/
* Randy L. Ribler (2000): _Using Visualization to Detect Plagiarism_

## Future Plans
* Develop a Terminal Client 
* Embed Core Logic into WebApp
* Add user profile page
* Add Change password functionality
* Implement email based password reset in Django Rest API 

## Authors
* Bhavnoor Singh Marok
* Jayesh Singla
* Shrey Singla
* Tanu Goyal  
Under guidance of Prof. Amitabha Sanyal
