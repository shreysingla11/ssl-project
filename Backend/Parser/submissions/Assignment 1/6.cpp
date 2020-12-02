#include<iostream>
#include<cmath>
#include<iomanip>
#include "stdio.h"
using namespace std;

extern double f(int n);

int main()
{
    long long int n;
    cin>>n;
    double max_val=f(1);
    double max_fall=0.00000000;
    double max_rate=0.00000000;
    double f_i, f_prev;
    f_prev = f(1);
    for(int i=2;i<=n;i++)
    {
        f_i=f(i);
        if(f_i - f_prev >= max_rate)
            max_rate = f_i - f_prev;
        if(f_i>=max_val)
            max_val=f_i*1.00000000;
        if((max_val-f_i)>=max_fall)
            max_fall=max_val-f_i;
        f_prev = f_i;
    }
    if(max_fall>=0.00000000)
        printf("%0.6f",max_fall);
    else cout<<0.000000;
    cout<<endl;
    if(max_rate>=0.00000000)
        printf("%0.6f",max_rate);
    else cout<<0.000000;

    return 0;
}

