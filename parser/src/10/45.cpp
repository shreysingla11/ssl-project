#include<iostream>
#include<vector>
using namespace std;
class distinct{
private:
int * l;
int ** L;
public:
distinct(vector<int> v)
{
int s=v.size();
l = new int[s];
for(int i=0;i<s;i++)
{
    l[i]=-1;
}
for(int i=0;i<s;i++)
{
    for(int j=i+1;j<s;j++)
    {
    if(v[i]==v[j]){l[j]=i;}
    }
}

L = new int*[s];
for(int i=0;i<s;i++)
{
    L[i] = new int[s];
}
for(int i=0;i<s;i++)
{
L[i][i]=0;
}

for(int i=0;i<s;i++)
{
    for(int j=i+1;j<s;j++)
    {
    if(l[j]>=i){L[i][j]=1+L[i][j-1];}
    else{L[i][j]=L[i][j-1];}
    }
}

return ;
}
int num_distinct(int i,int j)
{
if(i<=j){return j-i+1-L[i][j];}
if(j<i){return 0;}
}
};

