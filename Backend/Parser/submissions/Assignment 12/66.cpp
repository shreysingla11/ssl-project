// C++ program to print DFS traversal for a given given graph
#include<iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
public:
    int V;
    vector< vector<int> > adj;
    vector< vector<bool> > edgeVisited;
    vector< vector<int> > pre;
    vector<int> threshold;
    vector<int> going;
    vector<int> notGoing;
    vector<int> FriendsGoing;
    vector<int> FriendsNotGoing;

    Graph(int v){
        V = v;
        vector<int> temp;
        vector<bool> temp2;
        adj.assign(v,temp);
        pre.assign(v,temp);
        edgeVisited.assign(v,temp2);
        threshold.assign(v,0);
        FriendsGoing.assign(v,0);
        //FriendsNotGoing.assign(v,0);
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
        pre[w].push_back(v);
        edgeVisited[w].push_back(false);
    }

    void DFSUtil(int v, bool visited[]){
        /*visited[v] = true;
        cout << v << " ";
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
            if(!visited[*i])
                DFSUtil(*i, visited);*/

    }

    void DFS(int start){
        /*bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                DFSUtil(i, visited);*/
        //if(edgeVisited[start]==true){return;}
        //cout<<"Inside DFS  : "<<start<<endl;
        int index=0;
        for(vector<int>::iterator it= pre[start].begin(); it!= pre[start].end(); index++,it++){
            //cout<<"hi ";
            if(!edgeVisited[start][index]){
                //cout<<"edge ";
                FriendsGoing[*it]++;
                edgeVisited[start][index]=true;
                if(FriendsGoing[*it]>=threshold[*it]){


                    vector<int>::iterator iter;
                    iter = find (going.begin(), going.end(), *it);
                    if(iter == going.end()){
                        going.push_back(*it);
                    }
                     DFS(*it);
                }
            }

        }
        return;

    }

};

int main()
{
    int nodes,t,nFriends,fNo;
    cin>> nodes;
    Graph G(nodes);

    for(int i=0; i<nodes; i++){
        cin>> t>>nFriends;
        if(t==0){
            G.going.push_back(i);
            for(vector<int>::iterator it= G.pre[i].begin(); it!=G.pre[i].end(); it++){
                G.FriendsGoing[*it]+=1;
                if(G.FriendsGoing[*it]>= G.threshold[*it]){
                    G.going.push_back(*it);
                }
            }
        }
        if(t>nFriends){
            G.notGoing.push_back(i);

        }

        G.threshold[i]=t;

        for(int j=0; j<nFriends ; j++){
            cin>>fNo;
            G.addEdge(i,fNo);
        }
    }


    for(int i=0; i< G.going.size(); i++) {
        G.DFS(G.going[i]);

    }

    int notGoing=0;
    for(int i=0; i< nodes; i++) {
        if(G.threshold[i]>G.FriendsGoing[i]){
            notGoing++;
        };
    }


    cout<< G.going.size()<<" " << nodes - notGoing <<endl;
    return 0;
}
