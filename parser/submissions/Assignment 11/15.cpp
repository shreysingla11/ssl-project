#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n=0,i=0,j=0,value=0,twopow=1;
	int oneCount[5] = {0,0,0,0,0};
	//string answer;
	char letter;
	int errors=0;
	long long int num = 0;
	char input[45];
	cin>>n;
	
	while(i!=n)
	{
		scanf("%lld", &num);
		for(j=0;j<45;j++)
		{
			if(num%2==0)
			{
				input[j] = 0;
			}
			else
			{
				input[j] = 1;
				oneCount[j/9]++;
			}
			num/=2;
		}
		for(j=0;j<5;j++)
		{
			if(oneCount[j]>=5)		
			{
				errors += 9 - oneCount[j];
				value += twopow; 
			}
			else
			{
				
				errors += oneCount[j];
			}
			twopow *= 2;
		}
		if((value>25)||(errors>4))
		{
			letter='?';
		}
		else
		{
			letter = 97 + value;
		}
		printf("%c",letter);
		//answer += letter;
		for(j=0;j<5;j++)
		{
			oneCount[j]=0;
		}
		value = 0;
		errors = 0;
		twopow = 1;
		i++;
	}
	cout<<endl;
	return 0;
}
