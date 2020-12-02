#include<iostream>
#include<vector>
using namespace std;

bool intersect(vector<vector<int> > red,vector<vector<int> > blue,vector<int> b,int i,int j)
{

int x=(red[j][1]-red[i][1])*(blue[b[i]][0]-red[i][0])-(red[j][0]-red[i][0])*(blue[b[i]][1]-red[i][1]);

int y=(blue[b[j]][1]-red[i][1])*(blue[b[i]][0]-red[i][0])-(blue[b[j]][0]-red[i][0])*(blue[b[i]][1]-red[i][1]);

int a=(red[i][1]-red[j][1])*(blue[b[j]][0]-red[j][0])-(red[i][0]-red[j][0])*(blue[b[j]][1]-red[j][1]);

int c=(blue[b[i]][1]-red[j][1])*(blue[b[j]][0]-red[j][0])-(blue[b[i]][0]-red[j][0])*(blue[b[j]][1]-red[j][1]);

if((x*y)<0&&(a*c)<0){return true;}
else {return false;}
}

void combinations(vector<int> &a,int n,int k)
{
if(a[n-1]<k-1){a[n-1]=a[n-1]+1;
return ;}
else{a[n-1]=0;
if(n>1){combinations(a,n-1,k);
}
return ;}
}

bool check(vector<int> a,int n)
{

for(int i=0;i<n;i++)
{if(a[i]!=n-1){return false;}}
return true;
}

bool distinct(vector<int> a,int n)
{
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(a[i]==a[j]){return false;}
}
}
return true;
}

int main(){
int n;
cin>>n;
n=n/2;

vector<vector<int> > red(n,vector<int>(2));
for(int i=0;i<n;i++)
{
cin>>red[i][0];
cin>>red[i][1];
}
vector<vector<int> > blue(n,vector<int>(2));
for(int i=0;i<n;i++)
{
cin>>blue[i][0];
cin>>blue[i][1];
}

vector<int> a(n,0);
// for ensuring only one input
int z=0;

while(!check(a,n)&&z<1)
{
combinations(a,n,n);
if(distinct(a,n))
{
int print =1;

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
if(intersect(red,blue,a,i,j)){print=0;break;}
}
}

if(print==1){
z++;
for(int i=0;i<n;i++){cout<<i<<" "<<a[i]<<endl;}}
}

}

return 0;
}
