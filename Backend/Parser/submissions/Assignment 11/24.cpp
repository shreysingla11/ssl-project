#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
long long toBinaryExtended(int i)
{
	long long n = 0, k = 1;
	int rem;
	while(i>=1)
	{
		rem = i%2;
		n = rem*k*511 + n;
		k = k*512;
		i = i/2;
	}
	return n;
}
struct func
{
	long long operator()(long long const i) const
	{
		long long int n = 0,bit;
		int count_errors = 0,count1;
		long long k = 1;
		long long bini= i;
		while(bini>0)
		{
			bit = bini%512;	//Taking first 9 digits
			count1 = 0;
			while(bit>0)
			{
				if(bit%2 == 1)
					count1++;
				bit = bit/2;
			}
			if(count1>=5) {
				n = k*511 + n;
				count_errors += 9 - count1;
			}
			else {
				count_errors += count1;
			}
			
			bini = bini/512;
			if(count_errors>4)
				return -1;
			k = k*512;
		}
		return n;
	}
};
int main()
{
	int i;

	unordered_map<long long, char, func> M;

	func f;

	for(i=0;i<26;i++)
	{
		M.insert(pair<long long, char> (toBinaryExtended(i),(char)(i+97)));

	}
	M.insert(pair<long long,char> (-1,'?'));

	int n;
	cin>>n;
	string str;
;
	long long t;
	char ch;
	for(i=0;i<n;i++)
	{
		cin>>t;
		t = f(t);
		if(M.count(t)>0)
			ch = M[t];
		else
			ch = '?';
		str+=ch;
	}
	cout<<str;
}
