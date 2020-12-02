#include<iostream>
#include<queue>
#include<vector>
#include<limits>
#include<cstdio>
#include<utility>
using namespace std;

int main()
{
int n;
scanf("%d",&n);
int C[n][n];
bool good[n][n];
bool instack[n][2*n+1];
int dis[n][2*n+1];
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
    scanf("%d",&C[i][j]);
    if(C[i][j]>0)
    {good[i][j]=false;}
    else
    {good[i][j]=true;
    C[i][j]=-1*C[i][j];}

}
}

for(int i=0;i<n;i++)
{
    for(int g=0; g<2*n+1; g++)
    {
    dis[i][g]=-1;
    instack[i][g]=false;
    }
}
dis[0][n]=0;
queue<pair<int,int> > q;
//for(int g=0;g<2*n+1;g++)
//{
    pair<int,int> p(0,n);
    q.push(p);
    instack[0][n]=true;
//}
while(!q.empty())
{
   pair<int,int> v=q.front();
    q.pop();
    instack[v.first][v.second]=false;
    for(int k=0;k<n;k++)
    {
        if(good[v.first][k]&&v.second!=2*n)
        {
            if(dis[v.first][v.second]!=-1)
            {
                if(dis[v.first][v.second]+C[v.first][k]<dis[k][v.second+1]||dis[k][v.second+1]==-1)
                {
                    dis[k][v.second+1]=dis[v.first][v.second]+C[v.first][k];
                    if(!instack[k][v.second+1])
                    {
                    pair<int,int> p(k,v.second+1);
                    q.push(p);
                    instack[k][v.second+1]=true;
                    }
                }
            }

        }
        else if(v.second!=0)
        {
            if(dis[v.first][v.second]!=-1)
            {
                 if(dis[v.first][v.second]+C[v.first][k]<dis[k][v.second-1]||dis[k][v.second-1]==-1)
                {
                    dis[k][v.second-1]=dis[v.first][v.second]+C[v.first][k];
                    if(!instack[k][v.second-1])
                    {
                    pair<int,int> p(k,v.second-1);
                    q.push(p);
                    instack[k][v.second-1]=true;
                    }
                }
            }
        }
    }
}
vector<int>ans(n,numeric_limits<int>::max());
for(int i=0;i<n;i++)
{
    for(int g=n;g<2*n+1;g++)
    {
        if(dis[i][g]!=-1)
        {
            if(dis[i][g]<ans[i])
            {
                ans[i]=dis[i][g];

            }
        }

    }
}
for(int i=0;i<n;i++)
{
    if(ans[i]==numeric_limits<int>::max())
    {cout<<"infinity"<<endl;}
    else
    {
        cout<<ans[i]<<endl;
    }
}

}
