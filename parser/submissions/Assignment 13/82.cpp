#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int inf = 1000000000;

struct node{
	vector<int> neighboor;
	vector<bool> inserted;
	vector<int> levels;
};

struct tuple{
	int ind;
	int level;
	tuple(int i, int j){
		ind = i;
		level = j;
	}
};

int main(){
	int n,temp,v,u;
	node *all;
	queue<tuple> checker; 
	scanf("%d", &n);
	all = new node[n];
	for (int i=0;i<n;i++)
	{
		all[i].inserted.resize(4*n+1, false);
		all[i].levels.resize(4*n+1, inf);
		for (int j=0;j<n;j++)
		{
			scanf("%d", &temp);
			all[i].neighboor.push_back(temp);
		}
	}
	tuple temp1(0,2*n);
	checker.push(temp1);
	all[0].levels[2*n] = 0;
	all[0].inserted[2*n] = true;
	int updatedCost, updatedLevel, sign;
	while (!checker.empty())
	{
		tuple temp2 = checker.front();
		checker.pop();
		v = temp2.ind;
		u = temp2.level;
		all[v].inserted[u] = false;
		for (int i=0;i<n;i++)
		{
			sign = (all[v].neighboor[i] > 0 ? 1 : -1);
			updatedCost = all[v].levels[u] + all[v].neighboor[i]*sign;
			updatedLevel = u - sign ;
			if ((updatedLevel <= 4*n && updatedLevel >= 0) && updatedCost < all[i].levels[updatedLevel])
			{
				all[i].levels[updatedLevel] = updatedCost;
				if (!all[i].inserted[updatedLevel])
				{
					tuple temp3(i, updatedLevel);
					checker.push(temp3);
					all[i].inserted[updatedLevel] = true;
				}
			}
		}
	}
	int min;
	for (int i=0;i<n;i++)
	{
		min = inf;
		for (int j=2*n;j<4*n;j++)
		{
			temp = all[i].levels[j];
			min = (min<temp)?min:temp;
		}
		if (min == inf)
			printf("infinity\n");
		else
			printf("%d\n",min);
	}
	
}