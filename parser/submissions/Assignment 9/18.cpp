#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int var;
    node *left,*right;
    node()
    {
        left=NULL;
        right=NULL;
    }
    ~node()
    {
        delete left;
        delete right;
        delete &var;
    }
    node operator+=(node &m)
    {
        *(this->left)+=*(m.left);
        *(this->right)+=*(m.right);
        return *this;
    }
};

class boolfunc
{
private:
public:
    node data;
    boolfunc()
    {
        ;
    }
    ~boolfunc();
    boolfunc( boolfunc const &b)
    {
        data=b.data;
    }
    void operator+=(boolfunc const &b)
    {
        if(data.var == b.data.var)
        {
            *(data.left)+=*((b.data).left);
            *(data.right)+=*((b.data).right);
        }
        else if(data.var < b.data.var)
        {
            *(data.left)+=(b.data);
            data->right+=b;
        }
        else if(data.var > b.data.var)
        {
            b.data.left+=data.left;
            b.data.right+=data.right;
            b(this);
        }
    }
    void operator*=(boolfunc const &b);
    void operator~();
    bool operator==(boolfunc const &b);
    void read()
    {
        int no;
        cin>>no;
        vector<int> len;
        vector<vector<int> > input;
        for(int i=0; i<no; i++)
        {
            int x;
            cin>>x;
            len.push_back(x);
            vector<int> v;
            for(int j=0; j<x; j++)
            {
                int y;
                cin>> y;
                v.push_back(y);
            }
            input.push_back(v);
        }
        /*
        boolfunc *sum =new boolfunc;
        sum->n=0;
        sum->flag=0;
        sum->left=NULL;
        sum->right=NULL;
        for(int i=0; i<len.size(); i++)
        {
            boolfunc *pro =new boolfunc;
            pro->n=0;
            pro->flag=-1;
            pro->left=NULL;
            pro->right=NULL;
            for(int j=0; j<(input[i]).size(); j++)
            {
                boolfunc *in =new boolfunc;
                in->n=1;
            }
        }*/
    }
    void print();
    void subst(int i, bool v);
};
/* *
int main()
{

    return 0;
}* */
