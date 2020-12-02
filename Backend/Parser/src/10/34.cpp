#include<vector>
using namespace std;

class distinct
{
    vector<int> l;

    public:

    distinct(vector<int> in)
    {
        l.resize(in.size());
        for(int i=0;i<in.size();i++)
        {
            int pr=-1;
            for(int j=0;j<i;j++)
            {
                if(in[j]==in[i])pr=j;
            }
            l[i]=pr;
        }
    }

    int num_distinct(int i,int j)
    {
        int count=0;
        for(int k=i;k<=j;k++)
        {
            if(l[k]<i)count++;
        }
        return count;
    }
};
