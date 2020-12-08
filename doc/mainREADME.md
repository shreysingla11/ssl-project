Red Plag                         {#mainpage}
============
## About The Project 

A Web based plagiarism detection tool that allows authenticated users to upload testfiles and displays the pairwise similarity results in the form of graphical visualizations. Specialized for c++ codes, the tool is capable of autodetecting base file snippets.  
The Project has Four Parts:
* Core Logic: This part contains a parser and a k-gram modelling algorithm which is used to compute pairwise similarity for a given bunch of files
* Frontend: Built using Angular Web Framework
* Backend: Used Django Rest Framework to manage user data, batches and source code files  
* Terminal Client: A basic command line interface for the RedPlag API developed using NodeJS. 
Go to the respective folders for more detailed documentation.

## Features
* k-gram model to represent code files and compute pair-wise similarity
* Extensively tested and specialised for C++ and generalised to any arbitrary language
* Autodetection of base file code snippets
* Scatter Graph Visualization for Similarity Matrix
* Dynamic Graph based on threshold set by user
* Web Login and Register Setup 
* Command line Interface/ Terminal Client for our web service
* File upload/download interface in WebApp/Terminal Client
* Implemented a rest API in Django using Django Rest Framework to manage userdata, batches and source code files
* User profile page
* Change password functionality
* Detailed documentation for each part
        

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

## Authors
* **Bhavnoor Singh Marok** - [bhavnoormarok](https://github.com/bhavnoormarok)
* **Jayesh Singla** - [jayeshs999](https://github.com/jayeshs999)
* **Shrey Singla** - [shreysingla11](https://github.com/shreysingla11)
* **Tanu Goyal** - [TanuGoyal12](https://github.com/TanuGoyal12)
