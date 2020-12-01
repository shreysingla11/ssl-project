#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include <utility>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int temp;
    vector<vector<int> >cost(n);
    vector<vector<int> > label(n);
    vector<vector<bool> > inque(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&temp);
            cost[i].push_back(temp);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*n+1; j++)
        {
            label[i].push_back(-1);
            inque[i].push_back(false);
        }
    }
    label[0][n]=0;
    inque[0][n]=true;
    queue<pair<int,int> > q;
    pair <int,int> tem(0,n);
    q.push(tem);
    pair<int,int> pre;
    while(!q.empty())
    {
        pre=q.front();
        q.pop();
        inque[pre.first][pre.second]=false;
        for(int i=0; i<n; i++)
        {
            if(cost[pre.first][i]>0)
            {
                if(label[i][pre.second-1]!=-1)
                {
                    if(label[pre.first][pre.second]+cost[pre.first][i]<label[i][pre.second-1])
                    {
                        label[i][pre.second-1]=label[pre.first][pre.second]+cost[pre.first][i];
                        if(!inque[i][pre.second-1])
                        {
                            q.push(make_pair(i,pre.second-1));
                            inque[i][pre.second-1]=true;
                        }
                    }
                }
                else
                {
                    label[i][pre.second-1]=label[pre.first][pre.second]+cost[pre.first][i];
                    q.push(make_pair(i,pre.second-1));
                    inque[i][pre.second-1]=true;
                }
            }
            else
            {
                if(label[i][pre.second+1]!=-1)
                {
                    if(label[pre.first][pre.second]-cost[pre.first][i]<label[i][pre.second+1])
                    {
                        label[i][pre.second+1]=label[pre.first][pre.second]-cost[pre.first][i];
                        if(!inque[i][pre.second+1])
                        {
                            q.push(make_pair(i,pre.second+1));
                            inque[i][pre.second+1]=true;
                        }
                    }
                }
                else
                {
                    label[i][pre.second+1]=label[pre.first][pre.second]-cost[pre.first][i];
                    q.push(make_pair(i,pre.second+1));
                    inque[i][pre.second+1]=true;
                }
            }
        }
    }
    int answer;
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
            answer=label[i][j];
            for(int k=j+1; k<2*n+1; k++)
            {
                if(label[i][k]<answer&&label[i][k]!=-1){
                    answer=label[i][k];
                }
            }
            printf("%d\n",answer);
        }
    }
}
