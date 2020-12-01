#include<iostream>
using namespace std;

class boolfunc
{
    public:
    int r; //var number
    boolfunc *left,*right; //left and rt sub trees
    boolfunc()
    {
        left=NULL;
        right=NULL;
    }
    ~boolfunc()
    {
        delete left;
        delete right;
        //  destroy();
    }
    boolfunc(boolfunc const &temp) //copy constructor
    {
        if(temp.left!=NULL)
            left=new boolfunc(*(temp.left));
        else left=NULL;
        if(temp.right!=NULL)
            right=new boolfunc(*(temp.right));
        else right=NULL;
        r=temp.r;
    }
    void operator+=(boolfunc const &temp)// or operator
    {
        //base cases
        if(temp.r==0 || r==-1)
            return;
        else if(temp.r==-1)
        {
            r=-1;
            delete left; delete right;
            left=NULL;
            right=NULL;
        }
        else if(r==0)
        {
            r=temp.r;
            left=new boolfunc(*(temp.left));
            right=new boolfunc(*(temp.right));
        }
        else
        {
            if(r<temp.r)
            {
                (*left)+=(temp);
                (*right)+=(temp);
            }
            else if(r==temp.r)
            {
                (*left)+=(*(temp.left));
                (*right)+=(*(temp.right));
            }
            else
            {
                boolfunc *dummy=new boolfunc(*this);
                r=temp.r;
                delete left; delete right;
                left=new boolfunc(*(temp.left));
                right=new boolfunc(*(temp.right));
                (*left)+=(*dummy);
                (*right)+=(*dummy);
                delete dummy;
            }
        }
    }
    void operator*=(boolfunc const &temp) // and operator
    {
        if(temp.r==-1)
            return;
        else if(temp.r==0 || r==0)
        {
            r=0;
            delete left; delete right;
            left=NULL;
            right=NULL;
        }
        else if(r==-1)
        {
            r=temp.r;
            left=new boolfunc(*(temp.left));
            right=new boolfunc(*(temp.right));
        }
        else
        {
            if(r<temp.r)
            {
                (*left)*=(temp);
                (*right)*=(temp);
            }
            else if(r==temp.r)
            {
                (*left)*=(*(temp.left));
                (*right)*=(*(temp.right));
            }
            else
            {
                boolfunc *dummy=new boolfunc(*this);
                r=temp.r;
                delete left; delete right;
                left=new boolfunc(*(temp.left));
                right=new boolfunc(*(temp.right));
                (*left)*=(*dummy);
                (*right)*=(*dummy);
                delete dummy;
            }
        }
    }
    void operator~() // not operation
    {
        if(r==0) r=-1;
        else if(r==-1) r=0;
        else
        {
            ~(*left); ~(*right);
            boolfunc *cross=new boolfunc(*left);
            (*cross)*=*right;
            (*this)+=*cross;
            delete cross;
        }
    }
    bool operator==(boolfunc const &temp) // check for equality.
    {
        if(r!=temp.r)
            return false;
        else
        {
            if(left==NULL && temp.left==NULL)
                return  (*right)==(*(temp.right));
            return (*left)==(*(temp.left)) && (*right)==(*(temp.right));
        }
    }
    void read()
    {
        int t,p,v;
        cin>>t;//no of terms
        boolfunc *a=new boolfunc;
        a->left=NULL; a->right=NULL; a->r=0;
        for(int i=0;i<t;t++)
        {
            cin>>p; //no of elements in product
            boolfunc *b=new boolfunc;
            b->left=NULL; b->right=NULL; b->r=1;
            for(int j=0;j<p;j++)
            {
                cin>>v;
                boolfunc *c=new boolfunc;
                if(v<0)
                {
                    c->left=new boolfunc;
                    c->right=new boolfunc;
                    c->r=-v;
                    c->left->r=1;
                    c->right->r=0;
                }
                else
                {
                    c->left=new boolfunc;
                    c->right=new boolfunc;
                    c->r=-v;
                    c->left->r=0;
                    c->right->r=1;
                }
                *b*=*c;
                delete c;
            }
            *a+=*b;
            delete b;
            r=a->r;
            left=a->left;
            right=a->right;
        }
    }
    void print()
    {

    }
    void subst(int i, bool v)
    {

    }
};
