#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class distinct
{
    vector<int> l;
public:
    distinct(vector<int> seq)
    {
        int x;
        for(int i=0; i<seq.size(); i++)
        {
            l.push_back(-1);
            for(int j=i-1; j>-1; j--)
            {
                if(seq[j]==seq[i])
                {
                    l[i]=j;
                    break;
                }
            }
        }
    }
    int num_distinct(int i,int j)
    {
        int count=0;
        for(int p=i+1;p<=j;p++)
        {
            if(l[p]>=i)
            {
                count++;
            }
        }
        return j-i+1-count;
    }
};
