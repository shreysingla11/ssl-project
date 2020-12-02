#include<iostream>
using namespace std;
#include <list>
#include<vector>
#include<queue>
#include<cstdio>

class node
{

    public:
        int ti;
        int ni;
        int is_going;
        node(){}
        node(int ti, int ni)
        {
            ti=ti;
            ni=ni;
            is_going=0;
        }
};
queue<int> going;
int finallynotgoing=0;
queue<int> notgoing;
int finallygoing=0;

int main()
{
int number_nodes;
cin>>number_nodes;
vector<vector <int> > predecessors(number_nodes);
vector<node> graph;
int i=0;
while(i<number_nodes)
{
    int ti;
    int ni;
    scanf("%d",&ti);
    scanf("%d",&ni);
    graph.push_back(node(ti,ni));
    graph[i].ti=ti;
    graph[i].ni=ni;
    if(ti==0)
    {
        graph[i].is_going=1;
        going.push(i);

    }
    else if(ti>ni)
    {
        graph[i].is_going=-1;
        notgoing.push(i);
    }
    for(int j=0; j<ni; j++)
    {
        int newentry;
        scanf("%d",&newentry);
        predecessors[newentry].push_back(i);
    }

    i++;
}


while(!going.empty())
{
    //int numberofpre = predecessors[going.front()].size();
    vector<int>::iterator it= predecessors[going.front()].begin();
    while(it !=predecessors[going.front()].end())
    {
        if(graph[(*it)].is_going==0)
        {
            //cout<<"SDSDBDB"<<endl;
            graph[(*it)].ti--;
            //cout<<graph[(*it)].ti;
            graph[(*it)].ni--;
            if(graph[(*it)].ti == 0)
            {
                //cout<<"aaaaaaaaa"<<endl;
                graph[(*it)].is_going=1;
                going.push(*it);
            }
        }
        ++it;
    }

    going.pop();
    finallygoing++;
}

while(!notgoing.empty())
{
    //int numberofpre = predecessors[notgoing.front()].size();
    vector<int>::iterator it= predecessors[notgoing.front()].begin();
    for(;it !=predecessors[notgoing.front()].end() ; ++it)
    {
        //cout<<"sdgds"<<endl;
        if(graph[(*it)].is_going == 0)
        {
            //cout<<"dJHDBAD"<<endl;
            graph[(*it)].ni--;
            //cout<<graph[(*it)].ti<<" "<<graph[(*it)].ti<<"  asdvsdv"<<endl;
            if(graph[(*it)].ti > graph[(*it)].ni)
            {
                graph[(*it)].is_going=-1;
                notgoing.push(*it);
            }
        }
    }
    notgoing.pop();
    finallynotgoing++;
}
int y;
y=number_nodes-finallynotgoing;
printf("%d %d",finallygoing, y );
//cout<<finallygoing<<" "<<number_nodes-finallynotgoing<<endl;

return 0;
}
