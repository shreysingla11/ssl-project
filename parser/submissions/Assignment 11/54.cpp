#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <bitset>
using namespace std;
typedef unsigned long long ull;
bitset<45> generate_string(char ch)
{
	int n = (int)(ch-'a'), i, j;
	string s = "", final = "";
	bitset<5> bits(n);
	s = bits.to_string();
	for (i=0; i<5; ++i)
	{
		for (j=0; j<9; ++j)
		{
			final += s[i];
		}
	}
	bitset<45> b(final);
	return b;
}
int main()
{
	unordered_map<ull, char> um;
	unordered_map<ull, char> :: iterator it;
	string s;
	ull i, j, k, l, m , n, num, check, max = 0, count = 0;
	bitset<45> temp, real;
	for (i=0; i<26; ++i)
	{
		temp = generate_string((char)(97+i));
		num = temp.to_ullong();
		um[num] = (char)(97+i);
		for (j=0; j<45; ++j)
		{
			temp.flip(j);
			for (k=j+1; k<45; ++k)
			{
				temp.flip(k);
				for (l=k+1; l<45; ++l)
				{
					temp.flip(l);
					for (m=l+1; m<45; ++m)
					{
						temp.flip(m);
						num = temp.to_ullong();
						um[num] = (char)(97+i);
						temp.flip(m);
					}
					temp.flip(l);
				}
				temp.flip(k);
			}
			temp.flip(j);
		}
		for (j=0; j<45; ++j)
		{
			temp.flip(j);
			for (k=j+1; k<45; ++k)
			{
				temp.flip(k);
				for (l=k+1; l<45; ++l)
				{
					temp.flip(l);
					num = temp.to_ullong();
					um[num] = (char)(97+i);
					temp.flip(l);
				}
				temp.flip(k);
			}
			temp.flip(j);
		}
		for (j=0; j<45; ++j)
		{
			temp.flip(j);
			for (k=j+1; k<45; ++k)
			{
				temp.flip(k);
				num = temp.to_ullong();
				um[num] = (char)(97+i);
				temp.flip(k);
			}
			temp.flip(j);
		}
		for (j=0; j<45; ++j)
		{
			temp.flip(j);
			num = temp.to_ullong();
			um[num] = (char)(97+i);
			temp.flip(j);
		}
	}
	scanf("%llu", &n);
	for (i=0; i<n; ++i)
	{
		scanf("%llu", &check);
		it = um.find(check);
		if (it == um.end())
		{
			printf("?");
		}
		else
		{
			printf("%c", (*it).second); 
		}
	}
	cout << endl;
	// for (i=0; i<um.bucket_count(); ++i)
	// {
	// 	if (um.bucket_size(i) > max)
	// 	{
	// 		max = um.bucket_size(i);
	// 	}
	// }
	// for (i=0; i<um.bucket_count(); ++i)
	// {
	// 	if (um.bucket_size(i) == max)
	// 	{
	// 		++count;
	// 	}
	// }
	// cout << i << " " << max << " " << count << endl;
	return 0;
}