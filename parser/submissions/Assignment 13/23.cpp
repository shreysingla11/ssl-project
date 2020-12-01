#include <iostream>
#include <cstdio>
#include <queue>
#define min(a, b) ((a>b)?b:a)
using namespace std;

struct toUpdate{
	int vertex;
	int goodness;
	toUpdate(int x, int y){
		vertex = x;
		goodness = y;
	}
};

int n;
int INF = 1000000000;
int C[101][101];
int S[101][204]; // S[0.1.2....n-1][-n.-(n-1)....0....(n-1).n]
// g=x is stored at [x+n]
// [x] stores g=x-n
bool isInQueue[101][204];
bool isGood[101][101];
queue<toUpdate> q;

void take_input(){
	int temp;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &temp);
			if(temp<0){
				C[i][j] = -temp;
				isGood[i][j] = 1;
			}
			else{
				C[i][j] = temp;
				isGood[i][j] = 0;
			}
		}
	}
}

void initialize(){
	// i = 0;
	for(int w=0; w<n; w++){
		for(int g=-n; g<=n; g++){
			S[w][g+n] = INF;
			isInQueue[w][g+n] = 0;
		}
	}
	S[0][0+n] = 0;
	q.push(toUpdate(0, 0));
	isInQueue[0][0+n] = 1;
	//i=0; w=0(source);
	// for(int g=-n; g<=0; g++){
	// 	S[0][g+n] = 0;
	// 	q.push(toUpdate(0, g));
	// 	isInQueue[0][g+n] = 1;
	// }
	// for(int g=1; g<=n; g++){
	// 	S[0][g+n] = INF;
	// 	isInQueue[0][g+n] = 0;
	// }
}

void prints(){
	for(int v=0; v<n; v++) for(int g=-n; g<=n; g++)
	printf("S[%d][%d] = %d\n", v, g, S[v][g+n]);
}

void go(){
	while(!q.empty()){
		toUpdate u = q.front();
		//if(u.goodness==-3) cout <<u.vertex << endl;
		isInQueue[u.vertex][u.goodness+n] = 0;
		q.pop();
		for(int v=0; v<n; v++){
			if(isGood[u.vertex][v] && u.goodness<n){
				// good edge
				if(S[u.vertex][u.goodness+n] + C[u.vertex][v] < S[v][u.goodness+1+n]){
					S[v][u.goodness+1+n] = S[u.vertex][u.goodness+n] + C[u.vertex][v];
					//printf("S[%d][%d] got updated to %d\n", v, u.goodness+1, S[v][u.goodness+1+n]);
					if(!isInQueue[v][u.goodness+1+n]){
						q.push(toUpdate(v, u.goodness+1));
						isInQueue[v][u.goodness+1+n] = 1;
					}
					//prints();
				}
			}
			else if(u.goodness>-n){
				// bad edge
				if(S[u.vertex][u.goodness+n] + C[u.vertex][v] < S[v][u.goodness-1+n]){
					// printf("%d\n", S[v][u.goodness-1+n]);
					S[v][u.goodness-1+n] = S[u.vertex][u.goodness+n] + C[u.vertex][v];
					// printf("S[%d][%d] got updated to %d\n", v, u.goodness-1, S[v][u.goodness-1+n]);
					if(!isInQueue[v][u.goodness-1+n]){
						q.push(toUpdate(v, u.goodness-1));
						isInQueue[v][u.goodness-1+n] = 1;
					}
					//prints();
				}
			}
		}
	}
}

void print_ans(){
	for(int v=0; v<n; v++){
		int minVal = INF;
		for(int g=0; g<=n; g++) minVal = min(minVal, S[v][g+n]);
		if(minVal < INF)
			printf("%d\n", minVal);
		else
			printf("infinity\n");
	}
}

int main(){
	take_input();
	initialize();
	go();
	print_ans();
	return 0;
}