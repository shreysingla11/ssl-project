#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;

class person
{
public:
	int numberoffriends;
	int threshold;
	int goingfriends;
	int notgoingfriends;
	bool checkmax;
	bool checkmin;
	vector<int> friends,predecessors;
};

int main()
{
	int n;
	int minimum=0;
	scanf("%d",&n);
	int maximum=n;
	vector<person> persons(n);
	vector<int> t0;
	vector<int> tgreat;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&(persons[i].threshold));
		if(persons[i].threshold == 0)
		{
			t0.push_back(i);
			persons[i].checkmin = 1;
		}
		scanf("%d",&(persons[i].numberoffriends));
		if(persons[i].threshold > persons[i].numberoffriends)
		{
			tgreat.push_back(i);
			persons[i].checkmax = 1;
		}
		for(int j=0;j<persons[i].numberoffriends;j++)
		{
			int fnum;
			scanf("%d",&fnum);
			persons[i].friends.push_back(fnum);
			persons[fnum].predecessors.push_back(i);//updating predecessors
		}
	}

	stack<int> going, notgoing;

	for(int i=0;i<t0.size();i++)
	{
		going.push(t0[i]);
	}
	for(int i=0;i<tgreat.size();i++)
	{
		notgoing.push(tgreat[i]);
	}

	while(going.size()>0)
	{
		int top = going.top();
		going.pop();
		minimum++;
		for(int i=0;i<persons[top].predecessors.size();i++)
		{
			int index = persons[top].predecessors[i];
			persons[index].goingfriends++;
			if(persons[index].goingfriends==persons[index].threshold)
			{
				if(persons[index].checkmin!=1)
				{
					going.push(index);
					persons[index].checkmin=1;
				}
			}
		}
	}

	while(notgoing.size()>0)
	{
		int top = notgoing.top();
		notgoing.pop();
		maximum--;
		for(int i=0;i<persons[top].predecessors.size();i++)
		{
			int index = persons[top].predecessors[i];
			persons[index].notgoingfriends++;
			if(persons[index].threshold > persons[index].numberoffriends - persons[index].notgoingfriends)
			{
				if(persons[index].checkmax!=1)
				{
					notgoing.push(index);
					persons[index].checkmax=1;
				}
			}
		}
	}

	//printf("%d %d\n",minimum,maximum);
	cout<<minimum<<" "<<maximum<<endl;
    return 0;
}
