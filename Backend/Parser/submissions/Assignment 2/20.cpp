#include<iostream>
 using namespace std;

 struct point{
 int x;
 int y;
 };

 struct  line{
 point a;
 point b;
 int red_num;
 int blue_num;
 };
bool check(line l1,line l2);
 int main()
 {
 int n=0;
 cin>>n;
 n=n/2;
 point red[n],blue[n];
line l[n];
for(int i=0;i<n;i++)
    cin>>red[i].x>>red[i].y;
for(int i=0;i<n;i++)
    cin>>blue[i].x>>blue[i].y;
for(int i=0;i<n;i++){
    l[i]={red[i],blue[i],i,i};
    //cout<<l[i].a.x<<l[i].a.y<<l[i].b.x<<l[i].b.y;
    }
while(1){
for(int i=0;i<n;i++)
    {
    for(int j=i+1;j<n;j++)
        {
        bool b=check(l[i],l[j]);
        if(b)
            {
            point c=l[i].b;
            l[i].b=l[j].b;
            l[j].b=c;
            int d=l[i].blue_num;
            l[i].blue_num=l[j].blue_num;
            l[j].blue_num=d;
        }
        }
    }
bool b=true;
for(int k=0;k<n;k++)
    {
    for(int m=k+1;m<n;m++)
        if(check(l[k],l[m]))
            {
            b=false;
            break;
            }
    if(b==false)
        break;
    }
if(b==true)
break;
}
for(int i=0;i<n;i++)
    {
    cout<<l[i].red_num<<" "<<l[i].blue_num<<"\n";
    }
return 0;
}

bool check(line l1,line l2)
{

if(((l2.a.y-l1.a.y)*(l1.b.x-l1.a.x)-(l2.a.x-l1.a.x)*(l1.b.y-l1.a.y))*((l2.b.y-l1.a.y)*(l1.b.x-l1.a.x)-(l2.b.x-l1.a.x)*(l1.b.y-l1.a.y))<0
 &&((l1.a.y-l2.a.y)*(l2.b.x-l2.a.x)-(l1.a.x-l2.a.x)*(l2.b.y-l2.a.y))*((l1.b.y-l2.a.y)*(l2.b.x-l2.a.x)-(l1.b.x-l2.a.x)*(l2.b.y-l2.a.y))<0)
return true;
else return false;
}
