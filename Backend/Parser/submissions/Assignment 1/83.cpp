#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
exterm double f(long int n);

double funcgiven(long int i,int p,int a,int b,int c,int d )
{
    double result;
    result=p*(sin(a*i+b)+cos(c*i+d) +2 );

//compute the value for that function
    return result;
}



double f(long int n)
{
    double result=0.0,maxrateresult=0.0;
//first make array of all the values of the function

    long double fvalues[n];
    for(long int i=0; i<n; i++)
    {
        fvalues[i]=funcgiven(i,p,a,b,c,d);//
    }


    //mergesort(fvalues,sortedfvalues,0,n-1,result,maxrateresult);
    double maxn=fvalues[0],tempfall,tempratefall=0;
    for(long int i=1; i<n; i++)
    {
        if(fvalues[i]>=maxn)
        {
            //no fall
            maxn=fvalues[i];
        }
        else
        {
            tempfall=maxn-fvalues[i];
                     if(tempfall>result)
            {
                result=tempfall;
            }
        }
        tempratefall=fvalues[i]-fvalues[i-1];
        //maxrateresult=fvalues[i]-fvalues[i-1];
        if(maxrateresult<tempratefall){
        maxrateresult=tempratefall;
        }

    }

//we have the array
//now find the falls using mergesort for O(nlogn) time

    return result;
}

int main()
{
    int p,a,b,c,d;//n as defined in function
    long int n;
    cin>>p>>a>>b>>c>>d>>n;
    double maxfal=f(n,p,a,b,c,d);
    std::cout<<std::fixed;
    std::cout<<std::setprecision(6);
    cout<<"answer:"<<maxfall;
    //checked mergesort

    return 0;
}
