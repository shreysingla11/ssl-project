
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<list>
using namespace std;

int infinity = 10000000;

struct Node
{
	vector<int > nextNodeCost;
	vector<int > good;
	vector<bool > inqueue;

	Node (int n)
	{
		nextNodeCost.resize(n);
		good.resize(4*n + 1, infinity);
		inqueue.resize(4*n + 1, false);
	}
};

int main()
{
	int n;
	cin>>n;
	Node source(n);
	vector<Node> Nodes(n, source);
	int input;
    int A[1000];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>input;
			Nodes[i].nextNodeCost[j] = input;
		}
	}

	queue<pair<int, int> > minwalk;
	minwalk.push(make_pair (0,2*n));

	Nodes[0].inqueue[2*n] = true;
	Nodes[0].good[2*n] = 0;

	while (!minwalk.empty())
	{
		pair<int, int > temp;
		temp = minwalk.front();
		int ind = temp.first;
		int gdness = temp.second;
		minwalk.pop();
		Nodes[ind].inqueue[gdness] = false;

		int multiplier;
		int upgood;
		int upcost;
		for (int i = 0; i < n; ++i)
		{
			if (Nodes[ind].nextNodeCost[i] < 0)
				multiplier = -1;
			else
				multiplier = 1;

			upgood = gdness - multiplier;
			upcost = Nodes[ind].good[gdness] + Nodes[ind].nextNodeCost[i]*multiplier;

			if (upcost < Nodes[i].good[upgood] && upgood <= 4*n)
			{
				Nodes[i].good[upgood] = upcost;
				if (Nodes[i].inqueue[upgood] == false)
				{
					minwalk.push(make_pair(i, upgood));
					Nodes[i].inqueue[upgood] = true;
				}
			}
		}
	}

	int minCost;
	for (int i = 0; i < n; ++i)
	{
		minCost = infinity;
		for (int j = 2*n; j < 4*n + 1; ++j)
		{
			minCost = min(minCost, Nodes[i].good[j]);
		}
		if (minCost == infinity)
			cout<<"infinityinity\n";
		else
			cout<<minCost<<endl;
	}
	return 0;
}
