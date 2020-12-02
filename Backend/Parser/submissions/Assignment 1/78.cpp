#include <iostream>
#include <math.h>
using namespace std;

extern double f(int x);

int main() {

int i,j;
int n;
double maxFall = 0.0;
double maxFall1 = 0.0;
double maxFall2 = 0.0;
double maxValue = f(1);
double minValue1 = f(1);
int minIndex1 = 1;
int maxIndex = 1;
cin>>n;

for(i=1;i<=n;i++) {

if (f(i)>maxValue) {maxValue = f(i); maxIndex = i;}
else if (f(i)<minValue1) {minValue1 = f(i); minIndex1 = i;}
}

int minIndex = maxIndex+1;
int maxIndex1 = minIndex1-1;
double minValue = f(maxIndex+1);
double maxValue1 = f(minIndex1-1);

for(j=maxIndex+1;j<=n;j++) {

if (f(j)<minValue) {minValue = f(j); minIndex = j;}
}

maxFall1 = maxValue - minValue;

for(j=minIndex-1;j>=1;j--) {

if (f(j)>maxValue1) {maxValue1 = f(j); maxIndex1 = j;}
}

maxFall2 = maxValue1 - minValue1;

if(n>1) {
    if(maxFall1>maxFall2) maxFall = maxFall1;
    else maxFall = maxFall2;
}

double maxFallRate = f(2)-f(1);

for(int k=1;k<n;k++) {

if((f(k)-f(k+1))>maxFallRate) {
    maxFallRate = f(k) - f(k+1);
}
}
if(n==1) maxFallRate = 0.0;


//for(j=1;j<=n;j++) {
//for(i=1;i<j;i++){

//if(f(i)>=f(j)) {
//    if((f(i)-f(j)) > maxFall){
//    maxFall = f(i) - f(j);
//    }
//    if(((f(i)-f(j))/(j-i)) > maxFallRate) {
//    maxFallRate = (f(i) - f(j))/(j-i);
//    }
//}
//
printf("%.6f\n",maxFall);
printf("%.6f\n",maxFallRate);

return 0;
}

//100000000
