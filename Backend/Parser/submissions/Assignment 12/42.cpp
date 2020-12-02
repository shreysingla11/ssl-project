#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld",&n);
    vector<long long> T;//Threshold values
    vector<vector<long long> > v(n,T);
    T.resize(n);
    vector<long long> G(n);
    vector<long long> N2(n);
    vector<int> B(n);//1: going ; 0: not going 2: not decided
    queue<long long> q;
    long long going = 0;
    long long notgoing = 0;
    for(long long i=0;i<n;i++){
        vector<int> templ;
        long long temp;
        scanf("%lld",&temp);
        T[i] = temp;
        scanf("%lld",&temp);
        for(long long j=0;j<temp;j++){
            long long temp2;
            scanf("%lld",&temp2);
            v[temp2].push_back(i);
        }
        if(T[i]==0){G[i]=-1;B[i]=1;q.push(i);going++;}
        else{
            if(T[i]>temp){N2[i]=-1;B[i]=0;q.push(i);notgoing++;}
            else{N2[i]=temp;B[i]=2;G[i]=0;}
        }
    }
    /*
    for(long long i=0;i<n;i++){
        for(long long j=0;j<v[i].size();j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }

    while(!q.empty()){
        long long temp = q.front();
        q.pop();
        cout<<temp<<" "<<B[temp]<<endl;
    }
    cout<<"adsca"<<endl;
    for(int i=0;i<B.size();i++){
        cout<<i<<B[i]<<endl;
    }
    */
    while(!q.empty()){
        long long temp = q.front();
        q.pop();
        if(B[temp]==true){
            //for each predecessor w
            long long l = v[temp].size();
            for(long long i=0;i<l;i++){
                long long w = v[temp][i];
                if(B[w]==2){
                    G[w]++;
                    if(G[w]>=T[w]){B[w]=1;q.push(w);going++;}
                }
            }
        }
        else{
            //for each predecessor w
            long long l = v[temp].size();
            for(long long i=0;i<l;i++){
                long long w = v[temp][i];
                if(B[w]==2){
                    N2[w]--;
                    if(N2[w]<T[w]){B[w]=0;q.push(w);notgoing++;}
                }
            }
        }
    }
    /*
    for(int i=0;i<B.size();i++){
        cout<<i<<B[i]<<endl;
    }
    */
    cout<<going<<" "<<(B.size()-notgoing)<<endl;
    return 0;
}
