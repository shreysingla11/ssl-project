#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<map>
using namespace std;
map<int,int>M;
int *A,*B;
int n,m;
int a = numeric_limits<int>::max();
int f(int x,int y)
{
    if(x==n-1&&y==m-1)
    {
        if(A[n-1]==B[m-1])
        {
            return 1;
        }
        else
        {
            return a;
        }
    }
    if(x==n-1&&y<m-1)
    {
        return a;
    }

    if(x<n-1&&y<m-1)
    {
        if(A[x]==B[y])
        {
            return 1+f(x+1,y+1);
        }
        else
        {
            return 1+f(x+1,y);
        }
    }
    if(x<n-1&&y==m-1)
    {
        if(A[x]==B[m-1])
        {
            return 1;
        }
        else
        {
            return 1+f(x+1,m-1);
        }
    }
}
int main()
{
    cin>>n;
    cin>>m;
    int p=0,q=n-1;
    A=new int[n];
    B=new int[m];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>B[i];
    }
    bool temp1=true,temp2=true;
    for(int i=0; i<n&&(temp1||temp2); i++)
    {
        if(A[n-i-1]==B[m-1]&&temp2&&p<q)
        {
            q=n-i-1;
            temp2=false;
        }
        if(A[i]==B[0]&&temp1&&p<q)
        {
            p=i;
            temp1=false;
        }
    }
    vector<int>L;
    if(p>q)
    {
        L.push_back(a);
    }
    else
    {
        for(int i=p; i<=q; i++)
        {
            int temp=f(i,0);
            L.push_back(temp);
            M[temp]=i+1;
        }
    }
    sort(L.begin(),L.end());
    for(int i=0; i<L.size(); i++)
    {
        if(L[i]>=0)
        {
            if(L[i]>=a)
            {
                cout<<"infinity";
            }
            else
                cout<<L[i]<<" "<<M[L[i]];
            return 0;
        }
    }
}
