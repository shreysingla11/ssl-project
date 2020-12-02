#include<iostream>
#include<map>
#include<list>
#include<algorithm>
#include<cstdio>
using namespace std;
class data
{
public:
    double val;
    int isstart;
    data(double x, int y)
    {
        val=x;
        isstart=y;
    }
    bool operator < (const data& d)
    {
        if(val<d.val)
        {
            return true;
        }
        else if(d.val<val)
        {
            return false;
        }
        if(isstart==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    double n,w,u,v;
    double t1,t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    list<data> intervals;
    double T=w*1.0/v;
    for(int q=0; q<n; q++)
    {
        char dir;
        cin>>dir;
        double m;
        cin>>m;
        double xr=0,lr=0,l,d;
        if(dir=='W')
        {
            for(int z=0; z<m; z++,xr=d,lr=l)
            {
                cin>>l>>d;
                d=d-(u*T*q);
                if(d<0)
                {
                    continue;
                }
                if(t1<(d*1.0/u)-T)
                {
                    double temp=max(t1,(xr+lr)*1.0/u);
                    if(t2>temp)
                    {
                        data temp2(temp,1);
                        intervals.push_back(temp2);
                    }
                    else
                    {
                        continue;
                    }
                    temp=min(t2,(d*1.0/u)-T);
                    data temp2(temp,0);
                    intervals.push_back(temp2);
                }
            }
            if(t2>(d+l)*1.0/u){
                data temp2((d+l)*1.0/u,1);
                intervals.push_back(temp2);
                data temp1(t2,0);
                intervals.push_back(temp1);
            }
        }
        else
        {
            xr=(t2+T+T)*u;
            for(int z=0; z<m; z++,xr=d,lr=l)
            {
                cin>>l>>d;
                d=-d;
                d=d-(u*T*q);
                if(d<0)
                {
                    continue;
                }
                if(t2>(d+l)*1.0/u)
                {
                    double temp=min(t2,(d*1.0/u)-T);
                    if(t1<temp)
                    {
                        data temp2(temp,0);
                        intervals.push_back(temp2);
                    }
                    else
                    {
                        continue;
                    }
                    temp=max(t1,((d+l)*1.0/u));
                    data temp2(temp,1);
                    intervals.push_back(temp2);
                }
            }
            if(t1<(d)*1.0/u){
                data temp2(t1,1);
                intervals.push_back(temp2);
                data temp1((d)*1.0/u,0);
                intervals.push_back(temp1);
            }
        }
    }
    intervals.sort();
    //cout<<intervals.size();
    list<data>::iterator it=intervals.begin();
    /*while(it!=intervals.end())
    {
        cout<<it->val<<" ";
        it++;
    }*/
    double ans=0,maxans=0,dans=0,req,dgap=0;
     it=intervals.begin();
    //iterator::list<data> it=intervals.begin();
    while(it!=intervals.end())
    {
        if(it->isstart==1)
        {
            ans++;
            req=it->val;
        }
        else
        {
            if(ans>=maxans)
            {
                maxans=ans;
                double gap=it->val-req;
                //cout<<gap<<" ";
                if(dgap==ans){
                if(gap>dans){
                dans=gap;
                dgap=ans;
                }
                }
                else if(ans>dgap){
                dans=gap;
                dgap=ans;
                }
            }
            ans--;
        }
        it++;
    }
printf("%.8f",dans);
}
