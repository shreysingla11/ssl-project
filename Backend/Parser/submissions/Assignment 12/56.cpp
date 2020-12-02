#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstdio>
using namespace std;
struct node
{
	int id;
	int threshold;
	int sure; // 0 - going, 1- not going, -1 - unsure
	int no_of_friends;
	int yes_fr;
	int no_fr;
	list<int> pred;
	node(int id1)
	{
		id = id1;
		sure = -1;
		yes_fr = 0;
		no_fr = 0;
	}
};
class graph
{
	int n;
	int total_yes;
	int total_no;
	vector<node*> adjlist;
public:
	graph(int num)
	{
		int i, j, th, k, fr;
		n = num;
		total_no = total_yes = 0;
		for (i=0; i<n; ++i)
		{
			node *socnet = new node(i);
			adjlist.push_back(socnet);
		}
		for (i=0; i<n; ++i)
		{
			scanf("%d %d", &th, &k);
			adjlist[i]->threshold = th;
			adjlist[i]->no_of_friends = k;
			if (th == 0)
			{
				adjlist[i]->sure = 0;
				++total_yes;
			}
			else if (th > k)
			{
				adjlist[i]->sure = 1;
				++total_no;
			}
			adjlist[i]->id = i;
			for (j=0; j<k; ++j)
			{
				scanf("%d", &fr);
				(adjlist[fr])->pred.push_back(i);
			}
		}
	}
	void check()
	{
		int i;
		for (i=0; i<n; ++i)
		{
			cout << adjlist[i]->threshold << " ";
			for (list<int>:: iterator it = adjlist[i]->pred.begin(); it!=adjlist[i]->pred.end(); ++it)
				cout << *it << " ";
			cout << endl;
		}
	}
	void solve()
	{
		int i;
		queue<int> q;
		for (i=0; i<n; ++i)
		{
			if (adjlist[i]->sure == 0 || adjlist[i]->sure == 1)
			{
				// cout << i << " ";
				q.push(i);
			}
		}
		// cout << endl;
		int present;
		list<int>:: iterator it;
		while (!q.empty())
		{
			present = q.front();
			q.pop();
			for (it = adjlist[present]->pred.begin(); it!=adjlist[present]->pred.end(); ++it)
			{
				// cout << "*it" << *it << endl;
				if (adjlist[*it]->sure == 1 || adjlist[*it]->sure == 0)
					continue;
				if (adjlist[present]->sure == 0)
					++adjlist[*it]->yes_fr;
				else
					++adjlist[*it]->no_fr;
				if (adjlist[*it]->yes_fr >= adjlist[*it]->threshold)
				{
					q.push(*it);
					adjlist[*it]->sure = 0;
				}
				else if (adjlist[*it]->no_of_friends - adjlist[*it]->no_fr < adjlist[*it]->threshold)
				{
					q.push(*it);
					adjlist[*it]->sure = 1;
				}
			}
			// cout << present << endl;
		}
		total_no = 0;
		total_yes = 0;
		for (i=0; i<n; ++i)
		{
			if (adjlist[i]->sure == 0)
				++total_yes;
			else if (adjlist[i]->sure == 1)
				++total_no;
		}
		printf("%d %d \n", total_yes, n-total_no);
		// cout << total_yes << " " << (n-total_no) << endl; 
	}
};
int main()
{
	int n, k, th, i, j, fr;
	scanf("%d", &n);
	graph g(n);
	// g.check();
	// cout << endl;
	g.solve();
	return 0;
}