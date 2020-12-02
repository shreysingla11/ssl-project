#include <iostream>
#include <vector>
using namespace std;

class distinct
{
public:
    vector<int> l;
    distinct(vector<int> in)
    {
        for(int i=0;i<in.size();i++)
        {
            l.push_back(-1);
        }

        for(int i=0;i<in.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(in[i]==in[j])
                {
                    l[i]=j;
                    break;
                }
            }
        }
    }

    int num_distinct(int a,int b)
    {
        int k=0;
        for(int i=a;i<=b;i++)
        {
            if(l[i]>=a){k++;}
        }
        return b-a+1-k;
    }
};
