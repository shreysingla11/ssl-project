#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
extern double f(int i);

int main()
{
    int n;
    double maxrate=0;
    cout<<"enter n";
    cin>>n;
    double max_num=f(1);
    double max_diff=0;
    for(int i=2; i<=n; i++)
    {

        if(f(i-1)>max_num)
            max_num=f(i-1);
        if(max_num-f(i)>max_diff)
            max_diff=max_num-f(i);
        double temp_rate=f(i-1)-f(i);
        if(temp_rate>maxrate)
            maxrate=temp_rate;

    }

    printf("%.6f",max_diff);
    cout<<endl;
    printf("%.6f",maxrate);
}
