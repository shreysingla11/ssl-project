#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
//vector<int > pre(n);
    int c[n][n],pre[n][n];
    bool inqueue[n*(2*n+1)];
    int mincost[n*(2*n+1)];
    for(int i=0; i<n; i++)
    {

        for(int j=0; j<n; j++)
        {

            cin>>c[i][j];
            //pre[j][i]=c[i][j];
        }
    }
    for(int i=0;i<n*(2*n+1);i++){
    //inqueue[i]=false;
    if(i!=n)mincost[i]=INT_MAX;
        else mincost[i]=0;
        inqueue[i]=false;
    }
    /*for(int i=1;i<n;i++){

    for(int j=0;i<n;i++){
    for(int k=0;k<n;k++){
    if(mincost[j]+abs(c[j][k])<mincost[k]){
    mincost[k]=mincost[j]+abs(c[j][k]);
    }
    }}
    }*/

    queue<pair<int,int> > p;
    p.push(make_pair(0,n));
    inqueue[n]=true;
    while(!p.empty())
    {
        pair<int,int> v = p.front();
        inqueue[v.first*(2*n+1)+v.second]=false;
        p.pop();
        int i=0;
        while(i<n){
        if(c[v.first][i])

        }



    }



    for(int i=0; i<n; i++)
    {
        if(mincost[i]!=INT_MAX)cout<<mincost[i]<<endl;
        else cout<<"infinity"<<endl;
    }
}
