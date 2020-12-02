#include<iostream>
#include<vector>
using namespace std;
struct point
{
    int x;
    int y;
    point operator-(const point &b)
    {
        point temp;
        temp.x=x-b.x;
        temp.y=y-b.y;
        return temp;
    }
    int operator*(const point &b)
    {
        return x*b.y-y*b.x;
    }
};
bool intersect(point p,point b,point q,point d)
{
    point r,s;
    r=b-p;
    s=d-q;
    if(r*s!=0)
    {
        float t=((q-p)*r)/(r*s);

        float u=((q-p)*s)/(r*s);
        if(t>=0&&t<=1&&u>=0&&u<=1)
        {
            return true;
        }
    }
        return false;
}
vector<point>blue;
vector<point>red;

int main()
{
    int n;
    cin>>n;
    n=n/2;
    point temp= {0,0};
    red.assign(n,temp);
    blue.assign(n,temp);
    for(int i=0; i<n; i++)
    {
        cin>>red[i].x;
        cin>>red[i].y;
    }
    for(int i=0; i<n; i++)
    {
        cin>>blue[i].x;
        cin>>blue[i].y;
    }

    point A[n][2];
    int B[n];
    for(int i=0; i<n; i++)
    {
        A[i][0]=red[i];
        A[i][1]=blue[i];
        B[i]=i;
    }
lb:
    int i=0;
    int j;
    while(i<n)
    {
        j=i+1;
        while(j<n)
        {   if(intersect(A[i][0],A[i][1],A[j][0],A[j][1]))
            {
                temp=A[j][1];
                A[j][1]=A[i][1];
                A[i][1]=temp;
                B[j]=i;
                B[i]=j;
                i++;
                //goto lb;
            }
            j++;//cout<<j<<endl;
        }
        i++;
    }
    i=0;
while(i<n)
    {
        j=i+1;
        while(j<n)
        {
            if(intersect(A[i][0],A[i][1],A[j][0],A[j][1])!=0)
            {
                goto lb;
            }
            j++;//cout<<j<<endl;
        }
        i++;
    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<B[i]<<endl;
    }
    //cout<<intersect(red[0],blue[0],red[1],blue[1]);
    return 0;
}
