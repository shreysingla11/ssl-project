#include <iostream>
#include <cmath>

using namespace std;

int n;

extern double f(int i);


int main(){
	
	cin>>n;
	double arr[n+1];
	
	for(int i=1;i<=n;i++){
		arr[i] = f(i);
	}
	
	double max_f=arr[1],max_fall=0;
	
	for(int i=2;i<=n;i++){
		if(arr[i] > max_f)max_f = arr[i];
		if(arr[i] < max_f && ((max_f - arr[i]) > max_fall)){
			max_fall = (max_f - arr[i]);
		}
	}
	// to precise upto 6 decimals
	cout.precision(6);
	cout<<fixed<<max_fall<<endl;
	
	double max_slope=0;
	
	for(int i=2;i<=n;i++){
		if(arr[i] < arr[i-1]){
			double tmp = arr[i-1]-arr[i];
			if(tmp > max_slope)max_slope=tmp;
		}
	}
	
	cout<<fixed<<max_slope<<endl;
}
