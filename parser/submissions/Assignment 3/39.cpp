#include<iostream>
#include<limits>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
int i,j,c,min;
c = 100000000;
int a[n],b[m];
double L[n][m];
L[n][m]=0;
for(i=0;i<n;i++){
cin>>a[i];
}
for(i=0;i<m;i++){
cin>>b[i];
}
if(a[n-1]=b[m-1]){ L[n-1][m-1] = 1;}
else{L[n-1][m-1] = c;}
cout<<L[n-1][m-1]<<endl;
for(i=n-1;i<0;i--){
    if(a[i-1] = b[m-1])
           { L[i-1][m-1] = 1;}
    else
           { (L[i-1][m-1]) = 1 + (L[i][m-1]);}
}
cout<<L[n-2][m-1];
for(i=n-1;i<0;i--){
cout<<L[i][m-1]<<endl;}

for(j=0;j<m-1;m++){
L[n-1][j] = c;}

for(j=m-1;j<0;j--){
for(i=n-1;i<0;i--){
if(a[i-1] = b[j-1]){L[i-1][j-1] = 1+(L[i][j]);}
else{L[i-1][j-1] = 1+(L[i][j-1]);}
}
}
for(i=n-1;i<0;i--){
cout<<L[i][0]<<endl;}
int x;
min=c;
for(i=n-1;i<0;i--){
if(L[i][0] <= min)
{min = L[i][0];
   x = i;}
}
cout<<min<<x<<endl;

return 0;
}













