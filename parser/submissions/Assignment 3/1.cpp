#include <iostream>
using namespace std;
int main()
{
    int n;
    int minin=0;
    long long int min=100000000;
    int m;
    cin>>n>>m;
    int A[n];
    int B[m];


    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    for(int i=0; i<m; i++)
    {
        cin>>B[i];
    }
    int L[m];
    int C[m];
    if(A[n-1]==B[m-1])
    {
        L[m-1]=1;
    }
    else
    {
        L[m-1]=100000000;
    }
    for(int i=0;i<m-1;i++){L[i]=100000000;}
    min=L[0];
    for(int i=n-2; i>=0; i--)
    {
        if(A[i]==B[m-1]){C[m-1]=1;}else{C[m-1]=1+L[m-1];}
        for(int j=m-2; j>=0; j--)
        {
            if(A[i]==B[j])
            {
                C[j]=1+L[j+1];
            }
            else
            {
                C[j]=1+L[j];
            }
        }
        if(C[0]<min)
        {

            min=C[0];
            minin = i;
        }
        for(int k=0;k<m;k++)
        {
        L[k]=C[k];
        }
    }
    if(min<100000000){
    cout<<min<<" "<<minin+1;}
    else
    {cout<<"infinity";}

}
