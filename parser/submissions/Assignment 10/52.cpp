#include <iostream>
#include <math.h>
using namespace std;

vector<int>* get_vec(vector<int>* a, vector<int>* b){
	vector<int> c;
	
	find(c.begin(),c.end(),b[i])
	
	}
	
class distinct{
	public:
		vector<int> x;

		distinct( vector<int>* b){
				get_vec(x,b);
				}
			
			}
	
	}

int mid(int a, int b) {
	return s + (e-s)/2;
	}

int constructed(vector<int>* a, int start, int end, vector<int> *tree, int x){
	if(start == end){
		tree[x] = a[start];
		return tree[x];
		}
	int midle = mid(start, end);
		
	if(x%2==0){
	tree[x] = 	
		}	
	
	tree[x] = constructed(a, start, mid, tree, x*2 + 1) + constructed(a, mid + 1, end, tree, x*2 + 2);
	return tree[x];
	}
	
int *construct(vector<int>* a,int n){
	int x = int (ceil(log2(n)));
	int b = 2*(pow(2,x)) -1 ;
	int *s = new int[b]; 
	
	constructed(a,0,n-1,s,0);
	return s;
	}
