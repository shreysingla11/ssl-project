#include <iostream>
#include <cstdio>
#include <cmath>
//#define INFINITY INT_MAX
using namespace std;
int abs(int a)
{
	if (a<0){a*=-1;}
	return a;
}
int main()
{
	int n;
	scanf("%d",&n);
	int D[n];
	int G[n];
	int c[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
           scanf("%d",&c[i][j]);
           //cout<<c[i][j];
		}
	}
	D[0]=0;
	G[0]=0;
	for(int i=1;i<n;i++)
	{
		D[i]=-1;
		G[i]=0;
	}
	for(int a=0;a<n;a++)
	{
		for(int i=1;i<n;i++)
		{   
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{	if(D[k]!=-1)
					{
					if(G[k]<0)
					{
						/*if((c[j][k]>0)&&(G[j]-1>=G[k]))
						{
							D[k]=D[j]+c[j][k];
							G[k]=G[j]-1;
						}*/
						if((c[j][k]<0)&&(G[j]+1>=G[k]))
						{ 
							 if(G[k]==G[j]+1)
						    {
						    	if(D[k]>D[j]-c[j][k])
						    	{
						    		D[k]=D[j]-c[j][k];
						    	}
						    }

							if(G[k]<G[j]+1)
							{
							D[k]=D[j]-c[j][k];
							G[k]=G[j]+1;
						    }
						   
						}
					}
					if(G[k]>=0)
					{
						if((G[j]>=1)&&(c[j][k]>0)&&(D[j]+c[j][k]<D[k]))
						{
							D[k]=D[j]+c[j][k];
							G[k]=G[j]-1;
						}
						if((G[j]>=-1)&&(c[j][k]<0)&&(D[j]-c[j][k]<D[k]))
						{
							D[k]=D[j]-c[j][k];
							G[k]=G[j]+1;
						}
					}
				    }
				    if(D[k]==-1) 
				    	{   
				    		if(c[j][k]>0)
				    		{
				    		D[k]=D[j]+(c[j][k]);
				    		G[k]=G[j]-1;
				    	    }
				    	    else 
				    	    {
				    	    D[k]=D[j]-c[j][k];
				    	    G[k]=G[j]+1;
				    	    }
				    		
				    	}
				}
			}
		}
    }
	for(int i=0;i<n;i++)
	{
		cout<<D[i]<<endl;
	}
    
} 