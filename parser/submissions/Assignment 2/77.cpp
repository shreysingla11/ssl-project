#include<iostream>
#include<string>
#include<vector>
using namespace std;

class point
{
    public:
    double x = 0;
    double y = 0;
    int index = 0;
    int pairs = 0;
};

bool intersect(point a,point b,point c,double slope[]);
int main()
{
int n = 0, i = 0,j = 0;
cin >> n;
n = n/2;
double* slope = new double[n];
point* red = new point[n];
point* blue = new point[n];
for (i = 0;i < 2*n;i++)
{
    int x,y;

    if(i < n)
        {
        cin>>x>>y;
        red[i].x = x;
        red[i].y = y;
        if(i != n-1) red[i].pairs = i+1;
        if(i == n) red[n-1].pairs = 0;
        red[i].index = i;}
    else
        {
        cin>>x>>y;
        blue[i-n].x = x;
        blue[i-n].y = y;
        slope[i-n] = (red[i-n].y-blue[i-n].y)/(red[i-n].x-blue[i-n].x);
        }
}
int k = 1;
k = 1;
//while(k)
//{
//for(i=0;i<n;i++){
//
//
//        if(red[i].x == blue[red[i].pairs].x){
//
//
//                red[i].pairs = i+1;
//                slope[i] = (red[i].y-blue[i+1].y)/(red[i].x-blue[i+1].x);
//                slope[i+1] = (red[i+1].y-blue[i].y)/(red[i+1].x-blue[i].x);
//                break;
//
//
//            }
//
//
//        }
//for(i=0;i<n;i++){
//
//        {if(red[i].x == blue[red[i].pairs].x){k = 1;
//                                                break;}
//        }}
//}
k=1;
while(k)
{
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++)
        {

        if(intersect(red[i],red[j],blue[red[i].pairs],slope)){

                red[i].pairs = j;
                red[j].pairs = i;
                slope[i] = (red[i].y-blue[j].y)/(red[i].x-blue[j].x);
                slope[j] = (red[j].y-blue[i].y)/(red[j].x-blue[i].x);
                break;


            }

        }
        }
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++)
        { if(intersect(red[i],red[j],blue[red[i].pairs],slope)){}
        else k = 0;}}
}

for(i = 0;i<n;i++){
cout<<red[i].index<<" "<<red[i].pairs<<endl;
}
return 0;
}

bool intersect(point a,point b,point c,double slope[])
{
   double x = 0;

    x = (b.y - a.y - slope[b.index]*b.x + slope[a.index]*a.x)/(slope[a.index]-slope[b.index]);
    if(((x <= a.x)&&(x >= c.x))||((x >= a.x)&&(x <= c.x)))
        return true;
    else return false;

}
