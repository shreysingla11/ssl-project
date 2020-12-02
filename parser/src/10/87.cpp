#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class distinct{
	std::vector<int> req;
	vector<vector<int> > first;
	vector<vector<int> > second;
public:
	distinct(std::vector<int> input)
	{
		std::map<int, int> mapping;
		req.resize(input.size());
		std::map<int, int>::iterator it;
		for (int i = 0; i < input.size(); ++i)
		{
			it = mapping.find(input[i]);
			if (it!=mapping.end())
			{
				req[i]=it->second;
				it->second=i;
			}
			else
			{
				req[i]=-1;
				mapping[input[i]]=i;
			}
		}

		int l = ceil(log2(req.size()));
		//cout<<l;
		std::vector<int> temp,hello,hi,main1,main2;
		main1.resize(req.size(),0);
		main2.resize(req.size(),0);
		int k, n=req.size(), count;
		for (int j=0;j<l;j++)
		{
			count = pow(2,j);
			temp.clear();
			temp.resize(count,0);
			hello.clear();
			hello.resize(count,-1);
			hi.clear();
			hi.resize(count,-1);
			count=0;
			for (int i=0;i<n;i++)
			{

				k = req[i]*(pow(2,j))/n;
				if (req[i]>= k*n/(pow(2,j))+n/pow(2,j+1))
				{
					temp[k] += 1;
					main2[i] = hi[k];
					hello[k] = i;
				}
				else
				{
					main2[i]=hello[k];
					hi[k]=i;
				}
				main1[i] = temp[k];
			}
			/*cout<<"First"<<endl;
			for (int i=0 ;i<n;i++)
			{
				cout<<main1[i]<<" ";
			}
			cout<<"\nSecond"<<endl;
			for (int i=0 ;i<n;i++)
			{
				cout<<main2[i]<<" ";
			}
			cout<<endl;*/
			first.push_back(main1);
			second.push_back(main2);

		}
	}
	int num_distinct(int a, int b)
	{
		int init = b - a + 1, k=0, here=req.size()/2;
		if (b==a)
			return 1;

		for (int i=0;i<(int)ceil(log2(req.size()));i++)
		{
			if (a==here)
			{
				k += first[i][b];
				break;
			}
			else if (a>here)
			{
				if (req[b]<here)
					b = second[i][b];
				if (req[b]==-1)
					break;
				here += req.size()/pow(2,i+2);
			}
			else
			{
				k += first[i][b];
				if (req[b]>=here)
					b = second[i][b];
				if (req[b]==-1)
					break;
				here -= req.size()/pow(2,i+2);
			}
		}
		k = init - k;
		return k;
	}
};


