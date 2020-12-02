#include<iostream>
#include<vector>
#include<cmath>
#include<limits>

using namespace std;
int main()
{
	int n;
	bool x = true
  cin>> n;
  vector<int> temp(n,0);
  vector<int>dist(n,numeric_limits<int>::max());
  vector<vector<int> > C(n,temp);
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<n;j++)
  	{
  		cin>>C[i][j];
  		if(C[i][j]<0)
  			x = false;
  	}
  
  }

  dist[0] = 0;
  int i=0,startindex=0;
  while(i!=n)
  {
  	 int minindex,min=numeric_limits<int>::max();
  	for(int j=0;j<n;j++)
  	{
  		if(j!=startindex)
  		{
  		if(dist[j]>dist[startindex]+abs(C[startindex][j]))
  		{
  			dist[j] = dist[startindex]+abs(C[startindex][j]);
  		}
  		if(min>dist[j])
  		{
  			min = dist[j];
  			minindex = j;
  		}
  		}
  	}
  	startindex = minindex;
  	i++;
  }

if(!x)
{
  for(int i=0;i<n;i++)
  {
  	cout<<dist[i]<<endl;
  }
}
else
{
	cout<<"0"<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<"infinity"<<endl;
	}
}

	return 0;
}