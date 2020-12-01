#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int INF = 1000000000;

struct node
{
	vector<int > goodness;
	vector<bool > inQueue;

	node (int n)
	{
		goodness.resize(4*n + 1, INF);
		inQueue.resize(4*n + 1, false);
	}
};

int main()
{
	int n;
	cin>>n;
	node source(n);
	std::vector<node> nodes(n, source);
	int input;
	int costMatrix[n][n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>input;
			costMatrix[i][j] = input;
		}
	}

	queue<pair<int, int> > g_c;
	g_c.push(std::make_pair (0,2*n));

	nodes[0].inQueue[2*n] = true;
	nodes[0].goodness[2*n] = 0;

	while (!g_c.empty())
	{
		pair<int, int > temp;
		temp = g_c.front();
		int ind = temp.first;
		int gdness = temp.second;
		g_c.pop(); 
		nodes[ind].inQueue[gdness] = false;

		int multiplier;
		int updatedGdness;
		int updatedCost;
		for (int i = 0; i < n; ++i)
		{
			if (costMatrix[ind][i] < 0)
				multiplier = -1;
			else
				multiplier = 1;

			updatedGdness = gdness - multiplier; 
			updatedCost = nodes[ind].goodness[gdness] + costMatrix[ind][i]*multiplier; 

			if (updatedCost < nodes[i].goodness[updatedGdness] && updatedGdness <= 4*n && updatedGdness >= 0)
			{
				nodes[i].goodness[updatedGdness] = updatedCost;
				if (nodes[i].inQueue[updatedGdness] == false)
				{
					nodes[i].inQueue[updatedGdness] = true;
					g_c.push(std::make_pair(i, updatedGdness));
				}
			}
		}
	}

	int minCost;
	for (int i = 0; i < n; ++i)
	{
		minCost = INF;
		for (int j = 2*n; j < 4*n + 1; ++j)
		{
			minCost = min(minCost, nodes[i].goodness[j]);
		}
		if (minCost == INF)
			cout<<"infinity\n";
		else
			cout<<minCost<<endl;
	}
	return 0;
}
