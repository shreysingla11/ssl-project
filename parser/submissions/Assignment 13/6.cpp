#include<iostream>
#include<queue>
//#include<vector>
#include<cstdio>
#include<cmath>
#include<utility>
#include<limits.h>
using namespace std;
int main()
{
    int n,a;
    scanf("%d",&n);
    queue<pair<int,int> > Q;
    int *dist = new int[ (2*n+1)*n ];
    bool *inQ = new bool[ (2*n+1)*n ];
    int *C = new int[ n*n ];
    // C ij matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&C[i*n + j]);
        }
    }
    //distance[vertex][goodness]
    for(int v=0;v<n;v++)
    {
        for(int g=0;g<=2*n;g++)
        {
            dist[ v*(2*n+1) + g ] = INT_MAX;
            inQ[ v*(2*n+1) + g ] = false;
        }
    }
    dist[n]=0;
    Q.push(make_pair(0,n));
    inQ[n]=true;
    while( !Q.empty() )
    {
        pair<int,int> u=Q.front();
        Q.pop();
        inQ[ u.first*(2*n+1) + u.second] =false;
        // dist[goodness][vertex]
        for(int v=0;v<n;v++)
        {//loop for neighbours
            if( C[u.first*n+v] < 0) //good edge
            {
                if( dist[u.first*(2*n+1) +u.second] - C[u.first*n+v] < dist[v*(2*n+1) + u.second + 1] )
                {
                    dist[v*(2*n+1) + u.second + 1] = dist[u.first*(2*n+1) +u.second] - C[u.first*n+v];
                    if( !inQ[v*(2*n+1) + u.second + 1]  )
                    {
                        Q.push(make_pair(v,u.second + 1));
                        inQ[v*(2*n+1) + u.second + 1] = true;
                    }
                }
            }
            else //bad edge
            {
                if( dist[u.first*(2*n+1) +u.second] + C[u.first*n+v] < dist[v*(2*n+1) + u.second - 1] )
                {
                    dist[v*(2*n+1) + u.second - 1] = dist[u.first*(2*n+1) +u.second] + C[u.first*n+v];
                    if( !inQ[v*(2*n+1) + u.second - 1]  )
                    {
                        Q.push(make_pair(v,u.second - 1));
                        inQ[v*(2*n+1) + u.second - 1] = true;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int min=INT_MAX;
        for(int g=n;g<=2*n;g++)
        {
            if( dist[i*(2*n+1)+g] < min )
                min = dist[i*(2*n+1)+g];
        }
        if( min == INT_MAX )
            printf("%s\n","infinity");
        else
            printf("%d\n",min);
    }
    return 0;
}

