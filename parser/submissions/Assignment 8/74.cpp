#include <iostream>
using namespace std;
class lanes
{
public:
    char c;
    int m;
    int *l,*p;
};
int main()
{
    int n,w,us,v,t1,t2;
    cin>>n>>w>>us>>v>>t1>>t2;
    lanes* lane;
    lane=new lanes[n];
    for(int i=0; i<n; i++)
    {
        cin>>lane[i].c;
        cin>>lane[i].m;
        lane[i].l=new int[lane[i].m];
        lane[i].p=new int[lane[i].m];
        for(int j=0; j<lane[i].m; j++)
        {
            cin>>lane[i].l[j];
            cin>>lane[i].p[j];
        }
    }
    for(int i=0; i<n; i++)
    {
        lanes x = lane[i];
        if(x.c=='W')
        {
            int u1;
            for(u1=(x.m)-1; u1>=0; u1--)
            {
                x.p[u1] = x.p[u1] - t1*us;
                if(x.p[u1]+x.l[u1]<=0)
                {
                    break;
                }
            }
            double t0;
            double r;
            if(x.p[u1+1]>=0)
            {
                r=0;
                t0=t1;
            }
            if(x.p[u1+1]<0)
            {
                r=0;
                t0= t1 + (x.p[u1+1]+x.l[u1+1])/us;
                for(int o=(x.m)-1; o>=0; o--)
                {
                    x.p[o] = x.p[o] - t1*us;
                }
            }
            double ti;
            for(int k=u1+1; k<x.m; k++)
            {
                ti = t0 + (x.p[k]-r)/us;
                ti = ti - (w/v);
                if(t0<=ti)
                {
                    cout<<t0-i*(w/v)<<' '<<ti-i*(w/v)<<endl;
                }
                t0 = (x.l[k]+x.p[k])/us;
                r = x.p[k]+x.l[k];
            }

        }


    if(x.c=='E')
        {
            int u1;
            for(u1=0; u1<x.m; u1++)
            {
                x.p[u1] = x.p[u1] + t1*us;
                if(x.p[u1]>x.l[u1])
                {
                    break;
                }
            }
            double t0;
            double r;
            if(x.p[u1]<=0)
            {
                r=0;
                t0=t1;
            }
            if(x.p[u1]>0)
            {
                r=0;
                t0= t1 + (-x.p[u1]+x.l[u1])/us;
                for(int o=(x.m)-1; o>=0; o++)
                {
                    x.p[o] = x.p[o] - t1*us;
                }
            }
            double ti;
            for(int k=u1+1; k<x.m; k++)
            {
                ti = t0 + (x.p[k]-r)/us;
                ti = ti - (w/v);
                if(t0<=ti)
                {
                    //cout<<t0-i*(w/v)<<' '<<ti-i*(w/v)<<endl;
                }
                t0 = (x.l[k]+x.p[k])/us;
                r = x.p[k]+x.l[k];
            }
    }
    }
    return 0;
cout<<"6";
}





