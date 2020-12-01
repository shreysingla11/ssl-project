#include<iostream>
using namespace std;
int main()
{
int n, m;
cin>>n;
cin>>m;
int *a;
a=new int[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
int *b;
b=new int[m];
for(int i=0;i<m;i++)
{cin>>b[i];}

int l,k=n;

int **L;
L=new int *[n];

for(int i=n-1;i>=0;i--)
{
L[i]=new int[m];

for(int j=m-1;j>=0;j--)
{
//L[n,m] = 1 if a_n == b_m and infinity otherwise.
if(i==n-1&&j==m-1){
if(a[n-1]==b[m-1]){
L[i][j]=1;}
else{L[i][j]=n+1;}
}
else{
//L[i,m] = 1 if a_i == b_m otherwise it is 1+L[i+1,m], for 1 <= i < n;
if(j==m-1){
if(a[i]==b[m-1]){L[i][j]=1;}
else{if(i>=0&&i<(n-1)){L[i][j]=1+L[i+1][j];}}
}
else{
//L[n,j] = infinity for all j < m.
if(i==n-1){if(j<m-1){L[i][j]=n+1;}}
//L[i,j] = 1 + L[i+1,j+1] if a_i == b_j, otherwise it is 1 + L[i+1,j] for
//all 1 <= i < n, 1 <= j < m.
else{
if(a[i]==b[j]){L[i][j] = 1 + L[i+1][j+1];}
else{if((i>=0&&i<n-1)&&(j>=0&&j<m-1)){L[i][j]=1+L[i+1][j];}}
}
}
}
}
if(i==n-1){l=L[n-1][0];}
else{
if(l>=L[i][0]){l=L[i][0];k=i+1;}
}
}

if(l<=n){
cout<<l<<" "<<k<<endl;
}
else{cout<<"infinity";}

return 0;
}
