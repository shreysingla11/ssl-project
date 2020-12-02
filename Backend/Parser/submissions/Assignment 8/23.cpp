#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

class laneinfo
{
public:
    char c;
    int m;
    vector<int> len;
    vector<int> pos;
};
int main()
{
    int n,w,t1,t2,len,pos,open=0;
    double u,v,d=0.00000000;
    multimap<double,char> nrange;
    multimap<double,char>:: iterator it;
    multimap<double,char>:: iterator itnext;
    cin>>n>>w>>u>>v>>t1>>t2;
    laneinfo l[n];
    for(int i=0; i<n; i++)
    {
        cin>>l[i].c;
        cin>>l[i].m;
        for(int j=0; j<l[i].m; j++)
        {
            cin>>len>>pos;
            l[i].len.push_back(len);
            l[i].pos.push_back(pos);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(l[i].c=='W')
        {
            if(l[i].m==0){continue;}
            double a=+1.0;
            for(int j=0; j<l[i].m; j++)
            {
                double st,et;
                st=(l[i].pos[j])*a/(u);
                et=(l[i].len[j]+l[i].pos[j]*a)/(u);
                st = (st-((i+1)*w/v)<t1) ? t1:(st-(i+1)*w/v) ;
                et = (et-(i*w/v)>t2) ? t2:(et-i*w/v) ;
                nrange.insert(pair<double,char>(st,'('));
                nrange.insert(pair<double,char>(et,')'));
            }
        }
        else
        {
            if(l[i].m==0){continue;}
            double a=-1.0;
            for(int k=0; k<l[i].m; k++)
            {
                int j=l[i].m-1-k;
                double st,et;
                st=(l[i].pos[j])*a/(u);
                et=(l[i].len[j]+l[i].pos[j]*a)/(u);
                st = (st-((i+1)*w/v)<t1) ? t1:(st-(i+1)*w/v) ;
                et = (et-(i*w/v)>t2) ? t2:(et-i*w/v) ;
                nrange.insert(pair<double,char>(st,'('));
                nrange.insert(pair<double,char>(et,')'));
            }
        }
    }
    for(it=nrange.begin(); it!=nrange.end(); it++)
    {
        if(it->second=='(')
        {
            open++;
        }
        else
        {
            open--;
        }
        if(open==0)
        {
            it++;
            itnext=it;
            it--;
            if(itnext!=nrange.end())
            {
                double p=itnext->first - it->first;
                if(p>d)
                {
                    d=p;
                };
            }
            else
            {
                double p=t2- it->first;
                if(p>d)
                {
                    d=p;
                };
            }
        }
    }
    printf("%.8f",d);
    return 0;
}

