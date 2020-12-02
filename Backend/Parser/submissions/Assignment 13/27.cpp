#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int main()
{
	int num;
	scanf("%d",&num);
	vector<vector <int > > cost(num);
	vector<vector <int > > labels(num);
	vector<vector <bool > > presents(num);
	int costt;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			scanf("%d",&costt);
			cost[i].push_back(costt);
		}

		for(int j=0;j<2*num+1;j++)
		{
			labels[i].push_back(-1);
			presents[i].push_back(0);
		}
	}

	labels[0][num] = 0;
	presents[0][num] = 1;

	queue<pair<int,int> > check;
	check.push(make_pair(0,num));
	pair<int,int> copy;
	int vertex,goodness;
	while(!check.empty())
	{
		copy = check.front();
		check.pop();
		vertex = copy.first;
		goodness = copy.second;
		presents[vertex][goodness] = 0;
		for(int i=0;i<num;i++)
		{
			if(cost[vertex][i]>0)
			{
				if(labels[i][goodness-1]==-1)
				{
					labels[i][goodness-1] = labels[vertex][goodness] + cost[vertex][i];
					presents[i][goodness-1] = 1;
					check.push(make_pair(i,goodness-1));
				}
				else if(labels[i][goodness-1] > labels[vertex][goodness] + cost[vertex][i])
				{
					labels[i][goodness-1] = labels[vertex][goodness] + cost[vertex][i];
					if(presents[i][goodness-1]==0)
					{
						presents[i][goodness-1] = 1;
						check.push(make_pair(i,goodness-1));
					}
				}
			}
			else
			{
				if(labels[i][goodness+1]==-1)
				{
					labels[i][goodness+1] = labels[vertex][goodness] - cost[vertex][i];
					presents[i][goodness+1] = 1;
					check.push(make_pair(i,goodness+1));
				}
				else if(labels[i][goodness+1] > labels[vertex][goodness] - cost[vertex][i])
				{
					labels[i][goodness+1] = labels[vertex][goodness] - cost[vertex][i];
					if(presents[i][goodness+1]==0)
					{
						presents[i][goodness+1] = 1;
						check.push(make_pair(i,goodness+1));
					}
				}
			}
		}
	}

	int min;
	for(int i=0;i<num;i++)
	{
		int j=num;
		for(;j<2*num+1;j++)
		{
			if(labels[i][j]!=-1)
			{
				break;
			}
		}
		if(j == 2*num+1)
		{
			printf("infinity\n");
		}
		else
		{
			min = labels[i][j];
			for(int j=num;j<2*num+1;j++)
			{
				if(labels[i][j]!=-1 && (labels[i][j]<min))
				{
					min = labels[i][j];
				}
			}
			printf("%d\n",min);
		}
	}
	return 0;
}