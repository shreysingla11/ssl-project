#include <iostream>
#include <cstdio>
#include  <stack>
#include <vector>
using namespace std;

struct node{
	int t_i;
	int n_i;
	int numgoing;
	// vector<int> suc;
	vector<int> pre;
	node()
	{
		numgoing = 0;
	}
};

int main()
{
	int n,x,y,f;
	scanf("%d",&n);

	vector<node> friends(n);
	stack<int> going;
	stack<int> notgoing;
	vector<bool> go(n,false);

	for (int i = 0; i < n; ++i)
	{

		scanf("%d%d",&x,&y);
		
		if(x == 0){
			go[i] = true;
			going.push(i);
		}
		else if( x > y)
		{
			notgoing.push(i);
		}

		friends[i].t_i = x;
		friends[i].n_i = y;

		for(int j=0;j<y;j++)
		{
			scanf("%d",&f);
			friends[f].pre.push_back(i);
		}
	}

	int min = going.size(),max = notgoing.size();
	//cout << max << endl;
	// for min
	int num,index;
	while(!going.empty())
	{
		num = going.top();
		going.pop();
		int sz = friends[num].pre.size();
		for(int i = 0 ; i < sz;i++)
		{
			index = friends[num].pre[i];
			int no = ++(friends[index].numgoing);
			if(no >= friends[index].t_i && !go[index] )
			{
				go[index] = true;
				min++;
				going.push(index);
			}
		}
	}


	for (int i = 0; i < n; ++i)
	{
		friends[i].numgoing = friends[i].n_i;
		if(friends[i].t_i <= friends[i].n_i){
			go[i] = true;
		}
	}

	while(!notgoing.empty())
	{
		num = notgoing.top();
		notgoing.pop();
		//cout << num << "$";
		int sz = friends[num].pre.size();

		for (int i = 0; i < sz; ++i)
		{
			index = friends[num].pre[i];
			int no = --(friends[index].numgoing);
			
			if(no < friends[index].t_i && go[index])
			{
				go[index] = false;
				notgoing.push(index);
				max++;
			}
		}
	}

	printf("%d %d",min,n-max);

	return 0;
}