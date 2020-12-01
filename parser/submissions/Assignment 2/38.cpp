#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class point
{
public:
    int x;
    int y;
    int index;
    point()
    {

    };
    point(int a1,int a2,int ind)
    {
        x=a1;
        y=a2;
        index=ind;
    }
};

bool solver(vector<point> R,vector<point> B)
{
    int red_no=0;
    int blue_no=0;
    int n=R.size();
    if(n==1||n==0)
    {
        if(n==1)
        {
            cout<<R[0].index<<" "<<B[0].index<<endl;

        }
        else
        {
        }
        return 1;
    }
    else
    {
        point sol_1;
        point sol_2;
        sol_1.x=10001;
        sol_2.x=10001;
        vector<point> red_l;
        vector<point> blue_l;
        vector<point> red_r;
        vector<point> blue_r;
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<n; j++)
            {
                if((R[0].y-R[j].y)*(R[0].x-B[i].x)<(R[0].x-R[j].x)*(R[0].y-B[i].y))
                {
                    red_no++;
                    red_l.push_back(R[j]);
                }
                else
                {
                    red_r.push_back(R[j]);
                }
            }
            for(int j=0; (j<n); j++)
            {
                if(j==i)
                {
                    continue;
                }
                else
                {
                    if((R[0].y-B[j].y)*(R[0].x-B[i].x)<(R[0].x-B[j].x)*(R[0].y-B[i].y))
                    {
                        blue_no++;
                        blue_l.push_back(B[j]);
                    }
                    else
                    {
                        blue_r.push_back(B[j]);
                    }
                }
            }

            if(red_no==blue_no)
            {
                sol_1=R[0];
                sol_2=B[i];
                break;
            }
            else
            {
                red_l.clear();
                blue_l.clear();
                red_r.clear();
                blue_r.clear();
                red_no=0;
                blue_no=0;
            }

        }

        if(sol_1.x!=10001&&sol_2.x!=10001)
        {
            cout<<sol_1.index<<" "<<sol_2.index<<endl;
            solver(red_l,blue_l);
            solver(red_r,blue_r);
            return 1;
        }
        else
        {
            return 0;
        }
    }

}
int main()
{
    int N;
    cin>>N;
    int n=N/2;
    vector<point> R;
    for(int i=1; i<=n; i++)
    {
        point p;
        cin>>p.x>>p.y;
        p.index=i-1;
        R.push_back(p);

    }
    vector<point> B;
    for(int i=1; i<=n; i++)
    {
        point p;
        cin>>p.x>>p.y;
        p.index=i-1;
        B.push_back(p);

    }

    for(int i=1; i<n; i++)
    {
        if(solver(R,B)==1)
        {
            break;
        }
        else
        {
            point t;
            t=R[0];
            R[0]=R[i];
            R[i]=t;
        }
    }
    return 0;

}
