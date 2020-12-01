#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int> > C(n);
    vector<vector<int> > label(n);
    vector<vector<bool> > present(n);
    int temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {

            scanf("%d",&temp);
            C[i].push_back(temp);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*n+1; j++)
        {
            label[i].push_back(-1);
            present[i].push_back(0);
        }
    }
    label[0][n]=0;
    present[0][n]=1;
    queue<pair<int,int> > Q;
    Q.push(make_pair(0,n));
    pair<int,int> p;
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        int v=p.first;
        int g=p.second;
        present[v][g]=0;
        for(int i=0; i<n; i++)
        {
            if(C[v][i]>0)
            {
                if(label[i][g-1]!=-1)
                {
                    if(label[v][g]+C[v][i]<label[i][g-1])
                    {
                        label[i][g-1]=label[v][g]+C[v][i];
                        if(present[i][g-1]==0)
                        {
                            present[i][g-1]=1;
                            Q.push(make_pair(i,g-1));
                        }
                    }
                }
                else
                {
                    label[i][g-1]=label[v][g]+C[v][i];
                    present[i][g-1]=1;
                    Q.push(make_pair(i,g-1));
                }
            }
            else
            {
                if(label[i][g+1]!=-1)
                {
                    if(label[v][g]-C[v][i]<label[i][g+1])
                    {
                        label[i][g+1]=label[v][g]-C[v][i];
                        if(present[i][g+1]==0)
                        {
                            present[i][g+1]=1;
                            Q.push(make_pair(i,g+1));
                        }
                    }
                }
                else
                {
                    label[i][g+1]=label[v][g]-C[v][i];
                    present[i][g+1]=1;
                    Q.push(make_pair(i,g+1));
                }
            }
        }
    }
    int mincost;
    for(int i=0; i<n; i++)
    {
        int j=n;
        for(; j<2*n+1; j++)
        {
            if(label[i][j]!=-1)
            {
                break;
            }
        }
        if(j==2*n+1)
        {
            printf("infinity\n");
        }
        else
        {
            mincost=label[i][j];
            for(int j=n; j<2*n+1; j++)
            {
                if(label[i][j]!=-1&&label[i][j]<mincost)
                {
                    mincost=label[i][j];
                }
            }
            printf("%d\n",mincost);
        }

    }
    return 0;
}
