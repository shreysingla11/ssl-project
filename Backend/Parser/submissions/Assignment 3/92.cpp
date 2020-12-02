#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    vector<int> a;
    vector<int> b;
    a.push_back(0);
    b.push_back(0);
    int temp;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0; i<m; i++)
    {
        cin>>temp;
        b.push_back(temp);
    }
    int **L;
    L = new int*[n+1];
    for(int i=0; i<=n; i++)
    {
        L[i]=new int[m+1];

    }
    if(a[n]==b[m])
    {
        L[n][m]=1;
    }
    else
    {
        L[n][m]=n+1;
    }
    for(int i=n-1; i>=1; i--)
    {
        if(a[i]!=b[m])
        {
            L[i][m]=1+L[i+1][m];
        }
        else
        {
            L[i][m]=1;
        }
    }
    for(int j=m-1; j>=1; j--)
    {
        L[n][j]=n+1;
            for(int i=n-1; i>=1; i--)
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
    int min=L[1][1];
    int count=1;
    for(int i=2; i<=n; i++)
    {
        if(L[i][1]<min)
        {
            min=L[i][1];
            count=i;
        }
    }
    if(min<=n){cout<<min<<" "<<count<<endl;}
    else{cout<<"infinity";}
    return 0;
}
