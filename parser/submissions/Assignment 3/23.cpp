#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    int m;
    int i=0;
    int j=0;
    cin>>n;
    cin>>m;
    vector<int> a(n);
    vector<int> b(m);
    vector<vector<int> > L(n,vector<int>(m));
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            L[i][j]=n+1;
        }
    }
    i=0;
    while(i!=n)
    {
        cin>>a[i];
        i++;
    }
    j=0;
    while(j!=m)
    {
        cin>>b[j];
        j++;
    }
    i=n-1;
    j=m-1;

    if(a[n-1]==b[m-1])
    {
        L[n-1][m-1]=1;
    }

    for(i=n-2; i!=-1; i--)
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

    for(i=n-2; i!=-1; i--)
    {
        for(j=m-2; j!=-1; j--)
        {
            if(a[i]==b[j])
            {
                L[i][j]=L[i+1][j+1]+1;
            }
            else
            {
                L[i][j]=L[i+1][j]+1;
            }
        }
    }

    int min=L[0][0];
    int minindex=0;
    for(i=1; i<n; i++)
    {
        if(L[i][0]<min)
        {
            min=L[i][0];
            minindex=i;
        }
    }
    if(min>=n+1)
    {
        cout<<"infinity";
    }
    else
    {
        cout<<min<<" "<<minindex+1;
    }
    return 0;
}
