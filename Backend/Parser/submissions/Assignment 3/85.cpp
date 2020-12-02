#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int inf=n+1;
    int *A= new int [n];
    int *B= new int [m];
    for(int p=0; p<n; p++)
    {
        cin>>A[p];
    }
    for(int q=0; q<m; q++)
    {
        cin>>B[q];
    }
    int *X=new int [n];
    int *Y=new int [n];
    if(A[n-1]==B[m-1])
    {
        X[n-1]=1;
    }
    else
    {
        X[n-1]=inf;
    }
    for(int i=n-1; i>=1; i--)
    {
        if(A[i-1]==B[m-1])
        {
            X[i-1]=1;
        }
        else
        {
            X[i-1]=1+X[i];
        }
    }
    for(int j=m-2; j>=0; j--)
    {
        Y[n-1]=inf;
        for(int i=n-1; i>=1; i--)
        {
            if(A[i-1]==B[j])
            {
                Y[i-1]=1+X[i];
            }
            else
            {
                Y[i-1]=1+Y[i];
            }
        }
        for(int h=0; h<n; h++)
        {
            X[h]=Y[h];
        }
    }
    int mini=X[0];
    int p=1;
    for(int i=0; i<n; i++)
    {
        if(X[i]<mini)
        {
            mini=X[i];
            p=i+1;
        }
    }
    if(mini>n)
    {
        cout<<"INFINITY"<<endl;
        return 0;
    }
    cout<<mini<<" "<<p<<endl;
    return 0;
}
