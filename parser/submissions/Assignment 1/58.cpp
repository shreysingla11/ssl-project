#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
extern double f(int i);
//{

  // return 200*(sin(411*i+433)+cos(922*i+805)+2) ;
  // return 1000*(sin(797*i+148)+cos(780*i+347)+2);
  // return (sin(i+1)+cos(i+1)+2);
  // return (3-i)*1.0;
//}

int main()
{
    int n;
    double r1=0.0,r2=0.0;
    double mf=f(1);
    int i=1,k;
    double j;
    int t1=1,t2;
    cin>>n;
    while(i<n)
    {
        if(f(i)>mf)
        {
            mf=f(i);
            t1=i;
        }
        if(r1>(mf-f(i+1)))
        {

        }
        else
        {
            r1=(mf-f(i+1));  t2=i+1;
        }

        i++;
    }

   printf("%f",r1);
   cout<<endl;

   i=t1;
   while(i<t2)
   {
    k=t2;
   while(k>i)
   {//r1=maxi(r1,(mf-f(i+1)));
    if(r2<((f(i)-f(k))/(k-i))){r2=((f(i)-f(k))/(k-i));}
    k--;
   }
   i++;
    }

   printf("%f",r2);
      cout<<endl;

}
