#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
/*double f(int i)
{
    int p,a,b,c,d;
    return p * (sin(a*i+b) + cos(c*i+d) + 2);

}*/
extern double f(int i);
int main()
{
    int n,t=1;
    double fall,curmax=f(1),maxfal=0,maxratfal=0;
    cin>>n;
    while(t<=n)
    {
        if (f(t)>curmax)
        {
            curmax=f(t);
        }
        if(curmax>=f(t))
        {
            if(curmax-f(t)>maxfal)
            {
                maxfal=curmax-f(t);
            }
        }
        if(t!=n)
        {
            if((f(t)-f(t+1))>maxratfal)
            {
                maxratfal=(f(t)-f(t+1));
            }
        }
        t++;
    }
    printf("%f",maxfal);
    cout<<"\n";
    printf("%f",maxratfal);
}
