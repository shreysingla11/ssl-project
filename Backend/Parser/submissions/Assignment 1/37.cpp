#include <iostream>
#include<stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
extern double f(int n);
int main()
{
    int n;
    double fallmax,fallratemax,current,s,next;
    cin>>n;
    fallmax=0;
    fallratemax=0;
    s= f(1);

    for (int i=1; i<n; i++)
    {
        next=f(i+1);
        current=f(i);
        if (s-next>fallmax)//s is the max element upto current.
        {
            fallmax= s-next;
        }
        if (next>s)
        {
            s=next;
        }
        if (current-next>fallratemax)
        {
            fallratemax=current-next;//bcoz max rate of fall occurs between consecutive elements.
        }

    }
    printf("%.6f\n",fallmax);
    printf("%.6f\n",fallratemax);
    return 0;
}
