#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main(){

	int n; scanf("%d",&n);
	vector<int> threshhold(n,-1);
	vector<int> no_friends(n,-1);
	std::vector<bool> defgoing(n,false);
	std::vector<bool> defnotgoing(n,false);
	vector<vector<int> > list(n, vector<int>(0));

	for (int i=0; i<n; ++i){
		scanf("%d %d ",&threshhold[i],&no_friends[i]);
		int temp;
		for (int j=0; j<no_friends[i]; ++j){
			scanf("%d", &temp);
			list[temp].push_back(i);
		}
	}

	queue<int> defstatus1;
	vector<bool> visited(n, false);
	for (int i=0; i<n; ++i){ 
		if (threshhold[i] <= 0){
			defstatus1.push(i);
			defgoing[i] = true;
			visited[i] = true;
		}
	}
	
	int count = 0;
	vector<int> going(n,0);
	while (!defstatus1.empty()){
		int currNode = defstatus1.front();
		for (int i=0; i<list[currNode].size(); ++i){
			int myint = list[currNode][i];
			++going[myint];
			if (going[myint] >= threshhold[myint] && !visited[myint]){
				if (defgoing[currNode])
				{
					defstatus1.push(myint);
					visited[myint] = true;
					defgoing[myint] = true;	
				}
				else
				{
					defstatus1.push(myint);
					visited[myint] = true;
					defgoing[myint] = true;		
				}
			}
		}
		defstatus1.pop();
		++count;
	}

	printf("%d ",count);
	
	count=0;
	// queue<int> defstatus1;
	for (int i=0; i<n; ++i) visited[i] = false;
	vector<int> notgoing(n,0);
	
	for (int i=0; i<n; ++i){
		if (threshhold[i]>no_friends[i]){
			defstatus1.push(i);
			defnotgoing[i] = true;
			visited[i] = true;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		/* code */
	}
	while (!defstatus1.empty()){
		int currNode = defstatus1.front();
		for (int i=0; i<list[currNode].size(); ++i){
			int myint = list[currNode][i];
			++notgoing[myint];
			if (notgoing[myint] > no_friends[myint]-threshhold[myint] && !visited[myint]){
				if (defnotgoing[currNode])
				{
					defstatus1.push(myint);
					defnotgoing[myint] = true;	
					visited[myint] = true;
				}
				else
				{
					defstatus1.push(myint);
					visited[myint] = true;
					defnotgoing[myint] = true;	
				}
			}
		}
		defstatus1.pop();
		++count;
	}

	printf("%d",(n-count));

	return 0;
}