#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

struct node{

	int index,n_i,t_i;
	vector <int> friends;
	vector <int> friendto;
	int gng,notgng;

	bool added,deleted;
	
	node(){
		index=-1;
		n_i=0;
		t_i=0;
		gng=0;
		notgng=0;
		added=false;
		deleted=false;
	}; 


};


int main(){
	int n,n_i,t_i;
	scanf("%d",&n);
	vector <node> nodes(n);
	
	queue <int> going;
	queue <int> not_going;


	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&t_i);
		scanf("%d",&n_i);

		//cout<< " Yolo " <<n_i<<endl;
		nodes[i].index=i;
		nodes[i].n_i=n_i;
		nodes[i].t_i=t_i;
		for(int j=0;j<n_i;j++)
		{
			scanf("%d",&temp);
			nodes[i].friends.push_back(temp);
			nodes[temp].friendto.push_back(i);
		}	

		if(t_i==0){
			//cout<< "YIPEEEEE" <<endl;
			going.push(i);
			nodes[i].added=true;

		}
		if(t_i>n_i){
			nodes[i].deleted=true;
			not_going.push(i);	
		}
	}	

	int min=0,max=n;

	while(!going.empty())
	{
		node present=nodes[going.front()];
		going.pop();

		for(int i=0;i<present.friendto.size();i++)
		{
			nodes[present.friendto[i]].gng++;
			if(nodes[present.friendto[i]].gng >= nodes[present.friendto[i]].t_i && nodes[present.friendto[i]].added!=true)
			{
				nodes[present.friendto[i]].added=true;
				going.push(present.friendto[i]);
			}
		}

		min++;
	}

	while(!not_going.empty())
	{
		node present=nodes[not_going.front()];
		not_going.pop();

		for(int i=0;i<present.friendto.size();i++)
		{
			nodes[present.friendto[i]].notgng++;
			if(nodes[present.friendto[i]].n_i- nodes[present.friendto[i]].notgng < nodes[present.friendto[i]].t_i && nodes[present.friendto[i]].deleted!=true)
			{
				nodes[present.friendto[i]].deleted=true;
				not_going.push(present.friendto[i]);
			}
		}

		max--;
	}

	printf("%d %d\n",min,max);

return 0;
}