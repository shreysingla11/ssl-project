#include<iostream>
#include<cstdio>
using namespace std;
extern double f(int k);// {}

int main()
{
    int i,j,n;
    double maxel=0,maxfal=0,maxratefal=0;

    cin>>n;

    for(i=1; i<=n; i++)
    {
        if(f(i)>maxel)
        {
            maxel=f(i);
        }
        if(maxel-f(i)>maxfal)
        {
            maxfal=maxel-f(i);
        }
        if(maxratefal<(f(i)-f(i+1)))
        {
            maxratefal=(f(i)-f(i+1));
        }

    }

    cout<<"max fall=";
    printf("%.6lf",maxfal);
    cout<<endl;
    cout<<"max rate of fall=";
    printf("%.6lf",maxratefal);
}

