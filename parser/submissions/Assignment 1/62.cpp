#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double f(int k)
{
    double v=cos(k)+sin(k);
    return v;
}
int main()
{
    int n;
    double maxi=0,rate=0;
    cout<<"Give the value of 'n'"<<endl;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(f(i)<f(j)){;}
            else
            {
            double t= (f(i)-f(j))/(j-i);
            if(rate>=t){;}
            else{rate=t;}

                if(maxi>=(f(i)-f(j))){;}
                else
                {maxi=(f(i)-f(j));}
            }
        }
    }
    printf("%.6f\n",maxi);

    printf("%.6f\n",rate);
    return 0;
}
