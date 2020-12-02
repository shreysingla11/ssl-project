#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;


struct node
{
    int threshold;
    int friends; //no of friends
    int going; // no of fiends going
    int notgoing; //no of friends not going
    bool decision; //whether to go or not
    vector<int> v1; //list of friends.  in-edges
    vector<int> v2; //list of ppl who he is a friend of. out-edges
    node(int t=0, int f=0)
    {
        threshold=t;
        friends=f;
        going=0;
        notgoing=0;
        decision=false;
    }
};

int main()
{
    int n,t,f,id;
    cin>>n;
    vector<bool> visited(n,false);
    vector<bool> visited1(n,false);
    vector<node*> nodes(n);
    for(int i=0;i<n;i++) nodes[i]=new node();
    queue<int> defgoing;
    queue<int> defnotgoing;
    int mincount=0;
    int maxcount=n;
    for(int i=0;i<n;i++)
    {
        cin>>t>>f;
        nodes[i]->threshold=t;
        nodes[i]->friends=f;
        if(t==0)
        {
            nodes[i]->decision=true;
            defgoing.push(i);
            visited[i]=true;
            mincount++;
        }
        else if(t>f)
        {
            nodes[i]->decision=false;
            defnotgoing.push(i);
            maxcount--;
            visited1[i]=true;
        }
        for(int j=0;j<f;j++)
        {
            cin>>id;
            (nodes[i]->v1).push_back(id);
            (nodes[id]->v2).push_back(i);
        }
    }

    //min no of ppl going
    while(!defgoing.empty())
    {
        int node_no=defgoing.front();
        defgoing.pop();
        visited[node_no]=true;
        for(int i=0; i<(nodes[node_no]->v2).size(); i++)
        {
            //(nodes[node_no]->v2)[i] is the node number of some j, such that i is a friend of j
            int j=(nodes[node_no]->v2)[i];

            nodes[j]->going++;
            if( nodes[j]->going >= nodes[j]->threshold )
            {
                if(! visited[j])
                {
                    visited[j]=true;
                    nodes[j]->decision=true;
                    defgoing.push(j);
                    mincount++;
                }
            }
        }
    }

    //max no of ppl going
    while(!defnotgoing.empty())
    {
        int node_no=defnotgoing.front();
        defnotgoing.pop();
        visited1[node_no]=true;
        for(int i=0; i< (nodes[node_no]->v2).size(); i++)
        {
            //(nodes[node_no]->v2)[i] is the node number of some j, such that j is a friend of i
            int j=(nodes[node_no]->v2)[i];
            nodes[j]->notgoing++;
            if( nodes[j]->notgoing + nodes[j]->threshold > nodes[j]->friends )
            {
                if(! visited1[j])
                {
                    visited1[j]=true;
                    nodes[j]->decision=false;
                    defnotgoing.push(j);
                    maxcount--;
                }
            }
        }
    }

    cout<<mincount<<" "<<maxcount;

    return 0;
}
