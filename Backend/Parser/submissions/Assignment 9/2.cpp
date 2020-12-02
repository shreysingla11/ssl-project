#include<iostream>
#include<vector>
using namespace std;
class boolfunc{
//forming node
   struct node{
        int val;
        node *L, *R;
        node(){ L = NULL;R = NULL;}
              };
//node formed
node* root = new node();
//creating a tree
public:
void createBST(vector< vector<int> > &i,int mi,int me, int ni,int ne,node* root){
               if((me-mi<0)||(ne-ni==0)) {return;}
               root->val = i[mi][ni];
               root->L = new node();
               root->R = new node();
           createBST(i,mi,me/2,ni+1,ne,root->L);
           createBST(i,(me/2)+1,me,ni+1,ne,root->R);
                                                  }
//tree created
boolfunc(){}
~boolfunc(){}
boolfunc( boolfunc const &);
void operator+=(boolfunc const &){}
void operator*=(boolfunc const &){}
void operator~(){}
bool operator==(boolfunc const &){}
//function to read a input
void read() {
//reading input
int no_of_terms;
vector< vector<int> > i;
cin>>no_of_terms;
for(int m=1;m<=no_of_terms;m++){
      int no_of_items;cin>>no_of_items;
      vector<int>j;
          for(int n=1;n<=no_of_items;n++){
                  int item;cin>>item;
                      j.push_back(item);
                                         }
           i.push_back(j);

                                    }


//creating BST
int m,n;
m = i.size();n = i[0].size();
createBST(i,0,m,0,n,root);
                    }
//printing
void printbst(node* root){
           if(root->L==NULL){return;}
           if(root->R==NULL){return;}
           printbst(root->L);
           cout<<root->val<<" ";
           printbst(root->R);
                             }
//
void print() {
       printbst(root);
                       }
                };


