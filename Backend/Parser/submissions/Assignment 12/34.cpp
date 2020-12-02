#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
class person
{
public:
    int threshold,countOfFriends,fcount,notcount;
    vector<int > inverseFriends;
    bool visited,visitedmin;
    person()
    {
        countOfFriends=0;
        notcount=0;
        inverseFriends.clear();
        visited=false;
        visitedmin=false;
    }
};
int main()
{
    int n;
    scanf("%d",&n);
    int num;
    int pre;
    vector<person > members(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&members[i].threshold);
        scanf("%d",&num);
        members[i].fcount=num;
        for(int j=0; j<num; j++)
        {
            scanf("%d",&pre);
            members[pre].inverseFriends.push_back(i);
        }
    }
    stack<int > going,notgoing;
    int minimum=0;
    for(int i=0; i<n; i++)
    {
        if(members[i].threshold==0)
        {
            going.push(i);
            members[i].visitedmin=true;
        }
        else if(members[i].threshold>members[i].fcount)
        {
            notgoing.push(i);
            members[i].visited=true;
        }
    }
    minimum=going.size();
    while(!going.empty())
    {
        int index=going.top();
        going.pop();
        for(int i=0; i<members[index].inverseFriends.size(); i++)
        {
            int inverfrie=members[index].inverseFriends[i];
            members[inverfrie].countOfFriends++;
            if(members[inverfrie].countOfFriends==members[inverfrie].threshold)
            {
                if(!members[inverfrie].visitedmin){
                    going.push(inverfrie);
                    members[inverfrie].visitedmin=true;
                    minimum++;
                    }
            }
        }
    }
    int notgoingcount=notgoing.size();
    while(!notgoing.empty())
    {
        int index=notgoing.top();
        notgoing.pop();
        for(int i=0; i<members[index].inverseFriends.size(); i++)
        {
            int inverfrie=members[index].inverseFriends[i];
            members[inverfrie].notcount++;
            if(members[inverfrie].threshold>members[inverfrie].fcount-members[inverfrie].notcount)
            {
                if(!members[inverfrie].visited)
                {
                    notgoing.push(inverfrie);
                    members[inverfrie].visited=true;
                    notgoingcount++;
                }
            }
        }
    }
    cout<<minimum<<" "<<n-notgoingcount<<endl;
}
