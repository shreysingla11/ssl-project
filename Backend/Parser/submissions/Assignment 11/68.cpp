#include<stdio.h>
#include<unordered_map>
#include<iostream>
using namespace std;
typedef pair<long long int,char> pli;
typedef long long int lli;
int main()
{
		unordered_map<long long int, char> codeword;
		char charecter;
		long long int x=0,y,z,p,q;
		for(int i=0;i<=25;i++)
		{	x=0;
			charecter='a'+i;
			//cout<<charecter;
			for(int t=0;t<5;t++)
			{	if((i&(1<<t))!=0)
					x+=(((lli)((lli)1<<9)-1))<<(t*9);
			}
			//cout<<x<<endl;
			codeword.insert(pli(x,charecter)); 
			for(int i=0;i<45;i++)
			{	y = x^((lli)1<<i);
				codeword.insert(pli(y,charecter)); 
				for(int j=i+1;j<45;j++)
				{	z = y^(lli)((lli)1<<j);
					codeword.insert(pli(z,charecter)); 
					for(int k=j+1;k<45;k++)
					{	p = z^(lli)((lli)1<<k);
						codeword.insert(pli(p,charecter)); 
						for(int l=k+1;l<45;l++)
						{	
							q = p^(lli)((lli)1<<l);
							codeword.insert(pli(q,charecter)); 
						}
					}
				}
			}	
		}	
		int n;
		scanf("%d",&n);
		unordered_map<long long int, char>::iterator it;  
		while(n>0)
		{	n--;
			//cin>>x;
			scanf("%lld",&x);
			//cout<<x<<endl;
			it=codeword.find(x);
			if(it!=codeword.end())
				printf("%c",it->second);
			else
				printf("?");			
		}
		printf("\n");
		return 0; 
	
}	
