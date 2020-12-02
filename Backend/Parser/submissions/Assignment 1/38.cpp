#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;

extern double f(int i);
/*{
    int p,a,b,c,d;
    return p*(sin(a*i+b)+cos(c*i+d)+2);

}*/

int main()
{
    int n;
    double max_fall=0;
    double maximum=f(1);
    double curr;
    //int imax=1;
    double currrate=0;
    double maxrate=0;
    double prevcurr=0;
    cin>>n;

    for(int i=2; i<=n;i++)
    {
        curr=f(i);
        if(maximum<curr)
        {
            maximum=curr;
            //imax=i;
        }
        else
        {
            currrate=prevcurr-curr;
            if(currrate>maxrate)
            {
                maxrate=currrate;
            }
            else
            {

            }
            /*for(int j=imax; j<i; j++)
            {
                currrate=(f(j)-f(i))/(i-j);
                if(currrate>maxrate)
                {
                    maxrate=(f(j)-f(i))/(i-j);
                }
            }*///brute force method with slight improvisation for max fall rate
            if(max_fall<(maximum-curr))
            {
                max_fall=maximum-curr;
            }

            else
            {

            }
        }
            prevcurr =curr;
    }

    printf("%.6f",max_fall);
    cout<<endl;
    printf("%.6f",maxrate);
    return 0;
}




