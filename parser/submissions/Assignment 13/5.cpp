#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int INF=1000000000;
class node
{
public:
	int index;
	vector<int> neighbours;
	vector<int> cost;
	vector<bool> cost_present;
	//cost[i] gives the cost of path with goodness(-2n+i)
	node(int n)
	{
		neighbours.resize(n);
		cost_present.resize(4*n+1,false);
		cost.resize(4*n+1,INF);
	}

};
int main()
{
	int n,temp2;
	scanf("%d",&n);
	node initial(n);
	vector<node> vertices(n,initial);
	for(int i=0;i<n;i++)
		vertices[i].index=i;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp2);
			vertices[i].neighbours[j]=temp2;
		}

	pair<int,int> temp;
	temp=std::make_pair(0,2*n);
	vertices[0].cost_present[2*n]=true;
	vertices[0].cost[2*n]=0;
	//1st parameter is the index from which searching is happening
	//2nd parameter is the goodness value upto that node 
	queue<pair<int,int> > m;
	m.push(temp);
	int a,b;
	int t;
	int weight;
	int gb;
	while(!m.empty())
	{
		temp=m.front();
		m.pop();
		a=temp.first;
		b=temp.second;
		//a=0 b=0 for first iteration
		vertices[a].cost_present[b]=false;
		for(int i=0;i<n;i++)
		{
			t=vertices[a].neighbours[i];
			if(t>0)
				gb=-1;
			else 
				gb=1;
			weight=abs(t);
			if(b+gb <= 4*n || b+gb>=0)
			{
				if(vertices[i].cost[b+gb] > vertices[a].cost[b]+weight)
				{
					vertices[i].cost[b+gb]=vertices[a].cost[b]+weight;
					if(!vertices[i].cost_present[b+gb])
					{
						temp=std::make_pair(i,b+gb);
						m.push(temp);
						vertices[i].cost_present[b+gb]=true;
					}
				}
			}
			
		}

	}
	int ans;
	for(int i=0;i<n;i++)
	{
		ans=INF;
		for(int j=2*n;j<4*n+1;j++)
		{
			ans=min(vertices[i].cost[j],ans);
		}
		if(ans!=INF)
			printf("%d\n",ans);
		else
			printf("infinity\n");
	}



	return 0;
}