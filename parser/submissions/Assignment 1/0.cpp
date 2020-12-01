#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a,b,c,d,p;
double f(int i)
{
    double result=p*(sin(a*i+b) + cos(c*i+d) + 2);
    return result;
}
double diff(int j)
{
    return f(j)-f(j+1);
}
int main()
{
    int len=10000000;
    int n;
    int cnt=0;
    double *start=new double[len];
    double *end=new double[len];

    scanf("%d %d %d %d %d %d",&p,&a,&b,&c,&d,&n);
    double difference,max_diff=0;
    int i=1;
    while(i<n)
    {
        if(cnt>=100000)
            break;
        difference=diff(i);
        if(difference>=0)
        {
            if(difference>=max_diff)
                max_diff=difference;//Max rate of fall
            start[cnt]=f(i);
            while(diff(i)>=0&&i<n)//Function is decreasing
                i++;
            end[cnt++]=f(i);
         }
         i++;
    }
    double max_fall=0;
    for(int i=0;i<cnt;i++)
    {
        for(int j=i;j<cnt;j++)
            if(start[i]-end[j]>=max_fall)
                max_fall=start[i]-end[j];
    }
    printf("%lf\n%lf",max_fall,max_diff);

}

