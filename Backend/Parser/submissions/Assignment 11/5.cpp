#include <iostream>
#include <unordered_map>
#include <bitset>
#include <string>
#include <cstdio>

using namespace std;
unordered_map<bitset<45>,char> hash_table;

int main()
{
	int n;
	cin>>n;
	long long int temp;
	unordered_map<bitset<45>,char>::iterator it;
	int p=0;
	bitset<45> bin;
	string ans;
	ans.resize(n);
	for(char t='a';t<='z';t++,p++)
	{
		bitset<5> binary(p);
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<9;j++)
				bin.set(9*i+j,binary[i]);
		}
		hash_table[bin]=t;
		for(int i=0;i<45;i++)
		{

			bin.flip(i);
			hash_table[bin]=t;
			for(int j=i+1;j<45;j++)
			{
				bin.flip(j);
				hash_table[bin]=t;
				for(int k=j+1;k<45;k++)
				{
					bin.flip(k);
					hash_table[bin]=t;
					for(int l=k+1;l<45;l++)
					{
						bin.flip(l);
						hash_table[bin]=t;
						bin.flip(l);
					}
					bin.flip(k);
				}
				bin.flip(j);
			}
			bin.flip(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		bitset<45> b(temp),a;
		it=hash_table.find(temp);
		if(it!=hash_table.end())
			ans[i]=it->second;
		else
			ans[i]='?';
	}
	printf("%s\n",ans.c_str());
	return 0;
}