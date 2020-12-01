#include <iostream>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;



int main()
{
	unordered_map<long long int,char> mymap;

	bool digit[5];
	long long int bin;
	long long int pow9 = pow(2,9);
	long long int pow18 = pow9*pow9;
	long long int pow27 = pow9*pow18;
	long long int pow36 = pow18*pow18;

	for(int i=0;i<26;i++)
	{
		digit[4] = i%2;
		digit[3] = (i/2)%2;
		digit[2] = ((i/2)/2)%2;
		digit[1] = (((i/2)/2)/2)%2;
		digit[0] = ((((i/2)/2)/2)/2)%2;
		bin = (pow9-1)*(digit[0]*pow36 + digit[1]*pow27 + digit[2]*pow18 + digit[3]*pow9 + digit[4]);
		mymap[bin] = 97+i;
		long long int temp1;
		long long int temp2;
		long long int temp3;
		long long int powj = 1;
		long long int powk = 1;
		long long int powl = 1;
		long long int powm = 1;
		int var;
		for(int j=0;j<45;j++,powj*=2)
		{
			var = j/9;
			if(digit[4-var] == 0)
			{
				mymap[bin+powj] = 97 + i;
				temp1 = bin + powj;
			}
			else
			{
				mymap[bin-powj] = 97 + i;
				temp1 = bin - powj;
			}
			powk =1;
			for(int k=0;k<j;k++,powk*=2)
			{
				var = k/9;
				if(digit[4-var] == 0)
				{
					mymap[temp1+powk] = 97 + i;
					temp2 = temp1 + powk;
				}
				else
				{
					mymap[temp1-powk] = 97 + i;
					temp2 = temp1 - powk;
				}
				powl = 1;
				for(int l=0;l<k;l++,powl*=2)
				{
					var = l/9;
					if(digit[4-var] == 0)
					{
						mymap[temp2+powl] = 97 + i;
						temp3 = temp2 + powl;
					}
					else
					{
						mymap[temp2-powl] = 97 + i;
						temp3 = temp2 - powl;
					}
					powm = 1;
					for(int m=0;m<l;m++,powm*=2)
					{
						var = m/9;
						if(digit[4-var] == 0)
						{
							mymap[temp3+powm] = 97 + i;
						}
						else
						{
							mymap[temp3-powm] = 97 + i;
						}
					}
				}
			}
		}
	}

	int num=0;
	long long int in;
	//cin>>num;
	scanf("%d",&num);
	string out;

	for(int i=0;i<num;i++)
	{
		//cin>>in;
		scanf("%lld",&in);
		if(mymap.count(in) == 0)
		{
			//out = out + '?';
			//cout<<'?';
			printf("?");
		}
		else
		{
			//out = out + mymap[in];
			//cout<<mymap[in];
			printf("%c",mymap[in]);
		}
	}

	//cout<<out<<endl;
    return 0;
}
