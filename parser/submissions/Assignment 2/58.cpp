#include<iostream>
#include<vector>
using namespace std;

class point
{
public:
 int x;
 int y;
 int link;
};


int main()
{
int n;
cin>>n;
vector<point> r,b;
point input;
int i=0;
int t=0;int l0;int l1;
while(i < n/2)
{
 cin>>input.x>>input.y;
 input.link=n/2-i-1;
 r.push_back(input);
 i++;
}
i=0;
while(i < n/2)
{
 cin>>input.x>>input.y;
 input.link=i;
 b.push_back(input);
 i++;
}

i= n/2 -1;
while(i>0)
{
  t=i-1;
  while(!(t<0))
  {
  l0=r[t].link;l1=r[i].link;
  int t1,t2;
 t1 = ((r[t].y-r[i].y)*(b[l1].x-r[i].x) - (r[t].x-r[i].x)*(b[l1].y-r[i].y));
 t2 = ((b[l0].y-r[i].y)*(b[l1].x-r[i].x) - (b[l0].x-r[i].x)*(b[l1].y-r[i].y));
 if(t1*t2 < 0)
 {
 t1 = (r[i].y-r[t].y)*(b[l0].x-r[t].x) - (r[i].x-r[t].x)*(b[l0].y-r[t].y);
 t2 = (b[l1].y-r[t].y)*(b[l0].x-r[t].x) - (b[l1].x-r[t].x)*(b[l0].y-r[t].y);

 if(t1*t2 < 0){r[i].link=l0;r[t].link=l1;t= i -1;}
 }
  t--;
  }
  i--;
  }
  i=0;
  while(i<n/2)
  {
  cout<<i<<" "<<r[i].link<<endl;i++;
  }
return 0;
}

