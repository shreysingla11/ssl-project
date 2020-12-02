#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class counter{
  private:	
	int n;
	vector<int> var;
	vector<list<int> > lis;
	vector<list<int> > :: iterator tp;
	vector<list<int> :: iterator> :: iterator end;
  public:
	counter(int);
	void increment(int);
	void decrement(int);
	void reset(int);
	int count(int);
	int findMax();
	int numMax();
	void printMax();
};

counter :: counter(int j){
	var.resize(j);
	n = j;
	for(int i=0; i<n; i++)
		var[i] = 0;
	lis.resize(n);
	tp = lis.begin();
	for(int i=0; i<n; i++){
		lis[0].push_back(i);
	}
}

void counter :: increment(int i){
	bool flag = false;
	list<int> :: iterator tmp1;
	list<int> :: iterator tmp2;
	list<int> :: iterator tmp;
	for(int k=0; k<n; k++){
		tmp = lis[k].begin();
		if(k!=0 && *tmp == var[i]){
			lis[k].remove(i);
			}
		if(*tmp == var[i]+1) {
			lis[k].push_back(i);
			flag = true;
			break;
		}
	}
	if(!flag){
		list<int> l(1,var[i]+1);
		l.push_back(i);
		tmp = l.begin();
		for(int m=0; m<n-1; m++){
			tmp1 = lis[m].begin();
			tmp2 = lis[m+1].begin();
			tp = lis.begin() + m;
			if(*tmp1 < *tmp && *tmp2 > *tmp){
				lis.insert(tp,l);
				break;
			}
		}
	}
	var[i]++;
}

void counter :: decrement(int i){
	list<int> :: iterator tmp;
	for(int k=1; k<n; k++){
		tmp = lis[k].begin();
		if(*tmp == var[i]) {
			lis[k].remove(i);
			if(lis[k].empty())
				tmp = lis[k-1].begin();
			if(*tmp == var[i]-1) lis[k-1].push_back(i);
			else if(*lis[k-1].begin() < var[i]){
				list<int> l(1,var[i]-1);
				l.push_back(i);
				tp = lis.begin() + k-1;
				lis.insert(tp,l);
			}
			break;
		}
	}
	tmp = lis[0].begin();
	if(*tmp == var[i]) lis[0].remove(i);
	list<int> l(1,var[i]-1);
	l.push_back(i);
	tp = lis.begin();
	lis.insert(tp,l);
	
	var[i]--;
}

void counter :: reset(int i){
	list<int> :: iterator tmp;
	for(int k=0; k<n; k++){
		tmp = lis[k].begin();
		if(var[i] == *tmp){
			lis[k].remove(i);
			break;
		}
	}
	tmp = lis[0].begin();
	if(*tmp == 0) lis[0].push_back(i);
	else{
		list<int> l(1,0);
		l.push_back(i);
		tp = lis.begin();
		lis.insert(tp,l);
	}
	var[i] = 0;
}

int counter :: count(int i){
	return var[i];
}

int counter :: findMax(){
	int max = 0;
	for(int i=0; i<n; i++){
		if(var[i] > max) max = var[i];
	}
	return max;
}


int counter :: numMax(){
	int max = this -> findMax();
	int count=0;
	for(int i=0; i<n; i++){
		if(var[i] == max) count++;
	}
	return count;
}

void counter :: printMax(){
	list<int> :: iterator tmp;
	int max = this -> findMax();
	for(int i=0; i<n; i++){
		tmp = lis[i].begin();
		if(*tmp == max){
			int num = this -> numMax();
			for(int j=1; j<num; j++){
				cout << *tmp << " ";
				tmp++;
			}
			cout << endl;
			return;
		}
	}
}
