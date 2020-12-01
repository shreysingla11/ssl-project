#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
extern double f(int n);
int main()
{
int p,a,b,c,d,n;
double g=0.0;
double h=0.0;
cin>>p;
cin>>a;
cin>>b;
cin>>c;
cin>>d;
cin>>n;
double* l= new double[n+1];
{
for(int i=1;i<=n;i++)
{
l[i]=f(i);
}
}
for(int i=1;i<n+1;i++)
{
for(int j=i+1;j<n+1;j++)
{
double temp=l[i]-l[j];

if(temp>g)
g=temp;
 temp=(l[i]-l[j])/j-i;
 if(temp>h)
h=temp;
}
}
printf("%.6f\n",g);
printf("%.6f",h);
}
