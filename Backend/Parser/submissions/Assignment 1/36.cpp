#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
 double func(int i){
int p,a,b,c,d;
return p * (sin(a*i+b) + cos(c*i+d) + 2);

}
int main(){
int n,r,z;
double x,q;
q=0;
cin>>n;
if(n==1){
printf("%.6f",q);
}
else{
for(z=1;z<n;z++){
for(r=z;r<n;r++){
if (func(z)>func(r+1)){
x=func(z)-func(r+1);

if(x>q){
q=x;
}
}
}
}
printf("%.6f",q);
}
return 0;
}
