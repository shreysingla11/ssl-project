#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int threshold;
    int numfriendgoing;
    int maxpossfriendgoing; //total-friends definitely not going
    bool will_go; //to see if placed in willgo queue
    bool wont_go; //to see if placed in wontgo queue
    vector <int> friendindexes;
    vector <int> predecessors;
    node()
    {
        threshold=0;
        will_go=false;
        wont_go=false;
        numfriendgoing=0;
        maxpossfriendgoing=0;
    }
    node (int t, vector <int> friends, vector <int> pres)
    {
        threshold=t;
        will_go=false;
        wont_go=false;
        numfriendgoing=0;
        maxpossfriendgoing=friends.size();
        friendindexes=friends;
        predecessors=pres;
    }
};

int main()
{
    int n;
    cin>>n;
    node tempnode2;
    vector <node> graph(n,tempnode2);
    queue <node> willgo;
    queue <node> wontgo;
    for(int i=0; i<n; i++)
    {
        vector <int> vec;
        int thresh;
        int numberoffriends;
        node tempnode;
        cin>>thresh;
        cin>>numberoffriends;
        tempnode.threshold=thresh;
        for(int j=0;j<numberoffriends;j++)
        {
            int tempfriendindex;
            cin>>tempfriendindex;
            tempnode.friendindexes.push_back(tempfriendindex);
        }

        graph[i]=tempnode;

        graph[i].maxpossfriendgoing=graph[i].friendindexes.size();

        if(graph[i].threshold==0)
        {
            willgo.push(graph[i]);
            graph[i].will_go=true;
        }

        if(graph[i].threshold>graph[i].friendindexes.size())
        {
            wontgo.push(graph[i]);
            graph[i].wont_go=true;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0;j<graph[i].friendindexes.size();j++)
        {
            graph[graph[i].friendindexes[j]].predecessors.push_back(i);
        }
    }
    //initialisation is done
    int numdefgoing=0;
    while(willgo.size()>0)
    {
        int tempsize;
        tempsize=willgo.front().predecessors.size();
        //cout<<tempsize<<endl;
        for(int i=0;i<tempsize;i++)
        {
            //cout<<"here!"<<endl;
            graph[willgo.front().predecessors[i]].numfriendgoing++;
            //if not already in the list, push if going
            if (graph[willgo.front().predecessors[i]].will_go==false)
            {
                if(graph[willgo.front().predecessors[i]].numfriendgoing >= graph[willgo.front().predecessors[i]].threshold)
                {
                    willgo.push(graph[willgo.front().predecessors[i]]);
                    graph[willgo.front().predecessors[i]].will_go=true;
                }
            }
        }
        numdefgoing++;
        //cout<<willgo.front().threshold;
        willgo.pop();
    }
    ////////////////////////////////////////////////////////////////
    int numdefnotgoing=0;
    while(wontgo.size()>0)
    {
        int tempsize2;
        tempsize2=wontgo.front().predecessors.size();
        for(int i=0;i<tempsize2;i++)
        {
            graph[wontgo.front().predecessors[i]].maxpossfriendgoing--;
            //if not already in the list, push if going
            if (graph[wontgo.front().predecessors[i]].wont_go==false)
            {
                if(graph[wontgo.front().predecessors[i]].maxpossfriendgoing < graph[wontgo.front().predecessors[i]].threshold)
                {
                    wontgo.push(graph[wontgo.front().predecessors[i]]);
                    graph[wontgo.front().predecessors[i]].wont_go=true;
                }
            }
        }
        numdefnotgoing++;
        wontgo.pop();
    }
    cout<<numdefgoing<<" "<<(n-numdefnotgoing);
return 0;
}
