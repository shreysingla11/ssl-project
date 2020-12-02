#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
using namespace std;
extern double func(int);
int main()
{
    int maxi,j,n;
    double x,y,val=0.0,mrf=0.0;
    cin>>n;
    if(n<2)
    {
        cout<<setprecision(6)<<std::fixed;
        cout<<"The maximum value fall: "<<val<<"\n";
        cout<<"The maximum rate of fall: "<<mrf<<"\n";
    }
    else
    {
        x=maxi=func(1);
        j=2;
        while(j<=n)
        {
            y=func(j);
            if(x>y)
            {
                mrf=x-y;
            }
            if((maxi-y)>val)
            {
                val=maxi-y;
            }
            else if(maxi<y)
            {
                maxi=y;
            }
            x=y;
            j++;
        }
    }
    cout<<setprecision(6)<<std::fixed;
    cout<<"The maximum value fall: "<<val<<"\n";
    cout<<"The maximum rate of fall: "<<mrf<<"\n";
    return 1;
}
/*
double func(int i)
{
    double p=350,a=0,b=957,c=0,d=310;
    return (p*(sin(a*i+b)+cos(c*i+d)+2.0));
}
*/

