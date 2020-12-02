#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class obj
{
public:
    double i;
    bool isstart;
    bool operator<(const obj&a)const
    {
        return i<a.i;
    }
};
vector<obj> timescale;
long int n;
double w,u,v,t1,t2;


void timeinput(bool k,int i,int m)
{
    //cout<<k<<endl;
    for(int j=0; j<m; j++)
    {
        double len,pos,ts,te;
        obj times,timee;
        cin>>len>>pos;
        if(k)
        {
            pos=pos*-1;
        }
        ts=(pos/u)-(i*w/v)-(w/v);
        te=ts+(len/u)+(w/v);
        /*if(ts<0)
        {
            times.i=0;
        }
        else
        {
        times.i=ts;
        }
        times.isstart=true;
        timescale.push_back(times);

        if(te<0)
        {
            timee.i=0;
        }
        else
        {
        timee.i=te;
        }
        timee.isstart=false;
        timescale.push_back(timee);
        //cout<<ts<<" "<<te<<endl;*/
        if(ts<t1&&te<t1)
        {

        }
        else if(ts<t1&&te>t1&&te<t2)
        {
         times.i=t1;
         times.isstart=true;
         timescale.push_back(times);
         timee.i=te;
         timee.isstart=false;
         timescale.push_back(timee);

        }
        else if(ts>t1&&te>t1&&ts<t2&&te<t2)
        {
         times.i=ts;
         times.isstart=true;
         timescale.push_back(times);
         timee.i=te;
         timee.isstart=false;
         timescale.push_back(timee);

        }
        else if(ts>t1&&te>t2&&ts<t2)
        {
         times.i=ts;
         times.isstart=true;
         timescale.push_back(times);
         timee.i=t2;
         timee.isstart=false;
         timescale.push_back(timee);

        }
        else if(ts>t2&&te>t2)
        {

        }

    }
}


double findd()
{
    int start=0,endi=0,k;
    double d=0,temp,d1,d2;
    //vector<obj>::iterator itr;
    d1=timescale[0].i-t1;
    k=timescale.size();
    d2=t2-timescale[k-1].i;
    if(d1>d2)
    {
        d=d1;
    }
    else
    {
        d=d2;
    }
    for(int j=0;j<timescale.size();j++)
    {
        //cout<<itr->i<<" "<<itr->isstart<<endl;
        if(timescale[j].isstart)
        {
            start++;
          //  cout<<start<<" is start "<<endl;

        }
        else
        {
            endi++;
            //cout<<endi<<" is end "<<endl;
        }
        if(start-endi==0)
        {
            //cout<<"entered"<<endl;
            //vector<obj>::iterator nitr=++itr;
            //cout<<"nitr value "<<nitr->i<<" itr val"<<itr->i<<endl;
            temp=(timescale[j+1].i)-(timescale[j].i);
            if(temp>d)
            {
                d=temp;
            }
        }

    }
    return d;

}


int main()
{
    cin>>n>>w>>u>>v>>t1>>t2;
    double d;
    for(int i=0; i<n; i++)
    {
        char ch;
        long int m;
        //cout<<"i val"<<i<<endl;
        cin>>ch>>m;
        if(ch=='E')
        {
            timeinput(true,i,m);
        }
        else
        {
            timeinput(false,i,m);
        }

    }
    sort(timescale.begin(),timescale.end());
    d=findd();
    //cout<<d<<endl;
    printf("%.8f \n",d);
   // cout<<endl;

}
