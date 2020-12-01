#include<iostream>
#include<vector>
using namespace std;

int l(int i,int j,vector<int> a,vector<int> b,int n,int m)
{
    if((i==n-1)&& (j==m-1))
    {
        if(a[i]==b[j])
        {
            return 1;
        }
        else
        {
            return n+1;
        }
    }
    if ((i!=n-1)&& (j==m-1))
    {
        if(a[i]==b[j])
        {
            return 1;
        }
        else
        {
            return 1+l(i+1,j,a,b,n,m);
        }
    }
    if  ((i==n-1)&& (j!=m-1))
    {
        return n+1;
    }
    if(a[i]==b[j])
    {
        return 1+ l(i+1,j+1,a,b,n,m);
    }
    else
    {
        return 1+ l(i+1,j,a,b,n,m);
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a(n),b(m),k(n);
    int minlen=n+1;
    // minlen gives the length of substring of minimum size
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int j=0; j<m; j++)
    {
        cin>>b[j];
    }


    for(int i=0; i<n; i++)
    {
        if(a[i]==b[0])
        {
            k[i]=l( i,0,a,b,n,m);
            if(minlen>k[i])
            {
                minlen=k[i];
            }

        }

    }
    int p=0;
    for(int i=0; i<n; i++)
    {
        if(k[i]==minlen)
        {
            p=i+1;
            break;
        }
    }
    if (minlen!=n+1)
    {
        cout<<minlen<<" "<<p;
    }
    else
    {
        cout<<"infinite";
    }
    return 0;
}


