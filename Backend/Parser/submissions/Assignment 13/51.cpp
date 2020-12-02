#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, bool> pid;
struct node
{
	int id;
	bool visited;
	bool good;
	vector<pid> wts;
	vector<int> goodness;
	node(int i, int n)
	{
		id = i;
		visited = false;
		for (int i=0; i<2*n+1; ++i)
			goodness.push_back(inf);
	}
};
class graph
{
	int n;
	vector<node*> adjlist;
	vector<bool> inqueue;
public:
	graph(int num)
	{
		n = num;
		int i, j, k;
		for (i=0; i<n; ++i)
		{
			adjlist.push_back(new node(i, n));
			inqueue.push_back(false);
			for (j=0; j<n; ++j)
			{
				cin >> k;
				adjlist[i]->wts.push_back(make_pair(abs(k), k<0));
			}
		}
	}
	void solve()
	{
		queue<int> q;
		bool flag = true;
		int g, i, count = 0;
		adjlist[0]->goodness[n] = 0;
		q.push(0);
		inqueue[0] = true;
		while (!q.empty()) // Loop termination to be decided
		{
			flag = true;
			int top = q.front();
			q.pop();
			inqueue[top] = false;
			++count;
			for (i=0; i<n; ++i)
			{
				if (adjlist[top]->wts[i].second)
				{
					for (g=1; g<2*n+1; ++g)
					{
						int temp = adjlist[top]->goodness[g-1]+adjlist[top]->wts[i].first;
						if (adjlist[i]->goodness[g] > temp)
						{
							adjlist[i]->goodness[g] = temp;
							if (!inqueue[i])
							{
								q.push(i);
								inqueue[i] = true;
							}
						}
					}
				}
				else 
				{
					for (g=0; g<2*n; ++g)
					{
						int temp = adjlist[top]->goodness[g+1]+adjlist[top]->wts[i].first;
						if (adjlist[i]->goodness[g] > temp)
						{
							adjlist[i]->goodness[g] = temp;
							if (!inqueue[i])
							{
								q.push(i);
								inqueue[i] = true;
							}
						}
					}
				}
				if (adjlist[i]->goodness[2*n] != inf)
					flag = false;
			}
		}
		// cout << boolalpha << q.empty() << endl;
	}
	void print()
	{
		int i, g, min = inf;
		for (i=0; i<n; ++i)
		{
			min = inf;
			// cout << "Test: " << i << " ";
			for (g=n; g<2*n; ++g)
			{
				// cout << adjlist[i]->goodness[g] << " ";
				if (min > adjlist[i]->goodness[g])
					min = adjlist[i]->goodness[g];
			}
			// cout << endl;
			if (min != inf)
				cout << min << endl;
			else
				cout << "infinity" << endl;
		}
	}
};
int main()
{
	int n;
	cin >> n;
	graph g(n);
	g.solve();
	g.print();
	return 0;
}