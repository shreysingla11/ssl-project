#include<iostream>
#include<bitset>
#include<unordered_map>

using namespace std;


struct func
{
	long long operator()(long long const i) const
	{
		string s = std::bitset< 45 >( i ).to_string();
		int num;
		int count0 = 0;
		int count1=0;
		for(int i=0;i<45;i=i+9)
		{
			for(int j=0;j<i+9);j++)
			{
				if(s[j]==0)
				{
					count0++;
				}
				else
				{
					count1++;
				}
			}
		}

		return num;//number lies between 0 and 25 each corresponds to a symbol between a and z
	}
};


int main(){
int n; //number of symbols transmitted
cin>>n;

long long int arr[n];
unordered_map<long long,char> map;
map::hasher fn = map.hash_function();

for(int i=0;i<n;i++)
{
	cin>>arr[i];
	cout<<std::bitset< 45 >( arr[i] )<<endl;
}

for(int i=0;i<26;i++)
{
	std::bitset< 5 >(i);
	map::hasher fn = map.hash_function(arr[i]);
}


return 0;
}
