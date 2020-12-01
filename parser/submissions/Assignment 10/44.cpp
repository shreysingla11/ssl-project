#include<iostream>
#include<vector>

using namespace std;

class distinct{
vector<int> v0;
int l[];
public:
distinct(vector<int> v);
int num_distinct(int i, int j);
};

distinct::distinct(vector<int> v){
v0=v;
int l1[v0.size()];
for(int i=0;i<v0.size();i++)
{
    l[i]=l1[i];
    l[i]=-1;
    for(int j=0;j<i;j++)
    {
        if(v0[i]==v0[j] && j>l[i])
        {
            l[i]=j;
        }
    }
}
}

int distinct::num_distinct(int i, int j){
int n = v0.size(),count=0;
int a = (n/2),b = 3*(n/4),c = (n/4);
int root_arr[n],A[n],B[n],merged_arr[n];//A and B arrays are to store number of numbers in upper half and lower half intervals
for(int j=0;j<n;j++) // for the array which we will store at the root
{
    root_arr[j]=0;
    A[j]=0;
    B[j]=0;
    for(int i=0;i<=j;i++)
    {
        if(l[j] <= n/2)
        {
            root_arr[j]++;
        }
    }

    if(l[j]>=b && l[j]<=(n-1))
    {
        A[j]++;
    }
    if(l[j]>=c && l[j]<=(a-1))
    {
        B[j] = root_arr[j]+1;
    }
}

for(int x=0;x<n;x++)
{
    if(l[x]>=a)
    {
        mergerd_arr[x]=A[x];
    }
    else
    {
        merged_arr[x]=B[x];
    }
}

}
