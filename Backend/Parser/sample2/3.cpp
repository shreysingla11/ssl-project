#include<bits/stdc++.h>
#define ll long long 
 
using namespace std;

ll k;

ll J(ll n){
    if(n==1)
        return 0;
    if(n>=k){
        ll t = J(n-n/k);
        if(t<n%k)
            return n-n%k+t;
        return (((t-n%k)/(k-1))*k + (t-n%k)%(k-1))%n;
    }
    ll t = J(n-1);
    return (k%n+t)%n;
}

int main(){
    ll n;
    cin>>n>>k;
    ll ans = J(n)+1;
    cout<<ans<<endl;
    return 0;
}