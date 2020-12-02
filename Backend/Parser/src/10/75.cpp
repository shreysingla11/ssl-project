#include <iostream>
#include <vector>
using namespace std;
class distinct
{
public:
    vector<int> v;
    vector<int> l;
    vector<vector<int> > r;
    distinct(vector<int> a)
    {
        v=a;
        l.push_back(-1);
        for(int i=1; i<v.size(); i++)
        {
            int j;
            for(j=i-1; j>=0; j--)
            {
                if(v[i]==v[j])
                {
                    l.push_back(j);
                    break;
                }
            }
            if(j==-1)
            {
                l.push_back(-1);
            }
        }
        r.resize(v.size());
        for(int i=0; i<v.size(); i++)
        {
            (r[i]).resize(v.size());
        }
        for(int i=0; i<v.size(); i++)
        {
            r[i][i]=0;
            for(int j=i; j<v.size()-1; j++)
            {
                if(l[j+1]>=i){r[i][j+1]=r[i][j]+1;}
                else{r[i][j+1]=r[i][j];}
            }
        }
    }
    int num_distinct(int i,int j)
    {
        return j-i+1-r[i][j];
    }
};
