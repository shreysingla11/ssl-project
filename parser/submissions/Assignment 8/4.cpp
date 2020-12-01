#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct ship //rather stores time intervals
{
    int status; // 0 for open 1 for close
    double time;
    bool operator<(const ship& rhs) const
    {
        if(time < rhs.time) return time<rhs.time;
        else if(time > rhs.time) return time<rhs.time;
        else return status < rhs.status;
    }
};

int main()
{
    int n,w,u,v,t1,t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    char c;
    int m,l,p;
    vector<ship> ships;
    for(int i=1;i<=n;i++)
    {
        cin>>c;//E or W
        cin>>m;//No of ships
        for(int j=1;j<=m;j++)
        {
            ship temp,temp1;
            cin>>l>>p;
            if(c=='E')
            {
                temp.time= -double(p)/double(u) - double(i)*double(w)/double(v);
                temp.status=0;
                temp1.time=temp.time + double(l)/double(u)+double(w)/double(v);
                temp1.status=1;
            }
            else
            {
                temp.time= double(p)/double(u) - double(i)*double(w)/double(v);
                temp.status=0;
                temp1.time= temp.time + double(l)/double(u)+double(w)/double(v);
                temp1.status=1;
            }
            if(temp1.time<t1)
                continue;
            else
            {
                if(temp.time<t1)
                {
                    temp.time=t1;
                }
            }
            if(temp.time>t2)
                continue;
            else
            {
                if(temp1.time>t2)
                {
                    temp1.time=t2;
                }
            }
            ships.push_back(temp);
            ships.push_back(temp1);
        }
    }

    sort(ships.begin(),ships.end());
    int count=0; //open and closed intervals

    double start_time=t1,end_time;
    double maxtime=0.0000000;

    for(int i=0;i<ships.size();i++)
    {
        if(ships[i].status==0)
        {
            if(count==0)
            {
                end_time=ships[i].time;//-double(w)/double(v);
                if(end_time>t2)
                    end_time=t2;
                if(end_time-start_time>maxtime)
                {
                    maxtime=end_time-start_time;
                }
            }
            count++;
        }
        else if(ships[i].status==1)
        {
            count--;
            if(count==0)
            {
                start_time=ships[i].time;
                if(start_time<t1)
                    start_time=t1;
            }
        }
    }
    if(t2>start_time)
    {
        if(maxtime < t2-start_time)
            maxtime = t2-start_time;
    }
    printf("\n%0.8f",maxtime);
    return 0;
}
