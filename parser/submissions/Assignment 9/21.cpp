#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class node
{
public:
    int val;
    node* left;
    node* right;

};
class boolfunc: public node
{
public:
    node root;
    boolfunc* left;
    boolfunc* right;
    vector<vector<int> > v;
    boolfunc* maintree=new boolfunc();
    boolfunc()
    {
    }
    ~boolfunc()
    {
    }
    boolfunc(boolfunc const &)
    {
    }
    void operator+=(boolfunc const & f)
    {
    if(this->root.val==(f.root).val){
     *this->left+=*(f.left);
     *this->right+=*(f.right);
     }
     if(this->root.val<(f.root).val){
     *this->left+=f;
     *this->right+=f;
     }
      if(this->root.val>(f.root).val){
     *this+=*(f.left);
     *this+=*(f.right);
     }


    }
    void operator*=(boolfunc const &)
    {

    }
    void operator~()
    {
    }
    bool operator==(boolfunc const & f)
    {

    }
    void read()
    {
        int n;
        cin>>n;
        int x[n];

        for(int i=0; i<n; i++)
        {
            cin>>x[i];
            vector<int> v1;
            v.push_back(v1);
            boolfunc* tree=new boolfunc();
            boolfunc* mini=tree;
            for(int j=0; j<x[i]; j++)
            {
                int k;
                cin>>k;
                v[i].push_back(k);
                tree->root.val=abs(k);
                if(k<0){
                tree->left=new boolfunc();
                tree->right=NULL;
                tree=tree->left;
                }
                 if(k>0){
                tree->right=new boolfunc();
                tree->left=NULL;
                tree=tree->right;
                }
            }
            tree=NULL;
           *maintree+=*mini;


        }
    }
    void print()
    {
    }
    void subst(int i, bool v)
    {
    }

};
