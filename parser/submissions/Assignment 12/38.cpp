#include <iostream>
#include <vector>
#include <stdio.h>
#include<queue>
using namespace std;
struct guy{
    int t;  //threshhold value
    int numFriends;
    bool visited;
    int numgoing;
    int numnotgoing;
    vector<int> predecess;
};
int main(){
    int n,temp;
    int gototal = 0;
    int notgototal = 0;
    queue<int> go;
    queue<int> notgo;
    vector<int>::iterator it;
    scanf("%d",&n);
    vector<guy> graph;
    int current;
    graph.resize(n);
    for (int i=0;i<n;i++){
        graph[i].numgoing=0;
        graph[i].numnotgoing=0;
        graph[i].visited = false;
        scanf("%d",&(graph[i].t));
        scanf("%d",&(graph[i].numFriends));
        for(int j=0;j<graph[i].numFriends;j++){
            scanf("%d",&temp);
            graph[temp].predecess.push_back(i);
        }
    }
    //construction done
    //print the graph
    /*cout<<endl;
    for (int i=0;i<n;i++){
        cout<<graph[i].t<<" "<<graph[i].numFriends<<" ";
        for(it=graph[i].predecess.begin();it!=graph[i].predecess.end();it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }*/

    for(int i=0;i<n;i++){
        if (graph[i].t==0){
            go.push(i);
            gototal++;
            graph[i].visited=true;
        }
    }
    while(go.empty()==false){
        current = go.front();
        for(it=graph[current].predecess.begin();it!=graph[current].predecess.end();it++){
            graph[*it].numgoing+=1;
            if (graph[*it].numgoing>=graph[*it].t&&graph[*it].visited==false){
                go.push(*it);
                gototal++;
                graph[*it].visited=true;
            }
        }
        go.pop();
    }
    cout<<gototal<<" ";
    //cout<<"-------------------"<<endl<<gototal<<endl;

    for(int i=0;i<n;i++){
        graph[i].visited=false;
        if (graph[i].t>graph[i].numFriends){
            notgo.push(i);
            //cout<<i<<"--"<<endl;
            notgototal++;
            graph[i].visited=true;
        }
    }

    while(notgo.empty()==false){
        current = notgo.front();
        for(it=graph[current].predecess.begin();it!=graph[current].predecess.end();it++){
            graph[*it].numnotgoing+=1;
            if (graph[*it].numnotgoing>graph[*it].numFriends-graph[*it].t&&graph[*it].visited==false){
                notgo.push(*it);
                //cout<<(*it)<<"--"<<endl;
                notgototal++;
                graph[*it].visited=true;
            }
        }
        notgo.pop();
    }
    cout<<n-notgototal<<endl;
    //cout<<"-------------------"<<endl<<n-notgototal<<endl;
    return 0;
}