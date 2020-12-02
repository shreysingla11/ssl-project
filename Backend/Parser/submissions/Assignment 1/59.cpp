#include <cstdio>
#include <cmath>
using namespace std;
//int a,b,c,d,p;
extern double f(int);

int main()
{
    int n;
    scanf("%d",&n);
	double diff=0,val=f(1),fall=0,max=val,prev,temp;

	for (int i = 2; i <=n; ++i)
	{
		prev = val;
		val=f(i);
		if(max >= val){
			temp =max-val;
			diff = (diff < temp)? temp:diff;
		}
		else{
			max = val;
		}
		temp = prev -val;
		fall = (temp >fall)?temp:fall;
	}
	printf("%f\n",diff);
	printf("%f\n", fall);
	return 0;
}
/*
double f(int i)
{
    double a,b,c,d,p;
    p=a=b=c=d=1000;
	return p*(sin(a*i+b*1.0)+ cos(c*i+d*1.0));
};
*/

