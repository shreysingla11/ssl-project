#include<iostream>
#include<set>
#include<map>
#include<string>

using namespace std;

int main(){
	map<string,int> A;
	map<int,set<string> > B;
	int count=0;

	// variables need in switch case
	string name;
	int i,j; 
	map<int,set<string> >::iterator it1;
	map<int,set<string> >::iterator it2;
	int amount; 
	set<string>::iterator p;
				
	char op; cin>>op;
	while(op != 'E'){
		switch(op){
			case 'O':
				cin>>name;
				if (A.find(name) != A.end()){
					count++;
					break;
				}
				else{
					A[name]=0;
					if (B.find(0) == B.end()){
						B[0] = set<string>();
					}
					B[0].insert(name);	
				}
				//input string and create new account only if doesn't exist
				//then initialize in A and add to B
				//else increment count
				break;
			case 'D':
				cin>>name;
				cin>>amount;
				if (A.find(name) == A.end()){
					count++;
					break;
				}
				else{
					B[A[name]].erase(name);
					if (B[A[name]].empty()){
						B.erase(A[name]);
					}
					A[name] += amount;
					if (B.find(A[name]) == B.end()){
						B[A[name]] = set<string>();
					}
					B[A[name]].insert(name);	
				}
				//if account doesn't exist, count++
				//else 
				break;
			case 'W':
				cin>>name;
				cin>>amount;
				if (A.find(name) == A.end()){
					count++;
					break;
				}
				else{
					if (A[name]<amount){
						count++;
						break;
					}
					else{
						B[A[name]].erase(name);
						if (B[A[name]].empty()){
							B.erase(A[name]);
						}
						A[name] -= amount;
						if (B.find(A[name]) == B.end()){
							B[A[name]] = set<string>();
						}
						B[A[name]].insert(name);
					}	
				}
				//if account doesn't exist and balance>withdraw, count++
				//else 
				break;
			case 'P':
				cin>>i>>j;
				it1 = B.lower_bound(i); 
				it2 = B.upper_bound(j);
				while (it1 != it2){
					p = it1->second.begin();
					cout<<A[(*p)];
					while (p != it1->second.end() ){
						cout<<" "<<(*p);
						++p;
					}
					cout<<endl;
					it1++;
				}
				break;
			case 'C':
				cin>>name;
				if (A.find(name) != A.end()){
					if (A[name]!=0){
						count++;
						break;
					}
					else{
						B[0].erase(name);
						if (B[0].empty()){
							B.erase(0);
						}
						A.erase(name);
					}
				}
				else{
					count++;
					break;
				}
				//
				break;
			default:
				break;
		}
		cin>>op;
	}
	cout<<count<<endl;
	return 0;
}