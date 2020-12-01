#include <cstdio>
#include <unordered_map>
#include <bitset>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int xxx, n;

	unordered_map<unsigned long long int, char> hashmap;
	bitset<45> nbin;
	unsigned long long int temp;
	char a;
	// Initalisation
	for (int m = 0; m< 26; ++m)
	{
		a = 'a' + m;
		bitset<5> b(m);
		for (int i = 0; i <5; ++i)
		{
			for (int j =9*i; j < 9*(i+1); ++j)
			{
				nbin[j] = b[i];
			}
		}
		temp = nbin.to_ullong();
		hashmap[temp] = a;
		for (int r = 0; r < 45; ++r)
		{
			nbin[r].flip();
			temp = nbin.to_ullong();
			hashmap[temp] = a;
			for (int s = r+1; s < 45; ++s)
			{
				nbin[s].flip();
				temp = nbin.to_ullong();
				hashmap[temp] = a;
				for (int t = s+1; t < 45; ++t)
				{
					nbin[t].flip();
					temp = nbin.to_ullong();
					hashmap[temp] = a;
					for (int u = t+1; u < 45; ++u)
					{
						nbin[u].flip();
						temp = nbin.to_ullong();
						hashmap[temp] = a;
						nbin[u].flip();
					}
					nbin[t].flip();
				}
				nbin[s].flip();
			}
			nbin[r].flip();
		}
	}
	string asd = "";
	scanf("%d",&xxx);
	while(xxx--)
	{
		scanf("%d",&n);
		if(hashmap.count(n))
		{
			// a.append(hashmap[n]);
			printf("%c", hashmap[n]);
		}
		else
		{
			// a.append("?");
			printf("?");	
		}
	}
	return 0;
}