#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cstdio>
using namespace std;



struct kapil
{
    double t;
    bool f=true;
};

bool my(kapil x, kapil y)
{

    if(x.t==y.t)
    {
        if(x.f==true)
            return x.t<y.t;
        else
            return x.t>y.t;
        }
    return x.t<y.t;

}

int main()
{

    vector<kapil> a;
    double n,w,u,v,t1,t2;
    double i,j;
    double m;
    char c;
    cin>>n>>w>>v>>u>>t1>>t2;
    double offset;
    double l,p;
    offset=0;
    kapil x,y;



    for(i=0; i<n; i++)
    {
        cin>>c;

        if(c=='E')
        {
            cin>>m;
            for(j=0; j<m; j++)
            {
                cin>>l>>p;
                p=0-p;

                x.t=(((p/v)-(w/u))-offset);
                y.t=((p+l)/v)-offset;
                y.f=false;

                if((x.t>t2)||(y.t<t1))
                {
                    continue;
                }
                if((x.t<t1))
                {
                    x.t=t1;
                }
                if((y.t>t2))
                {
                    y.t=t2;
                }
                a.push_back(x);
                a.push_back(y);
            }
        }
        else
        {
            cin>>m;
            for(j=0; j<m; j++)
            {
                cin>>l>>p;
                p=0+p;

                x.t=(((p/v)-(w/u))-offset);
                y.t=((p+l)/v)-offset;
                y.f=false;
                if((x.t>t2)||(y.t<t1))
                {
                    continue;
                }
                if((x.t<t1))
                {
                    x.t=t1;
                }
                if((y.t>t2))
                {
                    y.t=t2;
                }
                a.push_back(x);
                a.push_back(y);

            }
        }

        offset=offset+(w/u);

    }



    sort(a.begin(),a.end(),my);

    double co=1,ma=a[0].t-t1,s=a.size();
    for(i=1; i<s; i++)
    {
        if(co==0)
        {
            if(ma<(a[i].t-a[i-1].t))
            {
                ma=a[i].t-a[i-1].t;
            }
        }
        else
        {

            if(a[i].f==true)
            {
                co++;
            }
            else
            {
                co--;
            }
        }
    }
    if(ma<(t2-a[s-1].t))
    {
        ma=t2-a[s-1].t;
    }
    printf("%.8f\n",ma);
    return 0;

}

