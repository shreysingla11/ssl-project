#include <iostream>
#include <vector>
using namespace std;

class distinct
{
    int *l;
public:
    distinct(vector<int> &v)
    {
        int n=v.size();
        l=new int[n];
        for(int i=0;i<n;i++)
        {
            l[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i]==v[j])l[i]=j;
            }
        }
    }
    int num_distinct(int i,int j)
    {
        int result=j-i+1;
        for(int k=i;k<=j;k++)
        {
            if(l[k]>=i)result--;
        }
        return result;
    }
};
