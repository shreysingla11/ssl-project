#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int *a = new int[n];
	int *b = new int[m];
	int INF = n+1;
	
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<m; i++) scanf("%d", &b[i]);
	
	
	int minScore = INF;
	int startAt = -1;

	for(int start=0; start+m-1<n; start++){
		if(a[start] != b[0]) continue;
		int j=1, i=start+1;
		for(; j<m && i<n; i++){ if(a[i]==b[j])j++;}
		if(j!=m) break;
		int k = i-1;
		for(j=m-1; j>=0; k--) if(a[k]==b[j])j--;
		start = k+1;
		if(i-start < minScore){
			startAt = start;
			minScore = i-start;
		}
	}
	
	if(minScore < INF){
		printf("%d %d\n", minScore, startAt+1);
	}
	else{
		printf("infinity\n");
	}
	
	return 0;
}
