#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

class interval
{
public:
    float first;
    float last;
};
bool PCompare(const  interval& a, const  interval& b)
{
    return a.first<b.first;
}
int main()
{
    int n,w,u,v,t1,t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    //vector< vector<ship> > vec;
    vector<interval> vec;
    float f=(w*1.0/v);
    char EorW;
    for(int i=0; i<n; i++)
    {
        //vector<ship> s;
        cin>>EorW;
        if(EorW=='W')
        {
            int count;
            cin>>count;
            float prev=t1;
            for(int j=0; j<count; j++)
            {
                //prev=t1-(i*w*1.0)/v;
                int pos,length;
                cin>>length;
                cin>>pos;
                float time1,time2;
                time1=(pos*1.0)/u-((i+1)*w*1.0)/v;
                time2=time1+(length*1.0)/u+(w*1.0/v);
                if(time1>=t1&&(time2<=t2))
                {
                    interval I;
                    I.first=prev;
                    I.last=time1;
                    prev=time2;
                    vec.push_back(I);
                }
            }
            if(prev!=t2)
            {
                interval I;
                I.first=prev;
                I.last=t2;
                vec.push_back(I);
            }
        }
        else
        {

            int count;
            cin>>count;
            float prev=t1;
            for(int j=0; j<count; j++)
            {
                //prev=t1-(i*w*1.0)/v;
                int pos,length;
                cin>>length;
                cin>>pos;
                pos=-1*pos;

                float time1,time2;
                time1=(pos*1.0)/u-((i+1)*w*1.0)/v;
                time2=time1+(length*1.0)/u+(w*1.0)/v;
                if(time1>=t1&&(time2<=t2))
                {
                    interval I;
                    I.first=prev;
                    I.last=time1;
                    prev=time2;
                    vec.push_back(I);
                }

            }
            if(prev!=t2)
            {
                interval I;
                I.first=prev;
                I.last=t2;
                vec.push_back(I);
            }
        }
    }

    sort(vec.begin(), vec.end(), PCompare);
    int left=vec[0].first;
    int right=vec[0].last;
    int j=0;
    float maxd=0;
    for(int i=1; i<vec.size(); i++)
    {
        if(right<vec[i].first)
        {
            j=0;
            if(maxd<right-vec[i-1].first)
            {
                maxd=right-vec[i-1].first;
            }
            right=vec[i].last;
        }
        if(right>vec[i].last)
        {
            right=vec[i].last;
            j++;
            if(j==n-1)
            {
                if(maxd<right-vec[i].first)
                {
                    maxd=right-vec[i].first;
                }
            }
        }

    }
    printf("%.8f",maxd);


    return 0;
}
