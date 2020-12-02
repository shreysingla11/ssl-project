#include <iostream>
#include <vector>
using namespace std;

class point
{
public :
    int x,y;

    point()
    {
        x=0;
        y=0;
    }

    point(int a,int b)
    {
        x=a;
        y=b;
    }
};

class res
{
public :
    int rleft,bleft,rright,bright;
    bool flag;
    vector<point> redvecleft,bluevecleft,redvecright,bluevecright;
};

class pairs
{
public :
    point a,b;


    pairs(point x,point y)
    {
        a=x;
        b=y;
    }

    float get_m()
    {
        return (b.y-a.y)/(b.x-a.x);
    }
    float get_c()
    {
        return a.y-get_m()*a.x;
    }

    bool if_left(point k)
    {
        if(get_m()*k.x-k.y+get_c()>0.0)
        {
            return true;
        }
        return false;
    }

};

res equal_left(int n,int i,int j,vector<point> r,vector<point> b)
{
    res result;
    int rleft=0,bleft=0,p;

    pairs q(r[i],b[j]);

    for(p=0; p<n; p++)
    {
        if(p==i&&p!=n-1)
        {
            p++;
        }
        if(q.if_left(r[p]))
        {
            rleft++;
            result.redvecleft.push_back(r[p]);
        }
        else
        {
            result.redvecright.push_back(r[p]);
        }
    }

    for(p=0; p<n; p++)
    {
        if(p==j&&p!=n-1)
        {
            p++;
        }
        if(q.if_left(b[p]))
        {
            bleft++;
            result.bluevecleft.push_back(b[p]);
        }
        else
        {
            result.bluevecright.push_back(b[p]);
        }
    }

    if(bleft==rleft)
    {
        result.flag=true;
        result.bleft=bleft;
        result.rleft=rleft;
        result.bright=n-bleft-1;
        result.rright=n-rleft-1;
    }
    else
    {
        result.flag=false;
    }

    return result;
}

void func(int n,vector<point> r,vector<point> b,vector<pairs> &result)
{
    res temp;
    int i,mid;
    if(r.empty()||b.empty())
    {

        return;
    }
    if(n==1)
    {
        pairs p(r[0],b[0]);
        result.push_back(p);
        return;
    }

    mid=n-1;
    for(i=1; i<n; i++)
    {
        temp=equal_left(n,mid,i,r,b);

        if((equal_left(n,mid,i,r,b).flag)&&((equal_left(n,mid,i,r,b).bleft>=1)||(equal_left(n,mid,i,r,b).bright>=1)))
        {

            result.push_back(pairs(r[mid],b[i]));

            func(temp.bleft,temp.redvecleft,temp.bluevecleft,result);
            func(temp.bright,temp.redvecright,temp.bluevecright,result);
            return;
        }
    }
}
int main()
{
    int two_n;
    vector<point> red,blue;
    vector<pairs> ans;

    cin>>two_n;
    point p;
    int n=two_n/2;
    for(int i=0; i<n; i++)
    {
        cin>>p.x;
        cin>>p.y;
        red.push_back(p);
    }
    for(int i=0; i<n; i++)
    {
        cin>>p.x;
        cin>>p.y;
        blue.push_back(p);
    }


    func(n,red,blue,ans);
    cout<<"Output format is different.";
    if(!(ans.empty()))
    {
        cout<<endl<<ans[0].a.x<<","<<ans[0].a.y<<"  "<<ans[0].b.x<<","<<ans[0].b.y<<endl;
        cout<<endl<<ans[1].a.x<<","<<ans[1].a.y<<"  "<<ans[1].b.x<<","<<ans[1].b.y<<endl;
        cout<<endl<<ans[2].a.x<<","<<ans[2].a.y<<"  "<<ans[2].b.x<<","<<ans[2].b.y<<endl;
    }
}

