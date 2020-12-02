#include <iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;


int main()
{
int n;
scanf("%d",&n);

vector<vector<int> > hisFriends(n);
vector<vector<int> > heIsFriends(n);
vector<int> t_i(n);
vector<int> n_i(n);
vector<int> friendsNotGoing(n);
vector<int> friendsGoing(n,0);
queue<int> definitelyGoing;
queue<int> definitelyNotGoing;
vector<bool> alreadyVisitedGoing(n,false);
vector<bool> alreadyVisitedNotGoing(n,false);



for(int i = 0;i < n;i++ )
{
    int tempInt;
    scanf("%d", &tempInt);
    t_i[i] = tempInt;
    scanf("%d", &tempInt);
    n_i[i] = tempInt;
    vector<int> temp(n_i[i]);
    for(int j=0;j<n_i[i];j++)
    {
        scanf("%d", &tempInt);
        temp[j] = tempInt;
    }
    hisFriends[i] = (temp);
    friendsNotGoing[i] = n_i[i];

    if(t_i[i] == 0){definitelyGoing.push(i);alreadyVisitedGoing[i]=true;}
    else if(t_i[i] > n_i[i]){definitelyNotGoing.push(i);alreadyVisitedNotGoing[i]=true;}

}

for (int i = 0; i < n; ++i)
{
	int len = hisFriends[i].size();
	vector<int> temp;
	for(int j = 0;j < len;j++ )
	{
		heIsFriends[hisFriends[i][j]].push_back(i);

	}
	//cout<<endl;
}

/*for(int i=0;i<heIsFriends.size();i++)
{
	for (int j = 0; j < heIsFriends[i].size(); ++j)
	{
		cout<<heIsFriends[i][j]<<endl;
	}
}
*/



int min =0;

while(!definitelyGoing.empty())
{

	int inQueue = definitelyGoing.front();
	definitelyGoing.pop();
	alreadyVisitedGoing[inQueue] = true;
	int len =heIsFriends[inQueue].size();
	min++;
	for(int i=0;i<len;i++)//optimize
	{
		if(!alreadyVisitedGoing[heIsFriends[inQueue][i]])
		{
			friendsGoing[heIsFriends[inQueue][i]]++;
			if(t_i[heIsFriends[inQueue][i]] == friendsGoing[heIsFriends[inQueue][i]]){definitelyGoing.push(heIsFriends[inQueue][i]);}
		}
	}
}
//cout<<endl;

int max =0;
while(!definitelyNotGoing.empty())
{

	int inQueue = definitelyNotGoing.front();
	//cout<<"inQueue: "<<inQueue<<endl;
	definitelyNotGoing.pop();

	int len =heIsFriends[inQueue].size();
	max++;
	for(int i=0;i<len;i++)//optimize
	{
		//cout<<"heIsFriends[inQueue][i]]: "<<heIsFriends[inQueue][i]<<endl;
		if(!alreadyVisitedNotGoing[heIsFriends[inQueue][i]])
		{
			--friendsNotGoing[heIsFriends[inQueue][i]];
			if(t_i[heIsFriends[inQueue][i]] > friendsNotGoing[heIsFriends[inQueue][i]]){
				definitelyNotGoing.push(heIsFriends[inQueue][i]);
				alreadyVisitedNotGoing[heIsFriends[inQueue][i]] = true;}
		}
	}
}













cout<<min<<" "<<n-max<<endl;
return 0;
}
