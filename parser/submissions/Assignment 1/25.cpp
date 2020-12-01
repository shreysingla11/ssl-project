#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

extern double f(int i);

//int p, a, b, c, d;
int main(){
	int n;
	
	//cin>>p>>a>>b>>c>>d;
	cin >> n;

	double fallMax = 0.000000;
	double fallMaxGrad = 0.000000;
	double minSoFar = f(n);
	
	for(int i=n-1; i>=1; i--){
		double fi = f(i);
		double temp = fi - f(i+1);
		if(temp > fallMaxGrad) fallMaxGrad = temp;
		
		temp = fi - minSoFar;
		if(temp > fallMax) fallMax = temp;
		
		if(fi < minSoFar) minSoFar = fi;
	}
	
	printf("%.6lf\n%.6lf\n", fallMax, fallMaxGrad);
	return 0;
}
/*
double f(int i){
	return p*(sin(a*i+b) + cos(c*i+d) + 2);
}
*/
