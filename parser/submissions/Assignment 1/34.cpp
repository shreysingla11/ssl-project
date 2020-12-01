#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

extern double f(int n);

int main()
{
    int n;
    double max_fall=0,max_en,temp=0,max_rateoffall=0;
    cout<<"Give n: ";
    cin>>n;
    max_en=f(1);
    for(int j=2;j<=n;j++)
    {
        temp=f(j);
        if((max_en-temp)>max_fall)max_fall=max_en-temp;
        if(temp>max_en)max_en=temp;
    }
    printf("%0.6f",max_fall);
    cout<<endl;
    printf("%0.6f",max_rateoffall);
    return 0;
}
