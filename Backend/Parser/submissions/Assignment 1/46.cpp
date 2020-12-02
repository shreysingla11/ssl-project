#include<iostream>
#include<cmath>
#include<stdio.h>

using namespace std;

//Arbitrary function for testing
extern double fall_func(int i){
    int p = 1000,a = 355,b = 190,c = 512,d = 960;
    return p * (sin (a*i + b) + cos(c*i + d) + 2.000000);
    }

int main(){
    int  n,i=1,j=2;
    double max_fall = 0.000000,max_rate_of_fall, k = 0.000000;

    cin>>n;



    for(i = 1 ; i < n  ; i++){

        for(j = i+1 ; j <= n && fall_func(j)<fall_func(i)  ; j++){

        k = fall_func(i) - fall_func(j);

            if(max_fall <= k){
             max_fall = k;
            }

        }

    }
    printf("%.6f\n",max_fall);



return 0;
}
