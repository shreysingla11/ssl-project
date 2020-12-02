#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int persons;
    cin>>persons;
    vector<vector<int> > data;
    data.resize(persons);
    vector<int> threshold(persons);
    vector<int> friendsno(persons);
    queue<int> going;
    queue<int> notgoing;
    vector<bool> gopush(persons,false);
    vector<bool> notgopush(persons,false);
    int minimum=0;
    int maximum=persons;
    for(int i=0; i<persons; i++)
    {
        int t;
        scanf ("%d",&t);
        threshold[i] = t;
        int f;
        scanf ("%d",&f);
        friendsno[i] = f;
        if(t==0)
        {
            going.push(i);
            gopush[i] = true;
        }
        else if(t>f)
        {
            notgoing.push(i);
            notgopush[i] = true;
        }
        for(int j=0; j<f; j++)
        {
            int friendno;
            scanf ("%d",&friendno);
            data[friendno].push_back(i);
        }
    }
    while(!(notgoing.empty()))
    {
        int person = notgoing.front();
        notgoing.pop();
        maximum--;
        for(int i=0; i<data[person].size(); i++)
        {
            int x = data[person][i];
            friendsno[x]--;
            if(threshold[x]>friendsno[x])
            {
                if(!notgopush[x])
                {
                    notgoing.push(x);
                    notgopush[x] = true;
                }
            }
        }
    }
    while(!(going.empty()))
    {
        int person = going.front();
        going.pop();
        minimum++;
        for(int i=0; i<data[person].size(); i++)
        {
            int x = data[person][i];
            threshold[x]--;
            if(threshold[x]==0)
            {
                if(!gopush[x])
                {
                    going.push(x);
                    gopush[x] = true;
                }
            }
        }
    }
    printf("%d %d\n",minimum,maximum);
}
