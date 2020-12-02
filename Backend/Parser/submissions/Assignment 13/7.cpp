#include <iostream>
#include <queue>
int n, **C;
using namespace std;
struct node
{
	int value;
	vector<int> mincost;
	vector<bool> ispresent;
	node()
	{
		mincost.resize(4*n+1,-1);
		ispresent.resize(4*n+1,false);
	}		
};

int main()
{
	vector<node> nodes;
	pair<int ,int> p;
	queue<pair<int, int> > myqueue;
	int index,curcost,min,goodness;

	cin>>n;
	nodes.resize(n);
	C = new int*[n];
	for(int i=0;i<n;i++)
	{
		C[i] = new int [n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>C[i][j];
		}
	}
	
	p = make_pair(0,2*n);
	nodes[0].mincost[2*n] = 0;
	nodes[0].ispresent[2*n] = true; 
	myqueue.push(p);

	while(!myqueue.empty())
	{
		p = myqueue.front();
		index = p.first;
		goodness = p.second;
		myqueue.pop();
		nodes[index].ispresent[goodness] = false;
		curcost = nodes[index].mincost[goodness];
		for(int i=0;i<n;i++)
		{
			if(C[index][i]<0)
			{
				//good edge
				if(goodness==4*n)
					continue;
				if(nodes[i].mincost[goodness+1] > curcost - C[index][i] || nodes[i].mincost[goodness+1] == -1)
				{
					nodes[i].mincost[goodness+1] = curcost - C[index][i];

					// if there exist a value g s.t. g> goodness+1 and nodes[i].mincost()<= nodes[i].mincost[goodness+1] don't push it to queue
					if(!nodes[i].ispresent[goodness+1])
					{
						// for(int g = goodness + 2 ; g < 4*n+1 ; g++)
						// {
						// 	if(nodes[i].mincost[g] < nodes[i].mincost[goodness+1])
						// 		continue;
						// }
						p = make_pair(i,goodness+1);
						nodes[i].ispresent[goodness+1] = true;
						myqueue.push(p);
					}
				}
			}
			else if(C[index][i]>0)
			{
				//bad edge
				if(goodness == 0)
					continue;
				if((nodes[i].mincost[goodness-1] > curcost + C[index][i]) || nodes[i].mincost[goodness-1] == -1)
				{
					nodes[i].mincost[goodness-1] = curcost + C[index][i];
					if(!nodes[i].ispresent[goodness-1])
					{
						// for(int g = goodness ; g < 4*n+1 ; g++)
						// {
						// 	if(nodes[i].mincost[g] < nodes[i].mincost[goodness-1])
						// 		continue;
						// }
						p = make_pair(i,goodness-1);
						nodes[i].ispresent[goodness-1] = true;
						myqueue.push(p);
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		min = nodes[i].mincost[2*n];
		for(int j = 2*n+1; j<4*n+1 ; j++)
		{
			if(nodes[i].mincost[j] != -1)
			{
				if(min > nodes[i].mincost[j] || min == -1 )
				{
					min = nodes[i].mincost[j];
				}
			}
		}
		if(min!=-1)
		{
			cout<<min<<endl;
		}
		else
		{
			cout<<"infinity"<<endl;
		}
	}

	return 0;
}