#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstdio>
#include <cmath>

using namespace std;

int INF=1000000000;
struct node{
	int index;
	vector<int> edged;
	vector<int> cost;
	vector<bool> check;

	node(int n){
		edged.resize(n);
		cost.resize(4*n+1,INF);
		check.resize(4*n+1,false);
	}
};


int main(){
	int n,temp,a,b,c,d,e,minlength;
	cin>>n;
	queue< pair<int,int> > B;
	pair<int,int> temp2;
	node initial(n);
	vector<node> A(n,initial);

	for(int i=0;i<n;i++)
	{
		A[i].index=i;
		for(int j=0;j<n;j++){
			scanf("%d",&temp);
			A[i].edged[j]=temp;
		}
	}

	
	temp2=std::make_pair(0,2*n);
	B.push(temp2);
	A[0].check[2*n]=true;
	A[0].cost[2*n]=0;
	

	while(!B.empty())
	{
		temp2=B.front();
		B.pop();
		a=temp2.first;
		b=temp2.second;
		A[a].check[b]=false;
		for(int i=0;i<n;i++)
		{
			c=A[a].edged[i];
			if(c>0)
				e=-1;
			else 
				e=1;
			d=abs(c);
			if(b+e <= 4*n)
			{
				if(A[i].cost[b+e] > A[a].cost[b]+d)
				{
					A[i].cost[b+e]=A[a].cost[b]+d;
					if(!A[i].check[b+e])
					{
						temp2=std::make_pair(i,b+e);
						B.push(temp2);
						A[i].check[b+e]=true;
					}
				}
			}
			
		}

	}
	for(int i=0;i<n;i++)
	{
		minlength=INF;
		for(int j=2*n;j<4*n+1;j++)
		{
			minlength=min(A[i].cost[j],minlength);
		}
		if(minlength!=INF)
			printf("%d\n",minlength);
		else
			printf("infinity\n");
	}




}