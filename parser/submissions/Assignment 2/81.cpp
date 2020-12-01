#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<int> > &x,int i,int p)
{
    int b=0,r=0;
    for(int j=0; j<(x.size()/2); j++)
    {
if(((x[j][1]-x[p][1])*(x[i][0]-x[p][0])-(x[j][0]-x[p][0])*(x[i][1]-x[p][1])) >0 )
        {
            r++;
        }
    }

    for(int j=x.size()/2; j<x.size(); j++)
    {
if(((x[j][1]-x[p][1])*(x[i][0]-x[p][0])-(x[j][0]-x[p][0])*(x[i][1]-x[p][1])) >0 )
        {
            b++;
        }
    }

    if(r==b && r!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void fun(vector<vector<int> > &x)
{
    if(x.size()==0)
    {
        return ;
    }
    if(x.size()==2)
    {
        cout<<x[0][2]<<" "<<x[1][2]<<endl;
        return ;
    }
    else
    {
        int j,e;
        for( e=0; e<(x.size()/2); e++)
        {
            for(j=(x.size()/2); j<x.size(); j++)
            {
                if(check(x,j,e))
                {
                    break;
                }
            }

         }

            cout<<x[e][2]<<" "<<x[j][2]<<endl;
            int g,k,o,l;
            g = x[e][0];
            k = x[e][1];
            o = x[j][0];
            l = x[j][1];
            x.erase(x.begin() + e);
            x.erase(x.begin() + j -1);
            vector<vector<int> > w = x;
            vector<vector<int> > u = x;
            int m;
            int r=0,s=0;
            for(m=0; m<x.size(); m++)
            {
                if(((x[m][1]-k)*(o-g)-(x[m][0]-g)*(l-k)) >0)
                {
                    w.erase(w.begin() + m-r );
                    r++;
                }
                else
                {
                    u.erase(u.begin() + m-s);
                    s++;
                }
            }
            fun(u);
            fun(w);
        }
    }

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > points;
    for(int i=0; i<n; i++)
    {
        vector<int> p;
        int x,y;
        cin>>x;
        cin>>y;
        p.push_back(x);
        p.push_back(y);
        if(i<n/2)
        {
            p.push_back(i);
        }
        else
        {
            p.push_back(i - n/2);
        }
        points.push_back(p);
    }

    fun(points);
    return 0;
}
