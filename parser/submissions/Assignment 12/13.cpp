#include <bits/stdc++.h>
using namespace std;

bool search(int i, vector<int> final_){
	for(int j=0; j<final_.size(); j++){
		if(i = final_[j]) return true;
	}
}

int main(){
	int n;
	int num;
	cin >> n;
	
	vector<int> t(n);
	vector<vector<int> > t_;
	queue <int> definitely_going;
	queue <int> definitely_not_going;
	
	int tmp;
	for(int i=0; i<n; i++){
		cin >> t[i];
		cin >> num;
		
		vector<int> v;
		for(int j=0; j<num; j++){
			cin >> tmp;
			v.push_back(tmp);
		}
		t_.push_back(v);
	}
	
	for(int i=0; i<n; i++){
		//IF THRESHHOLD IS GREATER THAN THE NO. OF FRIENDS THEN 'i' NEVER GOES TO THE MOVIE!
		if(t_[i].size() < t[i] && t[i] != 0) definitely_not_going.push(i);
		//IF THRESHHOLD = 0 THEN 'i' ALWAYS GOES TO THE MOVIE!
		if(t[i] == 0) definitely_going.push(i);
	}
	
/*	while(!definitely_going.empty()){
		cout << definitely_going.top() << endl;
		definitely_going.pop();
	}
*/	
	vector<int> final_;
	
	while(!definitely_going.empty()){
		int tmp = definitely_going.front();
		definitely_going.pop();
		final_.push_back(tmp);
		for(int i=0; i<n; i++){
			if(t[i] <= t_[i].size() && search(tmp, t_[i]) && !search(i, final_)){
				int l = t_[i].size();
				--t[i]; --l;
				for(int j=0; j<t_[i].size(); j++){
					if(t_[i][j] == tmp){
						t_[i][j] = t_[i][l];
						t_[i].resize(l);
					}
				}
				if(t[i] == 0) definitely_going.push(i);
			}
		}
	}
	cout << final_.size() << " " << final_.size() << endl;
	
	//Outputting the input values!
/*	for(int i=0; i<n; i++) cout << t[i] << " ";
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<t_[i].size(); j++){
			cout << t_[i][j] << " ";
		}
		cout << endl;
	}*/
}
