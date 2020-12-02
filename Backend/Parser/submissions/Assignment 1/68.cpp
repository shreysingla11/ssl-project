#include<iostream>
#include<cmath>
#include<cstdio>
#include "stdio.h"
using namespace std;
double f(int n){

};
int main(){

int n;
cin>>n;
cout<<endl;
double max1=0,max2=0,a,b,max=f(1);
for(double i=2;i<=n;i++){
if(f(i)>=max){max=f(i);
}
//42 1 23 4 8 10
else{
a=max-f(i);
if(a>max1){max1=a;}
}
}
printf("%0.6f",max1);
cout<<max2;
return 0;
}
