#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll rec(ll n,ll k,ll st){
	if (n==1){
		return 1;
	}
	//cout<<l<<" "<<st<<endl;
	
	ll p;
	ll t_new,n_new;
	n_new = n-((n-st)/k);
	
	t_new = ((n-st)%k)*(-1);
		
	p=rec(n_new,k,t_new);

	if ((p-st)%(k-1)==0){
		return p + (p-st)/(k-1) - 1;
	}
	else{
		return p + (p-st)/(k-1);
	}
}


int main(int argc, char const *argv[])
{
	ll n,k;
	cin>>n>>k;
	cout<<rec(n,k,0)<<endl;
	return 0;
}