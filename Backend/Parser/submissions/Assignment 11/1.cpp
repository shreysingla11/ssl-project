#include<iostream>
#include<unordered_map>
#include<bitset>
#include<cstdio>
using namespace std;

int main()
{

unordered_map<long long int,char> str;

for(int p=0;p<26;p++)
{
	bitset<5> r=(p);
	bitset<45> bit_str;
	for(int v=0;v<5;v++)
	{

		for(int x=0;x<9;x++)
		{
			bit_str[x+9*v]=r[v];
		}
	}

	long long int number=bit_str.to_ullong();
	str[number]=char(int('a')+p);

	for(int v=0;v<45;v++)
	{
		bit_str.flip(v);
		number=bit_str.to_ullong();
		str[number]=char(int('a')+p);
		bit_str.flip(v);
	}
	for(int v=0;v<45;v++)
	{
		bit_str.flip(v);
		for(int x=v+1;x<45;x++)
		{
			bit_str.flip(x);
			number=bit_str.to_ullong();
			str[number]=char(int('a')+p);
			bit_str.flip(x);
		}
		bit_str.flip(v);
	}
	for(int v=0;v<45;v++)
	{
		bit_str.flip(v);
		int x=v+1;
		while(x<45)
		{
			bit_str.flip(x);
			for(int k=x+1;k<45;k++)
			{
				bit_str.flip(k);
				number=bit_str.to_ullong();
				str[number]=char(int('a')+p);
				bit_str.flip(k);
			}

			bit_str.flip(x);
        x++;
		}
		bit_str.flip(v);
	}
	for(int v=0;v<45;v++)
	{
		bit_str.flip(v);
		for(int x=v+1;x<45;x++)
		{
			bit_str.flip(x);
			int k=x+1;
			while(k<45)
			{
			bit_str.flip(k);
				for(int m=k+1;m<45;m++)
				{
					bit_str.flip(m);
					number=bit_str.to_ullong();
					str[number]=char(int('a')+p);
					bit_str.flip(m);
				}
			bit_str.flip(k);
            k++;
			}

			bit_str.flip(x);
		}
		bit_str.flip(v);
	}
}


long long int input=0;
unordered_map<long long int,char>::iterator iter;
int num;
scanf("%d",&num);
for(int n=0;n<num;n++)
{
	scanf("%lld",&input);
	iter=str.find(input);
	if(iter!=str.end())
	cout<<iter->second;
	else
	cout<<"?";
}

return 0;
}
