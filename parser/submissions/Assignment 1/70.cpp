#include<iostream>
#include<stdio.h>

using namespace std;



extern double f(long int i);

double maximum(double a, double b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
    long int N;

    cin>>N;
    double func_prev=f(1),func_new=0;
    long int n=1;//for highest fall
    double r=0,maxi=func_prev;

    double highest_rate=0;
    while(n<N){

        ///Calculating biggest fall
        func_new = f(n+1);
        r=maximum(r,maxi-func_new);
        maxi = maximum(maxi,func_new);
        if(r<0){r=0;}

        ///Biggest Rate
        double new_rate = func_prev - func_new;
        if(new_rate>highest_rate){
            highest_rate = new_rate;
        }
        if(highest_rate<0){highest_rate = 0;}

        func_prev  = func_new;
        n++;
    }

    printf("%.6f\n%.6f\n",r,highest_rate);
    return 0;
}
