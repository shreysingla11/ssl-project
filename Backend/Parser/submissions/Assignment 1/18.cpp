#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
extern double f(int i);
/*{
    int p=200,a=411,b=433,c=922,d=805;
    return p * (sin(a*i+b) + cos(c*i+d) + 2);
};*/
int main()
{
    int n;
    cin>>n;
    double s=0,p=0,q=0,r=0,temp1,temp2;
    int i=1;
    int k=1;
    while(i<=n)
    {
        temp1=f(i)-f(i+1);
        temp2=(f(k)-f(i+1)/(i+1-k));
        if(p>s)
        {
            s=p;
        }
        if(p+temp1>0&&p>0)
        {
            p=p+temp1;
        }
        else
        {
            if(temp1>0)
            {
                p=temp1;
            }
            else
            {
                p=0;
            }
        }
        if(r>q)
        {
            q=r;
        }
        if(temp2>temp1&&temp2>0)
        {
            r=temp2;
        }
        if(temp1>0&&temp1>temp2)
        {
            r=temp1;
            k=i;
        }
        i++;
    }
    printf("%0.6f \n",s);
    printf("%0.6f \n",q);
}
