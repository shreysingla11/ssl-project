#include<iostream>
#include<string>
using namespace std;

void mycomp(string s,int n,int *A){
	int v = s.length()/n;
	int z = s.length()%n;
	//cout<<v<<" "<<z<<endl;
	for(int i=0;i<v;i++){
	string s1 = s.substr(0+(i*n),n);
	string s2 = s.substr(0+((i+1)*n),n);
	int x = s1.compare(s2);
	if(x==0) {A[0]=n; A[1]=i*n;break;}	
		}
		for(int i=0;i<v;i++){
	string s1 = s.substr(z+(i*n),n);
	string s2 = s.substr(z+((i+1)*n),n);
	int x = s1.compare(s2);
	if(x==0) {A[0]=n; A[1]=z+(i*n);break;}	
		}
	}

int main(){

string s;

cin>>s;

//cout<<s<<endl;
int A[2]= {0,0};
//cout<<s[0]<<endl;
int n=s.length()/2;
//string s1=s.substr(0,3);
//string s2=s.substr(1,3);

for(int i=1;i<n;i++){
	mycomp(s,i,A);
	if(A[0]!=0)break;
	
	}


cout<<A[0]<<" "<<A[1]<<endl;



}
