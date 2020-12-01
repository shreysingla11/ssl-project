#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define s(n) scanf(" %d",&n)
#define sc(n) scanf("%c",&n)
#define INF 

int LEN,MIN_IN;

bool match(int size ,int i, int j,string & s)
{	
	int p1=j,p2=i,end = i+size;
	int curLen,min,count=0,l = s.size();
	//int val = j-(i+size-1);
	while(p1 >0 && p2 >0 && p1 < end )
	{
		if(s[p1-1] == s[p2-1]){
			p1--;p2--;
		}
		else break;
	}
	
	if(p1 == end){
		curLen = j-i;
		min = p2;
		if(curLen < LEN)
		{
			LEN = curLen;
			MIN_IN = min;
		}
		return true;
	}

	int p3 = end, p4 = j+size;
	while(p3 < p1  && p4 < l-1)
	{
		if(s[p3+1] == s[p4+1])
		{	
			p4++;p3++;
		}
		else break;
	}
	if(p3 == p1){
		curLen = p3-p2+1;
		min = p2;
		if(curLen < LEN)
		{
			LEN = curLen;
			MIN_IN = min;
		}
		return true;
	}
	return false;
}

void check(string & a)
{
	int c,n=a.size();
	for(int l =2;l < n;l+=2)
	{
		for (int i = 0; i < n-l ; ++i)
		{
			c = 0;
			for(int j=i;j< i+l/2 && i+l <= n;j++)
			{
				if(a[j] == a[i*2+l-j-1]) c++;
				//cout << c;
			}
			if(c == l/2){
				cout << l <<" "<< i <<"\n";
				return;
			}
		}
	}
	cout <<"0 0\n";
}

void calc(string & S)
{
	int n = S.length();
	int l=1,N = n/l;
	LEN = n+1;
	MIN_IN = n+1;
	bool X =0;
	int count;
	for (int l =1; 4*l-2 <= n; l*=2)
	{
		N = n/l;
		X=0;
		rep(block,0,N)
		{
			int k=3*l-2;
			int index =  block*l ,j = index+l,len=index+l;
			count =0;
			for (int i = index; i < len ; ++i)
			{
				if(i+j < n){

					if(S[i] == S[i+j]) count++;
					else
					{
						j = i+j+1;
						i=index;
						if(j - index > k + l){
							break;
						}
					}

					if(count == l)
					{
						X = match(l,index,j,S);
						j = i+j+1;
						i = index;
						count = 0;
						if(j-index > k + l) break;
					}
				}

				else break;
			}
		}
		if(X)
		{
			cout<< LEN << " "<< MIN_IN<<'\n';
			break;
		}
	}
	if(!X)
	{
		cout <<"0 0\n";
	}
	return;
}

int main()
{
	string s;
	cin>>s;
	//calc(s);
	check(s);
	return 0;
}