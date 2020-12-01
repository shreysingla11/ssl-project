#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iomanip>
using namespace std;
int main()
{
    int n,w,t1,t2;
    double u,v;
    int m,l,p;
    int i,j,k;
    double f1,f2;
    double ts,te;
    char a;
    double t;
    int open;
    double d;
    multimap<double,char> F;
    multimap<double,char>::iterator it;
    multimap<double,char>::iterator next;
    cin>>n>>w>>u>>v>>t1>>t2;
    t=w/v;
    for(i=0;i<n;i++)
    {
        cin>>a>>m;

        if(a=='E')
        {
            for(j=0;j<m;j++)
            {
                cin>>l>>p;
                f1=-p/u-(i+1)*t;
                f2=(l-p)/u-i*t;
                if(f2>=t1 && f1<=t2)
                {
                    if(f1<t1)
                    {
                        f1=t1;
                        //cout<<f1<<endl;
                    }
                    if(f2>t2)
                    {
                        f2=t2;
                        //cout<<f2<<endl;
                    }
                    F.insert(pair<double,char>(f1,'('));
                    F.insert(pair<double,char>(f2,')'));

                }
            }
        }
        if(a=='W')
        {
            for(j=0;j<m;j++)
            {
                cin>>l>>p;
                f1=p/u-(i+1)*t;
                f2=(l+p)/u-i*t;
                if(f2>=t1 && f1<=t2)
                {
                    if(f1<t1)
                    {
                        f1=t1;
                    }
                    if(f2>t2)
                    {
                        f2=t2;
                    }
                    F.insert(pair<double,char>(f1,'('));
                    F.insert(pair<double,char>(f2,')'));
                }
            }
        }
            it=F.begin();
    d=(it->first)-t1;
    open=0;
    if(it==F.end())
    {d=t2-t1;}
    for(it=F.begin();it!=F.end();it++)
    {
        if((it->second)=='(')
        {
            open++;
        }
        else
        {
            open--;
            if(open==0)
            {
                next=it;
                ++next;
                if((next)!=F.end())
                {

                    if(d<((next->first)-(it->first)))
                    {
                        d=((next->first)-(it->first));
                    }
                }
                else
                {
                    if(d<(t2-(it->first)))
                    {
                        d=(t2-(it->first));
                    }
                }

            }
        }
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    cout<<d<<endl;


    }

    return 0;
}
