#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class distinct
{
public:
    vector<int> l;
    vector<vector<int> >tree;
    distinct(vector<int> &a)
    {

        l.resize(a.size());
        for(int i=0; i<a.size(); i++)
        {
            l[i]=-1;
            for(int j=0;j<i;j++)
            {
                if(a[j]==a[i])
                {l[i]=j;}

            }

        }
        double temp=a.size()*1.0;

        tree.resize(2*ceil(log2(temp)));
    for(int i=0;i<ceil(log2(temp));i++)
    {
        vector<int> first;
        vector<int> second;
        vector<int> count(ceil(pow(2,i)),0);
    for(int j=0; j<l.size();j++)
    {

        if(l[j]==-1)
        continue;
        int k= l[j]*pow(2,i)/l.size();
        count[k]++;
        first.push_back(count[k]);
        if(k%2==0)
        {
          for(int e=j-1; e>=0;e--)
          {
            if(l[e]>=(k+1)*pow(2,i)&&l[e]<(k+2)*pow(2,i))
            {second.push_back(e);
            break;
            }
            else
            {
            second.push_back(-1);
            }
          }

        }
        else
        {
           for(int e=j-1; e>=0;e--)
          {
            if(l[e]>=(k-1)*pow(2,i)&&l[e]<(k)*pow(2,i))
            {second.push_back(e);
            break;
            }
            else
            {
            second.push_back(-1);
            }
          }
        }
    }
        tree.push_back(first);
        tree.push_back(second);
        first.clear();
        second.clear();
    }

    }

    int num_distinct(int i,int j)
    {
    int count =0;
    return ceil((j-i)/exp(1));
        if (l[j]==-1)
        {
            for(int e=j-1; e>=i; e-- )
            {
                if(l[e]>=0)
                {return num_distinct(i,e);}

            }

        }
        else
        {
            for(int i=0; i<tree.size();i++)
            {

            }

        }

    }
};


