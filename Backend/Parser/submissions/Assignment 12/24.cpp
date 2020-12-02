#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    int n,x,minimum=0,maximum=0;
    scanf("%d",&n);
    vector<vector<int> > whosespan(n);
    vector<int> threshold(n);
    vector<int> friends(n);
    vector<int> hisgoing(n);
    vector<int> hisnotgoing(n);
    vector<bool>inmin(n,false);
    vector<bool>inmax(n,false);
    queue< int > willgo;
    queue< int > willnotgo;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        threshold[i]=x;
        scanf("%d",&x);
        friends[i]=x;
        hisnotgoing[i]=x;
        for(int j=0; j<x; j++)
        {
            int y;
            scanf("%d",&y);
            (whosespan[y]).push_back(i);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(threshold[i]==0)
        {
            willgo.push(i);
            inmin[i]=true;
        }
        else if(threshold[i]>friends[i])
        {
            willnotgo.push(i);
            inmax[i]=true;
        }
    }
    while(!willgo.empty())
    {
        for(int i=0; i<whosespan[willgo.front()].size(); i++)
        {
            int p=whosespan[willgo.front()][i];
            hisgoing[p]++;
            if(hisgoing[p]>=threshold[p] && !inmin[p])
            {
                willgo.push(p);
                inmin[p]=true;
            }
        }
        willgo.pop();
        minimum++;
    }
    while(!willnotgo.empty())
    {
        for(int i=0; i<whosespan[willnotgo.front()].size(); i++)
        {
            int p=whosespan[willnotgo.front()][i];
            hisnotgoing[p]--;
            if(hisnotgoing[p]<threshold[p] && !inmax[p])
            {
                willnotgo.push(p);
                inmax[p]=true;
            }
        }
        willnotgo.pop();
        maximum++;
    }
    maximum=n-maximum;
    printf("%d %d",minimum,maximum);
    return 0;
}
