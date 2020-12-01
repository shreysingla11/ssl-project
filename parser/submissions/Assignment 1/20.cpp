#include<iostream>
#include<cstdio>
using namespace std;
extern double f(double z);
int main()
{
    double n;
    cin>>n;
    double fall_rate=0;
    double i=1;
    double j;
    double max=f(i);
    double max_index=1;
    double fall=0;
    for(j=i+1; j<=n; j++)
    {
        if(f(i)>max)
        {
            max=f(i);
            max_index=i;
        }
        if(f(i)-f(j)>fall_rate)
        {
            fall_rate=f(i)-f(j);
        }
        if(max-f(j)>fall)
        {
            fall=max-f(j);
        }
        if(f(j)<=f(i))
        {
            if(f(i)-f(j)>fall)
            {
                fall=f(i)-f(j);
            }
            if(max-f(j)>fall)
            {
                fall=max-f(j);
            }
        }
        i++;
    }
    printf("%.6f",fall);
    cout<<endl;
    printf("%.6f",fall_rate);
    return 0;
}
