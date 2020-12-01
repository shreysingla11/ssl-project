#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int k=0;
struct point
{public:
    int x;
    int y;
};

bool intersect(point p1, point p2, point p3, point p4)
{
//int x=p3.y-p2.y;
if(p1.x==p2.x)
{
if((p3.x-p1.x)*(p4.x-p1.x)<=0)
{
    if(p4.x==p3.x)
    {
    if((p1.x-p3.x)*(p2.x-p3.x)<=0)
    return true;
    }
  else if ((p1.y-p4.y)-((p4.y-p3.y)/(p4.x-p3.x)*(p1.x-p4.x))*(p2.y-p4.y)-((p4.y-p3.y)/(p4.x-p3.x)*(p2.x-p4.x))<=0)
  {
  return true;
  }
  else return false;
}






}

    if((p3.y-p2.y)-((p2.y-p1.y)/(p2.x-p1.x)*(p3.x-p2.x))*(p4.y-p2.y)-((p2.y-p1.y)/(p2.x-p1.x)*(p4.x-p2.x))<=0)
    {
        if(p4.x==p3.x)
    {
    if((p1.x-p3.x)*(p2.x-p3.x)<=0)
    return true;
    else if ((p1.y-p4.y)-((p4.y-p3.y)/(p4.x-p3.x)*(p1.x-p4.x))*(p2.y-p4.y)-((p4.y-p3.y)/(p4.x-p3.x)*(p2.x-p4.x))<=0)
    return true;
    }

        else return false;
    }
    else return false;
    //

}
/*void solve(std::vector<point> &r, std::vector<point> &b,std::vector<int> &rindex, vector<int> &bindex, std::vector<point> &pair)
{int sum=0;
    if(r.size()==1)

    std::vector<point> ltempr;
    std::vector<point> ltempb;
    std::vector<point> rtempr;
    std::vector<point> rtempb;
    std::vector<int> lrindex;
    std::vector<int> lbindex;
    std::vector<int> rrindex;
    std::vector<int> rbindex;
    for (int i = 0; i < b.size(); ++i)
    {

        int slope=(b[i].y-r[0].y)/(b[i].x-r[0].x);
        for (int j = 0; j < r.size(); ++j)
        {
            /
            if((r[j].y-r[0].y)/(r[j].x-r[0].x)>slope)
            {    ltempr.push_back(r[j]);

            sum++;
            }
            else
            {
                rtempr.push_back(r[j]);
            }
        }
        for(int j=0; j< b.size(); ++j)
        {
            if((b[j].y-r[0].y)/(b[j].x-r[0].x>slope))
            {
                ltempb.push_back(b[j]);
                sum--;
            }
            else
            {
                rtempb.push_back(b[j]);
            }

        }
        if(sum==0)
        {
            pair[k]=i;
            break;
        }
        else
        {
            ltempr.clear();
            ltempb.clear();
            rtempb.clear();
            rtempr.clear();
        }


    }
    solve(ltempr,ltempb,pair);
    solve(rtempr,rtempb,pair);

}*/
int main()
{
    int n;
    cin>>n;
    vector <point> red(n/2);

    std::vector<point>blue(n/2);
    std::vector<point> tempred;
    std::vector<point> tempblue;
    std::vector<int> pair(n/2);
    for(int i =0;i<n/2;i++ )
    {
        cin>>red[i].x>>red[i].x;
    }
    for(int i=0; i<n/2; i++)
    {
        cin>>blue[i].x>>blue[i].y;
    }

    for (int i = 0; i < n/2; ++i)
       {
           pair[i]=i;
       }
    for(int i=0; i<n/2; i++)
    {
        for(int j=i+1; j<n/2; j++)
        {
            if(intersect(red[i],blue[pair[i]],red[j],blue[pair[j]]))
            {pair[i]=j;
            pair[j]=i;
            }
        }
    }
    for(int i=0; i<n/2; i++)
    {
        cout<<i<<" "<<pair[i]<<endl;
    }
    return 0;
}
