#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define inf 1000000000

int n;

class Vertex {
public:
	vector<int> label;
	vector<bool> inQueue;
	Vertex() {
		label.resize(4*n + 1, inf);
		inQueue.resize(4*n + 1, false);
	}
};

int main() {
	cin >> n;
	vector<Vertex> vertices(n);
	int** C = new int*[n];
	for(int i = 0; i < n; i++)
    	C[i] = new int[n];
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		cin >> C[i][j];
    	}
    }

    vertices[0].label[2*n] = 0;
    vertices[0].inQueue[2*n] = true;

    queue<pair<int, int> > mainQ;
    mainQ.push(make_pair(0, 2*n));

    while(!mainQ.empty()) {
    	int v = mainQ.front().first;
    	int goodness = mainQ.front().second;
    	int label = vertices[v].label[goodness];
    	mainQ.pop();
    	vertices[v].inQueue[goodness] = false;
    	for(int i = 0; i < n; i++) {
    		if(C[v][i] > 0) {
    			if(goodness == 0)
    				continue;
    			if(label + abs(C[v][i]) < vertices[i].label[goodness - 1]){
    				vertices[i].label[goodness - 1] = vertices[v].label[goodness] + abs(C[v][i]);
    				if(!vertices[i].inQueue[goodness - 1]) {
    					pair<int, int> p = make_pair(i, goodness - 1);
    					mainQ.push(p);
    					vertices[i].inQueue[goodness - 1] = true;
    				}
    			}
    		}
    		else if(C[v][i] < 0) {
    			if(goodness == 4*n)
    				continue;
    			if(label + abs(C[v][i]) < vertices[i].label[goodness + 1]){
    				vertices[i].label[goodness + 1] = vertices[v].label[goodness] + abs(C[v][i]);
    				if(!vertices[i].inQueue[goodness + 1]) {
    					pair<int, int> p = make_pair(i, goodness + 1);
    					mainQ.push(p);
    					vertices[i].inQueue[goodness + 1] = true;
    				}
    			}
    		}
    	}
    }

    for(int i = 0; i < n; i++) {
    	int min = inf;
    	for(int j = 2*n; j < 4*n + 1; j++) {
    		if(min > vertices[i].label[j]) {
    			min = vertices[i].label[j];
    		}
    	}
    	if(min == inf) {
    		cout << "infinity" << endl;
    	}
    	else {
    		cout << min << endl;
    	}
    }

   	return 0;
}
