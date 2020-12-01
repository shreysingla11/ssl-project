#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class distinct
{
//private:
public:
    vector<int> input;
    vector<int> L;
    vector<vector<int> > l;

    int num_distinct(int i,int j)
    {
        if(j<i) return -1;
        int count;
        int k=0;
        k=l[i][j];

        count=j-i+1-k;

        return count;
    }

    distinct(vector<int> V)
    {
        int n=V.size();
        input=V;
        vector<pair<int,int> > pairs;
        L.assign(n,-1);

        for(int i=0; i<n; i++)
        {
            pair<int,int> temp;
            temp.first=V[i];
            temp.second=i;

            pairs.push_back(temp);
        }

        sort(pairs.begin(),pairs.end());

        for(int i=0; i<n; i++)
        {

            if(i==0)continue;

            else
            {
                if(pairs[i].first==pairs[i-1].first)
                {
                    L[pairs[i].second]=pairs[i-1].second;
                }

            }

        }

        for(int i=0; i<n; i++)
        {
            vector<int> temp1;

            for(int j=0; j<n; j++)
            {

                if(j<i)
                {
                    temp1.push_back(-2);
                    continue;
                }
                if(j==i)
                {

                    temp1.push_back(0);
                    continue;
                }

                if(L[j]>=i) temp1.push_back(temp1[j-1]+1);

                else temp1.push_back(temp1[j-1]);
            }
            l.push_back(temp1);
        }

    }

};
