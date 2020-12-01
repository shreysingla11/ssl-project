#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class node{
    private :

    public :
        int val;
        node *left, *right;
        node (int key){
            val = key;
            left=NULL;
            right=NULL;
        }

};

class boolfunc{
    private:
        node *root;
        int numTerms,numLits;
        vector < vector<int> > V;
        int b1,b2,b3,b4,b5;

        node* makeTree(vector <vector<int> > vec,int k){
                    b1=0;
                    b2=0;
                    b3=0;
                    b4=0;
                    b5=0;
            node* tempNode=new node(k);
            int temp;
            temp=k;
/*
            if(vec.size()==1){
                if(vec.front().size()==1){
                    if(vec.front().front()>0){
                        node* node1=new node(-1);
                        node* node2=new node(0);
                        tempNode->left=node1;
                        tempNode->right=node2;
                    }
                    else{
                        node* node1=new node(-1);
                        node* node2=new node(0);
                        tempNode->left=node2;
                        tempNode->right=node1;
                    }
                }
            }*/
            vector< vector <int> > leftVec,rightVec;
            leftVec=vec;
            rightVec=vec;
            for (vector< vector<int> >::iterator it = leftVec.begin(); it!= leftVec.end(); it++){

                if(it->front()==temp ){//cout<<"y"<<endl;
                    if(it->size()==1){//cout<<"y"<<endl;
                        tempNode->left->val=-1;
                        tempNode->left->left=NULL;
                        tempNode->left->right=NULL;
                        b1=1;
                    }
                    else{it->erase(it->begin());}

                }
                if(it->front()==0-temp){
                    it=leftVec.erase(it);
                    if(leftVec.empty()){
                        tempNode->left->val=0;
                        tempNode->left->left=NULL;
                        tempNode->left->right=NULL;
                        tempNode->right->val=0;
                        tempNode->right->left=NULL;
                        tempNode->right->right=NULL;
                    }
                }
            }
            for (vector< vector<int> >::iterator it = rightVec.begin(); it!= rightVec.end(); it++){
                if(it->front()==temp ){
                    rightVec.erase(it);
                    if(rightVec.empty()){
                        tempNode->left->val=0;
                        tempNode->left->left=NULL;
                        tempNode->left->right=NULL;
                        tempNode->right->val=0;
                        tempNode->right->left=NULL;
                        tempNode->right->right=NULL;
                    }
                }
                if(it->front()==0-temp){
                    if(it->empty()){
                        tempNode->right->val=0;
                        tempNode->right->left=NULL;
                        tempNode->right->right=NULL;
                        b2=1;
                    }
                    else{it->erase(it->begin());}
                }
            }
            if(leftVec==rightVec){return makeTree(leftVec,k+1);}
            if(b1!=1){tempNode->left=makeTree(leftVec,k+1);}
            if(b1!=1){tempNode->right=makeTree(rightVec,k+1);}
            return tempNode;

        }
    public:
        boolfunc(){

        }
        ~boolfunc(){

        }
        boolfunc( boolfunc const &a){
            root=a.root;
            numTerms=a.numTerms;
            numLits=a.numLits;
            V= a.V;
        }
        void operator+=(boolfunc const &a){
            numTerms+=a.numTerms;

        }
        void operator*=(boolfunc const &){

        }
        void operator~(){

        }
        bool operator==(boolfunc const &){

        }
        void read(){
            cin>>numTerms;
            for (int i=1; i<=numTerms ; i++){
                vector < int > v;
                cin>>numLits;
                for (int j=1; j<=numLits; j++){
                    int x;
                    cin>>x;
                    v.push_back(x);
                }
                V.push_back(v);
            }
            root=makeTree(V,1);
        }
        void print(){
            cout << root->val;
        }
        void subst(int i, bool v){

        }

};
