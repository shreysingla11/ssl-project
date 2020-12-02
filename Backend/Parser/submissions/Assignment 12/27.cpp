#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

class friends
{
	public:
		int threshold;
		int countFriend;
		vector<int>inverseFriendList;
		bool inlist=false;

};



int main()
{
	vector<friends>f;
	int n,tempCount,tempThreshold,friendNumber,temp;
	vector<int>going,notgoing;
	scanf("%d",&n);
	f.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tempThreshold);
		scanf("%d",&tempCount);
		f[i].threshold = tempThreshold;
		f[i].countFriend = tempCount;

		for(int j=0;j<tempCount;j++)
		{
			scanf("%d",&friendNumber);
			f[friendNumber].inverseFriendList.push_back(i);
		}
	}

for(int i=0;i<n;i++)
	{
		if(f[i].threshold==0)
		{
			going.push_back(i);
			f[i].inlist=true;
		}
		else if(f[i].threshold > f[i].countFriend)
		{
			notgoing.push_back(i);
			f[i].inlist=true;
		}
	}

	for(int i=0 ; i<going.size() ; i++)
	{
		temp = f[going[i]].inverseFriendList.size();
		for(int j=0;j<temp;j++)
		{
			if(!f[f[going[i]].inverseFriendList[j]].inlist)
			{
				f[f[going[i]].inverseFriendList[j]].countFriend--;
				f[f[going[i]].inverseFriendList[j]].threshold--;
				if(f[f[going[i]].inverseFriendList[j]].threshold == 0)
				{
					going.push_back(f[going[i]].inverseFriendList[j]);
					f[f[going[i]].inverseFriendList[j]].inlist=true;
				}
			}
		}
	}

	for(int i=0;i<notgoing.size();i++)
	{
		temp = f[notgoing[i]].inverseFriendList.size();
		for(int j=0;j<temp;j++)
		{
			if(!f[f[notgoing[i]].inverseFriendList[j]].inlist)
			{
				f[f[notgoing[i]].inverseFriendList[j]].countFriend--;
				if(f[f[notgoing[i]].inverseFriendList[j]].threshold > f[f[notgoing[i]].inverseFriendList[j]].countFriend)
				{
					notgoing.push_back(f[notgoing[i]].inverseFriendList[j]);
					f[f[notgoing[i]].inverseFriendList[j]].inlist=true;
				}
			}
		}
	 }
	printf("%d %d",going.size(), n-notgoing.size());
	return 0;
}


