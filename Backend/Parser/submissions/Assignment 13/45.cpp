#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
vector<vector< int> > cost;
struct entity{
	int index;
	int goodness;
	entity(){}
	entity(int i,int j){
        index=i;
        goodness=j;
	}
};
struct nodes{
	vector<int> labells;
	vector<bool> qpre;
	nodes(int n){
		for(int i=0;i<4*n+1;i++){
			labells.push_back(INFINITY);
			qpre.push_back(false);
		}
	}
};
int main(int argc, char const *argv[])
{
    int n,buffer;
	scanf("%d",&n);
	cost.resize(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0;j < n; ++j)
		{
			scanf("%d",&buffer);
			cost[i].push_back(buffer);
		}
	}
	vector<nodes> say;
	queue<entity> say1;
	entity* ent;
	entity temp;
	nodes* a;
	for (int i = 0; i < n; ++i)
	{
		a=new nodes(n);
		say.push_back(*a);
	}
	say[0].labells[2*n]=0;
	say[0].qpre[2*n]=true;
	ent=new entity(0,2*n);
	say1.push(*ent);
	while(!say1.empty()){
		temp=say1.front();
		for (int i = 0; i < n; ++i)
		{
			if(cost[temp.index][i]<0){
				if(say[temp.index].labells[temp.goodness]-cost[temp.index][i]<say[i].labells[temp.goodness+1]&& temp.goodness+1<=4*n)
				{
					say[i].labells[temp.goodness+1]=say[temp.index].labells[temp.goodness]-cost[temp.index][i];
					if(say[i].qpre[temp.goodness+1]==false){
                        say[i].qpre[temp.goodness+1]=true;
						ent=new entity(i,temp.goodness+1);
						say1.push(*ent);
					}
				}
			}
			else{
				if(say[temp.index].labells[temp.goodness]+cost[temp.index][i]<say[i].labells[temp.goodness-1]&& temp.goodness-1>=0)
				{
					say[i].labells[temp.goodness-1]=say[temp.index].labells[temp.goodness]+cost[temp.index][i];
					if(say[i].qpre[temp.goodness-1]==false){
                        say[i].qpre[temp.goodness-1]=true;
						ent=new entity(i,temp.goodness-1);
						say1.push(*ent);
					}
				}
			}
		}
		say1.pop();
		say[temp.index].qpre[temp.goodness]=false;
	}
	int k;
	for(int i=0;i<n;i++){

       k=-1;
        for(int j=2*n;j<4*n+1;j++){
           if(say[i].labells[j]>2000000000)
               continue;
           if(k==-1){
               k=say[i].labells[j];
               continue;
           }
            if(k>say[i].labells[j])
            {
                k=say[i].labells[j];
                continue;
            }
        }
        if(k==-1)
            cout<<"infinity"<<endl;
        else
            cout<<k<<endl;
	}
	return 0;
}
