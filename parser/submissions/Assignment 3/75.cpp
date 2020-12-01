#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int INFI =0;

int compute_L(vector<int>&A, int n, vector<int>&B, int m, vector<vector<int> >&L){
	
	int column = 0;

	if(A[n-1]==B[m-1]){
		L[n-1][column] = 1;
	}
	else{
		L[n-1][column] = INFI;
	}

	for(int i=n-2;(i >=0)&&(i >=m);i--){
		if(A[i]==B[m-1]){
			
			L[i][column] = 1;
		}
		else{
			L[i][column] = 1+L[i+1][column];
		}
	}

	for (int j=m-2;j>=0;j--){
		column = 1 - column;
		L[n-1][column] = INFI;
		for(int i = n-2; (i >=0)&&(i >=j); i--){
			if(A[i]==B[j]){
				L[i][column] = 1 + L[i+1][1 - column];
			}
			else{
				L[i][column] = 1 + L[i+1][column];
			}
		}
	}
	return column;
}

int main(){

	int n;
	int m;

	cin>>n>>m;
	INFI = n + 100;
	
	vector<int> A(n);
	vector<int> B(m);

	for (int i = 0; i < n; ++i){
		cin>>A[i];
	}
	for (int i = 0; i < m; ++i){
		cin>>B[i];
	}

	vector<vector<int> > L(n,vector<int>(2));
	
	int col = compute_L(A, n, B, m, L);

	//Finding min i,L
	int i=0;
	int min_l=L[i][col];
	int min_i=1;
	for(;i<n;i++){
		if(L[i][col]<min_l){
			min_l = L[i][col];
			min_i = i+1;
		}
	}

	if(min_l>=INFI){
		cout<<"infinity"<<endl;
	}
	else{
		cout<<min_l<<" "<<min_i<<endl;
	}
}
