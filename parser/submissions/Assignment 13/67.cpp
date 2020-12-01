#include<iostream>
#include<fstream>
#include <limits.h>
using namespace std;

// this uses code from GeeksForGeeks.com, modified.

struct Edge
{
    int src, dest, weight, goodness;
};

struct Graph
{
    int V, E;

    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =
         (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge =
       (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

void printArr(int dist[], int n)
{
    for (int i = 0; i < n; ++i)
        if(dist[i]==INT_MAX){cout<<"infinity"<<endl;}
        else {cout<<dist[i]<<endl;}
}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int ng=0,nb=0,nc;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;

    while(nc!=0)
    {   nc=0;
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            int goodness =graph->edge[j].goodness ;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]&& ng-nb<=2*V && ng-nb>=-2*V){
                dist[v] = dist[u] + weight;
                if (goodness ==1){
                    ng++;
                }
                else{
                    nb++;
                }
                nc++;
            }


        }
    }

    printArr(dist, V);

    return;
}

int main()
{
	int V ;
	int E ;
	int i,j,k,e=0;

	cin>>V;
	E=V*V;
	struct Graph* graph = createGraph(V, E);

    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++) {
            cin>>k;

            graph->edge[e].src = i;
            graph->edge[e].dest = j;
            if (k>0){
                graph->edge[e].weight = k;
                graph->edge[e].goodness  = 0;
            }
            else{
                graph->edge[e].weight = -k;
                graph->edge[e].goodness  = 1;
            }
            e++;

        }
    }

	BellmanFord(graph, 0);

	return 0;
}

