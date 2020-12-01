#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node
{
	int index;
	vector<int> successors;
	vector<int> predecessors;

	char going;
	bool visited;
	int t_i;
	int n_i;
	int friendsGoing;
	int friendsNotGoing;

	node ()
	{
		going = '0';
		friendsGoing = 0;
		friendsNotGoing = 0;
		visited = false;
	}
};

struct graph
{
	vector<node> vertices;
};

int main()
{
	graph g;
	stack <int > definitelyGoing;
	stack <int > definitelyNotGoing;
	int num;
	cin>>num;
	g.vertices.resize(num);
	for (int i = 0; i < num; ++i)
	{
		g.vertices[i].index=i;
	
		int T_i;
		int N_i;
		int Friend;
		
		cin>>T_i>>N_i;
		g.vertices[i].t_i=T_i;
		g.vertices[i].n_i=N_i;

		if (T_i == 0)
		{
			definitelyGoing.push(i);
			g.vertices[i].visited = true;
		}
		else if (T_i > N_i)
		{
			definitelyNotGoing.push(i);
			g.vertices[i].visited = true;
		}

		for (int j = 0; j < N_i; ++j)
		{
			cin>>Friend;
			g.vertices[i].successors.push_back(Friend);
			g.vertices[Friend].index=Friend;
			g.vertices[Friend].predecessors.push_back(i);
		}
	}

	int min = 0;
	int max = num;

	while (!definitelyGoing.empty())
	{
		int temp = definitelyGoing.top();
		min++;
		definitelyGoing.pop();
		int size = g.vertices[temp].predecessors.size();
		for (int i = 0; i < size; ++i)
		{
			g.vertices[g.vertices[temp].predecessors[i]]. friendsGoing++;
			if (g.vertices[g.vertices[temp].predecessors[i]].visited == false && g.vertices[g.vertices[temp].predecessors[i]].friendsGoing >= g.vertices[g.vertices[temp].predecessors[i]].t_i)
			{
				definitelyGoing.push(g.vertices[temp].predecessors[i]);
				g.vertices[g.vertices[temp].predecessors[i]].visited = true;
			}
		}
	}

	while (!definitelyNotGoing.empty())
	{
		int temp = definitelyNotGoing.top();
		max--;
		definitelyNotGoing.pop();
		int size = g.vertices[temp].predecessors.size();
		for (int i = 0; i < size; ++i)
		{
			g.vertices[g.vertices[temp].predecessors[i]]. friendsNotGoing++;
			if (g.vertices[g.vertices[temp].predecessors[i]].visited == false && g.vertices[g.vertices[temp].predecessors[i]].friendsNotGoing > g.vertices[g.vertices[temp].predecessors[i]].n_i - g.vertices[g.vertices[temp].predecessors[i]].t_i)
			{
				definitelyNotGoing.push(g.vertices[temp].predecessors[i]);
				g.vertices[g.vertices[temp].predecessors[i]].visited = true;
			}
		}
	}

	cout<<min<<" "<<max<<endl;
	return 0;
}
