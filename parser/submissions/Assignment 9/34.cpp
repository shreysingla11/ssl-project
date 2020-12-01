#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
class boolfunc
{
private:
    vector<vector<int> > a;
public:

    boolfunc()
    {
        return ;
    }
    ~boolfunc()
    {
        a.clear();
        return ;
    }
    boolfunc( boolfunc const &b)
    {
        a=b.a;
        return;
    }
    void operator+=(boolfunc const &b)
    {
        vector<vector<int> > c=b.a;
        vector<vector<int> >::iterator it;
        for(it=c.begin(); it!=c.end(); ++it)
        {
            vector<int> d=*it;
            a.push_back(d);
        }
        sort(a.begin(),a.end());
        return ;
    }
    void operator*=(boolfunc const &)
    {
        return ;
    }
    void operator~()
    {
         vector<vector<int> >::iterator it;
        for(it=a.begin(); it!=a.end(); ++it)
        {
            vector<int> b=*it;
            for(vector<int>::iterator init=b.begin(); init!=b.end(); ++init)
            {
            *init=-1*(*init);
            }
        }
        return ;
    }
    bool operator==(boolfunc const & b)
    {
        if(a==b.a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void read()
    {

        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int k;
            cin>>k;
            vector<int> b;
            for(int j=0; j<k; j++)
            {
                int c;
                cin>>c;
                if(j==0&&k==0)
                {
                    data=c;
                }
                b.push_back(c);
            }
            a.push_back(b);
        }
        sort(a.begin(),a.end());
        return;
    }

    void print()
    {
        vector<vector<int> >::iterator it;
        for(it=a.begin(); it!=a.end(); ++it)
        {
            vector<int> b=*it;
            for(vector<int>::iterator init=b.begin(); init!=b.end(); ++init)
            {
                cout<<*init<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    void subst(int i, bool v)
    {
        return ;
    }

};

