#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

extern double f(long long n);

double fallmax(long long start,long long end,double fall)
{
    double fall1=0,fall2=0,max=f(start),min=f((start+end)/2),temp=0;
    long long mid=(start+end)/2;
    if(end-start==0)
    {
        fall=0;
        return fall;
    }
    else
    {
        fall1=fallmax(start,mid,fall);
        fall2=fallmax(mid+1,end,fall);
        if(fall1>fall2){fall=fall1;}
        else{fall=fall2;}
    }
    for(long long i=start;i<=mid;i++)
    {
        temp=f(i);
        if(temp>max){max=temp;}
    }
    for(long long j=mid+1;j<=end;j++)
    {
        temp=f(j);
        if(temp<min){min=temp;}
    }
    if(max-min>fall)
    {
        fall=max-min;
    }
    return fall;
}

double fallmaxrate(long long n)
{
    double fvalues[n],maxrate=0,temp=0;
    fvalues[0]=f(0);
    for(long long i=1;i<=n;i++)
    {
        fvalues[i]=f(i);
        temp=fvalues[i-1]-fvalues[i];
        if(temp>maxrate)
        {
            maxrate=temp;
        }
    }
    return maxrate;
}
int main()
{
    long long n=0;
    scanf("%ld",&n);
    double fall=0,fallrate=0;
    fall=fallmax(0,n,fall);
    fallrate=fallmaxrate(n);
    printf("%.6f \n",fall);
    printf("%.6f \n",fallrate);
    return 0;
}
