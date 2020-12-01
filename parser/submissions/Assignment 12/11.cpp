#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

struct person{
	int t;
	int nf;
};

int main(){
	int n, a;
	scanf("%d", &n);
	vector<vector<int> >adj;
	vector<person> val;
	vector<int>temp;
	vector<int> status;
	queue<int> g;
	queue<int> ng;
	adj.resize(n, temp);
	status.resize(n, 0);
	person tmp;
	val.resize(n, tmp);
	int going = 0;
	int not_going = 0;
	for (int j=0; j<n; j++){
		scanf("%d", &val[j].t);
		scanf("%d", &val[j].nf);
		if (val[j].t == 0){
			g.push(j);
			status[j] = 1;
			going ++;
		}
		if (val[j].t > val[j].nf){
			ng.push(j);
			status[j] = -1;
			not_going++;
		}
		//val.push_back(tmp);
		for (int i=0; i<val[j].nf; i++){
			scanf("%d", &a);
			adj[a].push_back(j);
		}
	}

	int p,q,num;
	while (!ng.empty()){
		 p = adj[ng.front()].size();
		for (int i=0; i<p; i++){
			 num = adj[ng.front()][i];
			if (status[num] !=0)
				continue;
			val[num].nf--;
			if (val[num].t > val[num].nf){
				status[num] = -1;
				not_going++;
				ng.push(num);
			}
		}
		ng.pop();
	}

	while (!g.empty()){
		 q = adj[g.front()].size();
		for (int i = 0; i<q; i++){
			num = adj[g.front()][i];
			//cout<<num<<endl;
			if (status[num]!=0){
				continue;
			}
			val[num].t--;
			val[num].nf--;
			if (val[num].t==0){
				status[num] = 1;
				g.push(num);
				going++;
			}	
		} 
		g.pop();
	}

	printf("%d %d\n", going, n-not_going);

}