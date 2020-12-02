#include<iostream>
#include<list>
using namespace std;
int main()
{
    int p,q,n,m,x=0,i=0,d=n;
    cin>>n>>m;

    int *A=new int[n];
    int *B=new int[m];
    int *M=new int[n];
    int *N=new int[n];


    for(p=0;p<n;p++){cin>>A[p];}
    for(p=0;p<m;p++){cin>>B[p];}



    for(q=m-1; q>=0; q--)
    {
        for(p=n-1; p>=0; p--)
        {


            if(q==m-1)
            {

                if(p==n-1)
                {
                    if(A[p]==B[q])
                    {
                        N[p]=1;
                    }
                    else
                    {
                        N[p]==n+1;
                    }
                }
                else
                {
                    if(A[p]==B[q])
                    {
                        N[p]=1;
                    }
                    else
                    {
                        N[p]=1+N[p+1];
                    }
                }
            }
            else
            {
                if(p==n-1)
                {
                    M[p]=n+1;
                }
                else
                {

                    if(A[p]==B[q])
                    {
                        M[p]=1+N[p+1];
                    }
                    else
                    {
                        M[p]=1+M[p+1];
                    }
                }
            }

        }
        for(i=0;i<d;i++){if(N[i]>d){x++;}
        else {x=0;break;}}

        if(x==d){cout<<"Infinity";return 1;}
        if(q!=m-1 || q==0){
        for(i=0;i<n;i++){N[i]=M[i];}}
    }
    m=N[0];
    q=1;
    for(p=1; p<n; p++)
    {
        if(N[p]<m)
        {
            m=N[p];
            q=p+1;
        }
    }
    cout<<m<<" "<<q;




    return 1;
}

