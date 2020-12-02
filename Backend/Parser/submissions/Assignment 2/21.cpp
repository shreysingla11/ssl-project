#include<iostream>
#include<vector>
using namespace std;
class point
{
public:
    int x;
    int y;
};
class line
{
public:
    point r;
    point b;
    bool isintersecting(line &l)
    {
        int a = (((l.r.x-l.b.x)*(r.y-l.r.y))-(l.r.y-l.b.y)*(r.x-l.r.x));
        // a=x b=y c=cf
        int d = (((r.x-l.r.x)*(b.y-r.y))-(r.y-l.r.y)*(b.x-r.x));
        int c = (((b.x-r.x)*(l.r.y-l.b.y))-(b.y-r.y)*(l.r.x-l.b.x));
        if(c==0)
            return false;
            //cout<<a/c<<" "<<d/c<<endl;
        if(((a/c)>=0)&&((d/c)>=0)&&((a/c)<=1)&&((d/c)<=1))
            return true;
        else
            return false;
    }
};
int main()
{
    int no_of_points;
    bool done=true;
    vector<point> red;
    vector<point> blue;
    vector<line> joinrb;
    cin>>no_of_points;
    for(int i=0; i<(no_of_points/2); i++)
    {
        point temp;
        cin>>temp.x>>temp.y;
        red.push_back(temp);
    }
    for(int i=0; i<(no_of_points/2); i++)
    {
        line l;
        point temp;
        cin>>temp.x>>temp.y;
        blue.push_back(temp);
        l.r=red[i];
        l.b=blue[i];
        joinrb.push_back(l);
    }
    while(done)
    {
        int i,j;
        for( i=0; i<(no_of_points/2); i++)
        {
            for( j=i+1; j<(no_of_points/2); j++)
            {
                if(joinrb[i].isintersecting(joinrb[j]))
                {
                 //cout<<i<<" "<<j<<endl;
                  //cout<<joinrb[i].r.x<<" "<<joinrb[i].r.y<<" "<<joinrb[i].b.x<<" "<<joinrb[i].b.y<<" "<< joinrb[j].r.x<<" "<<joinrb[j].r.y<<" "<<joinrb[j].b.x<<" "<<joinrb[j].b.y<<endl;
                    point temp;
                    temp=joinrb[j].b;
                    joinrb[j].b=joinrb[i].b;
                    joinrb[i].b=temp;
                    break;
                }
            }
            if(j<no_of_points/2)
                break;
        }
        if(i==no_of_points/2)
            done=false;

    }
    for(int i=0; i<(no_of_points/2); i++)
    {
        int index;
        for(index=0; index<no_of_points/2; index++)
        {
            if((blue[index].x==joinrb[i].b.x)&&(blue[index].y==joinrb[i].b.y))
                break;
        }
        cout<<i<<" "<<index<<endl;
    }
    return 0;
}
