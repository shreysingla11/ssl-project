#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

class boolfunc{	
public:
	int root;
	int no_of_terms;
	boolfunc *left;
	boolfunc *right;
	boolfunc();  
	~boolfunc();  
	boolfunc(boolfunc const &a);
	void operator+=(boolfunc const &a);
	void oraux(boolfunc const &a);
	void operator*=(boolfunc const &a);
	void andaux(boolfunc const &a);
	void operator~();
	bool operator==(boolfunc const &a); 
	void read();
	void print(); 
	void printaux(vector< vector<int> > &v);;
	void subst(int i, bool v);
	void substaux(int i, bool v);
	void optimize();
	void copy(boolfunc const &a);
};

boolfunc::boolfunc(){
	root = 0;
	no_of_terms = 0;
}

boolfunc::boolfunc(boolfunc const &a){
	root = a.root;
	no_of_terms = a.no_of_terms;
	if(root == 0 || root == -1) return;
	left = new boolfunc(*(a.left));
	right = new boolfunc(*(a.right));
}

boolfunc::~boolfunc(){
	// nothing to do
}

void boolfunc::operator~(){
	if(root == 0){ root = -1; return; }
	if(root == -1){ root = 0; return; }
	~(*left);
	~(*right);
	boolfunc *temp = left;
	left = right;
	right = temp;
}

bool boolfunc::operator==(boolfunc const &a){
	if(root==0) return (a.root == 0);
	if(root==-1) return (a.root == -1);
	if(a.root==0) return (root == 0);
	if(a.root==-1) return (root == -1);
	if(root == a.root){
		if(*left == *(a.left)){
			if(*right == *(a.right)){
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}
/////////////modify
void boolfunc::print(){
	vector< vector<int> > v;
	v.push_back(vector<int>());
	printaux(v);
	cout << v.size()-1 << endl;
	for(int i=0; i<v.size()-1; i++){
		cout << v[i].size() << endl;
		for(int j=0; j<v[i].size(); j++) cout << v[i][j] << " ";
		cout << endl;
	}
}


void boolfunc::subst(int i, bool v){
	substaux(i, v);
	optimize();
}

void boolfunc::substaux(int i, bool v){
	if(root == 0 || root == -1) return;
	if(root == i && v == false){
		root = left->root;
		left = left->left;
		right = right->right;
	}
	else if(root == i && v == true){
		root = right->root;
		left = right->left;
		right = right->right;
	}
	else{
		left->substaux(i, v);
		right->substaux(i, v);
	}
}

void boolfunc::operator+=(boolfunc const &a){
	oraux(a);
	optimize();
}


void boolfunc::operator*=(boolfunc const &a){
	andaux(a);
	optimize();
}

void boolfunc::oraux(boolfunc const &a){
	if(root == 0){
		copy(a);
		return;
	}
	if(root == -1){
		return;
	}
	if(a.root == 0){
		return;
	}
	if(a.root == -1){
		copy(a);
		return;
	}

	if(root == a.root){
		left->oraux(*(a.left));
		right->oraux(*(a.right));
	}
	else if(root < a.root){
		left->oraux(a);
		right->oraux(a);
	}
	else{
		boolfunc temp = a;
		temp.oraux(*this);
		copy(temp);
	}
}

void boolfunc::andaux(boolfunc const &a){
	if(root == 0){
		return;
	}
	if(root == -1){
		copy(a);
		return;
	}
	if(a.root == 0){
		copy(a);
		return;
	}
	if(a.root == -1){
		return;
	}
	if(root == a.root){
		left->andaux(*(a.left));
		right->andaux(*(a.right));
	}
	else if(root < a.root){
		left->andaux(a);
		right->andaux(a);
	}
	else{
		boolfunc temp = a;
		temp.andaux(*this);
		copy(temp);
	}
}

void boolfunc::optimize(){
	if(root == 0 || root == -1) return;
	left->optimize();
	right->optimize();
	if(*left == *right){
		copy(*left);
	}
}
void boolfunc::printaux(vector< vector<int> > &v){
	if(root == 0){
		return;	
	} 
	if(root == -1){
		v.push_back(vector<int>(v[v.size()-1]));
		//cout << "done" << endl;
		return;
	}

	v[v.size()-1].push_back(-root);
	left->printaux(v);
	v[v.size()-1].pop_back();
	//cout << "ggg" << root << endl;  
	v[v.size()-1].push_back(root);
	right->printaux(v);
	v[v.size()-1].pop_back();
	return;
}

void boolfunc::read(){
	root = 0;
	int te;
	cin >> te;
	while(te--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++) cin >> v[i];
		boolfunc temp;
		boolfunc *head = &temp;
		for(int i=0; i<n; i++){
			head->root = abs(v[i]);
			head->right = new boolfunc();
			head->left = new boolfunc();
			if(v[i]<0){	
				head->right->root = 0;
				head = head->left;
			}
			else{
				head->left->root = 0;
				head = head->right;
			}
		}
		head->root = -1;
		oraux(temp);
	}
	
	optimize();
}

//////////look
void boolfunc::copy(boolfunc const &a){
	root = a.root;
	no_of_terms = a.no_of_terms;
	if(root == 0 || root == -1) return;
	left = new boolfunc(*(a.left));
	right = new boolfunc(*(a.right));
}
