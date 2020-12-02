#include<iostream>
#include<vector>
using namespace std;

class distinct
{
    vector<int>v;
    vector<int>l;
    vector<int>p;
    int find_l(int x,int index)
    {
        int max_count=-1;
        for(int i=0;i<v.size(),i!=index;i++)
        {
            if(v[i]==x)
            {
                max_count=i;
            }
        }
        return max_count;

    }
public:
    distinct(vector<int>v1)
    {
        int index=-1;
        v=v1;
        for(int i=0;i<v.size();i++)
        {
            int x=0;
            l.push_back(find_l(v[i],i));
                x=0;
            if(i==0)
            {
                p.push_back(0);
            }
            else
            {
            if(l[i]>=v.size()/2)
            {
                p.push_back(p[i-1]+1);
            }
            else
            {
                p.push_back(p[i-1]);
            }
            }

        }




    }
    int num_distinct(int i,int j)
    {
        int k=0;
        for(int x=i;x<=j;x++)
        {
            if(l[x]>=i)
            {
                k++;
            }
        }
        return j-i+1-k;
    }

};



