#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <cstdio>
using namespace std;

struct node {
	int value;
	int threshold;
	int going;
	int n_friends;
	int going_friends;
	int not_going_friends;
	bool been_in_q;
	list<int> pre;

};

class graph {
	int n;
	vector<node> v;
	int going;
	int not_going;
	queue<int> q;
public:
	graph(int num) {
		n = num;
		going = 0;
		not_going = 0;
		v.resize(n);
		int thr, n_frnds, frnd;
		for (int i=0; i<n; i++) {
			v[i].value = i;
			//cin>>thr>>n_frnds;
			scanf("%d", &thr);
			scanf("%d", &n_frnds);
			if (thr == 0 || thr > n_frnds) {
				q.push(i);
				v[i].been_in_q = true;
				if (thr == 0) {
					v[i].going = 1;
					going++;
				}
				else {
					v[i].going = -1;
					not_going++;
				}
			}
			else {
				v[i].going = 0;
				v[i].been_in_q = false;
			}
			v[i].threshold = thr;
			v[i].n_friends = n_frnds;
			for (int j = 0; j<n_frnds; j++) {
				//cin>>frnd;
				scanf("%d", &frnd);
				v[frnd].pre.push_back(i);
			}
			v[i].going_friends = 0;
			v[i].not_going_friends = 0;

		}


		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for (list<int>::iterator it=v[u].pre.begin(); it != v[u].pre.end(); it++) {
				if (v[u].going == 1) {
					v[*it].going_friends++;
					if (v[*it].going_friends >= v[*it].threshold && !v[*it].been_in_q) {
						v[*it].going = 1;
						q.push(v[*it].value);
						v[*it].been_in_q = true;
						going++;
					}
				}
				else if (v[u].going == -1) {
					v[*it].not_going_friends++;
					if (v[*it].not_going_friends > v[*it].n_friends - v[*it].threshold && !v[*it].been_in_q) {
						v[*it].going = -1;
						q.push(v[*it].value);
						v[*it].been_in_q = true;
						not_going++;
					}
				}
			}

		}

		//cout << going << " " << n - not_going << endl;
		printf("%d %d\n", going, n - not_going);
	}


};

int main() {

	int n;
	//cin>>n;
	scanf("%d", &n);
	graph g(n);
	return 0;
}