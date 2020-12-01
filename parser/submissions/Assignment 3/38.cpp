#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int *A=new int[n];
    for(int i=0;i<n;i++)cin>>A[i];
    int *B=new int[m];
    for(int i=0;i<m;i++)cin>>B[i];
    int *L=new int[n];

    if(A[n-1]==B[m-1])L[n-1]=1;
    else L[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]==B[m-1])L[i]=1;
        else
        {
            if(L[i+1]==-1)L[i]=-1;
            else L[i]=1+L[i+1];
        }
    }
    int temp1=L[n-1],temp2;
    L[n-1]=-1;
    for(int j=m-2;j>=0;j--)
    {
        for(int i=n-2;i>=0;i--)
        {
            temp2=L[i];
            if(A[i]==B[j])
            {
                if(temp1==-1)L[i]=-1;
                else L[i]=1+temp1;
            }
            else
            {
                if(L[i+1]==-1)L[i]=-1;
                else L[i]=1+L[i+1];
            }
            temp1=temp2;
        }
        temp1=-1;
    }
    int min_i=0,min_s=L[0];
    if(min_s==-1)
    {
        cout<<"infinity";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(L[i]>-1&&L[i]<min_s)
        {
            min_s=L[i];
            min_i=i;
        }
    }
    cout<<min_s<<" "<<min_i+1;
    return 0;
}
