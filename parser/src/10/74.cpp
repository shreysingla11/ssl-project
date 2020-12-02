#include<iostream>
#include<vector>
using namespace std;
class distinct
{
    vector<int> v;
    vector<int> l;
    int n;
public:
    distinct(vector<int> g)
    {
        n=g.size();
        v.resize(n);
        l.resize(n);
        for(int i=0; i<n; i++)
        {
            v[i]=g[i];
        }

        bool b;
        for(int i=0; i<n; i++)
        {
            b=false;
            for(int j=i-1; j>=0; j--)
            {
                if(v[i]==v[j])
                {
                    b=true;
                    l[i]=j;
                    break;
                }
            }
            if(b==false)
            {
                l[i]=-1;
            }
        }
    }

    int num_distinct(int i,int j)
    {
        int r=j-i+1,k=0;
        for(int p=i; p<=j; p++)
        {
            if(l[p]>=i)
            {
                k++;
            }
        }
        return r-k;
    }
};

