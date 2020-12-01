#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

extern double f(int x);

double maxf(int x);

int main()
{
    int n,i,j;
    double temp;
    printf("Give the value of n :");
    cin>>n;

    cout<<fixed;
    cout<<setprecision(6);

    if(!((n>=1)&&(n<=100000000)))
    {
        printf("Value of n is out of bound of this problem.");
    }

    double maxfall=0.000000;
    double maxfallrate=0.000000;

    if(!(n>6000))
    {
        for(i=1; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                if(f(i)>f(j))
                {
                    if((f(i)-f(j))>maxfall)
                    {
                        maxfall=f(i)-f(j);
                    }

                    if(((f(i)-f(j))/(j-i))>maxfallrate)
                    {
                        maxfallrate=(f(i)-f(j))/(j-i);
                    }
                }
            }
        }
    }
    else
    {
        for(j=2; j<=n; j++)
        {
            temp=maxf(j);
            if(temp>f(j))
            {
                if((temp-f(j))>maxfall)
                {
                    maxfall=temp-f(j);
                }

            }
        }
    }
    cout<<endl<<maxfall<<endl;
    cout<<endl<<maxfallrate<<endl;

}

double maxf(int x)
{
    int i;
    double result=f(1);
    for(i=2; i<x; i++)
    {
        if(f(i)>result)
        {
            result=f(i);
        }
    }
    return result;
}

/*double f(int x)
{
    int p,a,b,c,d;
    //04.in
    p=350;
    a=0;
    b=957;
    c=0;
    d=310;

    //03.in
    p=350;
    a=120;
    b=957;
    c=785;
    d=310;

    //05.in
    p=200;
    a=411;
    b=433;
    c=922;
    d=805;

    //06.in
    p=200;
    a=178;
    b=828;
    c=458;
    d=260;

    //07.in
    p=1000;
    a=797;
    b=148;
    c=780;
    d=347;

    p=42;
    a=1;
    b=23;
    c=4;
    d=8;

    double result;
    result=p*(2+sin(a*x+b)+cos(c*x+d));

    return result;
}*/
