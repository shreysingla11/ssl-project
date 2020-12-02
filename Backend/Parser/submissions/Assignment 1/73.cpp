#include <iostream>
#include <algorithm>
#include <iomanip>

#define NINF -1000000000
using namespace std;

extern double f(int x);

int main()
{
	int N; cin>>N;

	double bigPos = NINF;
	double funcVal;
	double diffMax = 0;
	double prevVal = NINF;
	double diffRateMax = 0;

	for (int i = 1; i <= N; ++i)
	{
		funcVal = f(i);

		// biggest drop calculation
		if(funcVal - prevVal > 0)
		{
			bigPos = max(bigPos, funcVal);
		}
		else
		{
			diffMax = max(diffMax, bigPos - funcVal);
		}

		// rate calculation
		diffRateMax = max(diffRateMax, prevVal - funcVal);

		//setting prevVal
		prevVal = funcVal;
	}

	cout<<fixed<<setprecision(6)<<diffMax<<endl<<diffRateMax<<endl;
	return 0;
}
