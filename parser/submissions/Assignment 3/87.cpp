#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    list<int> a,b;
    for(int i=1; i<n+1; i++)
    {
        int xx;
        cin>>xx;
        a.push_back(xx);
    }
    for(int i=1; i<m+1; i++)
    {
        int yy;
        cin>>yy;
        b.push_back(yy);
    }
    vector<vector<int> > x(n+1,vector<int>(m+1));
    list<int>::iterator k=a.end(),l1=b.end();
    l1--;k--;
    if(*k==*l1)
    {
        x[n][m]=1;
    }
    else
    {
        x[n][m]=n+1;
    }

    for(int i=1; i<m-1; i++)
    {
        x[n][i] = n+1;
    }
k--;
    for(int i=n-1; i>=1; i--)
    {
        list<int>::iterator l=b.end();
        l--;
        for(int j=m; j>=1; j--)
        {
            if(j==m)
            {
                if(*k==*l)
                {
                    x[i][j]=1;
                }
                else
                {
                    x[i][j]=1+x[i+1][j];
                }
            }
            else
            {
                if(*k==*l)
                {
                    x[i][j] = 1 + x[i+1][j+1];
                }
                else
                {
                    x[i][j] = 1 + x[i+1][j];
                }
            }
        l--;
        }
        k--;
    }
    int ma = x[1][1],ans=1;
    for(int i=2; i<n+1; i++)
    {
        if(x[i][1]<ma)
        {
            ans=i;
            ma=x[i][1];
        }
    }
    if(ma==n+1)
    {
        cout<<"infinite";
        return 0;
    }
    cout<<ma<<" "<<ans;
    return 0;
}

