#include <iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

double f(int i)
{

}

double maxfall(int n)
{   if(n==1) return 0.0;
    double maxi=f(1);
    double fall=0.0;
    int i=2;
    double j;
    while(i<=n)
    {   j=f(i);
        if(j>maxi) maxi=j;
        else if((maxi-j)>fall) fall=maxi-j;
        i++;
    }
    return fall;
}
double maxratefall(int n)
{   if(n==1) return 0.0;
    double maxi=0.0, a, b;

    int i=2;
    while(i<=n)
    {   b=f(i);
        a=f(i-1);
        if((a-b)>maxi) maxi=(a-b);
        i++;
    }
    return maxi;
}
int main()
{
    int n;
    scanf("%d",&n);
    double result=maxfall(n);
    printf("%.6lf",result);
    cout<<endl;
    double result2=maxratefall(n);
    printf("%.6lf",result2);
    return 0;
}
