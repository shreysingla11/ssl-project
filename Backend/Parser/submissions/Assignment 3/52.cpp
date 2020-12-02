#include<iostream>
#include<vector>
#include<limits>
using namespace std;


int main()
{


    int n,m;
    cin>>n>>m;


    vector<int> a(n);
    vector<int> b(m);
    vector<vector<int> > l(n,vector<int>(m));

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }

    int c=n+1;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(j==m-1)
            {
                if(i==n-1)
                {
                    if(a[i]==b[j])
                    {
                        l[i][j]=1;
                    }
                    else
                    {
                        l[i][j]=c;
                    }
                }
                else
                {
                    if(a[i]==b[j])
                    {
                        l[i][j]=1;
                    }
                    else
                    {
                        l[i][j]=1+l[i+1][j];
                    }
                }
            }
            else
            {
                if(i==n-1)
                {
                    l[i][j]=n+1;
                }
                else
                {
                    if(a[i]==b[j])
                    {
                        l[i][j]=1+l[i+1][j+1];
                    }
                    else
                    {
                        l[i][j]=1+l[i+1][j];
                    }
                }

            }

        }

    }
    int r=l[0][0];
    int k=0;
    for(int i=n-1; i>=0; i--)
    {
        if(l[i][0]<=r)
        {
            r=l[i][0];
            k=i+1;
        }
    }
    if(r==n+1){cout<<"infinity"<<" ";}
    else{
    cout<<r<<" "<<k;}
    return 0;
}

