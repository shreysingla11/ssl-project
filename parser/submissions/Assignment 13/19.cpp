#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define inf 1000000
using namespace std;

class node{
public:
int number;
int cost;
int goodness;
int min;

};

struct edge{
int cost;
bool good_value;

};
int main()
{
int num_nodes;
cin>>num_nodes;
edge edge_matrix[num_nodes][num_nodes];

for(int i=0;i<num_nodes;i++)
{
    for(int j=0;j<num_nodes;j++)
    {
        int num;
        edge e;
        cin>>num;
        if(num>0)
        {
            e.cost=num;
            e.good_value=false;
            edge_matrix[i][j]=e;
        }
        else
        {
            e.cost=-num;
            e.good_value=true;
            edge_matrix[i][j]=e;
        }
    }
}
node vertices[num_nodes];
vertices[0].cost=0;
vertices[0].min=0;
vertices[0].goodness=0;
vertices[0].number=0;
for(int i=1;i<num_nodes;i++)
{
    vertices[i].cost=inf;
    vertices[i].min=inf;
    vertices[i].goodness=inf;
    vertices[i].number=i;

}

queue<node> Q;
Q.push(vertices[0]);
int k=0;
while(!Q.empty())
{
    node v=Q.front();
    Q.pop();
    for(int i=0;i<num_nodes;i++)
    {
        edge e=edge_matrix[v.number][i];
        node succr=vertices[i];
        if(e.good_value==true)
        {

            if(v.goodness+1<succr.goodness&&v.cost+e.cost>succr.cost)
            {
                ;
            }
            else
            {

                succr.goodness++;
                int temp=succr.min;
                succr.cost=v.cost+e.cost;
                if(succr.cost<temp&&succr.goodness>0)
                {
                    succr.min=succr.cost;
                }
                vertices[i].cost=succr.cost;
                vertices[i].goodness=succr.goodness;
                vertices[i].min=succr.min;
                if(succr.goodness<=2*num_nodes)
                Q.push(succr);
            }
        }
        else
        {

            if(v.goodness-1<succr.goodness&&v.cost+e.cost>succr.cost)
            {
                ;
            }
            else
            {
                succr.goodness--;
                int temp=succr.min;
                succr.cost=v.cost+e.cost;
                if(succr.cost<temp&&succr.goodness>0)
                {
                    succr.min=succr.cost;
                }
                vertices[i].cost=succr.cost;
                vertices[i].goodness=succr.goodness;
                vertices[i].min=succr.min;
                if(succr.goodness<=2*num_nodes)
                Q.push(succr);
            }
        }


    }
}

for(int i=0;i<num_nodes;i++)
{
    if(vertices[i].min!=inf)
    {
        cout<<vertices[i].min<<"\n";
    }
    else
    {
        cout<<"infinity"<<"\n";
    }
}
return 0;
}
