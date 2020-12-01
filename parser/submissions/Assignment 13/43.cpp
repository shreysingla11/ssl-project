#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int> > Edges(n,vector<int>(n));
    //Initialisation of the vector
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&Edges[i][j]);
        }
    }

    queue<pair<int,int> > Q;
    vector<vector<int> > queues(n,vector<int>((2*n)+1,-1));

    pair<int,int> temp;
    temp.first=0;
    temp.second=n;
    queues[0][n]=1;
    Q.push(temp);
    //Initialisation of the labels vector
    vector<vector<int> > Labels(n,vector<int>((2*n)+1,INT_MAX));
    Labels[0][n]=0;
    while(!Q.empty())
    {
        pair<int,int> temp2 = Q.front();
        Q.pop();
        int t1 = temp2.first;
        int t2 = temp2.second;
        queues[t1][t2]=-1;
        for(int i=0;i<n;i++)
        {
            if(Edges[t1][i]>0)
            {
                if(t2>0)
                {
                    if(Labels[t1][t2] + Edges[t1][i] < Labels[i][t2-1])
                    {
                        Labels[i][t2-1] = Labels[t1][t2] + Edges[t1][i];
                        if(queues[i][t2-1]==-1)
                        {
                            Q.push(make_pair(i,t2-1));
                            queues[i][t2-1]=1;
                        }
                    }
                }
            }
            if(Edges[t1][i]<0)
            {
                if(t2<2*n+1)
                {
                    if(Labels[t1][t2] - Edges[t1][i] < Labels[i][t2+1])
                    {
                        Labels[i][t2+1] = Labels[t1][t2] - Edges[t1][i];
                        if(queues[i][t2+1]==-1)
                        {
                            Q.push(make_pair(i,t2+1));
                            queues[i][t2+1]=1;
                        }
                    }
                }
            }
        }
    }

    vector<int> answer(n,INT_MAX);
    for(int i=0;i<n;i++)
    {
        for(int j=n;j<2*n+1;j++)
        {
            if(Labels[i][j]<answer[i])
            {
                answer[i]=Labels[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",answer[i]);
    }




    return 0;
}
