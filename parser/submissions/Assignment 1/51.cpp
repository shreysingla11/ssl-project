#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
extern double func(int n){
 //return 212 * (sin(516*n+989) + cos(348*n+25) + 2);

}

double fall(int n){
double maxi=func(1),maxfall=0,i,k;
for(i=2;i<n+1;i++){
k=func(i);
if(maxfall<maxi-k){maxfall=maxi-k;}
if(maxi<k){maxi=k;}
}
return maxfall;
}

int main(){
int x;
cout<<"Give the value of n:\n";
cin>>x;
printf("%f",fall(x));
return 0;
}
