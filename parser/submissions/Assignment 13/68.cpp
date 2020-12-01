#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <stdio.h>
using namespace std;

vector <vector <int> > c;
vector<int> v;

struct vertex{
	int vertex_no;
	vector <int> cost;
	vector <bool> whether_good;
	vertex (int n){
		cost.resize(4*n+1, INFINITY);
		whether_good.resize(4*n+1, false);
	}
};

struct queue_struct{
	int no;
	int good;
};

queue <queue_struct> queue_final;
vector <vertex> point;

int main(){
	int n;
	scanf("%d", &n);
	int l = n;
	while(l>0) {
		vector <int> temp;
		int b =n;
		while(b>0) {
			int a;
			scanf("%d",&a);
			temp.push_back(a);
			b--;
		}
		c.push_back(temp);
		l--;
	}
	v.resize(n,0);

	vertex extra(n);
	extra.vertex_no = 0;
	point.resize(n, extra);

	{
		int i =0;
		while(i<n) {
		point[i].vertex_no = i;
		i++;
	}


	}

	point[0].whether_good[2*n] = true;
	point[0].cost[2*n] = 0;
	queue_struct Element_Queue, temp1;
	Element_Queue.no = 0;
	Element_Queue.good = 2*n;
	queue_final.push(Element_Queue);


	while (!queue_final.empty()){
		temp1 = queue_final.front();
		int it=0;
		for (;it<n;) {
			if (c[temp1.no][it] < 0){
				if (point[it].cost[temp1.good+1] > point[temp1.no].cost[temp1.good] - c[temp1.no][it] && temp1.good<=4*n-1){
					point[it].cost[temp1.good+1] = point[temp1.no].cost[temp1.good] - c[temp1.no][it];
					if (point[it].whether_good[temp1.good+1] != true){

						Element_Queue.good = temp1.good+1;
						Element_Queue.no = it;
						
						queue_final.push(Element_Queue);
						point[it].whether_good[temp1.good+1] = true;
					}
				}
			}
			if (c[temp1.no][it] > 0){
				if (point[it].cost[temp1.good-1] > point[temp1.no].cost[temp1.good] + c[temp1.no][it] && temp1.good >=1){
					point[it].cost[temp1.good -1] = point[temp1.no].cost[temp1.good] + c[temp1.no][it];
					if (point[it].whether_good[temp1.good - 1] != true){
						
						Element_Queue.good = temp1.good -1;
						Element_Queue.no = it;

						queue_final.push(Element_Queue);
						point[it].whether_good[temp1.good - 1] = true;
					}
				}
			}
			it++;
		}
		queue_final.pop();
		point[temp1.no].whether_good[temp1.good] = false;
	}

	for (int i=0; i<n; i++){
		int infi = INFINITY;
		for (int j = 2*n; j<4*n+1; j++){
			infi = min(infi, point[i].cost[j]);
		}
		if (infi >= 123456789){
			printf("infinity\n");
		}
		else
			printf("%d\n", infi);
	}

}