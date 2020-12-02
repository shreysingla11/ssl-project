#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main(){

	int n; scanf("%d",&n);
	vector<int> thold(n,-1);
	vector<int> numF(n,-1);
	vector<vector<int> > list(n, vector<int>(0));

	for (int i=0; i<n; ++i){
		scanf("%d %d ",&thold[i],&numF[i]);
		int temp;
		for (int j=0; j<numF[i]; ++j){
			scanf("%d", &temp);
			list[temp].push_back(i);
		}
	}

	queue<int> Q1;
	vector<bool> visited(n, false);
	for (int i=0; i<n; ++i){ 
		if (thold[i] <= 0){
			Q1.push(i);
			visited[i] = true;
		}
	}
	
	int count = 0;
	vector<int> going(n,0);
	while (!Q1.empty()){
		int currNode = Q1.front();
		for (int i=0; i<list[currNode].size(); ++i){
			int predess = list[currNode][i];
			++going[predess];
			if (going[predess] >= thold[predess] && !visited[predess]){
				Q1.push(predess);
				visited[predess] = true;
			}
		}
		Q1.pop();
		++count;
	}

	printf("%d ",count);
	
	count=0;
	// queue<int> Q1;
	for (int i=0; i<n; ++i) visited[i] = false;
	vector<int> notgoing(n,0);

	for (int i=0; i<n; ++i){
		if (thold[i]>numF[i]){
			Q1.push(i);
			visited[i] = true;
		}
	}

	while (!Q1.empty()){
		int currNode = Q1.front();
		for (int i=0; i<list[currNode].size(); ++i){
			int predess = list[currNode][i];
			++notgoing[predess];
			if (notgoing[predess] > numF[predess]-thold[predess] && !visited[predess]){
				Q1.push(predess);
				visited[predess] = true;
			}
		}
		Q1.pop();
		++count;
	}

	printf("%d",(n-count));

	return 0;
}