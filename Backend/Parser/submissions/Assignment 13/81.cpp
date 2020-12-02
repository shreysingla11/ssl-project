#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

#define m_inf -1000000000
#define inf 1000000000
struct Edge {
	bool good;
	int wt;
};

struct Node {
	int val;
	vector<Edge> out;
	vector<int> path;
	int max_gd;
	int goodness(int i) {
		return path[i+out.size()];
	}
	int gset(int i, int j) {
		path[i+out.size()] = j;
	}
};

class Graph {
	vector<Node> v;
	int n;
	vector<bool> b;
	queue<int> q;
public:
	Graph(int N) {
		n = N;
		v.resize(n);
		int t;
		Edge temp;
		for (int i=0; i<n; i++) {
			b.push_back(false);
			v[i].val = i;
			v[i].max_gd = 0;
			v[i].path.resize(2*n+1, inf);
			for (int j=0; j<n; j++) {
				cin>>t;
				
				if (t<0) {
					temp.good = true;
					temp.wt = -t;
				}
				else {
					temp.good = false;
					temp.wt = t;
				}
				
				v[i].out.push_back(temp);
			}

		}
		v[0].gset(0, 0);
		// for (int i=0; i<n; i++) {
		// 	for (int j=0; j<n; j++) {
		// 		cout<<v[i].out[j].wt<<" ";
		// 	}
		// 	cout<<endl;
		// }
	}

	void Solve() {
		q.push(0);
		b[0] = true;

		while(!q.empty()) {
			int vert = q.front();
			q.pop();
			b[vert] = false;
			//cout<<vert<<endl;
			// if (v[vert].max_gd == n) {
			// 	//cout<<"H"<<endl;
			// 	break;
			// }
			for (int i=0; i<n; i++) {
				if (v[vert].out[i].good) {
					for (int j= -n+1; j<= n; j++) {
						//cout<<"H"<<v[vert].out[i].wt;
						if (v[vert].goodness(j-1)+v[vert].out[i].wt < v[i].goodness(j)) {
							v[i].gset(j, v[vert].goodness(j-1)+v[vert].out[i].wt);
							if (!b[i]) {
								q.push(i);
								b[i] = true;
								//cout<<i<<endl;
							}
						}
					}
					v[i].max_gd = v[vert].max_gd + 1;
				}
				else {
					for (int j= -n; j<= n - 1; j++) {
						
						if (vert == 0 && i==0) {
							//cout<<"Hello"<<endl;
							//cout<<"K"<<v[vert].goodness(j+1)+v[vert].out[i].wt<<" "<<v[i].goodness(j)<<" "<<j<<endl;;
						}
						if (v[vert].goodness(j+1)+v[vert].out[i].wt < v[i].goodness(j)) {

							v[i].gset(j, v[vert].goodness(j+1)+v[vert].out[i].wt);
							if (!b[i]) {
								q.push(i);
								//cout<<i<<"H"<<endl;
								b[i] = true;
								//cout<<i<<endl;
								
							}
						}
					}
				}

			}

		}

		for (int i=0; i<n; i++) {
			int min = inf;
			for (int j=0; j<=n; j++) {
				if (v[i].goodness(j) < min) {
					min = v[i].goodness(j);
				}

			}
			if (min!=inf) {
				cout<<min<<endl;
			}
			else {
				cout<<"infinity"<<endl;
			}
		}

	}

};

int main() {
	int n;
	cin>>n;
	Graph g(n);
	g.Solve();

}