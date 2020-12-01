#include <bits/stdc++.h>

using namespace std;

class nint{
	public:
	int x;
	nint(){
		x=0;
	}
	nint(int a){
		x=a;
	}
	//we use 0 to denote infinity
	nint operator+(const int a){
		if (x==0) {return nint(0);}
		else {return nint(x+a);}
	}
	nint operator=(const int a){
		x=a;
	}
	nint operator=(const nint A){
		x=A.x;
	}
};

int main(){
	int n,m; cin>>n>>m;
	int *A = new int[n+1];
	int *B = new int[m+1];
	for (int i=1; i<=n; i++) {cin>>A[i];}
	for (int i=1; i<=m; i++) {cin>>B[i];}

	nint *L = new nint[n];
	
	if (A[n]==B[m]) { L[n]=1; }
	else { L[n]=0; }
	for (int i=n-1; i>=1; i--){
		if (A[i]==B[m]) {L[i]=1;}
		else {L[i]=L[i+1]+1;}
	}

	for (int k=m-1; k>=1; k--){
		nint below=0,current=0;
		for (int p=n-1; p>=1; p--){
			if (A[p]==B[k]){
				current = L[p+1]+1;
			}
			else {current=below+1;}
			L[p+1]=below;
			below=current;
		}
		L[1]=below;
	}

	int min=0,id=0;
	for (int i=1; i<=n; i++){
		if (L[i].x !=0){
			if (min==0) {min=L[i].x; id=i;}
			else {
				if (L[i].x < min) {min=L[i].x; id=i;} 
			}
		}
	}
	
	if (min==0) {cout<<"infinity";}
	else{
		printf("%d %d\n",min,id);
	}
	return 0;
}