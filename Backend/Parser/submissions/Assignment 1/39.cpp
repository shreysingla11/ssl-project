#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double f(int i);
int main()
{
    int n;
    cin>>n;
    double maxim = f(1);
    double fall_max = 0;
    double fall_rate = 0;
    double current;
    double curr_fall_rate;
    double previous_value;
    for(int i = 2; i<=n ; i++)
    {
        current = f(i);
        if(maxim<current)
        {
            maxim = current;
        }
        else if(maxim-current>fall_max)
        {
            fall_max = maxim-current;
        }
        curr_fall_rate = previous_value - current;
        if(curr_fall_rate>fall_rate)
        {
            fall_rate = curr_fall_rate;
        }
        previous_value = current;
    }
    printf("%.6f",fall_max);
    cout<<endl;
    printf("%.6f",fall_rate);
    return 0;
}
