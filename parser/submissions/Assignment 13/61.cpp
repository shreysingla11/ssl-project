#include <iostream>
#include <algorithm>
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
#include <vector>
#include <limits>
#include <utility>      // std::pair, std::make_pair

#define INF std::numeric_limits<int>::max()

using namespace std;

int N;

int goodness(int a){
	return a + 2*N;
}

int main(){
	cin>>N;
	vector< vector<int> > W;
	for(int i = 0; i<N; i++){
		vector<int> temp(N, 0);
		for (int j = 0; j < N; j++){
			int w;
			cin>>w;
			temp[j] = w;
		}
		W.push_back(temp);
	}
	queue< pair<int,int> > updated;
	vector< vector<bool> > is_present(N,vector<bool>(4*N + 1,false));
	vector< vector<int> > C(N, vector<int>(4*N + 1,INF));

	pair<int, int> temp(0,2*N);
	
	updated.push(temp);
	is_present[0][2*N] = true;
	C[0][2*N] = 0;
	
	while(!updated.empty()) {
		temp = updated.front();
		updated.pop();

		int V = temp.first;
		int G = temp.second;

		is_present[V][G] = false;

		for(int i = 0; i<N; i++) {

			int w = W[V][i]; //weight
			int g = G;

			if(w < 0) { //good
				w = -w;
				g = G + 1;
			}
			else{ //bad
				g = G - 1;
			}
			if(g >=0 && g <=4*N){

				if(C[i][g] > C[V][G] + w){

					C[i][g] = min(C[i][g], C[V][G] + w);
					if(!is_present[i][g]) {
						
						bool to_be_added = true;
						for(int goodness = g+1; goodness<4*N + 1; goodness++) {
							if(C[i][goodness] <= C[i][g]){
								to_be_added = false;
								break;
							}
						}

						if(to_be_added){
							updated.push(pair<int, int>(i,g));
							is_present[i][g] = true;
						}
					}
				}

			}
		}
	}
	for(int i =0; i<N; i++) {
		int minimum = INF;
		for(int g = 2*N; g<4*N + 1; g++){
			minimum = min(minimum, C[i][g]);
		}
		if(minimum == INF){
			cout<<"INFINITY"<<endl;
		}
		else{
			cout<<minimum<<endl;
		}
	}

	return 0;
}
