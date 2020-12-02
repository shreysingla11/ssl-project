#include <iostream>
#include <bitset>
#include <unordered_map>

using namespace std;
void generateMap_each(unordered_map<unsigned long long int,char> &mymap, unsigned long long int i);
unsigned long long int getull(unsigned long long int i);
void generateRecursive(unordered_map<unsigned long long int,char> &mymap, unsigned long long int i, int index, int count, std::bitset<45> b);
void generateMap(unordered_map<unsigned long long int,char> &mymap);

int main(){

    unsigned long long int x;
    unordered_map<unsigned long long int,char> mymap;
    generateMap(mymap);
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
    	scanf("%lld",&x);
    	if(mymap.find(x) == mymap.end())
    	{
    		//printf("?");
    		putchar('?');
    	}
    	else
			putchar(mymap[x]);
			//printf("%c",mymap[x]);
    }
}

void generateMap(unordered_map<unsigned long long int,char> &mymap)
{
	unsigned long long int i;
	for (i=0; i<26; i++)
	{
		generateMap_each(mymap,i);
	}
}

void generateMap_each(unordered_map<unsigned long long int,char> &mymap, unsigned long long int i)
{
	std::bitset<45> b(getull(i));
	mymap[b.to_ullong()] = 97 + i;
	generateRecursive(mymap,i,0,4,b);

	return;
}

void generateRecursive(unordered_map<unsigned long long int,char> &mymap, unsigned long long int i, int index, int count, std::bitset<45> b)
{
	if(count==0 || index>44)
	{
		return;
	}

	generateRecursive(mymap, i, index+1, count, b);

	b.flip(index);
	mymap[b.to_ullong()] = 97 + i;
	generateRecursive(mymap, i, index+1, count-1, b);
}

unsigned long long int getull(unsigned long long int i)
{
	std::bitset<5> b(i);
	string number;
	for(int j=4; j>=0; j--)
	{
		std::bitset<9> temp;

		if(b.test(j))
		{
			temp.set();
		}

		number += temp.to_string();
	}

	std::bitset<45> c(number);

	return c.to_ullong();
}
