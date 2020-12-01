#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

extern double f(int i);


int main()
{
    int n;

    cout<<"input n ";
    cin>>n;
//m represents fall and p represnts fall rate.
    double m=0.000000,s=0.000000,p=0;


    int k=1;
    while(k!=n)
    {

        if(s<=0)
        {
            s=f(k)-f(k+1);
        }
        else
        {
            s+=f(k)-f(k+1);
        }
        if(m<=s)
        {
            m=s;
        }
        k=k+1;
    }
    cout<<"fall=";
    printf("%f",m);
//cout<<m;
    cout<<endl;
/*
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            double x=(f(i)-f(j))/(j-i*1.0);
            if(x>0)
            {
                if(x>p)
                {
                    p=x;
                }
            }
        }
    }*/
    cout<<"fall rate=";
    printf("%f",p);

    return 0;
}
