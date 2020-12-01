#include<iostream>
#include<vector>
#include<stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
struct Interval
{
    double start;
    double end;
};
double t10,t20;
bool compareInterval(Interval i1, Interval i2)
{  return (i1.start < i2.start)? true: false; }
double mergeIntervals(vector<Interval>& intervals)
{
        double max=0;
        double right=t20,left;
    if (intervals.size() <= 0)
        return max;
    stack<Interval> s;
    sort(intervals.begin(), intervals.end(), compareInterval);
    s.push(intervals[0]);
    for (int i = 1 ; i < intervals.size(); i++)
    {
            Interval top = s.top();
        if (top.end < intervals[i].start)
        {
            s.push( intervals[i] );
        }
        else if (top.end < intervals[i].end)
        {
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty())
    {
        Interval t = s.top();
        left =t.end;
        double temp=right - left;
        if(t10<=t.start)
        {right=t.start;}
        else{right=t10;}
        if(temp >max)
        {max=temp;}
        s.pop();
    }
    return max;
}

int main()
{
    int n,w,u,v;
    int temp,temp01;
    double temp02;
    vector<Interval>intervals;
    char c;
    cin>>n;
    cin>>w;
    cin>>u;
    cin>>v;
    cin>>t10;
    cin>>t20;
    for(int i=0; i<n; i++)
    {
        cin>>c;
        if(c=='E')
        {
        cin>>temp;
        for(int j=0;j<temp;j++)
        {
        cin>>temp02;
        cin>>temp01;
        if(temp01>0&&(temp01)>temp02)
        {Interval temp;
        temp.start=0;
        temp.end=0;intervals.push_back(temp);}
        else
        {
        double t0=(i+1)*w/v;
        double t1=(-1*temp01)/u-t0;
        Interval temp;
        temp.start=t1;
        t1+=(temp02/u)+(t0/(i+1));
        temp.end=t1;
        intervals.push_back(temp);}

        }
        }
        if(c=='W')
        {
        cin>>temp;
        for(int j=0;j<temp;j++)
        {
        cin>>temp02;
        cin>>temp01;
        if(temp01<0&&(-1*temp01)>temp02)
        {Interval temp;
        temp.start=0;
        temp.end=0;intervals.push_back(temp);}
        else
        {
        double t0=(i+1)*w/v;
        double t1=(temp01)/u-t0;
        Interval temp;
        temp.start=t1;
        if(t1<t10){temp.start=t10;}
        t1+=(temp02/u)+(t0/(i+1));
        temp.end=t1;
        if(t1>t20)
        {temp.end=t20;}
        intervals.push_back(temp);}
        }
        }
    }
    printf("%.8f",mergeIntervals(intervals));
    cout<<endl;
    return 0;
}

