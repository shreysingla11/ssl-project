#include <iostream>
#include <iomanip>
#include <cmath>

extern double f(int n);

using namespace std;

int main()
{
	int n;
	double maxfall=0,max,maxfallrate=0,prev,fall,value;
	cout<<std::fixed;
	cin>>n;
	prev=f(1);
	max=prev;
	for(int i=2;i<=n;i++)
	{
		value=f(i);
		fall=prev-value;
		if(value>max)
		{
			max=value;
		}
		else 
		{
			if(max-value>maxfall)
			{
				maxfall=max-value;
			}
			if(fall>maxfallrate)
			{
				maxfallrate=fall;
			}
		}
		prev=value;
	}
	cout<<setprecision(6)<<maxfall<<endl;
	cout<<setprecision(6)<<maxfallrate<<endl;
	return 0;
}