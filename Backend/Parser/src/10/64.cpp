#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <utility> 

using namespace std;


// void print(vector<int> A) {
// 	for(int i = 0; i < A.size(); i++){
// 		cout<<A[i]<<" ";
// 	}
// 	cout<<endl;
// }

class distinct
{
public:
	vector<int> Orig;
	vector<int> l;
	// vector<int> inverse_l;
	vector<vector<int> > count;
	vector<vector<int> > k;

public:
	distinct(vector<int> A){
		Orig = A;
		l.resize(A.size());
		map<int,int> m;
		for(int i = 0; i < A.size(); i++){
			if(m.count(A[i]) == 0){
				l[i] = -1;
				m[A[i]] = i;
			}
			else{
				l[i] = m[A[i]];
				m[A[i]] = i;
			}
		}
		// inverse_l = inv(l);
		pair< vector<int>, vector<int> > p;
		int n = l.size();
		int exp_i = 2;
		for(;exp_i <= n; exp_i*=2) {
			p = construct_level(exp_i);
			count.push_back(p.first);
			k.push_back(p.second);
			// cout<<"Level "<<exp_i<<" : "<<endl;
			// cout<<" Count : ";
			// print(p.first);
			// cout<<" Index : ";
			// print(p.second);
			// cout<<endl;
		}
	};

	pair< vector<int>, vector<int> > construct_level(int exp_i){
		int n = l.size();
		int interval_size = n/(exp_i);
		vector<int> level_count(n);
		vector<int> level_index(n);
		vector<int> intervals_index(exp_i, -1);
		vector<int> intervals_count(exp_i, 0);

		for(int j = 0; j < n; j++){
			if(l[j] >= 0) {
				int k = l[j]/interval_size;
				intervals_count[k]++;

				if(k%2 == 1){//second half
					level_count[j] = intervals_count[k];
					level_index[j] = intervals_index[k-1];
				}
				else {//first half
					level_count[j] = intervals_count[k+1];
					level_index[j] = intervals_index[k+1];
				}

				intervals_index[k] = j;
			}
			else {
				level_count[j] = 0;
				level_index[j] = -1;
			}
		}

		pair< vector<int>, vector<int> > p(level_count, level_index);
		return p;
	}

	int num_distinct(int i, int j) {
		int I=i,J=j;
		int n = l.size();
		int cnt = 0;
		int level = 0;
		int expo = 4;
		int mid = n/2;

		if(i == j) {
			return 1;
		}
		if(i > j){
			return 0;
		}


		while(true) {
			if( i == mid){
				if(count[level][j] > 0){
					cnt += count[level][j];
				}
				break;
			}
			else if (i > mid) {
				
				if(l[j] < mid) {
					j = k[level][j];
				}
				if(j < 0){
					break;
				}

				mid += n/expo;
				level++;
			}
			else {

				if(count[level][j] > 0){
					cnt += count[level][j];
				}

				if(l[j] >= mid) {
					j = k[level][j];
				}
				if(j < 0){
					break;
				}

				mid -= n/expo;
				level++;
			}
			expo = expo*2;
			if(expo > n){
				break;
			}
		}
		return J - I + 1 - cnt;
	}

	// int count_l(int a, int b, int j){
	// 	int c = 0;
	// 	for (int i = 0; i <= j; ++i)
	// 	{
	// 		if(l[c]>=a && l[c]<b){
	// 			c++;
	// 		}
	// 	}
	// }

	// vector<int> inverse(vector<int> v) {
	// 	vector<int> inv(v.size(),-1);
	// 	for(int i = 0; i< A.size(); i++){
	// 		if(A[i] != -1){
	// 			inv[A[i]] = i;
	// 		}
	// 	}
	// 	return inv;
	// }



};


// int main(){
// 	vector<int> input;
// 	input.push_back(1);
// 	input.push_back(2);
// 	input.push_back(1);
// 	input.push_back(3);
// 	input.push_back(2);
// 	input.push_back(1);
// 	input.push_back(1);
// 	input.push_back(3);

// 	// int in;
// 	// cin>>in;
// 	// while(in != -1){
// 	// 	input.push_back(in);
// 	// 	cin>>in;
// 	// }

// 	distinct B(input);
// 	print(B.Orig);
// 	print(B.l);

// 	int in1,in2;
// 	cout<<"Enter input: ";
// 	cin>>in1>>in2;

// 	while(in1 != -1){
// 		cout<<B.num_distinct(in1,in2)<<endl;
// 		cout<<"Enter input: ";
// 		cin>>in1>>in2;
// 	}


// 	return 0;
// }
