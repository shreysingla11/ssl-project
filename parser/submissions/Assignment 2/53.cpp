#include<iostream>
#include<algorithm>
#include<math.h>
#define PI 3.14159265
using namespace std;
struct point
{
 int x;
 double y;
 double slope;
 int index;

 };
 bool compare( point lhs, point rhs) { return lhs.slope < rhs.slope; };
 int main()
 {int start =0;
  int n;
  cin>>n;
  int end =n;
  cout<<endl;
  point a[n/2],b[n/2];
  for(int i=0;i<n/2;i++)
      {
        cin>>a[i].x>>a[i].y;
if(a[i].x==0&&a[i].y>=0){a[i].slope=0;}
if(a[i].x==0&&a[i].y<0){a[i].slope=180;}
if(a[i].x>0&&a[i].y>=0){a[i].slope=atan(a[i].y/a[i].x)*180/PI;}
if(a[i].x>0&&a[i].y<=0){a[i].slope=atan(a[i].y/a[i].x)*180/PI+2*PI;}
if(a[i].x<0&&a[i].y>=0){a[i].slope=atan(a[i].y/a[i].x)*180/PI+PI;}
if(a[i].x<0&&a[i].y<=0){a[i].slope=atan(a[i].y/a[i].x)*180/PI+PI;}
a[i].index=i;
        }
for(int i=0;i<n/2;i++)
      {
        cin>>b[i].x>>b[i].y;
if(b[i].x==0&&b[i].y>=0){b[i].slope=0;}
if(b[i].x==0&&b[i].y<0){b[i].slope=180;}
if(b[i].x>0&&b[i].y>=0){b[i].slope=atan(b[i].y/b[i].x)*180/PI;}
if(b[i].x>0&&b[i].y<=0){b[i].slope=atan(b[i].y/b[i].x)*180/PI+2*PI;}
if(b[i].x<0&&b[i].y>=0){b[i].slope=atan(b[i].y/b[i].x)*180/PI+PI;}
if(b[i].x<0&&b[i].y<=0){b[i].slope=atan(b[i].y/b[i].x)*180/PI+PI;}
b[i].index=i;
        }
std::sort(a, a+n/2, compare);
std::sort(b, b+n/2, compare);
for(int j=0;j<n/2;j++)
{cout<<a[j].index<<' '<<b[j].index<<endl;
}
  return 0;}


