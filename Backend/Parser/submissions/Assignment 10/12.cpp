#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class distinct
{
vector<int> v;
vector<int> l;
public:
int x,i,j;
int Count;
distinct(vector<int> v);
int num_distinct(int i, int j);

};
distinct::distinct(vector<int> u){
v=u;
x=v.size();
l.resize(x,-1);
for(int k=0;k<x;k++)
{
    for(int j=0;j<k;j++)
    {
    if(v[k]==v[j]){l[k]=j;}
    }

}

}

int distinct::num_distinct(int a,int b){
i=a;j=b;
Count=0;
for(int s=a;s<=b;s++)
{
//cout<<Count;
//if(!((l[i]>=i)&&(l[i]<=j))){Count++;}
//else  if(((l[i]>i)&&(l[i]<j))){Count--;}
if(l[s]>=a){Count++;}

}
return ((j-i-Count)+1);
}


