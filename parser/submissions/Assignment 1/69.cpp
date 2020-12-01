#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//int p=1000,a=1000,b=1000,c=1000,d=1000;
extern double f(int i);

int main()
{
	long int n;
	cin>>n;

	double fallRate;
	double maxFallRate=0;
	double diff=0;
    double maxTillNow=0.0;
    double currFvalue;
    double prevFnValue;

    prevFnValue=f(1);
    for (int i = 1; i <n; ++i)
    {
    	currFvalue=f(i+1);
    	fallRate=prevFnValue-currFvalue;

    	if (maxTillNow<currFvalue)
    	{
    		maxTillNow=currFvalue;
    	}

    	else
    	{
			diff=max(diff,maxTillNow-currFvalue);
    	}

    	if(maxFallRate<fallRate)
    	{
    		maxFallRate=fallRate;
    	}
    	prevFnValue=currFvalue;
    }

	cout<<std::fixed;
	cout<<setprecision(6)<<"Max Fall "<<diff<<endl;
	cout<<setprecision(6)<<"Max fall rate "<<maxFallRate<<endl;
	return 0;
}
