#include <iostream>
using namespace std;
class point
{
public:
double x;
double y;
int c;
};
int main()
{
int red=0;
int blue=0;
int twon;
cin>>twon;
point R[twon/2];
point B[twon/2];
point A[twon];
for(int i=0;i<twon/2;i++)
{
cin>>R[i].x>>R[i].y;
R[i].c=0;
A[i].x=R[i].x;A[i].y=R[i].y;
A[i].c=0;

}
for(int i=0;i<twon/2;i++)
{
cin>>A[i+twon/2].x>>A[i+twon/2].y;
A[i+twon/2].c=1;

B[i].x=A[i+twon/2].x;B[i].y=A[i+twon/2].y;

B[i].c=1;
}
/*
for(int i=2;i<twon;i++)
{
if(A[i].y-A[0].y-(A[i].x-A[0].x)*(A[1].y-A[0].y)/(A[1].x-A[0].x)>=0{if(A[i].c==0){red++;}else{blue++;}}

}
if(red==blue)

for(int i=0;i<twon-3;i++)
{
if(A[i+2].x>A[i].x&&A[i+3].x>A[i].x&&A[i+2].x>A[i+1].x&&A[i+3].x>A[i+1].x||(A[i+2].x>A[i].x&&A[i+3].x>A[i].x&&A[i+2].x>A[i+1].x&&A[i+3].x>A[i+1].x)
}
*/
int bin=400;
int counter=0;
A[0]=R[0];
for(int k=0;k<twon/2;k++){
for(int i=0;i<twon/2;i++)
{
for(int j=0;j<twon;j++)
{
if((A[j].y-R[k].y-(A[j].x-R[k].x)*(B[i].y-R[k].y)/(B[i].x-R[k].x))>=0){if(A[j].c==0){red++;}else{blue++;}}


}
if(red==blue){bin=i;counter=k;break;}
red=0;blue=0;
}
cout<<counter<<" "<<bin<<endl;
}}
