#include <iostream>
#include<cstdio>

using namespace std;

extern double f(long int i);

double themaxfall(double *ar,int n)
{
    double max1=ar[0],min1=ar[0],fall=0,temp=0,rate=ar[0]-ar[1];

    if (n<2)
        return 0;
    for (int i=1; i<n; i++)
    {
        if (i!=n-1)
        {
            if (ar[i]-ar[i+1]>rate)
            {
                rate = ar[i]-ar[i+1];
            }
        }
        if (ar[i]>max1)
        {
            max1 = ar[i];
            min1 = ar[i];
            continue ;
        }
        if (ar[i]<min1)
        {
            min1 = ar[i];
            temp = max1 - min1 ;
            if (temp>fall)
            {
                fall=temp ;
            }
        }
    }
    cout<<endl<<"The Maximum Rate Of Fall Is :";
    printf("%.6f",rate);
    if (fall<0)
        return 0;
    return fall;
}

int main()
{
    double *ar;
    int n;
    cin>>n;
    ar = new double[n];
    for (int i=0; i<n; i++)
    {
        ar[i]=f(i+1);
    }
    printf("\nThe Maximum Fall Is : %.6f",themaxfall(ar,n));
    delete ar ;
}
