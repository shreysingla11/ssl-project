#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

extern double f(int i);


double maxfall(int n)
{
    int N=2;
    double mval=f(1),nval,mfall=0;
    while(N!=n)
    {
        nval=f(N);
        if(nval>mval)
        {
            mval=nval;
        }
        else
        {
            if(mfall<mval-nval)
            {
                mfall=mval-nval;
            }
        }
        N++;
    }
    return mfall;
}

double maxratefall(int n)
{
    double mval=0,nval,fval,lval=f(1);
    for(int i=2; i<n; i++)
    {
        fval=f(i);

        nval=fval-lval;
        if(nval>mval)
        {
            mval=nval;
        }
        lval=fval;

    }


    return mval;
}








int main()
{
    double f,l;
    cin>>n;
    f=maxfall(n);
    printf("%.6f ",f);
    l=maxratefall(n);
    cout<<endl;
    printf("%.6f",l);
    return 0;
}
