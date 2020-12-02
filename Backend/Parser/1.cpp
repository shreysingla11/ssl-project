#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(ll A[],ll n){
	for (int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}


void f(ll a[],ll N,ll ans[]){

	if (N==1){
		ans[0]=a[0];
		return;
	}

	ll a1[N/2];
	ll a2[N/2];
	ll ans1[N/2];
	ll ans2[N/2];

	for (ll i=0;i<N/2;i++){
		a1[i]=a[i];
	}

	for (ll i=N/2;i<N;i++){
		a2[i-N/2]=a[i];
	}

	f(a1,N/2,ans1);
	f(a2,N/2,ans2);

	for (ll i=0;i<N/2;i++){
		ans[i]=ans1[i];
	}

	for (ll i=N/2;i<N;i++){
		ans[i]=ans2[i-N/2]+ans1[i-N/2];
	}

}

int p=1; //How's life

/*
void f(ll a[], ll start, ll end, ll ans[]){

	if (start==end-1){
		ans[0]=a[start];
		return;
	}

	ll mid=(start+end)/2;

	ll temp1[mid-start];
	ll temp2[mid-start];

	f(a,start,mid,temp1);
	f(a,mid,end,temp2);

	//print(temp1,mid-start);
	//print(temp2,mid-start);

	for (ll i=start;i<mid;i++){
		ans[i-start]=temp1[i-start];
	}

	for (ll i=mid;i<end;i++){
		ans[i-start]=temp1[i-mid]+temp2[i-mid];
	}
}
*/
/*
void g(ll a[], ll b[], ll start, ll end, ll ans[]){

	if (start==end-1){
		ans[0]=a[start];
		//ans2[0]=a[start];
		return;
	}

	ll mid=(start+end)/2;

	ll temp1[mid-start];
	ll temp2[mid-start];
	//ll temp3[mid-start];
	//ll temp4[mid-start];
	g(a,b,start,mid,temp1);
	g(a,b,mid,end,temp2);

	for (ll i=start;i<mid;i++){
		ans[i-start]=temp1[i-start];
		//ans2[i-start]=temp2[i-start];
	}

	for (ll i=mid;i<end;i++){
		if (b[i]==0){
			ans[i-start]=temp2[i-mid]+temp1[i-mid];
		}
		else{
			ans[i-start]=a[i];
		}
	}
}
*/

void g(ll a[], ll N, ll ans[]){

	if (N==1){
		ans[0]=a[0];
		return;
	}

	ll a1[N/2];
	ll a2[N/2];
	ll ans1[N/2];
	ll ans2[N/2];

	for (ll i=0;i<N/2;i++){
		a1[i]=a[i];
	}

	for (ll i=N/2;i<N;i++){
		a2[i-N/2]=a[i]-a[i-N/2];
	}

	g(a1,N/2,ans1);
	g(a2,N/2,ans2);

	for (ll i=0;i<N/2;i++){
		ans[i]=ans1[i];
	}

	for (ll i=N/2;i<N;i++){
		ans[i]=ans2[i-N/2];
	}

}

void k(ll a[], ll b[], ll N, ll ans[]){
	if (N==1){
		ans[0]=a[0];
		return;
	}

	ll a1[N/2];
	ll a2[N/2];
	ll ans1[N/2];
	ll ans2[N/2];
	ll b1[N/2];
	ll b2[N/2];

	for (ll i=0;i<N/2;i++){
		a1[i]=a[i];
		b1[i]=b[i];
	}

	for (ll i=N/2;i<N;i++){
		a2[i-N/2]=a[i];
		b2[i-N/2]=b[i];
	}

	k(a1,b1,N/2,ans1);

	for (ll i=0;i<N/2;i++){
		if (b2[i]==0){
			a2[i]=a[N/2+i];
		}
		else{
			a2[i]=a[N/2+i]-ans1[i];
		}
	}

	k(a2,b2,N/2,ans2);

	for (ll i=0;i<N/2;i++){
		ans[i]=ans1[i];
	}

	for (ll i=N/2;i<N;i++){
		ans[i]=ans2[i-N/2]+ans1[i-N/2];
	}

}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	//srand(time(0));
	ll n;
	cin>>n;
	//n=20;
	ll N=(1<<n);
	//cout<<N<<endl;

	ll a[N];
	ll b[N];
	for (ll i=0;i<N;i++){
		//a[i]=rand()%10;
		cin>>a[i];
	}
	for (ll i=0;i<N;i++){
		cin>>b[i];
	}

	ll ans1[N];
	ll temp1[N];
	ll temp2[N];
	//ll ans2[N];
	
	f(a,N,ans1);
	//k(a,0,N,ans2);
	k(a,b,N,temp1);
	g(temp1,N,temp2);

	//print(ans1,N);
	//print(temp1,N);
	
	for (int i=0;i<N;i++){
		cout<<ans1[i]<<" ";
	}
	cout<<endl;
	//print(temp1,N);
	//print(temp2,N);
	//print(b,N);
	for (int i=0;i<N;i++){
		if (b[i]==0){
			cout<<temp1[i]<<" ";
		}
		else{
			cout<<temp2[i]<<" ";
		}
	}
	
	cout<<endl;
	//print(ans2,N);
	//print(ans2,N);

	return 0;
}