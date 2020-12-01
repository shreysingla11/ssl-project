#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
class lane
{
public:
    char c;
    int m;
    double* p;//starting point of ship
    double* l;//length of ship
    double* e;//ending point of ship
};
int main()
{
    int n,w,u,v,t1,t2;
    vector<pair<double,double> > intervals;
    pair<double,double> point;
    cin>>n;
    cin>>w;
    cin>>u;
    cin>>v;
    cin>>t1;
    cin>>t2;
    char c;
    int m;
    lane lanes[n];
    for(int i=0;i<n;i++)
    {
        cin>>c;
        cin>>m;
        lanes[i].c=c;
        lanes[i].m=m;
        lanes[i].l=new double[m];
        lanes[i].p=new double[m];
        lanes[i].e=new double[m];
        for(int j=0;j<m;j++)
        {
            cin>>lanes[i].l[j];
            cin>>lanes[i].p[j];
            if(c=='E')lanes[i].e[j]=lanes[i].p[j]-lanes[i].l[j];
            else lanes[i].e[j]=lanes[i].p[j]+lanes[i].l[j];
        }
    }
    double t=w/v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(lanes[i].c=='E' && (lanes[i].p[j]<t1*u*-1-i*t*u || lanes[i].e[j]<t1*u*-1-i*t*u) && (lanes[i].p[j]>t2*u*-1-i*t*u || lanes[i].e[j]>t2*u*-1-i*t*u))
            {
              point.first=-1*lanes[i].e[j]/u - i*t;
              point.second=-1*lanes[i].p[j]/u - i*t;
              intervals.push_back(point);
            }
            if(lanes[i].c=='W' && (lanes[i].p[j]>t1*u+i*t*u|| lanes[i].e[j]>t1*u+i*t*u) && (lanes[i].p[j]<t2*u+i*t*u || lanes[i].e[j]<t2*u+i*t*u))
            {
              point.first=lanes[i].e[j]/u - i*t;
              point.second=lanes[i].p[j]/u - i*t;
              intervals.push_back(point);
            }
        }
    }
    sort(intervals.begin(),intervals.end());
    int count=0,one,two;
    double max=0;
    bool flag=false;
    for(int i=1;i<intervals.size();i++)
    {
        if(max<intervals[i].second-intervals[i-1].first)max=intervals[i].second-intervals[i-1].first;
    }
    max=max-t;
    printf("%.8f \n",max);
    return 0;
}
