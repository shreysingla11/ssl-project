#include<iostream>
#include<vector>

using namespace std;

long long int rec(long long int l,long long int k,long long int st){
	if (l==1){
		return 1;
	}
	//cout<<l<<" "<<st<<endl;
	
	long long int p;
	long long int st_new,l_new;
	l_new = l-((l-st)/k);
	
	st_new = ((l-st)%k)*(-1);
		
	p=rec(l_new,k,st_new);

	if ((p-st)%(k-1)==0){
		return p + (p-st)/(k-1) - 1;
	}
	else{
		return p + (p-st)/(k-1);
	}
}


int main(int argc, char const *argv[])
{
	long long int n,k;
	cin>>n>>k;

	cout<<rec(n,k,0)<<endl;
	return 0;
}