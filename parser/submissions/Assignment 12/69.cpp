#include <iostream>
#include <algorithm>
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <queue>          // std::queue
#include <cstdio>          // input

using namespace std;

class node{
public:
	int index;
	int threshold;
	vector<int> predecessors;
	// vector<int> successors;
	int going;
	int not_going;
	int total;
	int going_enqued;
	int not_going_enqued;
	node() {
		index = -1;
		going = not_going = total = 0;
		going_enqued = false;
		not_going_enqued = false;
	};
	node(int x) {
		index = x;
		going = not_going = total = 0;
		going_enqued = false;
		not_going_enqued = false;
 	};

};
int main(){
	int N;
	scanf("%d\n", &N);

	vector<node> All(N);
	queue<int> going;
	queue<int> not_going;

	for(int i = 0; i< N; i++){

		int thresh, n_i;
		scanf("%d %d ", &thresh, &n_i);
		// cin>>thresh>>n_i;

		All[i].index = i;
		All[i].threshold = thresh;
		All[i].total = n_i;
		for(int k	 = 0; k	<n_i; k	++){
			int j;
			// cin>>j;
			scanf("%d", &j);
			// All[i].successors.push_back(j);
			All[j].predecessors.push_back(i);
		}

		if(thresh == 0){
			// cout<<" PUSHING into GOING : "<< i<<endl;
			going.push(i);
			All[i].going_enqued = true;
		}
		if(thresh > n_i){
			// cout<<" PUSHING into NOT_GOING : "<< i<<endl;
			not_going.push(i);
			All[i].not_going_enqued = true;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		// cout<< All[i].index<<" thresh:"<<All[i].threshold<<" n_i:"<<All[i].total<<endl;
		// cout<<"      successors: ";
		for(int k = 0; k<All[i].total; k++){
			// cout<<All[i].successors[k]<<" ";			
		}
		// cout<<endl;
		// cout<<"      predecessors: ";
		for(int k = 0; k<All[i].predecessors.size(); k++){
			// cout<<All[i].predecessors[k]<<" ";			
		}
		// cout<<endl<<endl;
	}

	// FINDING MIN
	int min = 0;
	while(!going.empty()){
		int curr_index = going.front();
		going.pop();

		for (vector<int>::iterator i = All[curr_index].predecessors.begin(); i != All[curr_index].predecessors.end(); ++i)
		{
			All[*i].going ++;
			if(All[*i].going >= All[*i].threshold){
				if(All[*i].going_enqued == false){
					// cout<<" PUSHING into GOING : "<< *i<<endl;
					going.push(*i);
					All[*i].going_enqued = true;
				}
			}
		}

		min++;
	}


	// FINDING MAX
	int max = 0;
	while(!not_going.empty()){
		int curr_index = not_going.front();
		not_going.pop();

		for (vector<int>::iterator i = All[curr_index].predecessors.begin(); i != All[curr_index].predecessors.end(); ++i)
		{
			All[*i].not_going ++;
			if(All[*i].total - All[*i].not_going < All[*i].threshold){
				if(All[*i].not_going_enqued == false){
					// cout<<" PUSHING into NOT_GOING : "<< *i<<endl;
					not_going.push(*i);
					All[*i].not_going_enqued = true;
				}
			}
		}
		max++;
	}

	cout<<min<<" "<<N-max<<endl;


	return 0;
}
