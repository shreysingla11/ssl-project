#include<iostream>
#include<cstdio>
using namespace std;
extern double f(int n);
int main()
{
    int n;
    double maxvalue;
    double maxfall=0.0;
    double maxfallrate=0.0;
    cin>>n;
    maxvalue=f(1);
    for(int i=2; i<=n; i++)
    {
        if((maxvalue-f(i))>maxfall)
        {
            maxfall=maxvalue-f(i);
        }
        if(f(i)>maxvalue)
        {
            maxvalue=f(i);
        }
         if((f(i)-f(i-1))>maxfallrate)
         {
         maxfallrate=f(i)-f(i-1);
         }
    };
    /*if(f(2)-f(1)>0)
    {

    maxfallrate = f(2)-f(1);

    }*/
    for(int j=2;j<=n;j++)
    {

    }
    printf("%.6f",maxfall);
    cout<<endl;
    printf("%.6f",maxfallrate);
    return 0;
}

