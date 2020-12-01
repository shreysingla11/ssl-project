#include<iostream>
#include<unordered_map>
#include<bitset>
#include<string>
using namespace std;
int main()
{ 
	bitset<45>alpha;
  bitset<5>bitvalue;
  int i,j,k,l,m;
 unordered_map<bitset<45>,int>a;
 for(i=0;i<26;i++)
 {
     bitvalue=bitset<5>(i);
     for(k=0;k<5;k++)
     {

     	for(j=0;j<9;j++)
     	{
     		alpha[(k*9)+j]=bitvalue[k];
     	}
     
     }

     a[alpha]=i;
     for(j=0;j<45;j++) 
     {
     	alpha.flip(j);
     	a[alpha]=i;
     	for(k=j+1;k<45;k++)
     	{
     		alpha.flip(k);
     		a[alpha]=i;
     		for(l=k+1;l<45;l++)
     		{
     			alpha.flip(l);
     			a[alpha]=i;
     			for(m=l+1;m<45;m++)
     			{
     				alpha.flip(m);
     				a[alpha]=i;
     				alpha.flip(m);
     			}
     			alpha.flip(l);
     		}
     		alpha.flip(k);
     	}
     	alpha.flip(j);
     }
 }

int n;long long int f;
char d;
cin>>n;
for(i=0;i<n;i++)
	{cin>>f;
	 alpha=bitset<45>(f);
    if (a.count(alpha)==0)
    {cout << "?";
     
    }
    else 
     {
      d=a[alpha]+97;
      cout<<d;
    }
	}
	cout<<endl;
return 0;
}
