#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	queue<int> G;
	queue<int> NG;
	vector<vector<int> >Graph(N,vector<int>(5,0));
	int min_G=0;
	int min_NG=0;
	for(int i=0;i<N;i++)
	{
		int t_i;
		scanf("%d",&t_i);
		Graph[i][0]=t_i;
		if(t_i==0)
		{
			G.push(i);
			Graph[i][4]=-1;
			min_G++;
		}
		int nOf;
		scanf("%d",&nOf);
		if(t_i>nOf)
		{
			NG.push(i);
			Graph[i][4]=1;
			min_NG++;
		}
		Graph[i][1]=nOf;
		for(int j=0;j<nOf;j++)
		{
			int index;
			scanf("%d",&index);
			Graph[index].push_back(i);
		}
	}
	while(!G.empty())
	{
		int front=G.front();
		G.pop();
		for(int k=5;k<Graph[front].size();k++)
		{
			Graph[Graph[front][k]][2]++;
			if(Graph[Graph[front][k]][0]<=Graph[Graph[front][k]][2])
			{
				if(Graph[Graph[front][k]][4]!=-1)
				{
					G.push(Graph[front][k]);
					min_G++;
					Graph[Graph[front][k]][4]=-1;
				}
			}
		}
	}

	while(!NG.empty())
	{
		int front=NG.front();
		NG.pop();
		for(int k=5;k<Graph[front].size();k++)
		{
			Graph[Graph[front][k]][3]++;
			if(Graph[Graph[front][k]][1]-Graph[Graph[front][k]][3] < Graph[Graph[front][k]][0])
			{
				if(Graph[Graph[front][k]][4]!=1)
				{
					NG.push(Graph[front][k]);
					min_NG++;
					Graph[Graph[front][k]][4]=1;
				}
			}
		}
	}
	printf("%d %d\n",min_G,N-min_NG);
}
