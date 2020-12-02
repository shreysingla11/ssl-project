#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>

//int k,a,b,c,d;

extern double f(long long int i);
/*{

    return (double)(k*(sin(a*i+b)+cos(c*i+d)+2));

}*/

using namespace std;

int main()
{

//    scanf("%d",&k);
//    scanf("%d",&a);
//    scanf("%d",&b);
//    scanf("%d",&c);
//    scanf("%d",&d);

    long long int n;
    scanf("%lld",&n);
    double temp,maximum,minimum,diff_max=0,diff,fall=0,fall_max=0,index=1,adj;
    temp=f(1);adj=temp;
    //cout<<temp;
    maximum=temp;
    minimum=temp;
    for(long long int i=2;i<=n;i++)
    {
        temp=f(i);
        if(minimum>temp)
            minimum=temp;
        else if(maximum<=temp)
            {

                maximum=temp;
                minimum=temp;
            }
        diff=maximum-minimum;
        if(adj>temp)
            fall=adj-temp;
        if(diff>diff_max)
            diff_max=diff;
        if(fall_max<fall)
        {
            fall_max=fall;
        }
        adj=temp;

    }
    printf("%.6f\n", diff_max);
    printf("%.6f\n", fall_max);

}
