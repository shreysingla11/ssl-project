#include<iostream>
#include<vector>
using namespace std;
class distinct
{
    vector<int> l;
    public:
    distinct(vector<int> v)
    {
        l.push_back(-1);
        int i=1,j=v.size();
        while(i!=j)
        {
            int m=i-1;
            while(m!=-1)
            {
                if(v[m]==v[i])
                {
                    l.push_back(m);
                    break;
                }
                m--;
            }
            l.push_back(m);
            i++;
        }
    }
    int num_distinct(int a,int b)
    {
        int count=0;
        int j=a;
        while(j<=b)
        {
            if(l[j]>=a)
            {
                count++;
            }
            j++;
        }
        return count;
    }
};
