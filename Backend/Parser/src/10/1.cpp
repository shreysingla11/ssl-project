#include<iostream>
#include<vector>

using namespace std;
class distinct
{
    public:
    vector <int> l;
    vector <int> p;
    distinct (vector <int> p)
    {
        int n=p.size();
        for(int i=0; i<n; i++)
        {
            l.push_back(-1);
        }
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(p[j]==p[i])
                {
                    l[i]=j;
                    break;
                }
            }
        }
    }

    int num_distinct(int i,int j)
    {
        int c,k=0,ans;
        for(c=i; c<=j; c++)
        {
            if(l[c]>=i)
            {
                k++;
            }
            }
            ans=j-i-k+1;
            return ans;

    }
};
