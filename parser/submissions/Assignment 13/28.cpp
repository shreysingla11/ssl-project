#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <list>
#include <utility>

#define INF 100000
using namespace std;

int n;
class node
{
public:
	std::vector<int> cost;
	std::vector<bool> presence;
	node(){
		cost.resize(4*n+1);
		presence.resize(4*n+1);
		for (int i = 0; i < 4*n+1; ++i){
			cost[i] = INF;
			presence[i] = false;
		}
	}
};

int main(int argc, char const *argv[]){
	scanf("%d\n",&n);
	int g;
	std::vector<vector<int> > weights;
	int temp;
	for (int i = 0; i < n; ++i){
		std::vector<int> tempv;
		for (int j = 0; j < n; ++j){
			cin>>temp;
			tempv.push_back(temp);
		}
		weights.push_back(tempv);
	}
	queue< pair <int,int> > goodness;
	std::vector<node> list_node(n);
	goodness.push(pair <int,int>(0, 2*n));
	list_node[0].cost[2*n] = 0;
	list_node[0].presence[2*n] = true;

	pair <int,int> temp1;
		
	while(!goodness.empty()){
		temp1 = goodness.front();
		list_node[temp1.first].presence[temp1.second] = false;
		goodness.pop();
		int goodnesslevel = temp1.second;
		
		for (int i = 0; i < n; ++i){
			int wight = weights[temp1.first][i];

			if (wight<0){
				wight = -wight;
				g = goodnesslevel + 1;
			}
			else{
				g = goodnesslevel - 1;
			}
			if (g>=0 && g<=4*n)
			{
				if (list_node[i].cost[g] >list_node[temp1.first].cost[goodnesslevel] + wight)
				{
					list_node[i].cost[g] =list_node[temp1.first].cost[goodnesslevel]+wight;
					// cout<<list_node[i].cost[g]<<" "<<i<<" "<<g<<endl;
					// cout<<wight<<" "<<n<<endl;
					if (!list_node[i].presence[g])
					{
						bool to_add = true;
						for (int j = g+1; j < 4*n+1; ++j)
						{
							if (list_node[i].cost[j]< list_node[i].cost[g])
							{
								to_add = false;
								break;
							}
						}
						if (to_add)
						{
							goodness.push(pair <int,int>(i,g));
							list_node[i].presence[g] = true;
						}
					}
				}
			}
		}
	}
	int minimum = INF;
	for (int i = 0; i < n; ++i)
	{
		minimum = INF;
		for (int j = 2*n; j <= 4*n; ++j)
		{
			// cout<<list_node[i].cost[j]<<endl;
			if (minimum > list_node[i].cost[j])
			{
				minimum = list_node[i].cost[j];
			}	
		}
		if (minimum >=INF)
		{
			printf("infinity\n");
		}
		else
		{
			printf("%d\n", minimum);
		}
	}
	return 0;
}