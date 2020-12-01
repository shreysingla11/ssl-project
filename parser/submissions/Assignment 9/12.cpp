#include<iostream>
#include <cmath>
using namespace std;
class node
{
public:
    int data;
    node *parent;
    node *left;
    node *right;
};
class boolfunc: public node
{
public:
boolfunc *left;
boolfunc *right;
boolfunc *main=new boolfunc();
    boolfunc();// - constructor that does nothing
    ~boolfunc()
    {

    };//- destructor that should free all allocated memory
    boolfunc( boolfunc const &)
    {
    };//- copy constructor
    void operator+=(boolfunc const &b)
    {
        if(b.data==this->data)
        {
            *this->left+=*b.left;
            *this->right+=*b.right;
        }
        else if(this->data < b.data)
        {
            *this->left+=b;
            *this->right+=b;
        }
        else if(this->data > b.data)
        {
            *b.left+=*this;
            *b.right+=*this;
        }

    };//- or operator
    void operator*=(boolfunc const &)
    {
    }; // - and operator
    void operator~()
    {
    }; // - not operation
    bool operator==(boolfunc const &)
    {
    }; // - check for equality.
    void read()
    {
        int n=0;
        cin>>n;
        boolfunc *temp=new boolfunc();
        boolfunc *mini=temp;
        for(int i=0; i<n; i++)
        {
            int term;
            cin>>term;
            temp->data=abs(term);
            //main->data=abs(term);
            if(term<0){
                temp->left=new boolfunc();
                temp->right=NULL;
                temp=temp->left;
            }
            else if (term>0){
                temp->right=new boolfunc();
                temp->left=NULL;
                temp=temp->right;
            }
        }
        temp=NULL;
        *main+=*mini;

    };/* - reads the function in sum of products form and
    constructs it binary tree representation.
    You can read from cin.*/
    void print()
    {
    }; // - prints out the function in the same format as the input.
    void subst(int i, bool v)
    {
    }; /*- modifies the function by setting the value
    of x_i to v. This will be a new function
    independent of x_i.*/


};

