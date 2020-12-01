#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
};

class boolfunc{
  public:
	boolfunc();
	~boolfunc();
	boolfunc(boolfunc const &);
	void operator += (boolfunc const &);
	void operator *= (boolfunc const &);
	void operator == (boolfunc const &);
	void operator ~ ();
	void read();
	void print();
	void subst(int i, bool v);
  private:
};

void boolfunc :: operator += (boolfunc const &a){
	
}

void boolfunc :: operator *= (boolfunc const &){
	
}

void boolfunc :: operator == (boolfunc const &){
	
}

void boolfunc :: operator ~ (){
	
}

void boolfunc :: read(){
	
}

void boolfunc :: print(){
	
}

void boolfunc :: subst(int i, bool v){
	
}

int main(){
	int n;
	cin >> n;
	int A[n];
	vector<vector<int> > val;
	for(int i=0; i<n; i++){
		cin >> A[i];
		vector<int> tmp;
		for(int j=0; j<A[i]; j++){
			int temp;
			cin >> temp;
			tmp.push_back(temp);
		}
		val.push_back(tmp);
	}
}
