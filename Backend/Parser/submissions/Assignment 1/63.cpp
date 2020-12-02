#include <bits/stdc++.h>

using namespace std;

extern double f(long long int i);

int main(){

	int n; cin>>n;
	int a,b;  //m<=n ,, A[m]>=A[n]
	double br=0,bf=0;
	if (n==1) { br=0; bf=0;}
	else{

		if (f(1) > f(2)) { bf=br=f(1)-f(2);}
		else { bf=br=0;}
		int y=1; //y is the maximum over[0,q)
		int q;
		while (q<=n){
			if ( f(y)-f(q) >= bf ){
			bf= f(y) - f(q);
			}
			if (f(q)>f(y)) {y=q;}
 			if (f(q-1)-f(q) >= br) {br =f(q-1)-f(q);}
 			q++;
 		}
 	}

 	printf("%.6f\n%.6f\n",bf,br);
 	
	return 0;
}