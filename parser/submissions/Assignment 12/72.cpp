#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct aadmi
{
	bool Going, notGoing;
	vector<int> isFriendOf;
	int numFriendsGoing, neededFriends, numFriends;

	aadmi()
	{
		Going = false;
		notGoing = false;
		numFriends = 0;
		numFriendsGoing = 0;
	}
};

int main()
{
	int N,u,x; 
	scanf("%d", &N);
	vector<aadmi> everyone(N,aadmi());
	
	int aMin = 0, aMax = N; 
	queue<int> indexGoing;
	queue<int> indexNotGoing;

	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &everyone[i].neededFriends, &everyone[i].numFriends);

		if(everyone[i].neededFriends == 0)
		{
			indexGoing.push(i);
			everyone[i].Going = true;
			aMin++;
		}
		if(everyone[i].neededFriends > everyone[i].numFriends)
		{
			indexNotGoing.push(i);
			everyone[i].notGoing = true;
			aMax--;
		}

		for (int j = 0; j < everyone[i].numFriends; ++j)
		{
			scanf("%d",&u);
			everyone[u].isFriendOf.push_back(i);
		}
	}

	while(!indexGoing.empty())
	{
		u = indexGoing.front();
		indexGoing.pop();
		for (int i = 0; i < everyone[u].isFriendOf.size(); ++i)
		{	
			x = everyone[u].isFriendOf[i];
			everyone[x].numFriendsGoing++;
			if(!everyone[x].Going && (everyone[x].numFriendsGoing >= everyone[x].neededFriends))
			{
				indexGoing.push(everyone[u].isFriendOf[i]);
				everyone[x].Going = true;
				aMin++;
			}
		}
	}

	while(!indexNotGoing.empty())
	{	
		u = indexNotGoing.front();
		indexNotGoing.pop();
		for (int i = 0; i < everyone[u].isFriendOf.size(); ++i)
		{	
			x = everyone[u].isFriendOf[i];
			everyone[x].numFriends--;
			if(!everyone[x].notGoing && (everyone[x].numFriends < everyone[x].neededFriends))
			{
				indexNotGoing.push(everyone[u].isFriendOf[i]);
				everyone[x].notGoing = true;
				aMax--;
			}
		}
	}

	printf("%d %d\n", aMin, aMax);
	return 0;
}