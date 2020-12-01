#include<iostream>
#include<limits.h>
#include<fstream>
using namespace std;

void computeL(int L[][2], int A[], int B[], int n, int m)
{

    int i, j, k=0;
    if(A[n-1]==B[m-1]){
      L[n-1][1]=1;
    }
    else{
      L[n-1][1]=n+1;
    }
    for(i=n-2;i>=0;i--)
    {
        if(A[i]==B[m-1])
          L[i][1]=1;
        else
          L[i][1]=1+L[i+1][1];
    }

    for(j=m-2;j>=0;j--)
    {
        L[n-1-k][0]=n+1;

        for(i=n-2-k;i>=j;i--)
        {  if(A[i]==B[j])
             L[i][0]=1+L[i+1][1];
           else
             L[i][0]=1+L[i+1][0];
        }

        for(i=n-1-k;i>=j;i--)
        {
            L[i][1]=L[i][0];
        }
        k++;
     }
     for(i=n-m;i<n;i++)
        L[i][0]=n+1;

}

int main(){

    int n, m;
    cin>>n >>m;
    int A[n], B[m], L[n][2];
    int i, j;
    for(i=0 ; i<n; i++)
    {
       cin>>A[i];
    }
    for(i=0;i<m;i++)
    {
       cin>>B[i];
    }

    computeL(L,A,B,n,m);
    int posmin=n+1;
    int Lmin=n+1;
    for(i=0;i<n;i++)
    {
        if(L[i][0]<Lmin)
        {
            posmin=i;
            Lmin=L[i][0];
        }
    }
    if(Lmin>n||posmin>n)
      cout<<"infinity"<<endl;
    else
      cout<< Lmin<<' '<<posmin+1<<endl;

    return 0;

}

