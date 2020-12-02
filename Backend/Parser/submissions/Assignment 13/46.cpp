#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
    bool good;
};

// a structure to represent a connected, directed and
// weighted graph
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
    struct Graph* graph =
        (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge =
        (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int walk[], int n)
{
    //printf("Vertex Distance from Source\n");
    printf("%d\n", dist[0]);
    for (int i = 1; i < n; ++i)
    {
        if(walk[i]==1&&dist[i]!=INT_MAX)
        {
            printf("%d\n", dist[i]);
        }
        else
        {
            printf("infinity\n");
        }
    }
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm. The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int good[V];
    int bad[V];
    int walk[V];

    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        good[i] = 0;
        bad[i] = 0;
    }
    dist[src] = 0;
    //walk[0]=1;
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            bool goo = graph->edge[j].good;
            if(goo)
            {
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]&&good[v]+1>bad[v])
                {
                    dist[v] = dist[u] + weight;
                    if(goo)
                    {
                        good[v]++;
                    }
                    else
                    {
                        bad[v]++;
                    }
                }
            }
            else
            {
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]&&good[v]>bad[v]+1)
                {
                    dist[v] = dist[u] + weight;
                    if(goo)
                    {
                        good[v]++;
                    }
                    else
                    {
                        bad[v]++;
                    }
                }
            }
        }
    }
    for(int i=1; i <=V-1; i++)
    {
       // cout<<good[i]<<"\n"<<bad[i]<<"\n";
        if(good[i]>=bad[i])
        {
            walk[i]=1;
        }
    }

    printArr(dist, walk, V);

    return;
}

// Driver program to test above functions
int main()
{
    int n,k,coun=0;
    cin>>n;
    /* Let us create the graph given in above example */
    int V = n; // Number of vertices in graph
    int E = n*n; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            graph->edge[coun].src = i;
            graph->edge[coun].dest = j;
            cin>>k;
            if(k<0)
            {
                graph->edge[coun].weight = -k;
                graph->edge[coun].good = true;
            }
            else
            {
                graph->edge[coun].weight = k;
                graph->edge[coun].good = false;
            }
            coun++;
        }
    }
    /*int V = 7; // Number of vertices in graph
    int E = 7; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;
    graph->edge[0].good = false;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 1;
    graph->edge[1].good = false;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 2;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 1;
    graph->edge[2].good = false;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 3;
    graph->edge[3].dest = 4;
    graph->edge[3].weight = 1;
    graph->edge[3].good = true;

    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 4;
    graph->edge[4].dest = 5;
    graph->edge[4].weight = 1;
    graph->edge[4].good = true;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 5;
    graph->edge[5].dest = 6;
    graph->edge[5].weight = 1;
    graph->edge[5].good = true;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 6;
    graph->edge[6].dest = 0;
    graph->edge[6].weight = 1;
    graph->edge[6].good = true;
    */

    BellmanFord(graph, 0);

    return 0;
}
