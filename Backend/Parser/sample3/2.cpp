#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int t;
	cin>>n>>t;
	ll dp[n][n];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}

	for (int i=0;i<n;i++){
		dp[i][n-1]=1;
	}

	for (int j=n-2;j>=0;j--){
		for (int i=0;i<=j;i++){
			dp[i][j]=(i+1)*dp[i][j+1] + dp[i+1][j+1];
		}
	}

	for (int N=0;N<t;N++){
		char c;
		cin>>c;
		
		if (c=='U'){
			ll r;
			cin>>r;
			int m=0;
			ll ans[n];
			for (int i=0;i<n;i++){
				ll t1,t2;
				t1=dp[m][i];
				if (r/t1>m){
					dp[i]=m+1;
					r=r-(m+1)*t1;
					m++;
				}
				else{
					dp[i]=r/t1;
					r=r%t1;
				}
			}
			for (int i=0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}

		if (c=='R'){
			int p[n];
			for (int i=0;i<n;i++){
				cin>>p[i];
			}
			int maxm[n+1];
			maxm[0]=0;
			for (int i=1;i<=n;i++){
				maxm[i]=max(maxm[i-1],p[i-1]);
			}
			ll rank=0;
			for (int i=0;i<n;i++){
				rank+=(p[i]*dp[maxm[i]][i]);
			}
			cout<<rank<<endl;
		}
	}
	return 0;
}

