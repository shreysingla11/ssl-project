#include<iostream>
#include<queue>
#include<limits>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int> > cost;
    vector<vector<bool> > is_good;
    for(int i=0;i<n;i++){
        vector<int> t;
        vector<bool> tb;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            if(temp>0){
                t.push_back(temp);
                tb.push_back(false);
            }
            else{
                t.push_back(-temp);
                tb.push_back(true);
            }
        }
        cost.push_back(t);
        is_good.push_back(tb);
    }
    queue<pair<int,int> > q;
    vector<vector<int> > label;
    vector<vector<bool> > inq;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        vector<int> t;
        vector<bool> tb;
        for(int j=0;j<2*n+1;j++){
            t.push_back(numeric_limits<int>::max());
            tb.push_back(false);
        }
        label.push_back(t);
        inq.push_back(tb);
    }
    label[0][n] = 0;
    q.push(make_pair(0,n));
    inq[0][n] = true;
    while(!q.empty()){
        p = q.front();
        int v = p.first;
        int g = p.second;
        q.pop();
        inq[v][g] = false;
        for(int w=0;w<n;w++){
            if(is_good[v][w]){
              if(g+1<=2*n+1){
                if(label[v][g]+cost[v][w] < label[w][g+1]){
                    label[w][g+1] = label[v][g]+cost[v][w];
                    if(!inq[w][g+1]){
                        q.push(make_pair(w,g+1));
                        inq[w][g+1] = true;
                    }
                }
              }
            }
            else{
              if(g-1>=0){
                if(label[v][g]+cost[v][w] < label[w][g-1]){
                    label[w][g-1] = label[v][g]+cost[v][w];
                    if(!inq[w][g-1]){
                        q.push(make_pair(w,g-1));
                        inq[w][g-1] = true;
                    }
                }
              }
            }
        }
    }
    vector<int> ans(n,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=n;j<2*n+1;j++){
            if(ans[i]>label[i][j]){
                ans[i]=label[i][j];
            }
        }
        if(ans[i]!=INT_MAX){
            cout<<ans[i]<<endl;
        }
        else{
            cout<<"infinity"<<endl;
        }
    }
return 0;
}
