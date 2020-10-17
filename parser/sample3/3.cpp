#include<bits/stdc++.h>
#define ll long long 
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin>>n>>t;

    vector<vector<ll>> seqs(n+1,vector<ll> (n+1));

    for(int i=1;i<=n;i++){
        seqs[n][i]=1;
    }

    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            seqs[i][j] = j*seqs[i+1][j] + seqs[i+1][j+1];
        }
    }


    while(t--){
        char ch;
        cin>>ch;

        if(ch=='R'){
            vector<ll> p(n);
            ll curr_max;
            ll r = 0;
            for(int i=0;i<n;i++){
                cin>>p[i];
                //cout<<p[i];
            }
            curr_max = p[0];
            for(int i=1;i<n;i++){
                r += p[i]*seqs[i+1][curr_max+1];
                curr_max = max(p[i],curr_max);
            }
            cout<<r<<endl;
            
        }
        else
        {
            vector<int> p;
            ll r;
            cin>>r;
            printf("0 ");
            ll curr_max = 0;
            for(int i=2;i<=n;i++){
                ll temp = r/(seqs[i][curr_max+1]);
                if(temp<=curr_max){
                    printf("%lld ",temp);
                    r = r-temp*(seqs[i][curr_max+1]);
                }
                else{
                    printf("%lld ",curr_max+1);
                    r = r - (curr_max + 1)*seqs[i][curr_max+1];
                    curr_max++;
                }
            }
            printf("\n");

        }
        

    }
    
    return 0;
}