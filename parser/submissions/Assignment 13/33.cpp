#include<iostream>
#include<fstream>
#include <limits.h>
using namespace std;
struct Edge
{
    int src, dest, weight,g;
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
    int good=0,bad=0,nc;
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
            int g=graph->edge[j].g;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]&& good-bad<=2*V && good-bad>=-2*V){
                dist[v] = dist[u] + weight;
                if (g==1){
                    good++;
                }
                else{
                    bad++;
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
	int i,j,w,e=0;

	cin>>V;
	E=V*V;
	struct Graph* graph = createGraph(V, E);

    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++) {
            cin>>w;

            graph->edge[e].src = i;
            graph->edge[e].dest = j;
            if (w>0){
                graph->edge[e].weight = w;
                graph->edge[e].g = 0;
            }
            else{
                graph->edge[e].weight = -w;
                graph->edge[e].g = 1;
            }
            e++;

        }
    }

	BellmanFord(graph, 0);

	return 0;
}

