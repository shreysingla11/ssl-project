#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

extern double f(int i);

int main()
{
    int n;
    cin>>n;
    double fall_value,fall_rate=0;
    double s=f(1);

    for(int i=0; i<n; i++)
    {
        fall_value=max(fall_value,s-f(i));
        s=max(s,f(i));
        fall_rate=max(fall_rate,f(i)-f(i+1));
    }
    printf("%.6f",fall_value);
    cout<<endl;
    printf("%.6f",fall_rate);

return 0;
};
