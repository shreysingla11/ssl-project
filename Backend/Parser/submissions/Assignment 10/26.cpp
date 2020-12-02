#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct pairs{
	int index;
	int a_value;
	pairs(int x, int y){index = x; a_value = y;}
	bool operator<(pairs const &a) const{ return a_value < a.a_value;}
};

class distinct{
	vector<int> a;
	vector<int> l;
	vector<int> last;
	int N;
	vector< vector<int> > first;
	vector< vector<int> > second;
public:
	distinct(vector<int> &v);
	int num_distinct(int i, int j);
	void construct_l();
	void construct_tree(int lvl);
	int query(int i, int j, int s, int e, int lvl);
};

distinct::distinct(vector<int> &v){
	N = v.size();
	for(int i=0; i<N; i++) a.push_back(v[i]);
	construct_l();
	construct_tree(1);
}

int distinct::num_distinct(int i, int j){
	if(j<i) return 0;
	return j-i+1 - query(i, j, 0, N, 1);
}

void distinct::construct_l(){
	l.resize(N);
	vector<pairs> temp;
	for(int i=0; i<N; i++){
		temp.push_back(pairs(i, a[i]));
	}
	stable_sort(temp.begin(), temp.end());
	l[temp[0].index] = -1;
	for(int i=1; i<N; i++){
		if(temp[i].a_value > temp[i-1].a_value){
			l[temp[i].index] = -1;
		}
		else{
			l[temp[i].index] = temp[i-1].index;
		}
	}
	last.push_back(0);
	for(int i=1; i<N; i++){
		if(l[i] == -1)
			last.push_back(last[i-1]);
		else
			last.push_back(i);
	}
	first.push_back(vector<int> (N));
	second.push_back(vector<int> (N));
	//for(int i=0; i<N; i++) cout << l[i] << endl;
}

void distinct::construct_tree(int lvl){
	int interval_size = N/pow(2, lvl-1);

	int n_intervals = pow(2, lvl-1);
	
	vector<int> prev1(n_intervals, -1);
	vector<int> prev2(n_intervals, -1);
	vector<int> count2(n_intervals, 0);

	first.push_back(vector<int> (N));
	second.push_back(vector<int> (N));
	// if(interval_size == 1){
	// 	for(int j=0; i<N; j++) first[lvl][j] = 
	// }
	for(int j=0; j<N; j++){
		if(l[j] == -1){
			if(lvl == 1){
				first[lvl][j] = first[lvl][last[j]];
				second[lvl][j] = second[lvl][last[j]];
			}
			continue;
		}
		int k = l[j]/interval_size; // got the interval
		if(l[j] >= k*interval_size + interval_size/2){
			count2[k]++;
			prev2[k] = j;
			second[lvl][j] = prev1[k];
		}
		else{
			//do nothing to count2
			prev1[k] = j;
			second[lvl][j] = prev2[k];
		}
		first[lvl][j] = count2[k];
	}
	// for(int i=0; i<N; i++) cout << first[lvl][i] << " ";
	// 	cout << endl;
	// for(int i=0; i<N; i++) cout << second[lvl][i] << " ";
	// 	cout << endl;
	// 	cout << "--------" << endl;
	if(interval_size != 1) construct_tree(lvl+1);
}

int distinct::query(int i, int j, int s, int e, int lvl){
	//cout << i << j << s << e << lvl << endl;
	if(lvl >= first.size()) return 0;
	if(l[j] == -1){
		if(lvl!=1) return 0;
		if(j==0) return 0;
		else return query(i, last[j], s, e, lvl);
	}
	//if(j<i) return 0;
	if(j==-1) return 0;
	int mid = (s+e)/2;
	int ans = 0;
	if( i <= mid) ans += first[lvl][j];
	if( i == mid ) return ans;
	if(i < mid ){
		if(l[j] < mid) return ans + query(i, j, s, mid, lvl+1);
		else return ans + query(i, second[lvl][j], s, mid, lvl+1);
	}
	else{
		if(l[j]>=mid) return ans + query(i, j, mid, e, lvl+1);
		else return ans + query(i, second[lvl][j], mid, e, lvl+1);
	}

}
/*

int main(){
	//int a[] = {1,2,1,3,2,1,1,3};
	int a[] = {1, 2, 1, 1, 1, 1, 1, 3};
	vector<int> n(a, a+8);
	distinct f(n);
	cout << f.num_distinct(3, 6) << endl;
	cout << f.num_distinct(3, 7) << endl;
	cout << f.num_distinct(0, 0) << endl;
	cout << f.num_distinct(1, 2) << endl;
	cout << f.num_distinct(1, 3) << endl;
	cout << f.num_distinct(0, 7) << endl;
	return 0;
}

*/