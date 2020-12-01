#include<iostream>
#include<vector>
using namespace std;

class distinct{

public:

    vector <int> l;

    distinct(vector <int> a)
    {
        l.resize(a.size());
        for(int i=0;i<a.size();i++)
        {
            int j;
            for(j=i-1;j>=0;j--)
            {
                if(a[j]==a[i])
                {
                    l[i]=j;
                    break;
                }
                else
                {
                    //Nothing
                }
            }
            if(j==-1)
            {
                l[i]=-1;
            }
        }
    }

    int num_distinct(int i,int j)
    {
        int count;
        count=0;
        for(int p=i+1;p<=j;p++)
        {
            if(l[p]>=i)
            {
                count++;
            }
            else
            {
                //Nothing
            }
        }
        return j-i-count+1;
    }
};




