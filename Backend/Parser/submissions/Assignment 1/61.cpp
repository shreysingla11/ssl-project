#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(long long int i)
{
  // double p = 1000,a = 208,b = 734,c = 845,d = 264;
  // return (p * (sin(a*i+b) + cos(c*i+d) + 2));
}

int main()
{
    long long int n;
    cout<<"Enter n";
    cin>>n;
    double maxi,fall = 0,maxi_fall = 0,rate_of_fall = 0,max_rate_of_fall = 0;
/*    for(long long int i=1; i<=n; i++)
    {
        array1[i] = f(i);
    }*/
    maxi=f(1);
    for(int i=1; i<n; i++)
    {
        if(maxi<f(i))maxi=f(i);
        fall = maxi - f(i+1);
        if(fall> maxi_fall)maxi_fall = fall;
        rate_of_fall = (f(i)-f(i+1));
        if(max_rate_of_fall < rate_of_fall) max_rate_of_fall = rate_of_fall;
    }
    if(maxi_fall>=0)
    {
        cout<<"Fall is ";
        cout<<setprecision(10)<<maxi_fall<<endl;
    }
    else cout<<"Max Fall is 0"<<endl;
    if(max_rate_of_fall>=0)
    {
        cout<<"Max Rate Of Fall is ";
        cout<<setprecision(10)<<max_rate_of_fall<<endl;
    }
    else cout<<"Max rate of Fall is 0"<<endl;
}
