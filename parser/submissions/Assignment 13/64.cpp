#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

struct pairx
{
	int v,g;

	pairx(int x, int y)
	{
		v = x;g = y;
	}
	pairx(){};
};

int main()
{
	int N;	cin>>N;
	queue<pairx> Q;

	vector<vector<int> > dis(N,vector<int>(N, 0));
	vector<vector<int> > c(N,vector<int>(4*N+1, INF));
	vector<vector<bool> > isPresent(N,vector<bool>(4*N+1, false));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin>>dis[i][j];

	int costToI, currGoodness;
	bool flag;

	pairx x(0,2*N), temp;
	isPresent[0][2*N] = true;
	c[0][2*N] = 0;
	Q.push(x);

	while(!Q.empty())
	{
	    temp = Q.front();
	    Q.pop();
	    isPresent[temp.v][temp.g] = false;

	    for (int i = 0; i < N; ++i)
	    {
	    	currGoodness = temp.g;
	    	costToI = dis[temp.v][i];

	    	if(costToI > 0)				//bad
	    		currGoodness--;
	    	else						//good
	    		currGoodness++;

	    	if(currGoodness > 4*N || currGoodness < 0)
	    		continue;

	    	if(c[temp.v][temp.g] + abs(costToI) < c[i][currGoodness])
	    	{
	    		c[i][currGoodness] = c[temp.v][temp.g] + abs(costToI);

	    		if(!isPresent[i][currGoodness])
	    		{
	    			flag = true;

	    			for (int j = currGoodness + 1; j < 4*N+1 ; ++j)
	    				if(isPresent[i][j])
	    					if(c[i][j] <= c[i][currGoodness])
	    						flag = false;

	    			if(flag)
	    			{
	    				Q.push(pairx(i,currGoodness));
	    				isPresent[i][currGoodness] = true;
	    			}
	    		}
	    	}
	    }
	}

	int ans[N];
	for (int i = 0; i < N; ++i)
		ans[i] = INF;

	for (int i = 0; i < N; ++i)
		for (int j = 2*N; j < 4*N +1; ++j)
			ans[i] = min(ans[i],c[i][j]);

	for (int i = 0; i < N; ++i)
	{
		if(ans[i] == INF)
			cout<<"infinity"<<endl;
		else
			cout<<ans[i]<<endl;
	}

	return 0;
}
