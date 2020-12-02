#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	bool isgoing;
	bool isnotgoing;
	vector<int> isfriendof;
	int numfriends;
	int friendsgoing;
	int friendsnotgoing;
	int threshhold;
	node()
	{
		isgoing = false;
		isnotgoing = false;
		friendsgoing = 0;
		friendsnotgoing = 0;
		isfriendof.clear();
	}

};
int main()
{
	int n,temp,min,max,u,v;
	queue<int> going;
	queue<int> notgoing;
	scanf("%d",&n);
	min =0;
	max = n;
	node *persons = new node [n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&persons[i].threshhold);
		scanf("%d",&persons[i].numfriends);
		if(persons[i].threshhold==0)
		{
			going.push(i);
			persons[i].isgoing = true;
			min++;
		}
		if(persons[i].threshhold>persons[i].numfriends)
		{
			notgoing.push(i);
			persons[i].isnotgoing = true;
			max--;
		}
		for(int j=0;j<persons[i].numfriends;j++)
		{
			scanf("%d",&temp);
			persons[temp].isfriendof.push_back(i);
		}
	}

	while (!going.empty())
	{
		u = going.front();
		going.pop();
		for(int i=0;i<persons[u].isfriendof.size();i++)
		{
			v = persons[u].isfriendof[i];
			if(!persons[v].isgoing)
			{
				persons[v].friendsgoing++;
				if(persons[v].friendsgoing >= persons[v].threshhold)
				{
					going.push(v);
					persons[v].isgoing = true;
					min++;
				}
			}
		}
	}

	while (!notgoing.empty())
	{
		u = notgoing.front();
		notgoing.pop();
		for(int i = 0;i<persons[u].isfriendof.size();i++)
		{
			v = persons[u].isfriendof[i];
			if(!persons[v].isnotgoing)
			{
				persons[v].friendsnotgoing++;
				if(persons[v].threshhold>persons[v].numfriends - persons[v].friendsnotgoing)
				{
					notgoing.push(v);
					persons[v].isnotgoing = true;
					max--;
				}
			}
		}
	}
	printf("%d %d\n",min,max);
	return 0;
}
