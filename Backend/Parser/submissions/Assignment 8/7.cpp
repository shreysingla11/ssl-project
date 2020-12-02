#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
    double n,w,u,v,t1,t2;
    multimap < double , char > mymap;
    std::multimap<double,char>::iterator it=mymap.begin();
    std::multimap<double,char>::iterator next;
    cin>>n>>w>>u>>v>>t1>>t2;


    char dir;
    double nships,start,length,counts=0,ans;
    double time1,time2;

    for(int i=0; i<n; i++)
    {
        cin>>dir>>nships;
        for(int j=0; j<nships; j++)
        {

            cin>>length>>start;
            if(dir=='E')
            {
                time1=(-start)/u-(i+1)*(w/v);

                time2=(-start+length)/u-i*(w/v);
            }

            if(dir=='W')
            {
                time1=(start)/u-(i+1)*(w/v);

                time2=(start+length)/u-i*(w/v);
            }

            if(time1<=t2 && time2 >= t1)
            {
                if(time1<t1)
                {
                    time1=t1;
                }


                if(time2>t2)
                {
                    time2=t2;
                }
                mymap.insert(std::pair<double,char>(time1,'('));
                mymap.insert(std::pair<double,char>(time2,')'));
            }
        }
    }

    ans=it->first-t1;
    counts=0;
    for(it=mymap.begin(); it!=mymap.end(); it++)
    {
        if((it->second)=='(')
        {
            counts++;
        }
        else
        {
            counts--;
            if(counts==0)
            {
                next=it;
                ++next;
                if((next)!=mymap.end())
                {

                    if(ans<((next->first)-(it->first)))
                    {
                        ans=((next->first)-(it->first));
                    }
                }
                else
                {
                    if(ans<(t2-(it->first)))
                    {
                        ans=(t2-(it->first));
                    }
                }

            }
        }
    }
    printf("%0.8f\n",ans);
return 0;
};
