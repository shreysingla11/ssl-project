#include<iostream>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;
extern double f(int n);
int main()
{
    long long int n;
    double* arr=new double[n];
    int i;
    double maxe=arr[0];
    double diff=0.0;
    double fallrate=0.0;
    double temp=0.0;
    for(i=0;i<n;i++)
        arr[i]=f(i+1);
    for(i=0;i<n-1;i++)
    {
        if(maxe>=arr[i])
            diff=max(maxe-arr[i],diff);
        else
            maxe=arr[i];
        if(arr[i]>arr[i+1])
            fallrate=max(fallrate,arr[i]-arr[i+1]);
    }
    if(maxe>=arr[n-1])
        diff=max(maxe-arr[n-1],diff);
    cout<<fixed<<setprecision(6)<<diff<<endl;
    cout<<fixed<<setprecision(6)<<fallrate<<endl;
    return 0;
}
