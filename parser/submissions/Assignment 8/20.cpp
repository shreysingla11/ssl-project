#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct point{
double value;
char type;

};
bool compare(point p1,point p2)
{
if(p1.value<p2.value)
    return true;
else
    return false;
}

int main()
{
    int n;
    int w,u,v,t1,t2;
    vector<point> intervals;
    scanf("%d%d%d%d%d%d",&n,&w,&u,&v,&t1,&t2);
  //  cout<<n<<" "<<w<<" "<<u<<" "<<v<<" "<<t1<<" "<<t2;
    for(int i=1;i<=n;i++)
    {
        char c;
        int m;
        cin>>c;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int p,l;
            scanf("%d%d",&l,&p);
            if(c=='E')
            {
           // cout<<c<<" "<<i;
            double start,end;
            point in;
            start=((-1)*double(p)/double(u))-(double(w)*double(i))/double(v);
            end=((double(l)+(-1)*double(p))/double(u))-((double(w)*(double(i)-1))/double(v));
            //cout<<start<<" "<<end;
            in.value=start;
            in.type='s';
            intervals.push_back(in);
            in.value=end;
            in.type='e';
            intervals.push_back(in);
           //cout<<intervals[intervals.size()-1].value;
            }
            else if (c=='W')
            {
            double start,end;
            point in;
            start=(double(p)/double(u))-(double(w)*double(i))/double(v);
            end=((double(l)+double(p))/double(u))-((double(w)*(double(i)-1))/double(v));
            in.value=start;
            in.type='s';
            intervals.push_back(in);
            in.value=end;
            in.type='e';
            intervals.push_back(in);

            }
        }
    }

sort(intervals.begin(),intervals.end(),compare);
int count=0;
int start=0;
int end=0;
int i=0;
double max=0;
while(intervals[i].value<t1&&i<intervals.size())
    {
    if(intervals[i].type=='s')
        count++;
    else if(intervals[i].type=='e')
        count--;
    i++;
    }
if(count==0)
    {
    max=intervals[i].value-t1;
    }
start=i;
end=i;
for(;intervals[i].value<=t2&&i<intervals.size();i++)
    {
    if(count==0)
        end=i;
    if(intervals[end].value-intervals[start].value>max)
        max=intervals[end].value-intervals[start].value;
    if(intervals[i].type=='s')
        count++;
    else if(intervals[i].type=='e')
        count--;
    if(count==0)
        start=i;
    }
if(count==0)
    {
    if((t2-intervals[start].value)>max)
        max=t2-intervals[start].value;
    }
cout<<fixed;
cout<<  setprecision(8)<<max;
return 0;
}
