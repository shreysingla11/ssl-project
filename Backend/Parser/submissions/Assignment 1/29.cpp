#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;

extern double f(long long int n);

double max(double funcvalue[],long long int start,long long int end)
{
    double maximum=funcvalue[start];
    for(long long int i=start+1; i<=end; i++)
    {
        if(funcvalue[i] > maximum)
        {
            maximum = funcvalue[i];
        }
    }

    return maximum;
}

double min(double funcvalue[],long long int start,long long int end)
{
    double minimum=funcvalue[start];
    for(long long int i=start+1; i<=end; i++)
    {
        if(funcvalue[i] < minimum)
        {
            minimum = funcvalue[i];
        }
    }

    return minimum;
}

double maxfall(double funcvalue[],long long int start,long long int end)
{
    if(end == start + 1)
    {
        return (funcvalue[start] - funcvalue[end]);
    }

    if(end == start)
    {
        return 0;
    }

    long long int mid = (start + end) /2;
    double secondhalfmax;
    double mixedhalf;
    double maximumfall;
    double firsthalfmax = maxfall(funcvalue,start,mid);
    if(firsthalfmax < 0)
    {
        firsthalfmax = 0;
    }

    secondhalfmax = maxfall(funcvalue,mid+1,end);
    if(secondhalfmax < 0)
    {
        secondhalfmax = 0;
    }
    mixedhalf = max(funcvalue,start,mid) - min(funcvalue,mid+1,end);
    if(mixedhalf < 0)
    {
        mixedhalf = 0;
    }

    maximumfall = firsthalfmax;
    if(secondhalfmax > maximumfall)
    {
        maximumfall = secondhalfmax;
    }
    if(mixedhalf > maximumfall)
    {
        maximumfall = mixedhalf;
    }

    return maximumfall;
}

double maxfallrate(double funcvalue[],long long int start,long long int end)
{
    double maxdiff=0,temp;

    for(long long int i=start; i<end; i++)
    {
        temp = funcvalue[i] - funcvalue[i+1];
        if(maxdiff < temp)
        {
            maxdiff = temp;
        }
    }

    return maxdiff;
}

int main()
{
    long long int n;
    cin>>n;
    double *funcvalue;
    funcvalue = new double[n+1];

    for(long long int i=1; i<=n; i++)
    {
        funcvalue[i] = f(i);
    }

    double maximumfallvalue = maxfall(funcvalue,1,n);
    double maximumfallrate = maxfallrate(funcvalue,1,n);

    printf("%.6f",maximumfallvalue);
    cout<<endl;
    printf("%.6f",maximumfallrate);
    cout<<endl;

    return 0;
}
