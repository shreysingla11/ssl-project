#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

extern double f (int);
//{
    //function f is defined here
    /*double result1;
    int p=1000, a=797, b=148, c=780, d=347;
    result1=10-2*x;//p*(sin(a*x+b)+cos(c*x+d)+2);
    return result1;*/
//}

double fall (int a, int b)
{
    double result=0;
    if (f(a)>=f(b))
    {
        result=f(a)-f(b);
    }
    else
    {
        result=0;
    }
    return result;
}

double fallrate (int a, int b)
{
    double result=0;
    if (f(a)>=f(b))
    {
        result=(f(a)-f(b))/(b-a);
    }
    else
    {
        result=0;
    }
    return result;
}

int main()
{
    int N;
    cout<<"Give N : ";
    cin>>N;

    double r=0,s=0,p=0,q=0,t=f(1);
    int n=1,m=1;
    while (n<=N)
    {
        if (r<s)
        {
            r=s;
        }
        else
        {

        }

        //change s here for n:n+1
        if ((s+f(n))<=f(n+1))
        {
            s=0;
        }
        else
        {
            s=s+f(n)-f(n+1);
        }

        if (p<=q)
        {
            p=q;
        }

        if (f(n)>=t)
        {
            m=n;
            t=f(n);
        }

        q=(t-f(n+1))/(n+1-m);


        n=n+1;

    }

    //cout<<"\n Maximum fall is : "<<r;
    printf("%s %0.6f","Maximum fall is : ", r);

    printf("%s %0.6f","\nMaximum fall-rate is : ", p);

    return 0;
}
