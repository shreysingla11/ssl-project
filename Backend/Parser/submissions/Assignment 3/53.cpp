#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;

int L(int a[],int b[],int n,int m,int i,int j)
{
int an=n+1;
    if(i==n && j==m && a[i-1]==b[j-1]){return 1;}
    else if (i==n && j==m){return 1+L(a,b,n,m,i+1,m);}
    else if(i==n){return an;}
    else if(a[i-1]==b[j-1]){return 1+L(a,b,n,m,i+1,j+1);}
    else{return 1+L(a,b,n,m,i+1,j);}
}

void ans(int a[],int b[],int n,int m)
{
    int an=n+1,i=1,x;
    while(i<=n)
    {
        x=L(a,b,n,m,i,m);
        if(x<an){an=x;}
        i++;
    }
    printf("%d\n",an);
}

int main()
{
    int n,m,i=0;
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    while(i<n)
    {scanf("%d",&a[i]);i++;}
    i=0;
    while(i<m)
    {scanf("%d",&b[i]);i++;}

    ans(a,b,n,m);
}
