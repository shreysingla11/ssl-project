#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<list>
#include<cstdio>
using namespace std;
class point
{
public:
    double x;
    bool isstart;

    point(double a, bool b)
    {
        x=a;
        isstart=b;
    }
    bool operator<(const point& d)
    {
        if(x<d.x)
        {
            return true;
        }
        else
        {
            if(x>d.x)
            {
                return false;
            }
            else
            {
                if(isstart==1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};
int main()
{

    int n;//no.of lanes
    double w;//width of a lane
    double u;//speed of ships
    double v;//speed of ferry
    double t1;
    double t2;
    bool ew;
    char EW;
    list<point> A;
    cin>>n>>w>>u>>v>>t1>>t2;
    double T=w/v;
    for(int i=1; i<=n ; i++)
    {
        cin>>EW;
        if(EW=='E')
        {
            ew=0;
        }
        else
        {
            ew=1;
        }
        double xcurr,xprev=0;
        double lcurr,lprev=0;
        double m;
        cin>>m;
        if(ew==1)
        {
            for(int j=1; j<=m; j++,xprev=xcurr,lprev=lcurr)
            {
                cin>>lcurr;
                cin>>xcurr;
                xcurr=xcurr-u*T*(i-1);
                if(xcurr<0)
                {
                    continue;
                }
                else
                {
                    if(t1<xcurr/u-T)
                    {

                        double start = max(t1,(xprev+lprev)/u);
                        if(start<t2)
                        {
                            point temp(start,1);
                            A.push_back(temp);
                        }
                        else
                        {
                            continue;
                        }
                        double END = min(t2,(xcurr/u)-T);
                        point temp(END,0);
                        A.push_back(temp);
                    }
                }
            }
            if(t2>(xcurr+lcurr)/u)
            {
                double start=(xcurr+lcurr)/u;
                point temp(start,1);
                A.push_back(temp);
                double END=t2;
                point temp2(END,0);
                A.push_back(temp2);
            }
        }
        else
        {
            xprev=1000000;
            lprev=0;
            for(int j=1; j<=m; j++,xprev=xcurr,lprev=lcurr)
            {
                cin>>lcurr;
                cin>>xcurr;

                xcurr=xcurr+u*T*(i-1);
                if(xcurr>0)
                {
                    continue;
                }
                else
                {
                    xcurr=-xcurr;
                    if(t2>(xcurr+lcurr)/u)
                    {
                        double END = min(t2,xcurr/u-T);
                        if(END>t1)
                        {
                            point temp(END,0);
                            A.push_back(temp);
                        }
                        else
                        {
                            continue;
                        }
                        double start = max(t1,(xcurr+lcurr)/u);
                        point temp(start,1);
                        A.push_back(temp);
                    }
                }


            }
        }


    }

    A.sort();
    list<point>::iterator p=A.begin();
    /*while(p!=A.end())
    {
        cout<<(*p).x<<" "<<(*p).isstart<<endl;
        p++;
    }*/
    p=A.begin();

    int c=0;
    int maxc=0;
    while(p!=A.end())
    {
        if((*p).isstart==1)
        {
            c++;
        }
        else
        {
            c--;
        }
        if(c>maxc)
        {
            maxc=c;
        }
        p++;

    }
    p=A.begin();
    c=0;
    double maxans=0;
    while(p!=A.end())
    {
        double s,e;
        if((*p).isstart==1)
        {
            c++;
        }
        else
        {
            c--;
        }
        if(c==maxc)
        {
            s=(*p).x;
            //cout<<s<<endl;
            p++;
            e=(*p).x;
            c--;

            maxans=max(maxans,e-s);

        }
        p++;
    }
    printf("%.8f",maxans);


    return 0;

}
