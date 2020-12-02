#include<algorithm>
#include<list>
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    int* L =new int[n];
    int* a= new int[n];
    int* b= new int[m];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<m; j++)
    {
        cin>>b[j];
    }
    for(int i=n-1; i>=0; i--)
    {
        if(i==n-1)
        {
            if(a[n-1]==b[m-1])
            {
                L[i]=1;
            }
            else
            {
                L[i]=-1;
            }
        }
        else
        {
            if(a[i]==b[m-1])
            {
                L[i]=1;
            }
            else
            {
                if(L[i+1]!=-1)
                {
                    L[i]=1+L[i+1];
                }
                else
                {
                    L[i]=-1;
                }
            }
        }
    }
    for(int j=m-2; j>=0; j--)
    {
        int* R=new int[n];
        for(int k=0; k<n; k++)
        {
            R[k]=L[k];
            L[k]=-1;
        }
        for(int i=n-2; i>=0; i--)
        {
            if(a[i]==b[j])
            {
                if(R[i+1]!=-1)
                {
                    L[i]=1+R[i+1];
                }
                else
                {
                    L[i]=-1;
                }
            }
            else
            {
                if(L[i+1]!=-1)
                {
                    L[i]=1+L[i+1];
                }
                else
                {
                    L[i]=-1;
                }
            }
        }
        delete[]R;
    }
    int min=-1,p;
    for(int i=0; i<n; i++)
    {
        if(L[i]!=-1)
        {
            if(min==-1)
            {
                min=L[i];
                p=i;
            }
            else
            {
                if(L[i]<min)
                {
                    min=L[i];
                    p=i;
                }
            }
        }
    }
    if(min==-1)
    {
        cout<<"infinity";
    }
    else
    {
        cout<<min<<" "<<p+1;
    }
    return 0;
}
