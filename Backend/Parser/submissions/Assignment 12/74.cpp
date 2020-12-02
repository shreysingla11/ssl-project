#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

class Node {
public:
	int t;
	int n;
	vector<int> next;
	vector<int> prev;
	int going;
	int not_going;
	bool gpush, ngpush;

	Node(){
		t = n = going = not_going = 0;
		gpush = ngpush = false;
	}
};	

int main() {
	vector<Node> nodes;
	int N, tx, nx;
	scanf("%d\n", &N);
	nodes.resize(N);
	queue<int> going_s, not_going_s;
	
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &tx, &nx);
		nodes[i].t = tx;
		nodes[i].n = nx;
		if(tx == 0) {
			going_s.push(i);
			nodes[i].gpush = true;
		}
		if(tx > nx) {
			not_going_s.push(i);
			nodes[i].ngpush = true;
		}
		int temp;
		nodes[i].next.resize(nx);
		for(int j = 0; j < nx; j++) {
			scanf("%d", &temp);
			nodes[i].next[j] = temp;
			nodes[temp].prev.push_back(i);
		}
	}

	int min = 0;
	while (!going_s.empty())
	{
		Node curr = nodes[going_s.front()];
		going_s.pop();
		for(int i =0; i<curr.prev.size(); i++) {
			nodes[curr.prev[i]].going++;
			if(nodes[curr.prev[i]].t == nodes[curr.prev[i]].going && nodes[curr.prev[i]].gpush != true) {
				going_s.push(curr.prev[i]);
				nodes[curr.prev[i]].gpush = true;
			}
		}
		min++;
	}

	int max = 0;
	while (!not_going_s.empty())
	{
		Node curr = nodes[not_going_s.front()];
		not_going_s.pop();
		for(int i =0; i<curr.prev.size(); i++) {
			nodes[curr.prev[i]].not_going++;
			if(nodes[curr.prev[i]].t > (nodes[curr.prev[i]].n - nodes[curr.prev[i]].not_going) && nodes[curr.prev[i]].ngpush != true) {
				not_going_s.push(curr.prev[i]);
				nodes[curr.prev[i]].ngpush = true;
			}
		}
		max++;
	}

	cout << min << " " << N - max << endl;
	return 0;
}
