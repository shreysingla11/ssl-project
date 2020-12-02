#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;

struct pair1
{
    int v;
    int g;
};

int mod(int a)
{
    if(a>=0)return a;
    else
    {
        return (-1)*a;
    }
}

int main()
{
    vector<vector<int> > status;
    vector<vector<int> > A;
    vector<vector<int> > C;//C[i,j]:=cost of i-->j
    int n;
    //cin>>n;
    scanf("%d",&n);
    A.resize(n);
    status.resize(n);
    C.resize(n);
    //cout<<" bscgW"<<endl;
    for(int i=0; i<n; i++)
    {
        C[i].resize(n);
        A[i].resize(4*n+1);//A[i][j] gives origA[i][j-2n]
        status[i].resize(4*n+1);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4*n+1; j++)
        {
            A[i][j]=INFINITY;
            status[i][j]=0;
        }
    }
    //cout<<" bscgW"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int var;
            scanf("%d",&var);
            C[i][j]=var;
            //cin>>C[i][j];
        }
    }

    queue<pair1> Q;
    pair1 tmp,node;

    for(int g=0; g<=2*n; g++)
    {
        A[0][g]=0;
        status[0][g]=1;
        tmp.v=0;
        tmp.g=g;
        Q.push(tmp);
    }

    //cout<<" bscgW"<<endl;

    int v,g;
    while(!Q.empty())
    {
        node=Q.front();
        Q.pop();
        v=node.v;
        g=node.g;
        status[v][g]=0;
        for(int u=0; u<n; u++)
        {
            if(C[v][u]<0)
            {
                if(g+1<4*n+1)
                {
                    if(A[v][g]+mod(C[v][u])<A[u][g+1])
                    {
                        A[u][g+1]=A[v][g]+mod(C[v][u]);
                        if(status[u][g+1]==0)
                        {
                            status[u][g+1]=1;
                            tmp.v=u;
                            tmp.g=g+1;
                            Q.push(tmp);
                        }
                    }
                }
            }
            else
            {
                if(g-1>=0)
                {
                    if(A[v][g]+mod(C[v][u])<A[u][g-1])
                    {
                        A[u][g-1]=A[v][g]+mod(C[v][u]);
                        if(status[u][g-1]==0)
                        {
                            status[u][g-1]=1;
                            tmp.v=u;
                            tmp.g=g-1;
                            Q.push(tmp);
                        }
                    }
                }
            }
        }
    }

    int var;
    for(int i=0; i<n; i++)
    {
        //if(A[i][2*n]==-1){
         // cout<<"infinity"<<endl;
       // }
        //else{
          // cout<<A[i][2*n]<<endl;
        //}
        if(A[i][2*n]>=900000000){
          printf("infinity\n");
        }
        else{
            var=A[i][2*n];
            printf("%d\n",var);
           //cout<<A[i][2*n]<<endl;
        }
    }

    return 0;
}
