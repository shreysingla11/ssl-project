#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class distinct
{

public:
    vector<int>l;

	distinct(vector<int> v)
	{
		vector<pair<int,int> >p;
		int len=v.size();
		p.resize(len);
		for(int i=0;i<len;i++)
		{
			p[i].first=v[i];
			p[i].second=i;
		}
		sort(p.begin(),p.end());

		l.resize(len,-1);
		for(int i=1;i<len;i++)
		{
			if(p[i].first==p[i-1].first)
			{
				l[p[i].second]=p[i-1].second;
			}
		}
	}

	int query(int low,int high)
	{
        int k=0;
        for(int i=low;i<=high;i++)
        {
            if(l[i]>=low)
            {
                k++;
            }
        }
        return high-low+1-k;
    }
};


