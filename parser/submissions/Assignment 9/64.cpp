#include<iostream>
using namespace std;
class node
{
    public:
    int var,val;
    node *left,*right;
    node()
    {
    left=NULL;
    right=NULL;
    }
    ~node()
    {
        if(left!=NULL)
        {
        if(left->left==NULL && left->right==NULL)
        {
          delete left;
        }
        else
        {
            left->~node();
        }
        }
        if(right!=NULL)
        {
        if(right->left==NULL && right->right==NULL)
        {
            delete right;
        }
        else
        {
            right->~node();
        }
        }
    }
};
class boolfunc
{
    node *N;
public:
    boolfunc() //constructor that does nothing
    {
    N= new node();
    }
    ~boolfunc() //destructor that should free all allocated memory
    {

        N->~node();
        delete N;
    }
    boolfunc( boolfunc const &f) //copy constructor
    {




    }
    void operator+=(boolfunc const &f) //or operator
    {
        if(N->var<(f.N)->var)
        {
            boolfunc fl;
            fl.N=N->left;
            fl+=f;
            boolfunc fr;
            fr.N=N->right;
            fr+=f;
            fl.N=NULL;
            fr.N=NULL;
            return;
        }
        if(N->var > (f.N)->var)
        {
            boolfunc f1(f);
            boolfunc f1l,f1r;
            f1l.N=(f.N)->left;
            f1r.N=(f.N)->right;
            f1l+=(*this);
            f1r+=(*this);
            (N->left)->~node();
            (N->right)->~node();


        }
    }
    void operator*=(boolfunc const &f) //and operator
    {}
    void operator~() //not operation
    {}
    bool operator==(boolfunc const &f) //check for equality.
    {}
    void read() //reads the function in sum of products form and constructs
                //it binary tree representation.
    {}
    void print() //prints out the function in the same format as the input.
    {}
    void subst(int i, bool v) //modifies the function by setting the value
                              //of x_i to v. This will be a new function
						      //independent of x_i.
    {}

};
