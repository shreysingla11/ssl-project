#include <cstdio>
#include <queue>

using namespace std;

int maxGoing;
int minGoing;
queue<int> going;
queue<int> ditch;

struct node{
	int index;
	int th;
	int n_friends;
	bool isGoing;
	int going_friends;
	vector<int> parents;
	void aFriendGoing(){
		if(isGoing) return;
		going_friends++;
		if(going_friends >= th){
			isGoing = 1;
			minGoing++;
			going.push(index);
		}
	}
	void aFriendDitching(){
		if(!isGoing) return;
		going_friends--;
		if(going_friends < th){
			isGoing = 0;
			maxGoing--;
			ditch.push(index);
		}
	}
};

int main(){
	int n;
	scanf("%d", &n);

	node *all = new node[n];
	maxGoing = n;
	minGoing = 0;
	
	for(int i=0; i<n; i++){
		all[i].index = i;
		scanf("%d", &all[i].th);
		scanf("%d", &all[i].n_friends);
		for(int j=0; j<all[i].n_friends; j++){
			int temp;
			scanf("%d", &temp);
			all[temp].parents.push_back(i);
		}
		all[i].isGoing = 0;
		all[i].going_friends = 0;
		if(all[i].th<=0){
			all[i].isGoing = 1;
			minGoing++;
			going.push(i);
		}
	}
	while(!going.empty()){
		int process = going.front();
		going.pop();
		for(int i=0; i<all[process].parents.size(); i++)
			all[all[process].parents[i]].aFriendGoing();
	}
	for(int i=0; i<n; i++){
		all[i].isGoing = 1;
		all[i].going_friends = all[i].n_friends;
		if(all[i].n_friends<all[i].th){
			all[i].isGoing = 0;
			maxGoing--;
			ditch.push(i);
		}
	}
	while(!ditch.empty()){
		int process = ditch.front();
		ditch.pop();
		for(int i=0; i<all[process].parents.size(); i++)
			all[all[process].parents[i]].aFriendDitching();
	}
	printf("%d %d\n", minGoing, maxGoing);
	return 0;
}