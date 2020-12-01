#include<iostream>
#include<map>
#include<set>
#include<cstdlib>
#include <cstdio>
#include<iomanip>
using namespace std;
int main()
{
    int n,w,u,v,x1,x2;
    cin>>n>>w>>u>>v>>x1>>x2;
    multimap<double,int> collisionmap;
    for(int i=0; i<n; i++)
    {
        char dir;
        cin>>dir;
        int m;
        cin>>m;
        for(int j=0; j<m; j++)
        {
            double l,s;
            cin>>l>>s;
            double t1,t2;
            if(dir=='E')
            {
                s=-s;
                t1 = (((s)*v)-((i+1)*w*u))/(v*u*1.0);
                t2 = (((s+l)*v)-(i*w*u))/(v*u*1.0);
                //cout<<t1<<" "<<t2<<endl;
            }
            else if(dir=='W')
            {
                t1 = ((s*v)-((i+1)*w*u))/(v*u*1.0);
                t2 = (((s+l)*v)-(i*w*u))/(v*u*1.0);
                //cout<<t1<<" "<<t2<<endl;
            }
            if(t2>=x1&&t1<=x2)
            {
                if(t1<x1)
                {
                    t1=x1;
                }
                if(t2>x2)
                {
                    t2=x2;
                }
                multimap<double,int>::iterator it = collisionmap.end();
                collisionmap.insert (it,pair<double,int>(t1,1));
                collisionmap.insert (it,pair<double,int>(t2,-1));
            }
        }
        int count=0;
    double d=collisionmap.begin()->first-x1;
    if(collisionmap.size()==0)
    {
        d=x2-x1;
    }
    for(multimap<double,int>::iterator it = collisionmap.begin(); it!=collisionmap.end(); it++)
    {
        count = count + it->second;
        if(count==0)
        {
            multimap<double,int>::iterator ti = it;
            ti++;
            if(ti!=collisionmap.end())
            {
                if(((ti->first)-(it->first))>d)
                {
                    d=((ti->first)-(it->first));
                }
            }
            else
            {
                if((x2-(it->first))>d)
                {
                    d=(x2-(it->first));
                }
            }
        }
    }
    cout << fixed;
    cout << setprecision(8);
    cout << d<<endl;
    }

}
