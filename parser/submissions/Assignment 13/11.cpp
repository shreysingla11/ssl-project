#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;

	cin >> n;
	//Cost Matrix
	int C[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> C[i][j];
	}
	for(int i=0; i<n; i++) cout << "infinity" << endl;
}