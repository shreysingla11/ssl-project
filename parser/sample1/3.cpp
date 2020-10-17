#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
 
using namespace std;
vector<ll> ff;


void print(vector<ll> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

vector<ll> getLeft(vector<ll> a){
    
    int n = a.size();
    vector<ll> f(n);
    f[0] = -1;

    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        while ((j >= 0) && (a[j]<a[i]))  
            j = f[j];

        f[i] = j;
    }

    return f;
}

vector<ll> getRight(vector<ll> a){
    
    int n = a.size();
    vector<ll> f(n);
    f[n-1] = n;

    for (int i = n-2; i >= 0; i--)
    {
        int j = i+1;
        while ((j < n) && (a[j]<a[i]))  
            j = f[j];

        f[i] = j;
    }

    return f;
}

vector<ll> getLeftgt(vector<ll> a){
    
    int n = a.size();
    vector<ll> f(n);
    f[0] = -1;

    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        while ((j >= 0) && (a[j]<=a[i]))  
            j = f[j];

        f[i] = j;
    }

    return f;
}

vector<ll> getRightls(vector<ll> a){
    
    int n = a.size();
    vector<ll> f(n);
    f[n-1] = n;

    for (int i = n-2; i >= 0; i--)
    {
        int j = i+1;
        while ((j < n) && (a[j]>=a[i]))  
            j = f[j];

        f[i] = j;
    }

    return f;
}


ll solve2(int start,int end){
    if(start==end){
        return 0;
    }

    if(end-start == 1){
        return 1;
    }

    ll num = 0;
    int mid  = (start+end)/2;
    num += solve2(start,mid) + solve2(mid+1,end);
    //cout<<"Num 1"<<num<<endl;
    ll lc=0,rc=0,lmin=ff[mid],lmax=ff[mid],rmax=ff[mid],rmin=ff[mid];
    vector<int> rmaxa,rmina;
    for(int j=mid;j<end;j++){

        rmax = max(rmax,ff[j]);
        rmin = min(rmin,ff[j]);
        if(rmax==ff[j]){
            rmaxa.push_back(rmax);
            rmina.push_back(rmin);
        }
    }
    for(int i=mid;i>=start;i--){
        lmin = min(lmin,ff[i]);
        lmax = max(lmax,ff[i]);
        if(ff[i] == lmin){
            int temp1 = lower_bound(rmaxa.begin(),rmaxa.end(),lmax)-rmaxa.begin();
            int temp2 = upper_bound(rmina.begin(),rmina.end(),lmin,greater<int>()) - rmina.begin();
            //cout<<temp1<< " "<<temp2<<endl;
            num += max(temp2 -temp1,0);
        }
           
    }
    return num;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    ff = vector<ll> (n);

    for(int i=0;i<n;i++){
        cin>>ff[i]; 
    }

    {
        vector<ll> lg = getLeft(ff);
        vector<ll> rg = getRight(ff);

        vector<ll> num_seq(n);

        for(int i=0;i<n;i++){
            num_seq[i] = (i-lg[i])*(rg[i]-i);
        }

        print(num_seq);
    }
    /////////////////////////////////
    cout<<solve2(0,n)<<endl;


    return 0;
}