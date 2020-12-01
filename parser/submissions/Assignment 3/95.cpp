#include<iostream>
#include<vector>
using namespace std;
void g(vector<int> A,vector<int> B);
int main()
{
    int m,n,j;
    cin>>m>>n;
    vector<int> A(m);
    vector<int> B(n);
    for(int i=0; i<m; i++)
    {
        cin>>A[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>B[i];
    }
    j=m-1;
    while(j>=0)
    {
        if(A[j]!=B[n-1])
        {
            A.pop_back();
            j--;
        }
        else
        {
            break;
        }
    }
    if(A.size()<B.size())
    {
        cout<<"infinity"<<endl;
    }
    else
    {
        g(A,B);
    }
    return 0;
}
void g(vector<int> A,vector<int> B)
{
    int x=A.size(),y=B.size(),index;
    int p[y];
    if(A[x-1]==B[y-1])
    {
        p[y-1]=1;
    }
    else
    {
        p[y-1]=x+1;
    }
    for(int i=0; i<y-1; i++)
    {
        p[i]=x+1;
    }
    int Min=p[0];
    for(int i=x-1; i>0; i--)
    {
        for(int j=1; j<y; j++)
        {
            if(A[i-1]==B[j-1])
            {
                p[j-1]=1+p[j];
            }
            else
            {
                p[j-1]=1+p[j-1];
            }
        }
        if(A[i-1]==B[y-1])
        {
            p[y-1]=1;
        }
        else
        {
        p[y-1]=1+p[y-1];
        }
        if(p[0]<=Min)
        {
            Min=p[0];
            index=i;
        }
    }
    cout<<Min<<" "<<index<<endl;
    return ;
}
