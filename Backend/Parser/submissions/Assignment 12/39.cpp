#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
class node
{
public:
    int threshold;
    int count_friends;
    int notgoing;
    int no_friends;
    bool flagmin;
    bool flagmax;
    vector<int> inverse_friends;
    node()
    {
        count_friends=0;
        notgoing=0;
        flagmin=0;
        flagmax=0;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<node> V(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&V[i].threshold);
        scanf("%d",&V[i].no_friends);
        for(int j=0; j<V[i].no_friends; j++)
        {
            int temp;
            scanf("%d",&temp);
            V[temp].inverse_friends.push_back(i);
        }
    }
    stack<int> willgo,willnotgo;
    for(int i=0; i<V.size(); i++)
    {
        if(V[i].threshold==0)
        {
            willgo.push(i);
            V[i].flagmin=1;
        }
        else
        {
            if(V[i].threshold>V[i].no_friends)
            {
                willnotgo.push(i);
                V[i].flagmax=1;
            }
        }
    }
    int mingo=0,maxgo=n;
    while(willgo.size()>0)
    {
        int willgotop=willgo.top();
        willgo.pop();
        mingo++;
        for(int i=0; i<V[willgotop].inverse_friends.size(); i++)
        {
            int index=V[willgotop].inverse_friends[i];
            V[index].count_friends++;
            if(V[index].count_friends==V[index].threshold)
            {
                if(V[index].flagmin!=1)
                {
                    willgo.push(index);
                    V[index].flagmin=1;
                }
            }
        }
    }
    while(willnotgo.size()>0)
    {
        int willnotgotop=willnotgo.top();
        willnotgo.pop();
        maxgo--;
        for(int i=0; i<V[willnotgotop].inverse_friends.size(); i++)
        {
            int index=V[willnotgotop].inverse_friends[i];
            V[index].notgoing++;
            if(V[index].threshold>V[index].no_friends-V[index].notgoing)
            {
                if(V[index].flagmax!=1)
                {
                    willnotgo.push(index);
                    V[index].flagmax=1;
                }
            }
        }
    }
    cout<<mingo<<" "<<maxgo<<endl;
    return 0;
}
