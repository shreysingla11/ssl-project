#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class inv
{
public:
    int data;
    int index;
};

bool fn(inv a,inv b)
{
    if(a.data<b.data)
    {
        return true;
    }
    else
    {
        if(a.data>b.data)
        {
            return false;
        }
        else
        {
            if(a.index<b.index)return true;
            else
            {
                return false;
            }
        }
    }
}

class distinct
{
public:
    vector<inv>seq;
    vector<inv>copy;
    vector<int>l;
    distinct(vector<int>v)
    {   l.resize(v.size());
        for(int i=0; i<v.size(); i++)
        {
            inv x;
            x.data=v[i];
            x.index=i;
            seq.push_back(x);
        }
        sort(seq.begin(),seq.end(),fn);
        l[0]=-1;
        for(int i=1; i<v.size(); i++)
        {
            if(seq[i].data==seq[i-1].data)
            {
                l[seq[i].index]=(seq[i-1]).index;
            }
            else
            {
                l[seq[i].index]=-1;
            }
        }
    }
    int num_distinct(int i,int j){
    int count=0;
        for(int k=i+1;k<=j;k++){
             if(l[k]>=i)count++;
        }
        return j-i+1-count;
    }

};
