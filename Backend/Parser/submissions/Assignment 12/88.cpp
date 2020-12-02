#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
    public:
    int V;    // No. of vertices
    vector<int> *adj;    // Pointer to an array containing adjacency lists
    vector<int> *inv_adj;
    vector<int> go;    // Pointer to an array containing adjacency lists
    vector<int> nogo;
    vector<int> threshold;
    vector<int> num_Friends;
    vector<bool> go_bool;
    vector<bool> nogo_bool;
    Graph(int V);   // Constructor
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
    void setThreshold(int v,int t);
    void setNumFriends(int v,int n);
    void addinvEdge(int v, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
    inv_adj = new vector<int>[V];
    go_bool.assign(V,false);
    nogo_bool.assign(V,false);
    go.assign(V,0);
    nogo.assign(V,0);
    threshold.assign(V,0);
    num_Friends.assign(V,0);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::addinvEdge(int v, int w)
{
    inv_adj[v].push_back(w); // Add w to v’s invlist.
}

void Graph::setThreshold(int v,int t)
{
    threshold[v] = t;
}

void Graph::setNumFriends(int v,int n)
{
    num_Friends[v] = n;
}

int main()
{
    int n;
    int T_i,N_i;
    int f_num;
    int i,j,k,isize;
    cin >> n;
    Graph Network(n);

    for(i = 0 ; i < n ; i++)
    {
        cin >> T_i >> N_i;
        Network.setThreshold(i,T_i);
        Network.setNumFriends(i,N_i);
        
        for(j = 0 ; j < N_i ; j++)
        {
            cin >> f_num;
            Network.addEdge(i,f_num);
            Network.addinvEdge(f_num,i);
        }
    }

    vector<int> go_list,nogo_list;
    int gosize = 0,nogosize = 0;
    for(i = 0 ; i < n ; i++)
    {
        if(Network.threshold[i] == 0)
        {
            go_list.push_back(i);
            Network.go_bool[i] = true;
            gosize++;
            continue;
        }

        if(Network.threshold[i] > Network.num_Friends[i])
        {
            nogo_list.push_back(i);
            Network.nogo_bool[i] = true;
            nogosize++;
            continue;
        }
    }
    {
        cout << go_list[i] << endl ;
    }
    cout << endl;
    for(i = 0 ; i < nogosize ; i++)
    {
        cout << nogo_list[i] << endl ;
    }
    gosize = go_list.size();
    nogosize = nogo_list.size();
    int X;
    for (k = 0 ; k < gosize ; k++)
    {
        i = go_list[k];
        isize = Network.inv_adj[i].size();
        for(j = 0 ; j < isize ; j++)
        {
            X = Network.inv_adj[i][j];
            //cout << endl << X << endl;
            if(Network.go_bool[X]){continue;}
            else{Network.go[X] = Network.go[X] + 1;
            if(Network.go[X] >= Network.threshold[X])
            {
                go_list.push_back(X);
                gosize = go_list.size();
            }}
        }
    }

    for (k = 0 ; k < nogosize ; k++)
    {
        i = nogo_list[k];
        cout << "3";
        isize = Network.inv_adj[i].size();
        for(j = 0 ; j < isize ; j++)
        {
            X = Network.inv_adj[i][j];
            if(Network.nogo_bool[X]){continue;}
            else{
            	Network.nogo[X] = Network.nogo[X] + 1;
            cout << "1";
            if(Network.num_Friends[X]-Network.nogo[X] < Network.threshold[X])
            {	
            	cout << "2";
                nogo_list.push_back(X);
                nogosize = nogo_list.size();
            }}
        }
    }
   /* for(i = 0 ; i < gosize ; i++)
    {
        cout << go_list[i] << endl ;
    }
    cout << endl;
    for(i = 0 ; i < nogosize ; i++)
    {
        cout << nogo_list[i] << endl ;
    }
    //cout << endl << Network.threshold[2] << Network.go[2] << Network.nogo[2] ;*/
    cout << gosize << " " << n - nogosize << endl;
}
