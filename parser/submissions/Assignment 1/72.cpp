#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

extern double f(int);



int main()
{
    int n, i=0, j=0;
    cin>>n;
    double fall=0.000000, rateOfFall=0.000000;


    for(i=1; i<n;i++)
    {
        for(j=i+1; j<=n;j++)
        {
            if(f(j)<f(i))
            {   if(f(i)-f(j)>fall)
                  fall=f(i)-f(j);
            }
            else if(f(j)>f(i))
            {
                break;
            }
        }
        i=j-1;
    }
    for(i=1; i<n;i++)
    {
       if(f(i)-f(i+1)>rateOfFall)
         rateOfFall=f(i)-f(i+1);
    }


     std::cout.precision(6);
     cout<<std::fixed<<fall<<"\n"<<rateOfFall;
     return 0;
}
