#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

#define NINF -1000000000 
#define INF 1000000000

int n;

struct node{

	vector<int> goodness;		// good - bad
	vector<bool> isPresent;
	vector<int> adj;

	node()
	{
		goodness.resize(4*n+1,INF);
		isPresent.resize(4*n+1,false);
		adj.resize(n);

	}
};

int main()
{
	int x;
	scanf("%d",&n);
	vector<node> graph(n);
	for (int i = 0; i < n; ++i)
	{	
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&x);
			graph[i].adj[j] = x;
		}
	}



	queue<pair<int,int> > q;
	q.push(make_pair(0,2*n));

	graph[0].goodness[2*n] = 0;
	graph[0].isPresent[2*n] = 1;


	pair<int,int> v;
	int newG,newC,m;

	while(!q.empty())
	{
		v = q.front();
		q.pop();

		int no = v.first;
		int g = v.second;
		graph[no].isPresent[g] = 0;

		for (int i = 0; i < n; ++i)
		{
			m = (graph[no].adj[i] < 0)? -1 : 1;
			newC = graph[no].goodness[g] + graph[no].adj[i]*m;
			newG = g - m;
			if((0<= newG && newG<= 4*n) && newC < graph[i].goodness[newG])
			{	
				graph[i].goodness[newG] = newC;
				if(!graph[i].isPresent[newG])
				{
					q.push(make_pair(i,newG));
					graph[i].isPresent[newG] = 1;
				}
			}
		}
	}

	int val,min;

	for (int i = 0; i < n; ++i)
	{
		min = INF;
		for(int j = 2*n ; j <= 4*n ; j++)
		{
			val = graph[i].goodness[j];
			min = (min > val)?val:min; 
		}
		if(min != INF)
			printf("%d\n",min);
		else
			printf("infinity\n");
	}


	return 0;
}