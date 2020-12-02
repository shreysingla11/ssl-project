#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
struct Edge
{
    int src, dest, weight,gb;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =  new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}


void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int good[V];
    for (int i = 0; i < V; i++)
    {
        dist[i]   = INT_MAX;
        good[i]=-INT_MAX;
    }
    dist[src] = 0;
    good[src] = 0;
    while(true)
    {
        int changes=0;
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            int gb = graph->edge[j].gb;
            if(good[u]+ gb > good[v])
            {
                if(good[v]>=0)
                {
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        good[v]=good[u]+gb;
                        changes++;
                    }
                }
                else
                {
                    dist[v] = dist[u] + weight;
                    good[v]=good[u]+gb;
                    changes++;
                }
            }
        }
        if(changes==0)
        {
            break;
        }
    }

    for(int i=0; i<V; i++)
    {
    if(good[i]>=0)
    {cout<<dist[i]<<endl;}
    else
    {cout<<"infinity"<<endl;}
    }
    return;
}

int main()
{
    int V,E;
    cin>>V;
    E=V*V;
    struct Graph* graph = createGraph(V, E);
    E=0;
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            int temp;
            cin>>temp;
            graph->edge[E].src = i;
            graph->edge[E].dest = j;
            if(temp<0)
            {
                graph->edge[E].weight = -temp;
                graph->edge[E].gb = 1;
            }
            else
            {
                graph->edge[E].weight = temp;
                graph->edge[E].gb = -1;
            }

            E++;
        }
    }
    BellmanFord(graph, 0);
    return 0;
}
