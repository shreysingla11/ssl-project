#include <iostream>
#include <stdio.h>
#include <limits>
#include <queue>
#include <pair>
using namespace std;

class node{
public:
    int number;
    int g;
    int d;
    bool piq;
    node()
    {
      d=std::numeric_limits<int>::max();
      g=std::numeric_limits<int>::min();
      piq=false;
    }
};

int main()
{
	int n;
	node* adr[n];
	scanf("%d",&n);
	int** a1= new int*;
	for(int i=0;i<n;i++)
	{
		int* a2=new int;
		node temp;
		temp.number=i;
		adr[i]=&temp;
		for(int j=0;j<n;j++)
		{
          scanf("%d",&a2[j]);
		}
		a1[i]=a2;
	}
	queue<pair<int,int> > Q;
	pair<int,int> v;v.first=0;v.second=0;
	Q.push(v);
	int s[2*n+1][n];
	s[0][0]=0;
	for(int i=0;i<2*n+1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!(i==0 && j==0)){s[2*i+1][j]=std::numeric_limits<int>::min();}
		}
	}
	adr[0]->piq=true;
	while(!Q.empty())
	{
		pair<int,int> v=Q.front();
		adr[v.first]->piq=false;
		Q.pop();
		
		//for each vertex code to be performed
			for(int w=0;w<n;w++)
			  {

			  	if(a1[w][v.first]<0)
			  		{ 
			  			if(s[v.second][v.first]>s[v.second-1][w]-a1[w][v.first])
			  			{
			  				pair<int,int> p;p.first=w;p.second=
			  			}
			  			// s[g][w]=s[g-1][v]-a1[v.first][w];
			  		}
			  	
			  	else
			  		{
			  			 s[g][w]=s[g+1][v.first]+a1[v.first][w];
			  		}
			  }
        
	// }
}
