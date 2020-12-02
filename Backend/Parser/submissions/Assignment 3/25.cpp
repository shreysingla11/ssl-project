#include<iostream>
#include<limits>
using namespace std;
int main()
{
    int n,m,mini=numeric_limits<int>::max(),index=0;
    cin>>n>>m;
    int *A = new int[n];
    int *B = new int[m];
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        A[i]=temp;
    }
    for(int i=0; i<m; i++)
    {
        int temp;
        cin>>temp;
        B[i]=temp;
    }
    int *L1 = new int[n];
    int *L2 = new int[n];
    for(int i=m-1; i>-1; i--)
    {
        if(i==m-1)
        {
            for(int j=n-1; j>-1; j--)
            {
                if(j==n-1)
                {
                    if((A[n-1])==(B[m-1]))
                        L1[j]=1;
                    else
                        L1[j]=numeric_limits<int>::min();
                }
                else
                {   if((A[j])==B[m-1])
                       L1[j]=1;
                    else
                        L1[j]=1+L1[j+1];
                }
            }
            continue;
        }
        if((m-i-1)%2==0)
        {
            for(int j=n-1; j>-1; j--)
            {
                if(j==n-1)
                    L1[j]=numeric_limits<int>::min();
                else
                {
                    if((A[j])==(B[i]))
                        L1[j]=1+L2[j+1];
                    else
                    L1[j]=1+L1[j+1];
                }
            }
        }
        if((m-i-1)%2!=0)
        {
            for(int j=n-1; j>-1; j--)
            {
                if(j==n-1)
                    L2[j]=numeric_limits<int>::min();
                else
                {
                    if((A[j])==(B[i]))
                        L2[j]=1+L1[j+1];
                    else
                        L2[j]=1+L2[j+1];
                }
            }
        }

    }

    if(m%2==0)
    {
        for(int i=0; i<n; i++)
        {
            if((L2[i]>0)&&(mini>L2[i]))
            {
                mini=L2[i];
                index=i;

            }

        }
    }

    if(m%2!=0)
    {
        for(int i=0; i<n; i++)
        {
            if((L1[i]>0)&&(mini>L1[i]))
            {
                mini=L1[i];
                index=i;

            }
        }
    }

    if(mini!=numeric_limits<int>::max())
        cout<<mini<<" "<<index+1<<endl;

    else
        cout<<"infinity"<<endl;

    return 0;
}
