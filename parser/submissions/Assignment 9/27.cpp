#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
class node
{
    public:
    int val;
    node* left;
    node* right;
    node()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
    node(int a)
    {
        val=a;
        left=NULL;
        right=NULL;
    }
    void operator+=(node const&a)
    {
        if(val==a->val&&val>=1)
        {

        }
        if(val==a->val&&val>=1)
        {

        }
    }
};
class boolfunc
{
    boolfunc* result =new boolfunc();
    node* nd;
    public:
    boolfunc()
    {

    }
    ~boolfunc()
    {

    }
    void operator+=(boolfunc const &a)
    {
        *nd+=*(a->nd);
    }
    void read()
    {
        result->nd=new node(0);
        int N;
        cin>>N;
        boolfunc* semi;
        for(int i=0;i<N;i++)
        {
            int n;
            cin>>n;
            int variable;
            cin>>variable;
            node* c;
            node* p;
            if(variable>0){ p=new node(variable);}
            if(variable<0){ p=new node(-variable);}
            for(int j=0;j<n;j++)
            {
                cin>>variable;
                if(variable<0)
                {
                    c=new node(-variable);
                    p->left=c;
                    p->right=new node(0);
                    c->val=-variable;
                }
                else
                {
                    node* c=new node(variable);
                    p->right=c;
                    p->left=new node(0);
                    c->val=variable;
                }
                if(j==n-1)
                {
                    if(variable<0)
                    {
                        c->left=new node(1);
                        c->right=new node(0);
                    }
                    else
                    {
                        c->left=new node(0);
                        c->right=new node(1);
                    }
                }
                p=c;
            }
            semi->nd=p;
            *result+=*semi;
        }
    }
};
