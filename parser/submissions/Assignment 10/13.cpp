#include <bits/stdc++.h>
using namespace std;

class distinct{
  public:
	vector<int> a;
	vector<int> l;
	distinct(vector<int> arr);
	int num_distinct(int i, int j);
};

distinct :: distinct(vector<int> arr){
	for(int i=0; i<arr.size(); i++) a.push_back(arr[i]);
	int len = a.size();
	l.resize(len);
	l[0] = -1;
	for(int i=1; i<len; i++){
		int j;
		for(j=i-1; j>=0; j--){
			if(a[i] == a[j]){
				l[i] = j;
				break;
			}
		}
		if(j < 0) l[i] = -1;
	}
}

int distinct :: num_distinct(int i, int j){
	int k=0;
	for(int m=i; m<=j; m++){
		if(l[m] >= i) k++;
	}
	int t = j-i+1-k;
	return t;
}
