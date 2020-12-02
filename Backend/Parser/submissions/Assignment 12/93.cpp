#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

struct people{
	int t, going, notgoing, numfrnds, allfrnds;
	bool done, other;
	vector <int> friends;
	people(){
		going = 0;
		notgoing = 0;
		done = false;
		other = false;
	}
};

int main(){
	int total,min,num,suresize=0,notsuresize=0;
	people *all;
	stack<int> sure,notsure;
	scanf("%d",&total);
	all = new people[total];
	for (int i=0;i<total;i++)
	{
		scanf("%d",&all[i].t);
		scanf("%d",&num);
		if (all[i].t == 0)
		{
			sure.push(i);
			all[i].done = true;
		}
		else if (all[i].t>num)
		{
			notsure.push(i);
			all[i].done = true;
			all[i].other = true;
		}
		all[i].allfrnds = num;
		while (num--)
		{
			scanf("%d",&min);
			all[min].friends.push_back(i);
		}
	}
	suresize = sure.size();
	notsuresize = notsure.size();
	int i = 0;
	while (!sure.empty())
	{
		i = sure.top();
		sure.pop();
		all[i].numfrnds = all[i].friends.size();
		for (int j=0;j<all[i].numfrnds;j++)
		{
			all[all[i].friends[j]].going++;
			if ((all[all[i].friends[j]].going) >= all[all[i].friends[j]].t && !all[all[i].friends[j]].done)
			{
				sure.push(all[i].friends[j]);
				all[all[i].friends[j]].done = true;
				suresize++;
			}
		}
	}
	int another;
	while (!notsure.empty())
	{
		i = notsure.top();
		notsure.pop();
		all[i].numfrnds = all[i].friends.size();
		for (int j=0; j<all[i].numfrnds; j++)
		{
			all[all[i].friends[j]].notgoing++;
			if (((all[all[i].friends[j]].allfrnds - all[all[i].friends[j]].notgoing) < all[all[i].friends[j]].t && !all[all[i].friends[j]].other))
			{
				notsure.push(all[i].friends[j]);
				all[all[i].friends[j]].other = true;
				notsuresize ++;
			}
		}
	}
	printf("%d %d",suresize, total - notsuresize);
}