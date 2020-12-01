#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

extern double f(int n);

int main()
{
    int n;
    cin>>n;
    double maxfall=0;
    double maxfallrate=0;
    double maxelement=f(1);
    for(int i=2; i<n+1; i++)
    {
        if(f(i-1)>maxelement)
        {
            maxelement=f(i-1);
        }
        if((f(i)-f(i-1))<maxfallrate)
        {
            maxfallrate=f(i)-f(i-1);
        }

        if((maxelement-f(i))>maxfall)
        {
            maxfall=maxelement-f(i);
        }
    }

    printf("%.6f",maxfall);
    cout<<endl;
    printf("%.6f",maxfallrate);


}
