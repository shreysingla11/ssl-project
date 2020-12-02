#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

class node
{
	public :

	int t, n, going, not_going;
	vector<int> pre;
	bool checked, check_not_going;
	node()
	{
		t=0;
		n=0;
		going=0;
		not_going=0;
		checked=false;
		check_not_going=false;
	}
};

int main()
{
	int m;
	cin>>m;

	vector<node> graph;
	graph.resize(m);
	int numFriends=0;
	stack<int> def_going, def_not_going;
	int going_size=0, not_going_size=0;
	for(int i=0; i<m; i++)
	{
		scanf("%d", &graph[i].t);
		scanf("%d", &graph[i].n);

		if (graph[i].t > graph[i].n)
		{
			def_not_going.push(i);
			not_going_size++;
			graph[i].check_not_going = true;
		}

		else if (graph[i].t == 0)
		{
			def_going.push(i);
			going_size++;
			graph[i].checked = true;
		}
		for(int j=0; j<graph[i].n; j++)
		{
			int temp;
			scanf("%d", &temp);
			graph[temp].pre.push_back(i);
		}
	}

	int temp;
	while(!def_going.empty())
	{
		temp = def_going.top();
		def_going.pop();
		int x = graph[temp].pre.size();

		for(int i=0; i<x; i++)
		{
			graph[(graph[temp]).pre[i]].going++;
			if(graph[(graph[temp]).pre[i]].going>=graph[(graph[temp]).pre[i]].t && !graph[(graph[temp]).pre[i]].checked)
			{
				def_going.push(graph[temp].pre[i]);
				going_size++;
				graph[(graph[temp]).pre[i]].checked = true;
			}
		}

	}

	cout<<going_size<<" ";

	while(!def_not_going.empty())
	{
		temp = def_not_going.top();
		def_not_going.pop();
		int x = graph[temp].pre.size();

		for(int i=0; i<x; i++)
		{
			graph[(graph[temp]).pre[i]].not_going++;
			if(graph[(graph[temp]).pre[i]].n - graph[(graph[temp]).pre[i]].not_going<graph[(graph[temp]).pre[i]].t && !graph[(graph[temp]).pre[i]].check_not_going)
			{
				def_not_going.push(graph[temp].pre[i]);
				not_going_size++;
				graph[(graph[temp]).pre[i]].check_not_going = true;
			}
		}
	}

	cout<<m-not_going_size<<endl;

	return 0;
}
