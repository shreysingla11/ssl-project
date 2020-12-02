#include<iostream>
using namespace std;
/*class node
{
    int var;
    node *one,*zero;
    node()
    {
        one=NULL;
        zero=NULL;
    }
};*/
class boolfunc
{
    //node *root;
    //int var;
public:
    boolfunc *zero,*one;
    int var;
    boolfunc() //- constructor that does nothing
    {
        zero=NULL;
        one=NULL;
    }
    boolfunc(int val)
    {
        var=val;
        zero=NULL;
        one=NULL;
    }
    ~boolfunc()//- destructor that should free all allocated memory
    {

    }
    boolfunc( boolfunc const &temp)// - copy constructor
    {

    }
    void operator+=(boolfunc const &)//- or operator
    {

    }
    void operator*=(boolfunc const &)// - and operator
    {

    }
    void operator~() //- not operation
    {
        if(this->zero==NULL && this->one==NULL)
        {
            this->var=1-this->var;
            return ;
        }
        else if(this->zero==NULL) ~*(this->one);
        else if(this->one==NULL) ~*(this->zero);
        else
        {
            ~*(this->one);
            ~*(this->zero);
        }
    }
    bool operator==(boolfunc const &temp)//- check for equality.---DONE
    {
        if(var!=temp.var)return false;
        else
        {
            if(temp.zero==NULL && zero==NULL && temp.zero==NULL && zero==NULL)return true;
            if(temp.zero!=NULL && temp.one!=NULL && zero!=NULL && one!=NULL)
                return (zero==temp.zero && one==temp.one) ;
            else if(temp.zero==NULL && zero==NULL)return one==temp.one;
            else if(temp.one==NULL && one==NULL)return zero==temp.zero;
            else return false;
        }
    }
    void read()//- reads the function in sum of products form and constructs it binary tree representation.
    {
        int terms,vars,**exp;
        boolfunc tree,*node,*now;
        cin>>terms;
        exp=new int*[terms];
        for(int i=0; i<terms; i++)
        {
            cin>>vars;
            exp[i]=new int[vars];
            for(int j=0; j<vars; j++)
            {
                cin>>exp[i][j];
                if(exp[i][j]<0)
                {
                    node=new boolfunc(-exp[i][j]);
                    node->one=NULL;
                    now=node->zero;

                }
                else
                {
                    node=new boolfunc(exp[i][j]);
                    node->zero=NULL;
                    now=node->one;
                }
            }

        }
    }
    void print()//- prints out the function in the same format as the input.
    {

    }
    void subst(int i, bool v)//- modifies the function by setting the value of x_i to v. This will be a new function independent of x_i.
    {

    }

};

int main()
{
    return 0;
}
