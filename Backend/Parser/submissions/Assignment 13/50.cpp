#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<climits>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int> > C(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    queue<pair<int,int> > q;
    vector<vector<int> > inque(n, vector<int>((2*n)+1,-1));
    vector<vector<int> > label(n, vector<int>((2*n)+1,INT_MAX));
    label[0][n]=0;
    q.push(make_pair(0,n));
    inque[0][n]=1;
    while(!q.empty())
    {
        pair<int,int> v = q.front();
        q.pop();
        int v1 = v.first;
        int v2 = v.second;
        inque[v1][v2]=-1;
        for(int i=0; i<n; i++)
        {

            if(C[v1][i]<0)
            {
                if(v2<2*n)
                {
                    if( label[v1][v2] - C[v1][i] < label[i][v2+1])
                    {
                        label[i][v2+1] = label[v1][v2] - C[v1][i];
                        if(inque[i][v2+1]==-1)
                        {
                            q.push(make_pair(i,v2+1));
                            inque[i][v2+1]=1;
                        }
                    }
                }
            }
            else if(C[v1][i]>0)
            {
                if(v2>0)
                {
                    if( label[v1][v2] + C[v1][i] < label[i][v2-1])
                    {
                        label[i][v2-1] = label[v1][v2] + C[v1][i];
                        if(inque[i][v2-1]==-1)
                        {
                            q.push(make_pair(i,v2-1));
                            inque[i][v2-1]=1;
                        }
                    }
                }
            }
        }
    }
    vector<int> ans(n,INT_MAX);
    for(int i=0; i<n; i++)
    {
        for(int j=n; j<2*n+1; j++)
        {
            if(label[i][j]<ans[i])
            {
               ans[i] = label[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",ans[i]);
    }
}

