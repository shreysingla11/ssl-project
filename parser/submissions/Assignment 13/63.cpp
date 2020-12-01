#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;

typedef  pair<int , int> pii;
int main()
{
    int n;
    scanf("%d",&n);

    vector< vector<int> > C;
    queue<pii> q;
    vector<vector<int> > Label ; //stores the min cost path for node v with goodness value


    C.resize(n);
    int cost, i, j;
    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++)
        {   scanf("%d",&cost);
            C[i].push_back(cost);
        }
    }

    Label.resize(n);
    for(int i=0;i<n;i++)
    {   Label[i].resize(3*n+1,INT_MAX) ; //-n to 2n
    }

    int edge_goodness=0, final_goodness=0;
    Label[0][0+n]=0;
    q.push(pii(0,0));
    while(!q.empty())
    {   pii _v_g = q.front();   //(node,goodness)
        q.pop();

        int node_v = _v_g.first;
        int goodness = _v_g.second;
        for(i=0;i<n;i++)
        {   edge_goodness=(C[node_v][i]<0)?1:-1;
            final_goodness = edge_goodness + goodness;
            if(Label[node_v][goodness+n]+ abs(C[node_v][i]) < Label[i][final_goodness+n]&& final_goodness<=2*n && final_goodness>=-1*n)
            {   Label[i][final_goodness+n]=Label[node_v][goodness+n]+abs(C[node_v][i]);
                q.push(pii(i,final_goodness));
            }
        }
    }

    vector<int> MinCostGoodPath;
    MinCostGoodPath.resize(n,INT_MAX);
    for(i=0;i<n;i++)
    {
        for(j=n+0;j<=3*n; j++)  //goodness>=0
        {
            MinCostGoodPath[i]=min(MinCostGoodPath[i], Label[i][j]);
        }
        if(MinCostGoodPath[i]==INT_MAX)
            printf("infinity\n");
        else
            printf("%d\n",MinCostGoodPath[i]);
    }
    return 0;
}
