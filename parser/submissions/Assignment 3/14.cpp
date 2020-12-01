#include <iostream>
#include <vector>
using namespace std;

void input(int n, int m, vector<int> &substr, vector<int> &subseq){
	for(int i=1; i<=n; i++){
		cin >> substr[i];
	}
	for(int i=1; i<=m; i++){
		cin >> subseq[i];
	}
}

int L1(int i, int j, int n, int m, vector<int> &A,vector<int> &B);

int main(){
	int n,m;
	cin >> n >> m;
	
	vector<int> substr(n);
	vector<int> subseq(m);
	int L[n][m];
	
	input(n, m, substr, subseq);
	int min = 0, com = 0;
	
	int j = m;
 	
	if(min == 0) cout << "infinity" << endl;
}

int L1(int i, int j, int n, int m, vector<int> &A, vector<int> &B){
	if(i == n && j == m && A[n] == B[m]) 
		return 1;
	
	if(j == m && A[i] == B[m]) 
		return 1;
	else if(i < n && i >= 1)
		return 1+L1(i+1,j,n,m,A,B);
		
	if(i == n && j < m) 
		return 0;
		
	if(A[i] == B[j])
		return 1+L1(i+1,j+1,n,m,A,B);
	else if(i < n && i >= 1 && j >= 1 && j < m)
		return 1+L1(i+1,j,n,m,A,B);
}
