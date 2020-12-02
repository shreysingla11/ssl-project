#include<iostream>
#include<vector>
#define inf 2147483647
using namespace std;

int main()
{
    int m,n;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    a[0]=0; b[0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=m;j++)
        cin>>b[j];
    vector<int> l1(n+1), l2(n+1);
    l1[0]=0; l2[0]=0;
    if(a[n]==b[m]) l1[n]=1;
    else l1[n]=inf;

    for(int i=n-1;i>=1;i--)
    {
        if(a[i]==b[m]) l1[i]=1;
        else
        {
            if(l1[i+1] == inf)
                l1[i] = inf;
            else l1[i] = l1[i+1] + 1;
        }
    }

    for(int j=m-1;j>=1;j--)
    {
        l2[n]=inf;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]==b[j])
            {
                if(l1[i+1] == inf)
                    l2[i] = inf;
                else l2[i] = 1 + l1[i+1];
            }
            else
            {
                if(l2[i+1] == inf)
                    l2[i] = inf;
                else l2[i] = 1 + l2[i+1];
            }
        }
        for(int k=1;k<=n;k++)
        l1[k] = l2[k];
    }

    int min=l1[n]; int pos=n;
    for(int i=n-1;i>=1;i--)
    {
        if(l1[i]<min)
        {
            min = l1[i];
            pos = i;
        }
    }

    if(pos!=n) cout<<min<<' '<<pos;
    else cout<<"infinity"<<endl;
    return 0;
}

