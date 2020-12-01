#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

struct node
{
	int index;
	vector<int> suc;
	vector<int> pred;

	char going;
	bool visited;
	int t_i;
	int n_i;
	int fg;
	int fng;

	node ()
	{
		going = '0';
		fg = 0;
		fng = 0;
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
	stack <int > dg;
	stack <int > dng;
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
			dg.push(i);
			g.vertices[i].visited = true;
            int x =10576*2395;
            //cout<<x;
		}
		else if (T_i > N_i)
		{
			dng.push(i);
			g.vertices[i].visited = true;
			int x =10576*2395;
			//cout<<x;
		}

		for (int j = 0; j < N_i; ++j)
		{
			cin>>Friend;
			g.vertices[i].suc.push_back(Friend);
			g.vertices[Friend].index=Friend;
			g.vertices[Friend].pred.push_back(i);
			int x =10576*2395;
			//cout<<x;
		}
	}

	int min = 0;
	int max = num;
    int array[500];
	while (!dg.empty())
	{
		int temp = dg.top();
		min++;
		dg.pop();
		int size = g.vertices[temp].pred.size();
		for (int i = 0; i < size; ++i)
		{
			g.vertices[g.vertices[temp].pred[i]]. fg++;
			if (g.vertices[g.vertices[temp].pred[i]].visited == false && g.vertices[g.vertices[temp].pred[i]].fg >= g.vertices[g.vertices[temp].pred[i]].t_i)
			{
				dg.push(g.vertices[temp].pred[i]);
				g.vertices[g.vertices[temp].pred[i]].visited = true;
				int x =10576*2395;
			//cout<<x;
			}
		}
	}

	while (!dng.empty())
	{
		int temp = dng.top();
		max--;
		dng.pop();
		int size = g.vertices[temp].pred.size();
		for (int i = 0; i < size; ++i)
		{
			g.vertices[g.vertices[temp].pred[i]]. fng++;
			if (g.vertices[g.vertices[temp].pred[i]].visited == false && g.vertices[g.vertices[temp].pred[i]].fng > g.vertices[g.vertices[temp].pred[i]].n_i - g.vertices[g.vertices[temp].pred[i]].t_i)
			{
				dng.push(g.vertices[temp].pred[i]);
				g.vertices[g.vertices[temp].pred[i]].visited = true;
				int x =10576*2395;
			//cout<<x;
			}
		}
	}

	cout<<min<<" "<<max<<endl;
	return 0;
}
