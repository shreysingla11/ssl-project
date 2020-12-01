#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		long long int num;
		cin>>num;
		int orig=0;
		int errcount=0;
		bool flag=true;
		int power=1;
		for(int j=0;j<5;j++)
		{
			int count1=0;
			for(int k=0;k<9;k++)
			{
				if(num%2)
					count1++;
				num/=2;
			}
			if(count1>=5)
			{
				orig+=power;
				errcount+=(9-count1);
				if(errcount>4)
				{
					flag=false;
					break;
				}
			}
			else
			{
				errcount+=count1;
				if(errcount>4)
				{
					flag=false;
					break;
				}
			}
			power*=2;
		}
		if(!flag)
		{
			printf("?");
			continue;
		}
		else
		{
			char c=orig+97;
			if(orig>=26)
				printf("?");
			else
				printf("%c",c);
		}

	}
}
