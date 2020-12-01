#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
int m,n;
cin>>n>>m;
int *A=new int[n+1];
for(int i=1;i<(n+1);i++)
cin>>A[i];
int *B=new int[m+1];
for(int i=1;i<(m+1);i++)
cin>>B[i];
int L[n+1][2];
int a=n,b=m;
L[n][0]=INT_MAX;
if(A[n]==B[m])L[n][1]=1;
else L[n][1]=INT_MAX;
for(int i=n-1;i>0;i--)
{
    if(A[i]==B[m])L[i][1]=1;
    else{if(L[i+1][1]==INT_MAX)L[i][1]=INT_MAX;
        else L[i][1]=1+L[i+1][1];}
}


while(b>1)
{
for(int i=n-1;i>0;i--){if(A[i]==B[b-1]){if(L[i+1][1]==INT_MAX)L[i][0]=INT_MAX;
                                        else L[i][0]=1+L[i+1][1];}
                        else{if(L[i+1][0]==INT_MAX)L[i][0]=INT_MAX;
                                else L[i][0]=1+L[i+1][0];}

                    }
for(int i=n;i>0;i--){L[i][1]=L[i][0];}
b=b-1;
}
int minstartindex=n-m+1;
int minimum=L[n-m+1][1];
for(int i=n-m;i>0;i--)
{

if(L[i][1]<=minimum){minimum=L[i][1];minstartindex=i;}
}
if(minimum==INT_MAX)cout<<"infinity";
else {cout<<minimum<<" "<<minstartindex;}
}
