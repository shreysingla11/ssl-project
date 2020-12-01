#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point
{
    double co;
    bool s;
    bool operator<(const point &a) const
    {
        return co<a.co;
    }
};
int main()
{
    int n,t1,t2;
    double u,v,w;
    cin>>n>>w>>u>>v>>t1>>t2;
    double laneTime=w/(v); //double
    vector<point> MS;
    for(int i=0; i<n; i++)
    {
        //cout<<"hi"<<endl;
        int numShips,l,start;
        char d;
        cin>>d>>numShips;
        for(int j=0; j<numShips; j++)
        {
            //cout<<"hi"<<endl;
            cin>>l>>start;
            double tst,tend;
            if(d=='E')
            {
                tst=(-start)/u-(i+1)*laneTime;
                tend=(l-start)/u-i*laneTime;
            }
            else
            {
                tst=start/u-(i+1)*laneTime;
                tend=(l+start)/u-i*laneTime;
            }
            point p1,p2;
            if(tend<t1)
            {
                continue;
            }
            else
            {
                if(tst<t1)
                {
                    tst=t1;
                }
            }
            if(tst>t2)
            {
                continue;
            }
            else
            {
                if(tend>t2)
                {
                tend=t2;
                }
            }
            p1.co=tst;
            p1.s=true;
            p2.co=tend;
            p2.s=false;
            MS.push_back(p1);
            MS.push_back(p2);
        }
    }
    double interval=0;
    if(MS.begin()!=MS.end())
    {
    sort(MS.begin(),MS.end());
    vector<point> ::iterator it;
    double Start,End;
    int Count=0;
    int S=MS.size();
    if(MS[0].co>t1)
    {
    interval=MS[0].co-t1;
    }
    if(MS[S-1].co<t2)
    {
    if(interval < (t2-MS[S-1].co))
    {
    interval=t2-MS[S-1].co;
    }
    }
    for(int k=0; k<MS.size(); k++)
    {
        //printf("%.8f \n",MS[k].co);
        if(MS[k].s==true)
        {
            Count++;
        }
        else
        {
            Count--;
        }
        if(Count==0)
        {
            //cout<<"hi1"<<endl;
            Start=MS[k].co;
            k++;
            Count++;
            if(k<MS.size())
            {
                End=MS[k].co;
            }
            if((interval<End-Start) &&(Start>t1)&&(End<t2))
            {
                interval=End-Start;
            }
        }
    }
    }
    else
    {
    interval=t2-t1;
    }
    printf("%.8f \n",interval);
    return 0;
}
