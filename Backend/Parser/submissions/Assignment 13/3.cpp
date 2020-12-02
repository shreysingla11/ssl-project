#include<iostream>
using namespace std;


#define MAX 20
#define INFINITY 9999

class bell_ford
{
private:
 int n;
 int graph[MAX][MAX];
 int start;
 int distance[MAX];
 int predecessor[MAX];
public:
 void read_graph();
 void initialize();
 void update();
 void check();
 void algorithm();
};

void bell_ford::read_graph()
{
 
 cin>>n;
 
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   cin>>graph[i][j];
 
 start=0;
}
void bell_ford::initialize()
{
 for(int i=1;i<=n;i++)
 {
   distance[i]=INFINITY;
   predecessor[i]=0;
 }
 distance[start]=0;
}


// pseudo code





void bell_ford::update()
{
 for(int i=1;i<=n-1;i++)
 {
  for(int u=1;u<=n;u++)
  {
   for(int v=1;v<=n;v++)
   {
    if(graph[u][v]!=0)
    {
     if(distance[v]>distance[u]+graph[u][v])
     {
      distance[v]=distance[u]+graph[u][v];
      predecessor[v]=u;
     }
    }
   }
  }
 }
}


void bell_ford::check()
{
 for(int u=1;u<=n;u++)
 {
  for(int v=1;v<=n;v++)
  {
   if(graph[u][v]!=0)
   {
    if(distance[v]>distance[u]+graph[u][v])
    {
     cout<<"infinity";
     return;
    }
   }
  }
 }



}

void bell_ford::algorithm()
{
 read_graph();
 initialize();
 update();
 check();
}

int main()
{
 bell_ford obj;
 obj.algorithm();
}



