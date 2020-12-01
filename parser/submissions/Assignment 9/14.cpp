#include<iostream>
#include<vector>
#include<stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
extern class boolfunc
{
private:
    node main;
    vector< vector<int> >v;
    vector< vector<int> >vleft;
    vector< vector<int> >vright;
    int n,nleft,nright;
public:
    boolfunc()
    {

    }
    ~boolfunc()
    {

    }
    boolfunc( boolfunc const &b)
    {
        this->v=b.v;
    }
    void operator+=(boolfunc const &b)
    {

    }
    void operator*=(boolfunc const &b)
    {

    }
    void operator~()
    {

    }
    bool operator==(boolfunc const &b)
    {
        if(this->v==b.v)
        {
            return true;
        }
        else{return false;}
    }
    void read()
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int x;
            vector<int>temp;
            cin>>x;
            for(int j=0; j<x; j++)
            {
                int val;
                cin>>val;
                temp.push_back(val);
            }
            v.push_back(temp);
        }
        createbtree();
    }
    void createbtree()
    {
        int mainval=v[0][0];
        for(int i=0; i<n; i++)
        {
            if(find(v[i].begin(), v[i].end(), mainval)!=v[i].end()||find(v[i].begin(), v[i].end(),-1* mainval)!=v[i].end())
            {
                if ( find(v[i].begin(), v[i].end(), mainval)!=v[i].end() )
                {
                    v[i].erase(remove(v[i].begin(), v[i].end(), mainval), v[i].end());
                    vright.push_back(v[i]);
                }
                if ( find(v[i].begin(), v[i].end(), -1*mainval)!=v[i].end() )
                {
                    v[i].erase(remove(v[i].begin(), v[i].end(), -1*mainval), v[i].end());
                    vleft.push_back(v[i]);
                }
            }

            else
            {
                vleft.push_back(v[i]);
                vright.push_back(v[i]);
            }
        }
        if(vleft!=vright)
        {
            main->val=mainval;
            main.left.v=vleft;
            main.left.n=nleft;
            main.left.createbtree();
            main.right.v=vright;
            main.right.n=nright;
            main->right.createbtree();
        }
        else
        {
            v=vleft;
            n=nleft;
            createbtree();
            main.left.v=vleft;
            main.left.createbtree();
            main.right.v=vright;
            main->right.createbtree();
        }

    }
    void print()
    {
        cout<<n<<endl;
        for(int i=0; i<n; i++)
        {
            int size=v[i].size();
            cout<<size<<endl;
            for(int j=0; j<size; j++)
            {
                cout<<v[i][j]<<" ";
            }
        }
    }

    void subst(int i, bool v)
    {
    for(int i=0; i<n; i++)
        {

        }
    }
};

