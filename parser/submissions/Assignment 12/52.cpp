#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void go_go_go(int dude, stack<int> &def_go, vector<int> total, vector<int> t, vector<int> &friend_go, vector<int> &go_bool, vector<vector<int> > predecessors){
    int pre_dude;
    go_bool[dude] = 1;
    def_go.push(dude);
    for(int i = 0 ; i < predecessors[dude].size() ; i++){
        pre_dude = predecessors[dude][i];
        if(go_bool[pre_dude]==1 || go_bool[pre_dude]==-1){continue;}
        else{
            friend_go[pre_dude] += 1;
            if(friend_go[pre_dude]>=t[pre_dude]){
                go_go_go(pre_dude,def_go,total,t,friend_go,go_bool,predecessors);
            }
        }
    }
    return;
};
void never_go(int dude, stack<int> &def_no_go, vector<int> total, vector<int> t, vector<int> &friend_not_go, vector<int> &go_bool, vector<vector<int> > predecessors){
    int pre_dude;
    go_bool[dude] = -1;
    def_no_go.push(dude);
    for(int i = 0 ; i < predecessors[dude].size() ; i++){
        pre_dude = predecessors[dude][i];
        if(go_bool[pre_dude]==1 || go_bool[pre_dude]==-1){continue;}
        else{
            friend_not_go[pre_dude] += 1;
            if(total[pre_dude] - friend_not_go[pre_dude] < t[pre_dude]){
                never_go(pre_dude,def_no_go,total,t,friend_not_go,go_bool,predecessors);
            }
        }
    }
    return;
};

int main(){

    int N,n,dude,exact_go,exact_not_go;
    cin >> N;
    n=N;
    vector<vector<int> > predecessors;
    vector<int> total (N);
    vector<int> t (N);
    vector<int> go_bool (N);
    vector<int> friend_go (N);
    vector<int> friend_not_go (N);
    stack<int> def_go;
    stack<int> def_no_go;
    vector<int> temp;
    while(N--){
        predecessors.push_back(temp);
    }
    for(int i = 0 ; i < n ; i++){
        cin>>t[i]>>total[i];
        for(int j = 0 ; j < total[i] ; j++){
            cin>>dude;
            predecessors[dude].push_back(i);
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(go_bool[i]==0){
            if(t[i]==0){
                go_go_go(i,def_go,total,t,friend_go,go_bool,predecessors);
            }
            if(t[i]>total[i]){
                never_go(i,def_no_go,total,t,friend_not_go,go_bool,predecessors);
            }
        }
    }

    exact_go = def_go.size();
    exact_not_go = def_no_go.size();
   /* while (!def_go.empty())
  {
     cout << ' ' << def_go.top();
     def_go.pop();
  }
  cout<<endl;
  while (!def_no_go.empty())
  {
     cout << ' ' << def_no_go.top();
     def_no_go.pop();
  }
cout<<endl;*/
    cout << exact_go << " " << (n-exact_not_go) << endl;

    return 0;
}
