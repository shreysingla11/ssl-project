#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct queuewala{
	int no;
	int g;
};

struct node{
	int num;
	vector <int> label;
	vector <bool> inq;
	node (int n){
		label.resize(4*n+1, INFINITY);
		inq.resize(4*n+1, false);
	}
};


vector <vector <int> > c;
vector<int> v;
queue <queuewala> q;
vector <node> np;

int main(){
	int n;
	scanf("%d", &n);
	v.resize(n,0);
	c.resize(n, v);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &c[i][j]);
		}
	}

	node temp1(n);
	temp1.num = 0;
	np.resize(n, temp1);
	for(int i=0; i<n; i++){
		np[i].num = i;
	}

	queuewala elem, temp;
	elem.no = 0;
	elem.g = 2*n;
	np[0].inq[2*n] = true;
	np[0].label[2*n] = 0;
	q.push(elem);


	while (!q.empty()){
		temp = q.front();

		for (int i=0; i<n; i++){
			if (c[temp.no][i] < 0){
				if (np[temp.no].label[temp.g] - c[temp.no][i] < np[i].label[temp.g+1] && temp.g+1<=4*n){
					np[i].label[temp.g+1] = np[temp.no].label[temp.g] - c[temp.no][i];
					if (np[i].inq[temp.g+1] == false){
						np[i].inq[temp.g+1] = true;
						elem.no = i;
						elem.g = temp.g+1;
						q.push(elem);
					}
				}
			}
			if (c[temp.no][i] > 0){
				if (np[temp.no].label[temp.g] + c[temp.no][i] < np[i].label[temp.g-1] && temp.g -1 >=0){
					np[i].label[temp.g -1] = np[temp.no].label[temp.g] + c[temp.no][i];
					if (np[i].inq[temp.g - 1] == false){
						np[i].inq[temp.g - 1] = true;
						elem.no = i;
						elem.g = temp.g -1;
						q.push(elem);
					}
				}
			}
		}
		np[temp.no].inq[temp.g] = false;
		q.pop();
	}

	for (int i=0; i<n; i++){
		int mini = INFINITY;
		for (int j = 2*n; j<4*n+1; j++){
			//cout<<np[i].label[j]<<endl;
			mini = min(mini, np[i].label[j]);
		}
		if (mini >= 200000000){
			printf("infinity\n");
		}
		else
			printf("%d\n", mini);
	}

}