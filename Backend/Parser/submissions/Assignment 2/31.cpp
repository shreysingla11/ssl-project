#include<iostream>
#include<vector>
using namespace std;

struct point
{
    int x;
    int y;
};

bool diff_side(point p1,point p2,point p3,point p4)
{
    if(((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x))*((p4.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p4.x-p1.x))<0)
    { return true;}
    else
    { return false;}
};

bool intersect(point p1,point p2,point p3,point p4)
{
    if ((diff_side(p1,p2,p3,p4))&&(diff_side(p3,p4,p1,p2)))
    {return true;}
    else {return false;}
};

int main()
{
    int n;
    cout<<"Give Input :";
    cin>>n;
    n=n/2;
    int i=0, j=0;
    vector <point> red;
    vector <point> blue;
    while(i<n)
    {
        point p;
        red.push_back(p);
        blue.push_back(p);
        i=i+1;
    }
    i=0;
    j=0;
    while(i<n)
    {

        cin>>red[i].x;
        cin>>red[i].y;
        i=i+1;
    }
    while(j<n)
    {
        cin>>blue[j].x;
        cin>>blue[j].y;
        j=j+1;
    }

    i=0;
    j=0;

    int blue1[5000];
    int l=0;
    while(l<n)
    {
        blue1[l]=l;
        l=l+1;
    }
    point temp;
    while (i<n-1)
    {
        j=i+1;
        while (j<n)
        {

            if(intersect(red[i],blue[i],red[j],blue[j]))
            {
                temp.x=blue[i].x;
                temp.y=blue[i].y;
                blue[i].x=blue[j].x;
                blue[i].y=blue[j].y;
                blue[j].x=temp.x;
                blue[j].y=temp.y;
                blue1[i]=j;
                blue1[j]=i;

            }
            else
            {

            }
            j=j+1;
        }

        i=i+1;
    }

    l=0;
    while(l<n)
    {
        cout<<"\n"<<l<<" "<<blue1[l]<<endl;
        l=l+1;
    }

    return 0;
}
