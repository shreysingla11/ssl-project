//140050002 july23
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
using namespace std;

extern double f(long long int i);

void calculate(long long int n){

    double maxv,fall = 0;
    double diff;
    double maxdiff = 0;
    maxv = f(1);
    double v1,v2 = f(1);
    for(long long int i=1;i<n;i++){

        v1 = v2;
        v2 = f(i+1);
        if((maxv-v1)>fall){
            fall = maxv - v1;
        }
        if(v1>maxv){
            maxv = v1;
        }
        diff = v1 - v2;
        if(diff>maxdiff){maxdiff = diff;}
    }
    printf("%.6f \n %.6f \n",fall,maxdiff);

    return;
}

int main(){
    long long int n;
    cout<<"insert n\n";
    cin>>n;
    calculate(n);
    return 0;
}