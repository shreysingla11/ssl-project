#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, directed and edge-weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge;

    return graph;
}

// A function used to print the solution array
void printArr(int dist[], int n)
{
    for (int i = 0; i < n; ++i)
        cout<<dist[i]<<endl;
}

// The main function that finds shortest distances from src to all other vertices using Bellman-Ford algorithm.
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int gooddist[V];
    int good=0;
    int goodness[V];
    int var=0;
    bool changed=true;

    // Step 1: Initialize distances from src to all other vertices as INFINITE (INT_MAX)
    for (int i = 0; i < V; i++)
    {
        goodness[i]=0;
        dist[i] = INT_MAX;
        gooddist[i]= INT_MAX;
    }
    dist[src] = 0;

    // keep improving while you can
    while(changed)
    {
        changed=false;
        for (int j = 0; j < E; j++)
        {
            if(graph->edge[j].weight < 0)
                good = 1;
            else
                good = -1;
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = abs(graph->edge[j].weight);
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    changed=true;
                    dist[v] = dist[u] + weight;

                    if ( (goodness[u] + good ) >= 0 )//the path from source to v is a good path.
                    {
                        gooddist[v] = dist[u] + weight;
                        var = 0;
                    }
                    else
                    {
                        var =1;
                        break;
                    }
                    if(var == 0)
                    {
                        goodness[v] = goodness[u] + good ;
                    }
                }
        }
    }

    printArr(dist, V);

    return;
}

//main function
int main()
{
    int n;
    cin>>n;

    int V=n;
    int E=n*n;
    int temp=0;
    int edge_wt=0;

    struct Graph* graph = createGraph(V, E);

    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>edge_wt;
            temp=n*i+j+1;
            // add edge i-j
            graph->edge[temp].src = i;
            graph->edge[temp].dest = j;
            graph->edge[temp].weight = edge_wt;
        }
    }

    BellmanFord(graph, 0);

    return 0;
}
