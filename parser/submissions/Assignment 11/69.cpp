#include <iostream>
#include <unordered_map>
#include <bitset>
#include <cstdio>

using namespace std;

int main()
{
	bitset<45> representation;
	unsigned long long int repr;
	unordered_map<long long int, char> llintToCharNum;

    for (int albhabet = 0; albhabet < 26; ++albhabet)
    {
    	bitset<5> simple(albhabet);
        for (int i = 0; i < 45; i++) {
            representation[i] = simple[i / 9];
        }
    	repr = representation.to_ullong();
    	llintToCharNum[repr] = albhabet;
    	for (int w = 0; w < 45; ++w)
    	{
            representation.flip(w);
            repr = representation.to_ullong();
    		llintToCharNum[repr] = albhabet;
    		for (int x = w+1; x < 45; ++x)
    		{
                representation.flip(x);
                repr = representation.to_ullong();
    			llintToCharNum[repr] = albhabet;
    			for (int y = x+1; y < 45; ++y)
    			{
                    representation.flip(y);
                    repr = representation.to_ullong();
                   	llintToCharNum[repr] = albhabet;
    				for (int z = y+1; z < 45; ++z)
    				{
    					representation.flip(z);
    					repr = representation.to_ullong();
    					llintToCharNum[repr] = albhabet;
    					representation.flip(z);
    				}
    				representation.flip(y);
    			}
    			representation.flip(x);
    		}
    		representation.flip(w);
    	}
    }

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
    	scanf("%lld", &repr);
    	if(llintToCharNum.count(repr))
    		printf("%c", llintToCharNum[repr] + 97);
    	else
    		printf("?");
    }
    return 0;
}
