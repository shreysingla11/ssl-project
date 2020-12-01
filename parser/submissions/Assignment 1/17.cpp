#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double f(int i);
/*{
    return 1000*(sin(797*i+148)+cos(780*i+347)+2);
}*/

int main()
{

    int n;
    cout<<"enter the value of n";
    cin>>n;
    int i=1,p=1;
    double MaxRate=0,MaxFall=0,Temp1=0,Temp2=0,s=0;
    while(i<n)
    {
        s=f(i)-f(i+1);
        if(Temp1>0)
        {
            Temp1=Temp1+s;
        }
        else
        {
            Temp1=s;
        }
        if(MaxFall<Temp1)
        {
            MaxFall=Temp1;
        }
        if(Temp2>0)
        {    Temp2=(Temp2*(i-p)+s)/(i+1-p);
        }
        else
        {
             Temp2=s;
             p=i;
        }
        if(MaxRate<Temp2)
        {
            MaxRate=Temp2;
        }
        i++;

    }
    cout<<"max fall is  :";
    printf("%6f",MaxFall);
    cout<<endl;
    cout<<"max rate of fall is  :";
    printf("%6f",MaxRate);
    cout<<endl;
    return 0;
}
