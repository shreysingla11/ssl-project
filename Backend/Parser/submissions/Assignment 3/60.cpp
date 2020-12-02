#include<iostream>
using namespace std;

int main(){
	int m,n;
	int p=0;
	int min=1000;
	int out1=0;
	cin>>n;
	cin>>m;
	//int L[n][m];
	int C[m];
	int D[m];
			for(int j=0;j<m;j++){
	C[j]=0;D[j]=0;
		}
	
	int A[n];
	int B[m];
	
	while (p<n){cin>>A[p];p++;}
	p=0;
	while (p<m){cin>>B[p];p++;}
	
	
	/*if (A[n-1]==B[m-1]){L[n-1][m-1]=1;}
	else {L[n-1][m-1]=1000;}
	*/
	
	if (A[n-1]==B[m-1]){D[m-1]=1;}
	else {D[m-1]=100000;}
	
	
	
	for(int j=0;j<m-1;j++){
	//if (j<m-1){L[n-1][j]=1000;}
	if (j<m-1){D[j]=100000;}
	}

	/*for(int i=0;i<n-1;i++){
	if (A[(n-2)-i]==B[m-1]){L[(n-2)-i][m-1]=1;}
	else {L[(n-2)-i][m-1]=L[(n-1)-i][m-1]+1;}
	}*/
	
	min=D[0];
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
	if(A[i]==B[j])C[j]=D[j+1]+1;
	else C[j]=D[j]+1;
	}
	
	if(A[i]==B[m-1])C[m-1]=D[m-1]+1;
	
	if (C[0]<min) min=C[0];
	
	for(int k=0;k<m;k++){
		D[k]=C[k];
		C[k]=0;
		}
		cout<<"HELLO"<<endl;
		cout<<i<<endl;
		
}
		/*for(int i=n-2;i>=0;i--){
			for(int j=m-2;j>=0;j--){
	if (A[i]==B[j]){L[i][j]=L[i+1][j+1]+1;}
	else {L[i][j]=L[i+1][j]+1;}
		}}
		
	
	for(int i=0;i<n;i++){
		if(C<min)min=L[i][0];
		else min=min;
		}*/
	
	for(int i=n-1;i>min-2;i--){
		if ((A[i]==B[m-1])&&(A[i-(min-1)]==B[0])){out1=(i-(min-1))+1;}
		}
	
	cout<<"output"<<endl;
	cout<<min<<" "<<out1<<endl;

	}
