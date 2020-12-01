#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

extern double func(long long int);
double max(double,double);

int main()
{
long long int n=0;
double r=0,s=func(1),f1=0,f2=0,max_rate=0,rate=0;
cin>>n;
if(n>=1&&n<=100000000)
{
    for(int i=1;i<n;i++)
        {
            f1=func(i);
            f2=func(i+1);
            s=max(s,f1);
            r=max(r,(s-f2));

            rate=f1-f2;
            max_rate=max(max_rate,rate);
        }

    cout<<setprecision(6)<<fixed<<r<<"\n"<<max_rate;
}
else
    {
    cout<<"n not in limits";
    }
return 0;
}

double max(double a,double b)
{
if(a<=b)
return b;
else
return a;
}
