#include <iostream>
#include <cstdio>
#include <queue>
#include <limits>
#include <cstdlib>
using namespace std;

class bestpair
{
public:
	int vert;
	int good;
	bestpair(int ver,int goo)
	{
		vert = ver;
		good = goo;
	}
};

int main()
{
	int n,i=0,j=0,temp=0,vertex=0,goodness=0,min=numeric_limits<int>::max();
	cin>>n;
	int **cost = new int*[n];
	int **label = new int*[n];
	int **inQueue = new int*[n];
	queue<bestpair> Q;
	for(i=0;i<n;i++)
	{
		cost[i] = new int[n];
		label[i] = new int[(2*n)+1];
		inQueue[i] = new int[(2*n)+1];
		for(j=0;j<(2*n)+1;j++)
		{
			if(j<n)
			{
				cin>>cost[i][j];
			}
			label[i][j] = numeric_limits<int>::max();
			inQueue[i][j] = 0;
		}
	}


//intialize
	Q.push(bestpair(0,n));
	inQueue[0][n] = 1;
	label[0][n] = 0;

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
				if(label[i][goodness+1] > -(cost[vertex][i]) + label[vertex][goodness])
				{
					label[i][goodness+1] = -(cost[vertex][i]) + label[vertex][goodness];
					if(inQueue[i][goodness+1]==0)
					{
						Q.push(bestpair(i,goodness+1));
						inQueue[i][goodness+1] = 1;
					}
				}

			}
			if(cost[vertex][i]>0)
			{
				if(label[i][goodness-1] > (cost[vertex][i]) + label[vertex][goodness])
				{
					label[i][goodness-1] = (cost[vertex][i]) + label[vertex][goodness];
					if(inQueue[i][goodness-1]==0)
					{
						Q.push(bestpair(i,goodness-1));
						inQueue[i][goodness-1] = 1;
					}
				}
			}
		}
	}

	for(i=0;i<n;i++)
	{
		min=numeric_limits<int>::max();
		for(j=n;j<2*n+1;j++)
		{
			if(label[i][j]<min)
			{
				min = label[i][j];
			}
		}
		if(min==numeric_limits<int>::max())
		{
            cout<<"infinity"<<endl;
		}
		else{
            cout<<min<<endl;
		}

	}

}
