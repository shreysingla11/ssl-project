#include<vector>
#include<iostream>
using namespace std;
int main()
{
int twoN;
cin>>twoN;
int n=twoN/2;
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
vector<vector<int> > pairs(n,vector<int>(2));
for(int i=0;i<n;i++)
{
pairs[i][0]=i;
pairs[i][1]=i;
}
bool satisfy=true;
do
{
satisfy=true;
int r1,r2,r3,r4,b1,b2,b3,b4,a,b,c,d;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
    a=pairs[i][0];
    b=pairs[i][1];
    c=pairs[j][0];
    d=pairs[j][1];

    r1=red[a][0];
    r2=red[a][1];
    b1=blue[b][0];
    b2=blue[b][1];

    r3=red[c][0];
    r4=red[c][1];
    b3=blue[d][0];
    b4=blue[d][1];

    if((((r4-b2)*(b1-r1)-(r3-b1)*(b2-r2))*((b4-b2)*(b1-r1)-(b3-b1)*(b2-r2)))<0 && (((r2-b4)*(b3-r3)-(r1-b3)*(b4-r4))*((b2-b4)*(b3-r3)-(b1-b3)*(b4-r4))) )
    {
        pairs[i][1]=d;
        pairs[j][1]=b;
        satisfy=false;
    }

    }
}
}while(!satisfy);
for(int i=0;i<n;i++)
{
cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
}
}
