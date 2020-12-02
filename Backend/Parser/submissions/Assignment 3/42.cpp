#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>a;
    vector<int>b;
    int n,m;
    a.push_back(0);
    b.push_back(0);
    cin>>n;
    cin>>m;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int i=0; i<m; i++)
    {
        int k;
        cin>>k;
        b.push_back(k);
    }
    int l=0;
    int i=1;
    int j=1;
    int lmin;
    int index;
    int k;
    bool flag;
    bool start=0;
    int startindex;
    for(k=1; k<=n-m; k++)
    {
        if(a[k]==b[1]&&start!=1)
        {
            start=1;
            startindex=k;
        }
        else
        {

        }


        if(start==1)
        {
            i=k;
            l=0;
            j=1;
            for(; (i<=n)&&(j<=m);)
            {
                if(a[i]==b[j])
                {
                    i++;
                    j++;
                    l++;
                    flag=1;
                }
                else
                {
                    i++;
                    if(flag==1)
                    {
                        l++;
                    }
                }
            }
            if(k==startindex)
            {
                lmin=l;
                index=startindex;
            }
            else
            {
                if(l<lmin&&l!=0&&a[k]==b[1]&&a[k+l-1]==b[m]&&j==m+1)
                {
                    lmin=l;
                    index=k;

                }
            }
        }






    }
    if(a[index]==b[1]&&a[index+lmin-1]==b[m])
    {
        cout<<lmin<<" "<<index;

    }
    else
    {
        cout<<"infinity";
    }

    return 0;
}
