#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{

int n;
scanf("%d",&n);
bool *b,*c;
b=new bool[n];
c=new bool[n];

vector<int>  graph;
vector<int> Graph;
vector<int>  Count;
vector< vector<int> > revGraph;

for(int i=0;i<n;i++)
{
b[i]=true;
c[i]=true;
vector<int> row;
revGraph.push_back(row);
}

queue<int> q,Q;
int minCount=0,maxCount=0;

for(int i=0;i<n;i++)
{
int threshold;
scanf("%d",&threshold);
graph.push_back(threshold);
Graph.push_back(threshold);
int size;
scanf("%d",&size);
Count.push_back(size);
if(graph[i]>size)
{
	Q.push(i);
	c[i]=false;
	maxCount++;
}
if(graph[i]==0)
{
	q.push(i);
	b[i]=false;
	minCount++;
}
for(int j=0;j<size;j++)
{
int input;
scanf("%d",&input);
revGraph[input].push_back(i);
}
}

while(!q.empty())
{

	for (vector<int>::iterator it =revGraph[q.front()].begin() ; it != revGraph[q.front()].end(); ++it)
	{
		graph[*it]=graph[*it]-1;
		if(graph[*it]==0)
{
	if(b[*it]==true)
{
	minCount++;
	b[*it]=false;
	q.push(*it);
}
}
	}
	q.pop();
}

while(!Q.empty())
{
	for (vector<int>::iterator it =revGraph[Q.front()].begin() ; it != revGraph[Q.front()].end(); ++it)
	{
		Count[*it]=Count[*it]-1;
		if(Graph[*it]>Count[*it])
{
	if(c[*it]==true)
{
	maxCount++;
	Q.push(*it);
	c[*it]=false;
}
}
	}
	Q.pop();
}

cout<<minCount<<" "<<n-maxCount<<endl;
return 0;
}





