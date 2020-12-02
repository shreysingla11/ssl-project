#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

int I=100000;
struct node{
	int index;
	vector<int> E;
	vector<int> C;
	vector<bool> goodness;

	node(int n){
		E.resize(n);
		C.resize(4*n+1,I);
		goodness.resize(4*n+1,false);
	}
};


int main(){
	int n,t,a,b,c,d,e,m;
	pair<int,int> t2;
	scanf("%d",&n);
	node base(n);
	vector<node> A(n,base);

	for(int i=0;i<n;i++)
	{
		A[i].index=i;
		for(int j=0;j<n;j++){
			scanf("%d",&t);
			A[i].E[j]=t;
		}
	}


	t2=make_pair(0,2*n);
	A[0].goodness[2*n]=true;
	A[0].C[2*n]=0;

	queue< pair<int,int> > B;
	B.push(t2);


	while(B.empty()==false)
	{
		t2=B.front();
		a=t2.first;
		b=t2.second;
		B.pop();
		A[a].goodness[b]=false;
		for(int i=0;i<n;i++)
		{
			c=A[a].E[i];
			if(c>0)
				e=-1;
			else
				e=1;
			if(b+e <= 4*n)
			{
				if(A[i].C[b+e] > A[a].C[b]+abs(c))
				{
					A[i].C[b+e]=A[a].C[b]+abs(c);
					if(!A[i].goodness[b+e])
					{
						t2=make_pair(i,b+e);
						B.push(t2);
						A[i].goodness[b+e]=true;
					}
				}
			}

		}

	}
	
	for(int i=0;i<n;i++)
	{
		m=I;
		for(int j=2*n;j<4*n+1;j++)
		{
			m=min(A[i].C[j],m);
		}
		if(m!=I)
			printf("%d\n",m);
		else
			printf("infinity\n");
	}




}
