#include <vector>
#include <iostream>
#include <limits>
using namespace std;

float func(const vector <int> a,const vector <int> b,int i, int j, const int n, const int m)
{
    //cout<<i<<" "<<j<<endl;
    //cout<<2<<endl;
    float inf=std::numeric_limits<float>::infinity();
    float result;

    if (j==m)
    {
        if(i==n)
        {
            if(a[i]==b[j])
            {
                result=1;
            }
            else
            {
                result=inf;
            }
        }
        else
        {
            if(a[i]==b[j])
            {
                result=1;
            }
            else
            {
                result=1+func(a,b,(i+1),j,n,m);
            }
        }
    }
    else
    {
        if(i==n)
        {
            result=inf;
        }
        else
        {
            if(a[i]==b[j])
            {
                result=1+func(a,b,(i+1),(j+1),n,m);
            }
            else
            {
                result=1+func(a,b,(i+1),j,n,m);
            }

        }
    }
    return result;
}

int main()
{
    float inf=std::numeric_limits<float>::infinity();
    int n, m, k, min_index;
    float minimum;
    cin>>n>>m;
    vector <float> L1(n+1);
    vector <int> a(n+1), b(m+1);

    int i, j;


    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(j=1;j<=m;j++)
    {
        cin>>b[j];
    }

    j=1;

    for(k=1;k<=n;k++)
    {
       // cout<<k<<endl;
        L1[k]=func(a,b,k,j,n,m);
        if (k==1)
        {
            min_index=1;
            minimum=L1[1];
        }
        else
        {
            if (L1[k]<minimum)
            {
                min_index=k;
                minimum=L1[k];
            }
        }
    }
    if (minimum==inf)
    {
        cout<<"infinity"<<endl;
    }
    else
    {
        cout<<minimum<<" "<<min_index;
    }

    return 0;
}

