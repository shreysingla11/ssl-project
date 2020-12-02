#include <iostream>
#include <cstdio>
using namespace std;
extern double f(long e);
//double funcfall(long a,long b);
//double funcfallrate(long c, long d);
int main()
{
    long n;
    cin>>n;
    double fallmax=0.0;
    double maxfallrate=0.0;
    double maxi;
    maxi=f(1);
    int i=1;
    int j=1;
    for(i=2; i<=n; i++)
    {
        if((f(i)<maxi)&&((maxi-f(i))>fallmax)){fallmax=maxi-f(i);}
        if(f(i)>maxi){maxi=f(i);}
    }
    for(j=1;j<=n;j++){
    if((f(j)>=f(j+1))&&((f(j)-f(j+1))>=maxfallrate)){maxfallrate=f(j)-f(j+1);}
    }
    printf("%.6f",fallmax);
    cout<<endl;
    printf("%.6f",maxfallrate);
    //cout<<fallmax<<endl;
    //cout<<fallmaxrate<<endl;
    return 0;


}




