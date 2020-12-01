#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
public:
    vector<bool> friendarray;
    int id,numberoffriends;
    int threshold_value,peoplegoing;
    bool inqueue;
    bool definitelynotgoing;
    int peoplegoingmax;
};
int main()
{
    int n,min_count=0;
    cin>>n;
    int max_count=n;
    vector<Node> graph;
    queue<Node> q;
    queue<Node> r;
    for(int i=0; i<n; i++)
    {
        Node temp;
        (temp.friendarray).resize(n,false);
        cin>>temp.threshold_value;
        cin>>temp.numberoffriends;
        for(int j=0; j<temp.numberoffriends; j++)
        {
            int temp1;
            cin>>temp1;
            (graph[i].friendarray).push_back(temp1);
            //(graph[temp1].predecessorarray).push_back(i);
        }
        temp.peoplegoing = 0;
        temp.peoplegoingmax = graph[i].numberoffriends;
        temp.definitelynotgoing = false;
        temp.inqueue = false;
        temp.id = i;

        if(graph[i].threshold_value==0)
        {
            min_count++;
            graph[i].inqueue = true;
            q.push(graph[i]);
        }
        // cout<<(temp.threshold_value)<<" "<<temp.peoplegoingmax<<endl;
        if(graph[i].threshold_value>graph[i].peoplegoingmax)
        {
            max_count--;
            graph[i].definitelynotgoing = true;
            r.push(graph[i]);
            //cout<<"hai"<<endl;
            // cout<<temp.id<<" "<<temp.definitelynotgoing<<" "<<"hai"<<endl;
        }
        //graph.push_back(temp);
    }
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        for(int i=0; i<n; i++)
        {
            if(!(graph[i].inqueue))
            {
                if(graph[i].friendarray[temp.id])
                graph[i].peoplegoing++;
                if(graph[i].peoplegoing == graph[i].threshold_value)
                {
                    min_count++;
                    graph[i].inqueue = true;
                    q.push(graph[i]);
                }
            }
        }
    }

    while(!r.empty())
    {
        Node temp = r.front();
        r.pop();
        for(int i=0; i<n; i++)
        {
            if(!graph[i].definitelynotgoing)
            {
                if(graph[i].friendarray[temp.id])//cout<<graph[i].definitelynotgoing<<endl
                graph[i].peoplegoingmax--;
                if(graph[i].threshold_value>graph[i].peoplegoingmax)
                {
                    max_count--;
                    graph[i].definitelynotgoing = true;
                    r.push(graph[i]);
                    //cout<<i<<" "<<max_count<<" "<<graph[i].threshold_value<<" "<<graph[i].peoplegoingmax<<endl;
                }

            }
        }
    }


    cout<<min_count<<" "<<max_count;

    return 0;
}
