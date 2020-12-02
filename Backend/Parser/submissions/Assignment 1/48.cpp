#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double f(int n);
double fall(int n)
{
    double answer=0,s=0;
    int i,j;
    for(i=1; i<n; i++)
    {
        if(answer<(s-f(i))){answer=s-f(i);}
        if(s<f(i)){s=f(i);}
    }
    return answer;
}
double fallrate(int n)
{
    int i;
    double answer1=0;
    for(i=0; i<n; i++)
    {
        if(answer1<(f(i)-f(i+1))){answer1=(f(i)-f(i+1));}
    }

    return answer1;
}
int main()
{
    int n;
    cin>>n;
    double fallvalue=fall(n);
    printf("%.6f \n",fallvalue);
    double fallrates=fallrate(n);
    printf("%.6f",fallrates);
    return 0;
}

