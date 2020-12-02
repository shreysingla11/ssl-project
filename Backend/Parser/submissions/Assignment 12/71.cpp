#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
int main()
{
    int n=0;
    vector<vector<int> > successor;
    vector<vector<int> > predecessor;
    vector<int> threshold;

    queue<int> def_going;
    queue<int> def_not_going;
    vector<int> going;
    vector<int> not_going;
    int count_going=0;
    int count_not_going=0;

    scanf("%d",&n);
    predecessor.resize(n);
    successor.resize(n);
    going.resize(n,0);
    not_going.resize(n,0);
    int index=0, i, j, x;
    for(i=0;i<n;i++)
    {   x=0;
        scanf("%d",&x);      //threashold value
        threshold.push_back(x);
        scanf("%d",&x);
              //no of friends
        for(j=0;j<x;j++)
        {
            scanf("%d",&index) ;     // index of friend
            successor[i].push_back(index);
            predecessor[index].push_back(i);
        }
        if(threshold[i]==0)
        {    def_going.push(i);
             count_going++;
        }
        else if(threshold[i]>x)      //x=no. of friends
        {    def_not_going.push(i);
             count_not_going++;
        }
        //printf("%d",i);
    }
    int node_w, node_v, size_predecessor;

    while(!def_going.empty())
    {
        node_v=def_going.front();
        def_going.pop();
        size_predecessor = predecessor[node_v].size();
        for(i=0;i<size_predecessor;i++)
        {
            int node_w = predecessor[node_v][i];
            going[node_w]=going[node_w]+1;
            if(threshold[node_w]==going[node_w])    //threshold[node_w]!=0
            {   def_going.push(node_w);
                count_going++;
                //printf("going %d",node_w);
            }
        }
    }

    while(!def_not_going.empty())
    {
        node_v=def_not_going.front();
        def_not_going.pop();
        size_predecessor = predecessor[node_v].size();
        for(int i=0;i<size_predecessor;i++)
        {
            int node_w = predecessor[node_v][i];
            not_going[node_w]=not_going[node_w]+1;
            if(successor[node_w].size()-not_going[node_w]==threshold[node_w]-1) //successor[node_w].size()>=threshold[node_w]
            {
                def_not_going.push(node_w);
                count_not_going++;
                //printf("not going %d", node_w);
            }
        }
    }

    int minimum=count_going;
    int maximum=n - count_not_going;
    printf("%d %d\n",minimum,maximum);
/*
    vector<vector<int> > successor;
    vector<vector<int> > predecessor;
    vector<int> threshold;
    //vector<int> no_of_friends;

    queue<int> def_going;
    queue<int> def_not_going;
    vector<int> going;
    vector<int> not_going;
*/
    return 0;
}

