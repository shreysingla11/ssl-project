#include<iostream>
#include<limits>
#include<vector>
using namespace std;

int main()
{

    int n,m,k,l;
    cin>>n>>m;
    int inf= n+1;

    vector<int> a;
    vector<int> b;

    for(int i=0; i<n; i++)
    {
        cin>>k;
        a.push_back(k);
    }

    for(int i=0; i<m; i++)
    {
        cin>>k;
        b.push_back(k);
    }

    int* M = new int[n];

    if(a[n-1]==b[m-1])
    {
        k=1;
    }
    else
    {
        k=inf;
    }
    M[n-1]=k;
    for(int i=n-1; i>0; i--)
    {
        if(a[i-1]==b[m-1])
        {
            M[i-1]=1;
        }
        else
        {
            M[i-1]=1+M[i];
        }
    }
    for(int i=0;i<n;i++){cout<<M[i];}
        cout<<endl;


    for(int i=m-2; i>=0; i--)
    {
        k=inf;
        l=k;
        for(int j=n-2; j>=0; j--)
        {
            if(a[j]==b[i])
            {
                k=1+M[j+1];
                M[j+1]=l;
                l=k;
                if(j==0){M[0]=k;}
            }
            else
            {
                k=1+l;
                M[j+1]=l;
                l=k;
                if(j==0){M[0]=k;}
            }

        }
        for(int i=0;i<n;i++){cout<<M[i];}
        cout<<endl;
    }
    int mini=M[0];
    k=1;
    for(int i=1; i<=n-1; i++)
    {
        if(M[i]<mini)
        {
            mini=M[i];
            k=i;
        }
    }

    if(k>n)
    {
        cout<<"infinity";
    }
    else
    {
        cout<<mini<<" "<<k+1;
    }
    return 0;
}


