#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

extern double f(int k);

int main()
{
   double maxi,mini,diff,fall,fallrate,diffrate;
   int i,j,n;
   cin>>n;
   double r;
   maxi=mini=0.0;
   diff=fall=diffrate=fallrate=0.0;
   i=j=1;
   for(int k=2;k<=n;k++)
   {
        r=f(k);
        if(r>=maxi)
        {
            maxi=mini=r;
            diff=0.0;
            diffrate=0.0;
            i=j=k;
        }
        else
        {
            mini=r;
            diff=maxi-mini;
            j=k;
            diffrate=diff/(j-i);
        }
        if(fall<=diff)
        {
            fall=diff;
        }
        if(i!=j)
        {
            if(diffrate>=fallrate)
            {
                fallrate=diffrate;
            }
        }
    }
    printf("%.6lf\n%.6lf",fall,fallrate);
    return 0;
}
