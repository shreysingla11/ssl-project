#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	ll t;
	cin>>n>>t;
	ll arr[n][n];
	for (ll i=0;i<n;i++){
		for (ll j=0;j<n;j++){
			arr[i][j]=0;
		}
	}

	for (ll i=0;i<n;i++){
		arr[i][n-1]=1;
	}

	for (ll j=n-2;j>=0;j--){
		for (ll i=0;i<=j;i++){
			arr[i][j]=(i+1)*arr[i][j+1] + arr[i+1][j+1];
		}
	}

	for (ll I=0;I<t;I++){
		char c;
		cin>>c;
		if (c=='R'){
			ll p[n];
			for (ll i=0;i<n;i++){
				cin>>p[i];
			}
			ll maxm[n+1];
			maxm[0]=0;
			for (ll i=1;i<=n;i++){
				maxm[i]=max(maxm[i-1],p[i-1]);
			}
			ll rank=0;
			for (ll i=0;i<n;i++){
				rank+=(p[i]*arr[maxm[i]][i]);
			}
			cout<<rank<<"\n";
		}
		if (c=='U'){
			ll r;
			cin>>r;
			ll m=0;
			ll ans[n];
			for (ll i=0;i<n;i++){
				ll t1,t2;
				t1=arr[m][i];
				if (r/t1>m){
					ans[i]=m+1;
					r=r-(m+1)*t1;
					m++;
				}
				else{
					ans[i]=r/t1;
					r=r%t1;
				}
			}
			for (ll i=0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}

