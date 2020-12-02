#include<iostream>
#include<unordered_map>
#include<bitset>
#include<cstdio>
using namespace std;

int main()
{
unordered_map<long long int,char> error;


for(int l=0;l<26;l++)
{
	bitset<5> b=(l);
	bitset<45> c;
	for(int i=0;i<5;i++)
	{

		for(int j=0;j<9;j++)
		{
			c[j+9*i]=b[i];
		}
	}
	// for(int i=0;i<45;i++)
	// 	cout<<c[i];

	// cout<<"\n"<<c.to_ullong();
	long long int d=c.to_ullong();
	error[d]=char(int('a')+l);

	for(int i=0;i<45;i++)
	{
		c.flip(i);
		d=c.to_ullong();
		error[d]=char(int('a')+l);
		c.flip(i);
	}
	for(int i=0;i<45;i++)
	{
		c.flip(i);
		for(int j=i+1;j<45;j++)
		{
			c.flip(j);
			d=c.to_ullong();
			error[d]=char(int('a')+l);
			c.flip(j);
		}
		c.flip(i);
	}
	for(int i=0;i<45;i++)
	{
		c.flip(i);
		for(int j=i+1;j<45;j++)
		{
			c.flip(j);
			for(int k=j+1;k<45;k++)
			{
				c.flip(k);
				d=c.to_ullong();
				error[d]=char(int('a')+l);
				c.flip(k);
			}

			c.flip(j);
		}
		c.flip(i);
	}
	for(int i=0;i<45;i++)
	{
		c.flip(i);
		for(int j=i+1;j<45;j++)
		{
			c.flip(j);
			for(int k=j+1;k<45;k++)
			{
			c.flip(k);
				for(int m=k+1;m<45;m++)
				{
					c.flip(m);
					d=c.to_ullong();
					error[d]=char(int('a')+l);
					c.flip(m);
				}
			c.flip(k);
			}

			c.flip(j);
		}
		c.flip(i);
	}
}

int num_test;
scanf("%d",&num_test);
for(int n=0;n<num_test;n++)
{
	long long int e=0;
	scanf("%lld",&e);
	unordered_map<long long int,char>::iterator it;
	it=error.find(e);
	if(it!=error.end())
	printf("%c",it->second);
	else
	printf("%c",'?');
}

return 0;
}
