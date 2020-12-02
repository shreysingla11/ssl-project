#include<iostream>
#include<limits>
#include<queue>
#include<climits>
#include<cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<vector<int> > C;
    vector<vector<bool> > Goodness;
    for(int i=0;i<n;i++){
        vector<int> t;
        vector<bool> BOOLt;
        for(int j=0;j<n;j++){
            int cost;
            scanf("%d",&cost);
            if(cost>0){
                t.push_back(cost);
                BOOLt.push_back(false);
            }
            else{
                t.push_back(-cost);
                BOOLt.push_back(true);
            }
        }
        C.push_back(t);
        Goodness.push_back(BOOLt);
    }
    queue<pair<int,int> > q;
    vector<vector<int> > For_min;
    vector<vector<bool> > QUEUED;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        vector<int> t;
        vector<bool> BOOLt;
        for(int j=0;j<2*n+1;j++){
            t.push_back(numeric_limits<int>::max());
            BOOLt.push_back(false);
        }
        For_min.push_back(t);
        QUEUED.push_back(BOOLt);
    }
    For_min[0][n] = 0;
    q.push(make_pair(0,n));
    QUEUED[0][n] = true;
    while(!q.empty()){
        p = q.front();
        int v = p.first;
        int g = p.second;
        q.pop();
        QUEUED[v][g] = false;
        for(int j=0;j<n;j++){
            if(Goodness[v][j]){
              if(g+1<=2*n+1){
                if(For_min[v][g]+C[v][j] < For_min[j][g+1]){
                    For_min[j][g+1] = For_min[v][g]+C[v][j];
                    if(!QUEUED[j][g+1]){
                        q.push(make_pair(j,g+1));
                        QUEUED[j][g+1] = true;
                    }
                }
              }
            }
            else{
              if(g-1>=0){
                if(For_min[v][g]+C[v][j] < For_min[j][g-1]){
                    For_min[j][g-1] = For_min[v][g]+C[v][j];
                    if(!QUEUED[j][g-1]){
                        q.push(make_pair(j,g-1));
                        QUEUED[j][g-1] = true;
                    }
                }
              }
            }
        }
    }
    vector<int> min(n,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=n;j<2*n+1;j++){
            if(min[i]>For_min[i][j]){
                min[i]=For_min[i][j];
            }
        }
        if(min[i]==INT_MAX)
        {
            printf("infinity\n");
        }
        else
        {
            printf("%d\n",min[i]);
        }
    }
return 0;
}
