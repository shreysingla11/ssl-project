#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int maxi=1000000000;
class vertex
{
public:
    int val;
    vector<int> edge;
    vector<int> cost;
    vector<bool> flag;

    vertex(int n)
    {
        edge.resize(n);
        cost.resize(4*n+1,maxi);
        flag.resize(4*n+1,false);
    }
};


int main()
{
    int n,temp,mini;
    cin>>n;

    vertex node(n);
    vector<vertex> A(n,node);

    for(int i=0; i<n; i++)
    {
        A[i].val=i;
        for(int j=0; j<n; j++)
        {
            scanf("%d",&temp);
            A[i].edge[j]=temp;
        }
    }

    pair<int,int> p;
    p=std::make_pair(0,2*n);
    A[0].flag[2*n]=true;
    A[0].cost[2*n]=0;

    queue< pair<int,int> > Q;
    Q.push(p);
    int a,b,c,e;

    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        a=p.first;
        b=p.second;
        A[a].flag[b]=false;
        for(int i=0; i<n; i++)
        {
            c=A[a].edge[i];
            if(c>0)
                e=-1;
            else
                e=1;
            if(b+e <= 4*n)
            {
                if(A[i].cost[b+e] > A[a].cost[b]+abs(c))
                {
                    A[i].cost[b+e]=A[a].cost[b]+abs(c);
                    if(!A[i].flag[b+e])
                    {
                        p=std::make_pair(i,b+e);
                        Q.push(p);
                        A[i].flag[b+e]=true;
                    }
                }
            }

        }

    }
    for(int i=0; i<n; i++)
    {
        mini=maxi;
        for(int j=2*n; j<4*n+1; j++)
        {
            mini=min(mini,A[i].cost[j]);
        }
        if(mini!=maxi)
            printf("%d\n",mini);
        else
            printf("INFINITY\n");
    }
}
