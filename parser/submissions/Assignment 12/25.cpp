#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
class Graph
{
public:
    int vertex; //Number of vertices 
    vector<int> *adj;  //List of people who are friends of v
    vector<int> *invadj;
    vector<int> going; //No.of friends who are definitely going
    vector<int> nogoing;
    int *threshold;
    bool *ingo;
    bool *innogo;
    bool *visited;  
    Graph(int);  
    void DFSearch(int);    
    void addEdge(int, int);  
    void DFS(int);
};  
 
Graph::Graph(int n)
{
    vertex = n;
    adj = new vector<int>[n];
    invadj = new vector<int>[n];
    visited = new bool[n];
    ingo = new bool[n];
    innogo = new bool[n];
    for(int i=0; i<n; i++) {
    	ingo[i]=false;
    	innogo[i]=false;
    }
    threshold = new int[n];
    going = vector<int>(n);
    nogoing = vector<int>(n);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    invadj[w].push_back(v);
} 

int main()
{	
	int n,i;
	int n_i,v_i;
	cin>>n;
	Graph g(n);	//Initializing a graph with n nodes
	deque<int> go, nogo;
	int surego=0, surenogo=0;
	for (i = 0; i<n; i++)
	{
		cin>>g.threshold[i];
		if (g.threshold[i]==0)
			{
				go.push_back(i);
				g.ingo[i] = true;
				surego++;
			}
		cin>>n_i;
		if ( g.threshold[i] > n_i)
		{
			nogo.push_back(i);
			g.innogo[i] = true;
			surenogo++;
		}
		for( int j=0; j<n_i; j++)
		{
			cin>>v_i;
			g.addEdge(i,v_i);
		}			
	}

	
	i=0;
	while (go.size()>0)
	{
		vector<int> invadj_i = g.invadj[go[0]];
		for (int j=0; j<invadj_i.size(); j++)
		{
			int x = invadj_i[j];
			g.going[x]++;
			if(g.going[x]>=g.threshold[x] && !g.ingo[x]){
				//cout<<x<<endl;
				go.push_back(x);
				g.ingo[x] = true;
				surego++;
			}
		}
		go.pop_front();
	}
	while(nogo.size()>0)
	{
		vector<int> invadj_i = g.invadj[nogo[0]];
		for (int j=0; j<invadj_i.size(); j++)
		{
			int x = invadj_i[j];
			g.nogoing[x]++;
			if(g.nogoing[x]>g.adj[x].size() - g.threshold[x] && !g.innogo[x]){
				//cout<<x<<endl;
				nogo.push_back(x);
				g.innogo[x] = true;
				surenogo++;
			}
		}
		nogo.pop_front();
	}
	cout<<surego<<" "<<n - surenogo<<endl;
}