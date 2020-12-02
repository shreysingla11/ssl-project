#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class boolfunc
{
    class node
    {
    public:
        int data;
        node *left,*right;
    };
    node * tree=new node;
    node * converter(vector<vector<int> >vstoretemp)
    {
        vector<int>temp;
        bool c=false;
        for(int i=0; i<vstoretemp.size(); i++)
        {
            if(vstoretemp[i][0]>0)
                temp.push_back(vstoretemp[i][0]);
            else
                temp.push_back(-vstoretemp[i][0]);
        }
        sort(temp.begin(),temp.end());
        node *n=new node;
        n->data=temp[0];
        for(int i=0; i<vstoretemp.size(); i++)
        {
            if(vstoretemp[i][0]==temp[0])
            {
                c=true;
            }
        }
        vector<vector<int> >aftrem1;
        vector<vector<int> >aftrem2;
        for(int i=0; i<vstoretemp.size(); i++)
        {
            if(vstoretemp[i][0]==-temp[0]||(vstoretemp[i][0]!=temp[0]&&vstoretemp[i][0]!=-temp[0]))
            {
                vector<int>aftrem3;
                for(int j=1;j<vstoretemp[i].size();j++)
                {
                    aftrem3.push_back(vstoretemp[i][j]);
                }
                if(aftrem3.size()!=0)
                aftrem1.push_back(aftrem3);
            }
            if(vstoretemp[i][0]==temp[0]||(vstoretemp[i][0]!=temp[0]&&vstoretemp[i][0]!=-temp[0]))
            {
                vector<int>aftrem4;
                for(int j=1;j<vstoretemp[i].size();j++)
                {
                    aftrem4.push_back(vstoretemp[i][j]);
                }
                aftrem2.push_back(aftrem4);
            }
        }
        node *zero=new node;
        node *mone=new node;

        if(aftrem1.size()==0||aftrem2.size()==0)
        {
            zero->data=0;
            zero->left=NULL;
            zero->right=NULL;
           // n->left=zero;

            mone->data=-1;
            mone->left=NULL;
            mone->right=NULL;
           // n->left=one;
        }
        if(aftrem1.size()!=0)
        n->left=converter(aftrem1);
        else
        {
            if(c)
            {
                n->left=zero;
            }
            else
            {
                n->left=mone;
            }
        }
        if(aftrem2.size()!=0)
        n->right=converter(aftrem2);
        else
        {
            if(c)
            {
                n->right=mone;
            }
            else
            {
                n->right=zero;
            }

        }

    return n;
    }
    vector<vector<int> >mainv;
 /*void anticonverter(node *n)
 {
    vector<int>t1,t2;
    t1.push_back(-n->data);
    t2.push_back(n->data);
    anticonverter(leftp,n->left);
    anticonverter(rightp,n->right);

 }*/

public:
    boolfunc() //constructor that does nothing
    {

    }
    ~boolfunc() //destructor that should free all allocated memory
    {
        delete tree;
    }
    boolfunc( boolfunc const & other) //copy constructor
    {

    }
    void operator+=(boolfunc const &) //or operator
    {

    }
    void operator*=(boolfunc const &) //and operator
    {

    }
    void operator~() //not operator
    {


    }
    bool operator==(boolfunc const &) //check for equality.
    {

    }
    void read() //reads the function in sum of products form ,constructs it binary tree representation.
    {
        int terms,temp,value;
        cin>>terms;
        vector<vector<int> >vstore;
        for(int i=0; i<terms; i++)
        {
            cin>>temp;
            vector<int>store;
            for(int j=0; j<temp; j++)
            {
                cin>>value;
                store.push_back(value);
            }
            vstore.push_back(store);

        }
        //tree=converter(vstore);
        vstore=mainv;
    }
    void print() //prints out the function in the same format as the input.
    {
        node *temp=new node;
        temp=tree;
        vector<vector<int> >v1;
        //anticonveter(v1,tree);
        cout<<mainv.size()<<endl;
        for(int i=0;i<mainv.size();i++)
        {
            cout<<mainv[i].size()<<endl;
            for(int j=0;j<mainv[i].size();j++)
            {
                cout<<mainv[i][j]<<" ";
            }
        }

    }
    void subst(int i, bool v) //modifies the function by setting the value of x_i to v
    {

    }
};

