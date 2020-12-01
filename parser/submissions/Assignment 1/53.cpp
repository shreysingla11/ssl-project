#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
extern double f(int i);
int  main()
{
int  n;
cout<<"give the max limit:";
cin>>n;
int j,k;
double fall=0.000000,max_rate=0.000000;
if(n==1){cout<<"fall:"<<fall;
return 0;}
for(j=0;j<n;j++)
    {if(j>0&&f(j)<f(j-1)){break;}
        for(k=j+1;k<=n;k++)
            {if (k==j+1){ if(f(j)-f(k)>=max_rate)
                               {
                                  max_rate=f(j)-f(k);
                                }
                        }
              if(f(j)-f(k)>=fall)
                  {
                     fall=f(j)-f(k);
                  }
             }
     }
cout<<"fall:";
printf("%f",fall);
cout<<endl;
cout<<"max rate in fall:";
printf("%f",max_rate);
return 0;

 };




