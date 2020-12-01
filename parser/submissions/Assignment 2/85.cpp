#include<iostream>
#include<vector>
using namespace std;

class point
{
public:
    int x;
    int y;
    point(int a,int b)
    {
        x=a;
        y=b;
    }
    point()
    {
        ;
    }
};
float slope(point a,point b);
bool willintersect(point r1, point b1, point r2, point b2);
int main()
{
    int twon;
    cin>>twon;
    vector<point> red;
    vector<point> blue;
    int a,b,n=(twon/2);
    for(int i=0; i<(twon/2); i++)
    {
        cin>>a>>b;
        red.push_back(point(a,b));
    }
    for(int i=0; i<(twon/2); i++)
    {
        cin>>a>>b;
        blue.push_back(point(a,b));
    }
    vector<int> A(n,-1);
    /*for(int a=0; a<n; a++)
    {
        for(int b=0; b<a; b++)
        {
            A[a]=b;
            {
                for(int c=0; c<a; c++)
                {
                    if(A[c]=b)
                    {
                        continue;
                    }
                    if(A[c]!=b)
                    {

                        for(int d=0; d<n; d++)
                        {
                            if(b!=d)
                            {
                                A[c]=d;
                                if(willintersect(red[a],blue[b],red[c],blue[d]))
                                {
                                    A[a]=d;
                                    A[c]=b;
                                }
                            }
                        }
                    }
                }
            }
        }
    }*/
    for(int i=0;i<n;i++)
    {
    A[i]=i;
    }
    bool flag=true;
    while(flag)
    {flag = false;
    for(int a=0;a<n;a++)
    {
    for(int c=0;c<n;c++)
    {
    if(a!=c){
    if(willintersect(red[a],blue[A[a]],red[c],blue[A[c]]))
                                { flag = true;
                                int temp=A[a];
                                    A[a]=A[c];
                                    A[c]=A[a];
                                }
                                }

    }
    }
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<A[i];
        cout<<endl;
    }

    return 0;
}
float slope(point a,point b)
{
    return ((b.y-a.y)*1.0)/(b.x-a.x);
}
bool willintersect(point r1, point b1, point r2, point b2)
{
    if((slope(r1,r2)-slope(r1,b1))*(slope(r1,b2)-slope(r1,b1))<=0)
    {
        return true;

    }
    else
        return false;
}


