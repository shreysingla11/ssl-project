# include <iostream>
# include <vector>
# include <queue>
# include <cstdio>

using namespace std;

struct node
{
	int id;
	vector<int> nbr;
	std::vector<bool> inserted;
	vector<int> levels;
};

struct tuple
{
	int id;
	int level;
};

int main(){
	const int inf=1000000000;
	const int ninf=-100000000;
	int n;
	cin>>n;
	int temp;
	vector<node> Nodes(n);
		queue<tuple>check;
	for(int i=0;i<n;i++){
		Nodes[i].inserted.resize(4*n+1,false);
		Nodes[i].levels.resize(4*n+1,inf);
	}


	//std::vector<int> cost(n,inf);
	//cost[0]=0;



	for(int i=0;i<n;i++){
		Nodes[i].id=i;
		for(int j=0;j<n;j++){
			//cin>>temp;
			scanf("%d",&temp);
			Nodes[i].nbr.push_back(temp);
		}
	}

	tuple temp0;
	temp0.id=0;
	temp0.level=2*n;
	check.push(temp0);
	Nodes[0].levels[2*n]=0;
	Nodes[0].inserted[2*n]=true;
	int sign,updatedlevel,updatedcost;
	while(!check.empty()){
		int ind=check.front().id;
		int level=check.front().level;
		check.pop();
		Nodes[ind].inserted[level]=false;
		for(int i=0;i<n;i++){
			sign=(Nodes[ind].nbr[i] >0 ? 1:-1);
			updatedcost=Nodes[ind].levels[level] + Nodes[ind].nbr[i]*sign;
			updatedlevel=level - sign;
			if(updatedlevel <= 4*n && updatedcost < Nodes[i].levels[updatedlevel]){
				Nodes[i].levels[updatedlevel]=updatedcost;

				if(!Nodes[i].inserted[updatedlevel]){
					tuple temp3;
					temp3.id=i;
					temp3.level=updatedlevel;
					check.push(temp3);
					Nodes[i].inserted[updatedlevel]=true;
					}
				}
			}

		}

		int min;

		for(int i=0;i<n;i++)
		{
			min=inf;
			for(int j=2*n;j<4*n;j++){
				temp=Nodes[i].levels[j];
				min=(min<temp) ? min:temp;
			}
			if (min==inf)
				cout<<"infinity"<<endl;
			else
				cout<<min<<endl;

		}
		return 0;

}