#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double f(int i);
int main()
{
    int n;
    cout<<"Give the value of n :";
    cin>>n;
    if(!(n>=1 && n<=100000000))
    {
        cout<<"Sorry, the given n is very large";
    }
    int i=1;
    double r=0,s=0;
    while(i!=n)
    {
        if(s>r)
        {
            r=s;
        }
        if(f(i+1)>=f(i) && s!=0)
        {
            s=s+f(i)-f(i+1);
        }
        else{if(f(i+1)<f(i) && s==0){s=f(i)-f(i+1);}else{s=s+f(i)-f(i+1);}        i=i+1;
    }
    }
    printf("%6f",r);


}
