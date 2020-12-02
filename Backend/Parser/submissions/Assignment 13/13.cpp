#include <iostream>
#include <cstdio>
#include <queue>
#include <limits>
#include <cstdlib>
using namespace std;

class mypair
{
public:
	int vert;
	int good;
	mypair(int ver,int goo)
	{
		vert = ver;
		good = goo;
	}
};

int main()
{
	int n,i=0,j=0,temp=0,vertex=0,goodness=0,min=numeric_limits<int>::max()-1;
	cin>>n;
	int **cost = new int*[n];
	int **labels = new int*[n];
	int **inQueue = new int*[n];
	queue<mypair> Q;
	for(i=0;i<n;i++)
	{
		cost[i] = new int[n];
		labels[i] = new int[(2*n)+1];
		inQueue[i] = new int[(2*n)+1];
		for(j=0;j<(2*n)+1;j++)
		{
			if(j<n)
			{
				cin>>cost[i][j];
			}
			labels[i][j] = numeric_limits<int>::max()-1;
			inQueue[i][j] = 0;
		}
	}


//intialize
	Q.push(mypair(0,n));
	inQueue[0][n] = 1;
	labels[0][n] = 0;

//loop
	while(!Q.empty())
	{
		vertex = Q.front().vert;
		goodness = Q.front().good;
		Q.pop();
		inQueue[vertex][goodness] = 0;
		for(i=0;i<n;i++)
		{
			if(cost[vertex][i]<0)
			{
				if(labels[i][goodness+1] > abs(cost[vertex][i]) + labels[vertex][goodness])
				{
					labels[i][goodness+1] = abs(cost[vertex][i]) + labels[vertex][goodness];
					if(inQueue[i][goodness+1]==0)
					{
						Q.push(mypair(i,goodness+1));
						inQueue[i][goodness+1] = 1;
					}
					else{}
				}
				else{}

			}
			else{}
			if(cost[vertex][i]>0)
			{
				if(labels[i][goodness-1] > abs(cost[vertex][i]) + labels[vertex][goodness])
				{
					labels[i][goodness-1] = abs(cost[vertex][i]) + labels[vertex][goodness];
					if(inQueue[i][goodness-1]==0)
					{
						Q.push(mypair(i,goodness-1));
						inQueue[i][goodness-1] = 1;
					}
					else{}
				}
				else{}
			}
			else{}
		}
	}

	for(i=0;i<n;i++)
	{
		min=numeric_limits<int>::max()-1;
		for(j=n;j<2*n+1;j++)
		{
			if(labels[i][j]<min)
			{
				min = labels[i][j];
			}
		}
		if(min==numeric_limits<int>::max()-1)
		{
			cout<<"infinity"<<endl;
		}
		else
		{
			cout<<min<<endl;
		}
	}

}