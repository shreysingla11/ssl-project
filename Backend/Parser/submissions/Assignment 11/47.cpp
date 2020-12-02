#include<iostream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
#include<cmath>
using namespace std;
// vector<bool> binarys(int n){
// 	vector<bool> temp(5,0);
// 	int counts=4;
// 	while(n>0){
// 		temp[counts]=n%2;
// 		n/=2;
// 		counts--;
// 	}
// 	return temp;
// }
unordered_map<long long int,char> mymap;
int main()
{
	long long int t;
	scanf("%lld",&t);
	vector<long long int> arr(26,0);
	int z,count=0,b;
	long long int pow[46];
	pow[0]=1;
	for (int i = 1; i < 46; ++i)
	{
		pow[i]=pow[i-1]*2;
	}
	for (int i = 0; i < 26; ++i)
	{
		
		z=i;
		count =0;
		while(z>0){
			b=z%2;
			if(b==1){
				for (int j=0;j<9;++j)
				{
					arr[i]=arr[i]+(long long int)pow[count]*b;
					count++;
				}
			}
			else
				count+=9;
			z=z/2;
		}
	}
	// for (int i = 0; i < 26; ++i)
	// {
	// 	cout<<arr[i]<<endl;
	// }
	for (int i = 0; i < 26; ++i)
		{
			mymap[arr[i]]=(char(i+97));
			for (int j=0;j<45;++j)
			{
				long long int value1=arr[i]^((long long int)1<<j);
				mymap[value1]=(char(i+97));
				for (int k = j+1; k<45; ++k)
				{
					long long int value2=arr[i]^((long long int)1<<j)^((long long int)1<<k);
					mymap[value2]=(char(i+97));
					for(int l = k+1; l<45; ++l)
					{
						long long int value3=arr[i]^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l);
						mymap[value3]=(char(i+97));
						for(int m = l+1; m<45; ++m){
							long long int value4=arr[i]^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l)^((long long int)1<<m);
							mymap[value4]=(char(i+97));
							// if()
						}
					}
				}
			}
		}
	long long int n;
	while(t--){
		scanf("%lld",&n);
		unordered_map<long long int,char>::iterator got = mymap.find (n);
		if(got!=mymap.end())
			printf("%c",got->second);
		else
			printf("?");

	}
	printf("\n");
	return 0;
}