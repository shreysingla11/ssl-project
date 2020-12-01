#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
bool myfunction(const vector<double> &u,const vector<double> &v)
{
    return u[0]<v[0];
}
int main()
{
    double w,u,v,t1,t2;
    int n;
    cin>>n>>w>>u>>v>>t1>>t2;
    vector<vector<double> >intervel;
    int i=0;
    while(i!=n)
    {
        char d;
        cin>>d;
        int m;
        cin>>m;
        int j=0;
        while(j!=m)
        {
            vector<double> couple;
            double l,p;
            cin>>l>>p;
            double f,s;
            if(d=='E')
            {
                f=(0-p)/u - (i+1)*w/v;
                s=(l-p)/u - i*w/v;
                if(f<t1)
                {
                    if(s<t1)
                    {
                        s=t1;
                    }
                    f=t1;
                }
                if(s>t2)
                {
                    if(f>t2)
                    {
                        f=t2;
                    }
                    s=t2;
                }
            }
            else
            {
                f=(p/u)-(i+1)*w/v;
                s=(p+l)/u - i*w/v;
                if(f<t1)
                {
                    if(s<t1)
                    {
                        s=t1;
                    }
                    f=t1;
                }
                if(s>t2)
                {
                    if(f>t2)
                    {
                        f=t2;
                    }
                    s=t2;
                }
            }
            if(f!=s)
            {
                couple.push_back(f);
                couple.push_back(s);
                intervel.push_back(couple);
                couple.clear();
            }
            j++;
        }
        i++;
    }
    if(intervel.empty())
    {
        vector<double> u;
        u.push_back(t1);
        u.push_back(t1);
        vector<double> v;
        v.push_back(t1);
        v.push_back(t1);
        intervel.push_back(u);
        intervel.push_back(v);
    }
    sort(intervel.begin(),intervel.end(),myfunction);
    int z=intervel.size();
    int k=0;
    double max=0;
    if(intervel[0][0]>t1)
    {
        max=intervel[0][0]-t1;
    }
    double test;
    while(k!=z-1)
    {
        test=((intervel[k+1][0]-intervel[k][1]));
        if(max<test)
        {
            max=test;
        }
        k++;
    }
    if(intervel[z-1][1]<t2)
    {
        test=t2-intervel[z-1][1];
    }
    if(max<test)
    {
        max=test;
    }
    printf("%.8f", max);
    cout<<endl;
}
