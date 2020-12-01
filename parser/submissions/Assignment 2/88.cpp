#include<iostream>
#include<vector>
using namespace std;
class Point
{
public:
    int x;
    int y;
    int num;
};
/*class Pair
{
public:
    Point r;
    Point b;
};*/
bool intersect(Point p1,Point q1,Point p2,Point q2);
int main()
{
    int i=0,Size;
    bool b=false;
    cin>>Size;
    vector<Point> R(Size/2);
    vector<Point> B(Size/2);
    // vector<Pair> seg(Size/2);
    while(i<Size/2)
    {
        cin>>R[i].x>>R[i].y;
        R[i].num=i;
        i++;
    }
    i=0;
    while(i<Size/2)
    {
        cin>>B[i].x>>B[i].y;
        B[i].num=i;
        i++;
    }
    while(!b)
    {
    b=true;
    for(int i=0; i<Size/2; i++)
    {
        int j=i+1;
        while(j<Size/2)
        {
        //cout<<R[0].x<<R[0].y<<B[0].x<<B[0].y<<R[2].x<<R[2].y<<B[2].x<<B[2].y<<endl;
        //cout<<intersect(R[i],B[i],R[j],B[j])<<endl;
        if(intersect(R[i],B[i],R[j],B[j]))
        {
            Point temp;
            temp.x=B[i].x;
            temp.y=B[i].y;
            temp.num=B[i].num;
            B[i].x=B[j].x;
            B[i].y=B[j].y;
            B[i].num=B[j].num;
            B[j].x=temp.x;
            B[j].y=temp.y;
            B[j].num=temp.num;
        }
        j++;
        }
    }
    for(int i=0;(i<Size/2);i++)
    {
    for(int j=i+1;(j<Size/2);j++)
    {
        b=(!(intersect(R[i],B[i],R[j],B[j]))&&b);
        //cout<<intersect(R[i],B[i],R[j],B[j])<<endl;
    }
    }
    }
    for(int i=0;i<Size/2;i++)
    cout<<R[i].num<<" "<<B[i].num<<endl;
    return 0;
}
double slope(Point p,Point q)
{
    if((q.x-p.x)!=0)
    {
       // cout<<"bye"<<endl;
        double sl=(q.y-p.y)*1.0;
        double a=(q.x-p.x);
       // cout<<(q.y-p.y)<<endl;
        //cout<<sl/a<<"sl"<<endl;
        return sl/a;
    }
}
bool btw(Point p,Point q,double x)
{
    if((x<=q.x&&x>=p.x)||(x<=p.x&&x>=q.x))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool btwy(Point p,Point q,double y)
{
    if((y<=q.y&&y>=p.y)||(y<=p.y&&y>=q.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool intersect(Point p1,Point q1,Point p2,Point q2)
{
    double x,y;
    if((q1.x!=p1.x)&&(q2.x!=p2.x))
    {
    //cout<<"hi";
        y=slope(p2,q2)-slope(p1,q1);
        if(y!=0)
        {
            x=(q1.y-q2.y+q2.x*slope(p2,q2)-q1.x*slope(p1,q1))/y;
           // cout<<x<<"=x"<<endl;
            return (btw(p1,q1,x)&&btw(p2,q2,x));
        }
        else
            return false;    //since no three points are collinear
    }
    else
    {
        if((q1.x==p1.x)&&(q2.x==p2.x))
        {
            return false;
        }
        if(q1.x==p1.x)
        {
            return (btw(p2,q2,p1.x)&&btwy(p1,q1,(q2.y+slope(p2,q2)*(p1.x-q2.x))));
        }
        if(q2.x==p2.x)
        {
            return (btw(p1,q1,p2.x)&&btwy(p2,q2,(q1.y+slope(p1,q1)*(p2.x-q1.x))));
        }
    }
}






