#include <iostream>   
#include <unordered_map>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	unordered_map <unsigned long long int, char> decodeMap;

	//create bit string
	bitset<45> bitString;
	unsigned long long int temp;
	char currAlpha = 'a';
	for (int i = 0; i < 26; ++i)
	{
		bitset<5> t(i);

		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				bitString[9*j + k] 	= t[j];
			}
		}
		temp = bitString.to_ullong();
		decodeMap[temp]=currAlpha;
		for (int w = 0; w < 45; ++w)
		{
			bitString.flip(w);
			temp = bitString.to_ullong();
			decodeMap[temp]=currAlpha;
			for (int x = w + 1; x < 45; ++x)
			{
				bitString.flip(x);
				temp = bitString.to_ullong();
				decodeMap[temp]=currAlpha;
				for (int y = x + 1; y < 45; ++y)
				{
					bitString.flip(y);
					temp = bitString.to_ullong();
					decodeMap[temp]=currAlpha;
					for (int z = y + 1; z < 45; ++z)
					{
						bitString.flip(z);
						temp = bitString.to_ullong();
						decodeMap[temp]=currAlpha;
						bitString.flip(z);
					}
					bitString.flip(y);
				}
				bitString.flip(x);
			}
			bitString.flip(w);
		}
		currAlpha++;
	}

	int n;
	cin>>n;
	string output;
	long long int num;
	while (n != 0)
	{
		cin>>num;
		bitset<45> temp(num);
		unsigned long long int decode = temp.to_ullong();
		unordered_map<unsigned long long int,char>::const_iterator it = decodeMap.find (decode);
		if ( it == decodeMap.end() )
		    output += "?";
		else
		  	output += it->second;
		n--;
	}
	cout<<output<<endl;
	return 0;
}