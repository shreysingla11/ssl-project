#include <iostream>
#include <unordered_map>
#include <bitset>
#include <cstdio>

using namespace std;


int main()
{
	int n,x;
	long long y;
	int count =45;
	unordered_map<long long int, char> mymap;

	bitset<45> onechange[26];
	bitset<45> num;

	for (int i = 0; i < 26; ++i)
	{
		bitset<5> b(i);
		for(int t =0; t < 5; t++)
		{
			x= t*9;
			for(int j =0; j< 9; j++)
			{
				num[x+j] = b[t];
				// cout << num [x+j];
			}
		}
		char curr = 'a' +i;
		y = num.to_ullong();
		mymap[y] = curr;
		//cout << endl;

		
		for (int i = 0; i < count; ++i)
		{
			num[i].flip();
			y = num.to_ullong();
			mymap[y] = curr;
			for (int j = i+1; j < count; ++j)
			{
				num[j].flip();
				y = num.to_ullong();
				mymap[y] = curr;
				for (int k = j+1; k < count; ++k)
				{
					num[k].flip();
					y = num.to_ullong();
					mymap[y] = curr;
					for (int l = k+1; l < count; ++l)
					{
							num[l].flip();
							y = num.to_ullong();
							mymap[y] = curr;
							//cout <<y <<" " << curr <<endl;
							num[l].flip();
					}
					num[k].flip();
				}
				num[j].flip();
			}
			num[i].flip();
		}
	}

	scanf("%d",&n);
	long long number;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%lld",&number);
		if(mymap.count(number))
			printf("%c",mymap[number]);
		else
			printf("?");
	}
	printf("\n");

	return 0;

}
