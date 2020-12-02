#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000

class verGood
{
	public :
		int v;
		int g;

	verGood(){}

	verGood(int x, int y)
	{
		v=x;
		g=y;
	}
};

int main()
{
	int n;
	cin>>n;

	vector<vector<int> > dist(n,vector<int>(n, 0));
	vector<vector<int> > C(n,vector<int>(4*n+1, INF));
	vector<vector<bool> > isPresent(n,vector<bool>(4*n+1, false));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>dist[i][j];
		}
	}

	std::queue< verGood > myqueue;

	verGood zero(0,2*n);    // values shifted by 2*n
	verGood temp;
	myqueue.push(zero);
	
	for(int i=0; i<n; i++)
	{
		for (int j=0; j<4*n+1; j++)
		{
			C[i][j] = INF;
			isPresent[i][j] = false;
		}
	}
	C[0][2*n] = 0;
	isPresent[0][2*n] = true;
	int curr_goodness, weight, curr_cost;
	while(!myqueue.empty())
	{
		temp = myqueue.front();
		myqueue.pop();
		isPresent[temp.v][temp.g] = false;
		
		for(int i=0; i<n; i++)
		{
			curr_goodness = temp.g;


			if(dist[temp.v][i] < 0)
			{
				curr_goodness++;
			}
			else
			{
				curr_goodness--;
			}

			if (curr_goodness > 4*n || curr_goodness < 0)
				continue;
			weight = dist[temp.v][i];
			if (weight<0)
				weight = -weight;
			//curr_cost = min( C[i][curr_goodness], C[temp.v][temp.g] + weight);
	//		cout<<weight<<"!Yo";
			if(C[temp.v][temp.g] + weight < C[i][curr_goodness])
				curr_cost = C[temp.v][temp.g] + weight;
			else 
				curr_cost = C[i][curr_goodness];
			if (curr_cost<C[i][curr_goodness])
			{
				C[i][curr_goodness] = curr_cost;
				//cout<<"Heya!1"<<curr_cost<<endl;
				if (!isPresent[i][curr_goodness])
				{
					bool shouldPush = true;
					for(int j=curr_goodness + 1; j<4*n+1; j++){
						if(isPresent[i][j])
						{
							if(C[i][j] <= curr_cost)
							{
								shouldPush = false;
								//cout<<"Heya!2";
							}
						}
					}

					if(shouldPush)
					{
						myqueue.push(verGood(i,curr_goodness));
						isPresent[i][curr_goodness] = true;
					}

				}
			}
		}
	}

	int min_cost;
	for(int i=0; i<n; i++)
	{
		min_cost = C[i][2*n];
		for(int j=2*n; j<4*n+1; j++)
		{
			min_cost = min(min_cost, C[i][j]);
		}
		if (min_cost == INF)
			cout<<"infinity"<<endl;
		else
			cout<<min_cost<<endl;
	}


}
