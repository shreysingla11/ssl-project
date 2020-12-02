#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
class node
{
public:
    int var;
    int pos;
    int sign;
    node *left;
    node *right;
    node(int a,int c)
    {
        var=abs(a);
        pos=c;
        left=NULL;
        right=NULL;
        sign=a/var;
    }
};
class boolfunc:public node
{
private:
    node *root;
    void form(vector<queue<int> >&v,vector<queue<int> >&a,vector<queue<int> >&b)
    {
        int i=0;
        if(v[i].empty())
        {
            a.erase(a.begin(),a.end());
            b.erase(b.begin(),b.end());
            return;
        }
        int t=abs(v[0].front());
        while(i!=v.size())
        {
            if(v[i].empty())
            {
                a.erase(a.begin(),a.end());
                b.erase(b.begin(),b.end());
                return;
            }
            if(v[i].front()==t*(-1))
            {
                v[i].pop();
                a.push_back(v[i]);
            }
            else if(v[i].front()==t)
            {
                v[i].pop();
                b.push_back(v[i]);
            }
            else
            {
                a.push_back(v[i]);
                b.push_back(v[i]);
            }
            i++;
        }
        return;
    }
    void create(node *r,vector<queue<int> >&v)
    {
        vector<queue<int> >a;
        vector<queue<int> >b;
        if(v[0].empty())
        {
            r->var=1;
            r->pos=1;
            r->sign=1;
            return;
        }
        int x=v[0].front();
        form(v,a,b);
        r->var=abs(v[0].front());
        r->pos=0;
        r->sign=v[0].front()/r->var;
        if(a.empty())
        {
            r->left=new node(0,1);
        }
        else if(b.empty())
        {
            r->right=new node(0,1);
        }
        else
        {
            r->left=new node(0,0);
            r->right=new node(0,0);
            create(r->left,a);
            create(r->right,b);
        }
    }
public:
    boolfunc()
    {

    }
    boolfunc( boolfunc const &)
    {

    }
    void operator+=(boolfunc const &s)
    {

    }
    void operator*=(boolfunc const &p)
    {

    }
    void operator~()
    {

    }
    bool operator==(boolfunc const &e)
    {

    }
    void read()
    {
        int n;
        cin>>n;
        vector<queue<int> >v(n);
        int i=0;
        while(i!=n)
        {
            queue<int> q;
            int m,j=0;
            cin>>m;
            while(j!=m)
            {
                int x;
                cin>>x;
                q.push(x);
                j++;
            }
            v[i]=q;
            i++;
        }
        root=new node(1,0);
        create(root,v);
    }
    void print()
    {
        ;
    }
    void subst(int i, bool v)
    {
        ;
    }
    ~boolfunc()
    {
        ;
    }
};
