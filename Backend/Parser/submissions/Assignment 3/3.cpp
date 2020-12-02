#include<iostream>
using namespace std;

int main () {
	
	int n,m;
	cin>>n>>m;
	int a[n+1],b[m+1] ;
	for (int i=1;i<n+1;i++) {
		cin>>a[i];	
	}
	
	for (int i=1;i<m+1;i++) {
		cin>>b[i];
	}
	
	int L[n+1][m+1];
	
	
	if(a[n] == b[m])L[n][m]=1;
	else L[n][m]=-1;
	
	for(int i=n-1;i>0;i--){
		if(a[i] == b[m])L[i][m]=1;
		else {
				if(L[i+1][m] == -1)L[i][m]=-1; 
				else L[i][m]=1+L[i+1][m];
			
			}
	}
	
	for(int j=1;j<m;j++)L[n][j]=-1;
	
	for(int i=n-1;i>0;i--){
		for(int j=m-1;j>0;j--){
			if(a[i] == b[j]){
				if(L[i+1][j+1] != -1)L[i][j]=1+L[i+1][j+1];
				else L[i][j]=-1;
			}
			else {
				if(L[i+1][j] != -1)L[i][j]=1+L[i+1][j];
				else L[i][j]=-1;
				
			}
		}
		
	}
	
	int min = L[1][1]+1;
	int index = -1;
	bool ans = false;
	
	
	for(int i=1;i<=n;i++){
		if(L[i][1] < min && L[i][1]!=-1){
			ans = true;
			min=L[i][1];
			index = i;
		}
	}
	
	if(ans){
		cout<<min<<" "<<index<<endl;
	}
	
	else{
		cout<<"infinity"<<endl;
	}
	
	}
