#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n=0,m=0,i=0,j=0;
    scanf("%d %d",&n,&m);
    int *a = new int [n];
    int *b = new int [m];
    int *l1 = new int [n];
    int *l2 = new int [n];
    int *temp;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<m; i++)
    {
        cin>>b[i];
    }

    if(a[n-1]==b[m-1])
    {
        l1[n-1] = 1;
    }
    else
    {
        l1[n-1] = -100;
    }
    l2[n-1] = -100;
    for(i=n-2; i>=0; i--)
    {
        if(a[i]==b[m-1])
        {
            l1[i] = 1;
        }
        else
        {
            if(l1[i+1]==-100)
            {
                l1[i]==-100;
            }
            else
            {
                l1[i] = 1 + l1[i+1];
            }
        }
    }
    for(j=m-2; j>=0; j--)
    {
        for(i=n-2; i>=0; i--)
        {
            if(a[i]==b[j])
            {
                if(l1[i+1]==-100)
                {
                    l2[i] = -100;
                }
                else
                {
                    l2[i] = 1 + l1[i+1];
                }
            }
            else
            {
                if(l2[i+1]==-100)
                {
                    l2[i] = -100;
                }
                else
                {
                    l2[i] = 1 + l2[i+1];
                }
            }
        }
        temp = l1;
        l1 = l2;
        l2 = temp;
        l2[n-1] = -100;
    }
    int min = l1[0];
    j=0;
    if(min==-100)
    {
        cout<<"infinity"<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if((l1[i]<min)&&(l1[i]!=-100))
        {
            min = l1[i];
            j=i;
        }
        if(l1[i]==-100){break;}
    }

    printf("%d %d",min,j+1);
    cout<<endl;
    return 0;
}
