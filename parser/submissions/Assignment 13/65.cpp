#include<cstdio>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
class node{
public:
int goodness;
int cost;
int flag;
int id;
};

int main()
{
//input

int n;
scanf("%d",&n);
int c[n][n];
node g[n];

for(int i = 0;i<n;i++)
    {
    for(int j = 0;j<n;j++)
        {
        scanf("%d" ,&c[i][j]);
        }

    g[i].id = i;
    g[i].flag =0;
    g[i].goodness = 1000000000;
    g[i].cost = 1000000000;
    }


queue< node* > q;

g[0].cost =0;
g[0].goodness =0;
g[0].flag = 1;
node* a = new node;
a = &g[0];
q.push(a);


while(!q.empty())
{

node* temp = q.front();


// for each v in node
for(int m= 0;m<n;m++)
    {

        //if(abs(c[temp.id][m]) + temp.cost < g[m].cost )
        //if goodness increases
       // int gtemp = 0;
        if(c[temp->id][m]<0)
        {
            if(temp->cost-c[temp->id][m]< g[m].cost && temp->goodness-1<2*n && temp->goodness-1>-2*n)
            {
                g[m].cost = temp->cost-c[temp->id][m];
                g[m].goodness = temp->goodness - 1;

                if(g[m].flag==0)
                    {
                       // g[m].cost = temp->cost-c[temp->id][m];
                       // g[m].goodness = temp->goodness - 1;
                        g[m].flag = 1;
                        node *b = new node;
                        b = &g[m];
                        q.push(b);

                    }

            }
        }
        if(c[temp->id][m]>0) {

            if(temp->cost+c[temp->id][m]< g[m].cost && temp->goodness+1<2*n && temp->goodness+1>-2*n)
            {
               g[m].cost = temp->cost+c[temp->id][m];
                g[m].goodness = temp->goodness + 1;

                if(g[m].flag==0)
                    {
                        //g[m].cost = temp->cost+c[temp->id][m];
                        //g[m].goodness = temp->goodness - 1;
                        g[m].flag = 1;
                        node *c = new node;
                        c = &g[m];
                        q.push(c);

                    }

            }




        }




        //minchecck
        //if(g[m].cost<g[m].min && g[m].goodness>=0)g[m].min=g[m].cost;
q.pop();
g[temp->id].flag = 0;

}





}

for(int y = 0;y<n;y++)
{
if(g[y].cost==1000000000)printf("infinity\n");
else printf("%d\n",g[y].cost);

}


}




