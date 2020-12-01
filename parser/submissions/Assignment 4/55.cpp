#include<iostream>
#include<vector>
using namespace std;

class counter{
	vector<vector<char> > y;
	vector<int> z;
	vector<int> x1;
	vector<int> y1;
	public:
	
	counter(char *A,int len){new y; new z; new x1; new x2;
		new vector<char> x;
		y.push_back(x);
		for(int i = 0; i<len;i++){
			x.push_back(A[i]);
			
			}
		z.push_back(len);
		
		}
	
	void increment(int i){
		y[(x1[i])+1].push_back(y[x1[i]][y1[i]]);
		y.erase(y[x1[i]][y1[i]]);
		x1[i]=x1[i]+1;
		y1[i]=z[i+1];
		z[(x1[i])-1]=z[(x1[i])-1]-1;
		z[x1[i]]=z[x1[i]]+1;
		} 

	void decrement(int i){
		y[(x1[i])-1].push_back(y[x1[i]][y1[i]]);
		y.erase(y[x1[i]][y1[i]]);
		x1[i]=x1[i]-1;
		y1[i]=z[i-1];
		z[(x1[i])+1]=z[(x1[i])+1]+1;
		z[x1[i]]=z[x1[i]]-1;
		}

	
	
};

int main(){
	counter C;
	char A[4]={'a','v','n','m'};
	C(A,4);
	C.increment(0);
	cout<<C.z[0]<<endl;
	
	}
