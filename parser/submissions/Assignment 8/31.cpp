#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct ship
{
    double start;
    double ends;
};
struct interval
{
    double start;
    double ends;
};
bool comp(interval l,interval m)
{
    if(l.start<m.start)return true;
    else return false;
}
int main()
{
    vector<vector<ship> >pos;
    vector<vector<interval> >ranges;
    double n,w,u,v;
    double t1,t2;
    char c;
    ship tem;
    cin>>n>>w>>u>>v>>t1>>t2;

    /*Convert west directed ships to east*/
    for(int i=0; i<n; i++)
    {
        vector<ship>s;
        pos.push_back(s);
        char d;
        int num;
        double t=i*w/v*u;
        cin>>d>>num;
        for(int j=0; j<num; j++)
        {
            double length;
            cin>>length;
            cin>>tem.start;
            tem.start-=t;
            if(d=='E')
            {
                tem.start=-tem.start;
            }
            tem.ends=tem.start+length;
            (pos.back()).push_back(tem);
        }
    }
    for(int i=0; i<n; i++)
    {
        vector<interval>in;
        ranges.push_back(in);
        interval temp;
        for(int j=0; j<pos[i].size(); j++)
        {
            if(pos[i][j].ends<0 && pos[i][j].start<0)
            {
                continue;
            }
            else
            {

                if(pos[i][j].start-w/v*u<0)
                {

                    temp.start=0;
                    temp.ends=(pos[i][j].ends)/u;
                    (ranges.back()).push_back(temp);
                }
                else
                {
                    temp.start=(pos[i][j].start-w/v*u)/u;
                    temp.ends=(pos[i][j].ends)/u;
                    (ranges.back()).push_back(temp);
                }
            }
        }
    }
    //////////////sorting
    vector<interval>main;
    for(int i=0; i<n; i++)
    {
        main.insert(main.end(),(ranges[i]).begin(),(ranges[i]).end());
    }
    sort(main.begin(),main.end(),comp);
    int count=0;
    double max=0;
    vector<double>length;
    for(int i=0; i<main.size()-1; i++)
    {
        if(main[i].ends>max)
        {
            max=main[i].ends;
        }
        if(main[i+1].start<=max)
        {
            continue;
        }
        else
        {
            length.push_back(main[i+1].start-max);

        }
    }
    vector<double>::iterator it;
    double ans=0;
    for(it=length.begin();it!=length.end();it++){
         if(*it>ans){ans=*it;}
    }
    printf("%.8f",ans);
    return 0;
}
