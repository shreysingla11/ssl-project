#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
extern double f(int i);
/*{
 double p=200;
 double a=411;
 double b=433;
 double c=922;
 double d=805;
 return(p*(sin(a*i+b)+cos(c*i+d)+2));
}*/
void computemaxfallrate(int n)
{double k=0;
//the maximum value will always come out for consecutive integers.
    for(int i=1;i<n;i++)
    {
        double a=f(i);
        double b=f(i+1);
        if((a-b)>=k)
        {
            k=(a-b);
        }
    }
    printf("%.6f\n",k);
}
void computemaxfall(int n)
{
    int i,j;double maxi=f(1),z=0;
    for(i=2;i<=n;i++)
    {
       if(f(i-1)>maxi)
       {
       maxi=f(i-1);}
        if(maxi-f(i)>z)
        {
        z=maxi-f(i);
        }
    }
printf("%.6f\n",z);
}
int main()
{
    int n,i,j;double h=0,k=0,a,b;
    cin>>n;

    computemaxfall(n);
    cout<<endl;
    computemaxfallrate(n);
}

