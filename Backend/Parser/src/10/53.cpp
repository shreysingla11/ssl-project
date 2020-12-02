#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class distinct
{
public:
    vector<vector<int> > query1;
    vector<vector<int> > query2;
    vector<int> l;
    distinct(vector<int> v)
    {
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            int j;
            for(j=i-1; j>=0; j--)
            {
                if(v[j] == v[i])
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
        double dbn = n;
        int logofn = log2(dbn);
        for(int i=0; i< logofn; i++)
        {
            vector<int> q1(n);
            vector<int> q2(n);
            int power = pow(2,i);
            vector<int> left2(power,-1);
            vector<int> right1(power,0);
            vector<int> right2(power,-1);
            for(int j=0; j<n; j++)
            {
                int k = (l[j]*power)/(n);
                if((l[j]>=((k*n)/power)+(n/2*power)))
                {
                    right1[k]++;
                    q2[j] = left2[k];
                    right2[k] = j;
                }
                else
                {
                    q2[j] = right2[k];
                    left2[k] = j;
                }
                q1[j] = right1[k];
            }
            query1.push_back(q1);
            query2.push_back(q2);
        }

    }
    int num_distinct(int i, int j)
    {
          int count=0;
          for(int k=i;k<=j;k++)
          {
               if(l[k]>=i)
               {
                  count++;
               }
          }
          return j-i+1-count;
    }
};
