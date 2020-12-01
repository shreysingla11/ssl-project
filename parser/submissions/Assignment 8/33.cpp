#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;

void printmax(map<float,float> ntimes,int t1,int t2)
{
    map<float,float>::iterator it,it2;
    if(ntimes.empty())
    {
        float smax=t2-t1;
        printf("%.8f\n",smax);
        return;
    }
    float smax=(ntimes.begin())->first-t1;
    float maxsec=(ntimes.begin())->second;
    it=ntimes.begin();
    it2=it;
    ++it2;
    for(;it2!=ntimes.end();++it,++it2)
    {
        if(it->second>=maxsec) maxsec=it->second;
        if(it2->first-maxsec>smax) smax=it2->first-maxsec;
    }
    if(it->second>maxsec)maxsec=it->second;
    if((t2-maxsec)>smax) smax=t2-maxsec;
    printf("%.8f\n",smax);
    return;
}

int main()
{
    map<float,float> ntimes;
    map<float,float> ptimes;
    int nl,w,t1,t2;
    float u,v,t0;

    char d;
    int s,l,p;
    float ts,tf;

    cin>>nl>>w>>u>>v>>t1>>t2;
    t0=w/v;

    for(int i=0;i<nl;i++)
    {
        cin>>d>>s;
        for(int j=0;j<s;j++)
        {
            cin>>l>>p;
            if(p<0)p=-1*p;
            ts=(p/u)-t0-i*t0;
            tf=((p+l)/u)-i*t0;
            if((ts<t1&&tf<t1)||(ts>t2&&tf>t2)) continue;
            if(ts<t1)ts=t1;
            if(tf>t2)tf=t2;
            if(tf>0)
            {
                if(ntimes.find(ts)!=ntimes.end())
                {
                    if(ntimes[ts]<tf) ntimes[ts]=tf;
                }
                else ntimes[ts]=tf;
                //cout<<ts<<" "<<ntimes[ts]<<endl;
            }
        }
        printmax(ntimes,t1,t2);
    }
    //printmax(ntimes,t1,t2);
    return 0;
}
