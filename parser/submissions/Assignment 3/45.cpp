#include<iostream>
#include<vector>
using namespace std;

void modify1(vector<int> &L,vector<int> &v1,vector<int> &va,vector<int> &vb,int &i,int &m){
	for(int j=0;j<v1.size();j++){
		if(j==(m-1)){
			if(va[i]==vb[j]){v1[j]=1;}
			else{v1[j]++;}
			continue;
		}
		if(va[i]==vb[j]){v1[j]=1+v1[j+1];}
		else{v1[j]++;}
	}
	L[i] = v1[0];
	return;
}

void findSolution(vector<int> &va,vector<int> &vb,int &n,int &m){
	if(m>n){
		cout<<"infinity\n";
		return;
	}
	std::vector<int> v1(m,n+1);
	std::vector<int> L(n);
	//initialisation
	if(va[n-1]==vb[m-1]){v1[m-1] = 1;}
	L[n-1] = v1[0];
	for(int i=(n-2);i>=0;i--){
		modify1(L,v1,va,vb,i,m);
	}
	//finding minimum
	int min1 = (n+1),prefix;
	for(int i=0;i<n;i++){
		int q = L[i];
		if(q<min1){
			min1 = q;
			prefix = i+1;
		}
	}
	if(min1>n){cout<<"infinity\n";}
	else{cout<<min1<<" "<<prefix<<endl;}
	return;
}



int main(){

	int n,m,temp;
	cin>>n>>m;
	std::vector<int> va(n);
	std::vector<int> vb(m);
	for(int i=0;i<n;i++){
		cin>>temp;
		va[i] = temp;
	}
	for(int i=0;i<m;i++){
		cin>>temp;
		vb[i] = temp;
	}
	findSolution(va,vb,n,m);
	return 0;
}
