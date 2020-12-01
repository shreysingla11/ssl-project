#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double f(int i);
int main()
{
    int n;
    cin>>n;
    double *a=new double [n];
    for(int i=1; i<=n; i++)
    {
        a[i-1]=f(i);
    }
    double l,m,fall,rate;
    fall=0.0;
    rate=0.0;
    l=a[0];
    m=a[0];
    int x,y;
    for(int j=1; j<=n; j++)
    {
        if(a[j-1]>l)
        {
            l=a[j-1];
        }
        if(l-a[j-1]>fall)
        {
            fall=l-a[j-1];
        }
        if(a[j-1]-a[j]>rate)
        {
            rate=a[j-1]-a[j];
        }
    }
    printf("%.6lf",fall);cout<<endl;
    printf("%.6lf",rate);cout<<endl;
    return 0;
}
