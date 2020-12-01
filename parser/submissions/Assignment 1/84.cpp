#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

extern double f(long long int i);


int main()
{
    long long int n;
    cin>>n;
    long long int i;
    double mdc=0,md=0,m=f(1);
    double temp,tempo=f(1);
    for(i=2; i<=n; i++)
    {

    temp=f(i);


        if((tempo-temp)>mdc)
        {
            mdc=tempo-temp;
        }
        if((m-temp)>md)
        {
            md=m-temp;
        }
        if(temp>m)
        {
            m=temp;
        }
        tempo=temp;
    }

    printf("%.6lf",md);
    cout<<endl;
     printf("%.6lf",mdc);

    return 0;
}
