#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,len,startpos;
    cin>>n;
    cin>>m;
    vector<int> a(n),b(m);
    for(int p=0; p<n; p++)
    {
        cin>>a[p];
    }
    for(int p=0; p<m; p++)
    {
        cin>>b[p];
    }
    int L[n][m];int k=n;int l=0;

    for(l=0;l<n;l++)
    {
        if(a[l]==b[0]);
        {
            break;
        }
    }
    if(l==n)
    {
        cout<<"infinity";return 0;
    }

    for(k=n;k>0;k--)
    {
        if(a[k-1]==b[m-1])
        {
            break;
        }
    }
    if(k==0)
    {
        cout<<"infinity";return 0;
    }
    for(int j=m-1; j>l-1; j--)
    {
        for(int i=k-1; i>-1; i--)
        {
            if(i==k-1 && j==m-1)
            {
                if(a[i]==b[j])
                {
                    L[i][j]=1;
                }
            }
            else if (i==(k-1))
            {
                L[i][j]=n+1;
            }
            else if(j==(m-1))
            {
                if(a[i]==b[m-1])
                {
                    L[i][m-1]=1;
                }
                else
                {
                    L[i][m-1]=1+L[i+1][m-1];
                }
            }
            else
            {
                if(a[i]==b[j])
                {
                    L[i][j]=1+L[i+1][j+1];
                }
                else
                {
                    L[i][j]=1+L[i+1][j];
                }
            }
        }
    }
len=L[l][0];startpos=l;
for(int i=1; i<k; i++)
{
    if(L[i][0]<len)
    {
        len=L[i][0];
        startpos=i;
    }
}
if(len>n)
{
    cout<<"infinity"<<" ";
}
else
{
    cout<<len<<" "<<startpos+1;
}
return 0;
}
