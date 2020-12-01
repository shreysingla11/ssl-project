#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m,i,j,k,min,minpos,INF,searchtill,removedthisiteration;
	int *a,*b;
	vector<int> possible,last,toremove;
	cin>>n>>m;
	INF=n+1;
	a=new int[n];
	b=new int[m];

	for(i=0;i<n;i++)
		cin>>a[i];
	for(j=0;j<m;j++)
		cin>>b[j];
	for(i=n-1;i>=m-1;i--)
	{
		if(a[i]==b[m-1])
		{
			possible.push_back(i);
		}
	}
	last = possible;
	for(j=m-2;j>=0;j--)
	{
		for(k=0;k<possible.size();k++)
		{
			if(k==possible.size()-1)
			{
				searchtill=j-1;
			}
			else
			{
				searchtill=possible[k+1]-1;
			}
			for(i=possible[k]-1;i>searchtill;i--)
			{
				if(b[j]==a[i])
				{
					possible[k]=i;
					break;
				}
			}
			if(i==searchtill)
			{
				toremove.push_back(k);
			}
		}
		removedthisiteration=0;
		for(int l=0;l<toremove.size();l++,removedthisiteration++)
		{
			possible.erase(possible.begin()+toremove[l]-removedthisiteration);
			last.erase(last.begin()+toremove[l]-removedthisiteration);
		}
		toremove.clear();
	}
	min=INF;
	for(k=possible.size()-1;k>=0;k--)
	{
		if(last[k]-possible[k]+1<min)
		{
			min=last[k]-possible[k]+1;
			minpos=possible[k];
		}
	}
	if(min>=INF)
	{
		cout<<"infinity"<<endl;
	}
	else
	{
		cout<<min<<" "<<minpos+1<<endl;
	}
	return 0;
}