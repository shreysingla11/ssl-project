#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
using namespace std;
int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int abs(int a)
{
	if(a>0)
		return a;
	else
		return -a;
}
int main()
{
	int N;
	scanf("%d",&N);
	vector<vector<int> >cost(N,vector<int>(N));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	vector<vector<int> >v1(2*N+1,vector<int>(N));
	vector<vector<int> >v2(2*N+1,vector<int>(N));
	for(int i=0;i<2*N+1;i++)
	{
		for(int j=0;j<N;j++)
		{
			v1[i][j]=INT_MAX;
		}
	}
	v1[N][0]=0;
	for(int k=0;k<N*N-1;k++)
	{
		int i=0;
		for(int j=0;j<N;j++)
		{
			int minimum=INT_MAX;
			for(int nei=0;nei<N;nei++)
			{
				if(cost[nei][j]>0)
				{
					minimum=min(v1[i][j],v1[i+1][nei]+abs(cost[nei][j]));
				}
			}
			v2[i][j]=minimum;
		}
		for(int i=1;i<2*N;i++)
		{
			for(int j=0;j<N;j++)
			{
				int minimum=INT_MAX;
				for(int nei=0;nei<N;nei++)
				{
					if(cost[nei][j]>0)
					{
						minimum=min(v1[i][j],v1[i+1][nei]+abs(cost[nei][j]));
					}
					if(cost[nei][j]<0)
					{
						minimum=min(v1[i][j],v1[i-1][nei]+cost[nei][j]);
					}
				}
				v2[i][j]=minimum;
			}
		}
		for(int j=0;j<N;j++)
		{
			int minimum=INT_MAX;
			for(int nei=0;nei<N;nei++)
			{
				if(cost[nei][j]<0)
				{
					minimum=min(minimum,v1[i-1][nei]+cost[nei][j]);
				}
			}
			v2[i][j]=minimum;
		}
		for(int i=0;i<2*N+1;i++)
		{
			for(int j=0;j<N;j++)
			{
				v1[i][j]=v2[i][j];
			}
		}
	}
	for(int j=0;j<N;j++)
	{
		int minimum=INT_MAX;
		for(int i=N;i<2*N+1;i++)
		{
			minimum=min(minimum,v1[i][j]);
		}
		if(minimum==INT_MAX)
			cout<<"infinity";
		else
			cout<<minimum;
	}



}

