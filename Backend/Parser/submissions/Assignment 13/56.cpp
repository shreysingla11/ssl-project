#include <iostream>
#include <cstdio>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>

#define inf numeric_limits<int>::max()

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int **C = new int*[n];
	for (int i=0; i<n; ++i){
		C[i] = new int[n];
		for (int j=0; j<n; ++j){
			scanf("%d",&C[i][j]);
		}
	}

	// int inf = numeric_limits<int>::max();
	int **dist = new int*[n];
	for (int i=0; i<n; ++i){
		dist[i] = new int[4*n+1];
		for (int j=0; j<4*n+1; ++j) dist[i][j] = inf;
	}
	dist[0][2*n] = 0;

	int **inQ = new int*[n];
	for (int i=0; i<n; ++i){
		inQ[i] = new int[4*n+1];
		for (int j=0; j<4*n+1; ++j) inQ[i][j] = 0;
	}

	queue<pair<int,int> > Q;
	Q.push(pair<int,int>(0,2*n)); inQ[0][2*n] = 1;

	int curr_node,curr_goodness;
	int temp_dist,temp_goodness;
	while (!Q.empty()){
		curr_node = Q.front().first;
		curr_goodness = Q.front().second;
		Q.pop();
		inQ[curr_node][curr_goodness] = 0;
		for (int j=0; j<n; ++j){
			temp_dist = dist[curr_node][curr_goodness] + abs(C[curr_node][j]);
			temp_goodness = (C[curr_node][j] <0)? curr_goodness+1 : curr_goodness-1;

			if (temp_goodness > 4*n || temp_goodness <0) {}
			else{
				if (temp_dist < dist[j][temp_goodness] ){
					dist[j][temp_goodness] = temp_dist;
					if (inQ[j][temp_goodness] == 0){
						Q.push(pair<int,int>(j,temp_goodness));
						inQ[j][temp_goodness] = 1;
					}
				}
			}
		}
	}

	int *min_dist = new int[n];
	for (int i=0; i<n; ++i) {
		min_dist[i]=dist[i][2*n];
		for(int j=2*n+1; j<4*n+1; ++j){
			min_dist[i] = (dist[i][j] < min_dist[i])? dist[i][j] : min_dist[i]; 
		}
	}

	for (int i=0; i<n; ++i){
		if (min_dist[i] == inf) printf("infinty\n");
		else printf("%d\n",min_dist[i]);
	}
	return 0;
}