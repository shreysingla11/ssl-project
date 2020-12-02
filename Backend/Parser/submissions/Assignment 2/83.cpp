#include<iostream>
#include<vector>
using namespace std;

struct point
{

    int x,y;
    int color;
    int index;

};
struct line
{

    point rp,bp;

};

int intersect(line &l1,line &l2)
{
    int c1,c2,c3,c4;
    c1=(l2.rp.y)*(l1.rp.x-l1.bp.x)+(l2.rp.x)*(l1.bp.y-l1.rp.y)+(l1.rp.y*l1.bp.x)-(l1.rp.x*l1.bp.y);
    c2=(l2.bp.y)*(l1.rp.x-l1.bp.x)+(l2.bp.x)*(l1.bp.y-l1.rp.y)+(l1.rp.y*l1.bp.x)-(l1.rp.x*l1.bp.y);
    c3=(l1.rp.y)*(l2.rp.x-l2.bp.x)+(l1.rp.x)*(l2.bp.y-l2.rp.y)+(l2.rp.y*l2.bp.x)-(l2.rp.x*l2.bp.y);
    c4=(l1.bp.y)*(l2.rp.x-l2.bp.x)+(l1.bp.x)*(l2.bp.y-l2.rp.y)+(l2.rp.y*l2.bp.x)-(l2.rp.x*l2.bp.y);

    if((c1*c2<0)&&(c3*c4<0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cin>>n;
    int i;
    n=n/2;

    vector< point >  r(n);
    vector< point >  b(n);

    for(i=0; i<n; i++)
    {
        cin>>r[i].x>>r[i].y;
        r[i].color=0;
        r[i].index=i;
    }

    for(i=0; i<n; i++)
    {
        cin>>b[i].x>>b[i].y;
        b[i].color=1;
        b[i].index=i;
    }

    vector<line> l(n);
    int s=0;

    for(i=0; i<n; i++)
    {
        l[i].rp=r[i];
        l[i].bp=b[i];
    }

    int j,k;
    bool f=true;
    point temp;

    for(;f!=false;)
    {
        f=false;
        for(j=0; j<n; j++)
        {
            for(k=j+1; k<n; k++)
            {
                if(intersect(l[j],l[k])==1)
                {
                    f=true;
                    temp=l[j].bp;
                    l[j].bp=l[k].bp;
                    l[k].bp=temp;

                }

            }

        }

    }

    for(i=0;i<n;i++)
    {
    cout<<l[i].rp.index<<"  "<<l[i].bp.index;cout<<endl;
    }

    /*
    point p1,p2;
    p1.x=1;p1.y=2;
    p2.x=1;p2.y=0;
    line l1;
    l1.rp=p1;l1.bp=p2;

    point p3,p4;
    p3.x=0;p3.y=1;
    p4.x=2;p4.y=1;
    line l2;
    l2.rp=p3;l2.bp=p4;
    cout<<intersect(l1,l2);
    */
    return 0;

}
