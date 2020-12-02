#include <iostream>
#include <vector>
#include <algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;
struct point
{
    double start;
    char type;
};
bool comparator(const point& point1, const point& point2)
{
    return point1.start<point2.start;
}
int main()
{
    point temp;
    int n,w,u,v,t1,t2;
    char dir;
    vector <point> occupied;
    int m,len,pos;
    double factor;
    int count=0;
    cin>>n>>w>>u>>v>>t1>>t2;
    for (int i=0; i<n; i++)
    {

        cin>>dir;
        cin>>m;
        if ( dir == 'E')
        {
            factor = -1.0;
        }
        else factor = 1.0;
        for (int j = 0; j<m; j++)
        {
            cin>>len;
            cin>>pos;
            temp.start = (factor*pos/u)-(w+0.0)/v-i*(w+0.0)/v;
            temp.type = 'S';
            occupied.push_back(temp);

            temp.start = (len+factor*pos)/u-i*(w+0.0)/v;
            temp.type = 'E';
            occupied.push_back(temp);
        }
    }
    sort(occupied.begin(),occupied.end(),comparator);
    /*for (int k =0; k<occupied.size(); k++)
    {
        cout<< occupied[k].start<<" "<<occupied[k].type<<'\t';
    }*/
    double last0 = t1+0.0;
    double templength;
    int k;
    double maximum = 0.0;
    for ( k=0; k<occupied.size();)
    {
        if (occupied[k].start<=t2)
        {
            if (count == 0)
            {
                templength=occupied[k].start-last0;
                if (templength>maximum) maximum = templength;
            }
            if (occupied[k].type=='S')
            {
                count++;
                if (count==0&&occupied[k].start>=t1) last0=occupied[k].start;
            }
            else
            {
                count--;
                if (count ==0&&occupied[k].start>=t1) last0= occupied[k].start;
            }
        k++;
        }
        else break;
    }
    /*cout<<maximum<<endl;
    cout<<k<<endl;
    cout<<occupied[k-1].start<<endl;
    cout<<t2-occupied[k-1].start<<endl;*/
    //printf("%.8f",maximum);
    if (t2-occupied[k-1].start>maximum&&count==0) maximum = t2-occupied[k-1].start;
    printf("%.8f",maximum);
    cout<<endl;

    return 0;
}
