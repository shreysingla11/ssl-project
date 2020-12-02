#include<iostream>
#include<vector>
using namespace std;
class distinct
{
public:
    vector<int>l;
    distinct(vector<int> &I)
    {
        l.resize(I.size(),-1);
        for(int i=0; i<I.size(); i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(I[j]==I[i])
                {
                    l[i]=j;
                    break;
                }
            }
        }
    }
    int num_distinct(int i,int j)
    {
        int k=0;
        for(int a=i; a<=j; a++)
        {
            if(l[a]>=i)
            {
                k++;
            }
        }
        return j-i+1-k;
    }
};
