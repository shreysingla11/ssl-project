#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>


int main(){
	int n;
	std :: cin >> n;
	double A[n+1];
	
	for (int i=1;i<=n;i++){
		A[i] = f(i);
	}
		
	double max1 = 0; double max2 = 0;
	double tmp1,tmp2;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(A[i] <= A[j]) break;
			tmp1 = A[i]-A[j];
			tmp2 = (A[i]-A[j])/(j-i);
			if(tmp1 >= max1) max1 = tmp1;
			if(tmp2 >= max2) max2 = tmp2;
		}
	}
	
	std :: cout << std :: fixed;
	std :: cout << std :: setprecision(6);
	std :: cout << max1 << "\n" << max2 << "\n";
}
