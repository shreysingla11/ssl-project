#include<iostream>
#include<vector>
using namespace std;

class point
{
    public:
    int x,y,ind;
};

bool Check(int i,int j,vector<point>P1,vector<point>P2,vector<point>P3,int p)
{
    int x1=P1[i].x,y1=P1[i].y,x2=P2[j].x,y2=P2[j].y,x3=P3[p].x,y3=P3[p].y;
    if(x1==x2)
    {
        if(x3>x1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        float m=(y2-y1)/(x2-x1);
        float c=y1-m*x1;
        if((m*x3-y3+c)>0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Line(int i,int j,vector<point> a,vector<point> b)
{
    if(a.size()==1)
    {
        return true;
    }
    int rg=0,bg=0;
    for(int p=0; p<a.size(); p++)
    {
        if(Check(i,j,a,b,a,p))
        {
            rg++;
        }
        if(Check(i,j,a,b,b,p))
        {
            bg++;
        }
    }
    if(rg==bg)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void Output_Pairs(vector<point> m,vector<point> n)
{
    if(m.empty())
    {
        return;
    }
    for(int i=0; i<m.size(); i++)
    {
        for(int j=0; j<n.size(); j++)
        {

            if(m.size()==1)
            {
                cout<<m[0].ind<<" "<<n[0].ind<<endl;
            }
            if(Line(i,j,m,n))
            {
                cout<<m[i].ind<<" "<<n[j].ind<<endl;
                m.erase(m.begin()+i);
                n.erase(n.begin()+j);
                if(m.size()==1)
                {
                    cout<<m[0].ind<<" "<<n[0].ind<<endl;
                }
                i=0;
                j=0;
            }
        }
    }
    return;
}

int main()
{
    int n,a;
    cin>>a;
    n=(a/2);

    vector<point>RedPoints(n);
    vector<point>BluePoints(n);

    for(int i=0; i<n; i++)
    {
        cin>>RedPoints[i].x>>RedPoints[i].y;
        RedPoints[i].ind=i;
    }
    for(int i=0; i<n; i++)
    {
        cin>>BluePoints[i].x>>BluePoints[i].y;
        BluePoints[i].ind =i;
    }
    if(RedPoints.size()==1)
    {
        cout<<RedPoints[0].ind<<" "<<BluePoints[0].ind<<endl;
        return 0;
    }
    Output_Pairs(RedPoints,BluePoints);
    return 0;
}
