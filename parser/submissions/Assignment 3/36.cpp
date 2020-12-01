#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int main()
{
    int n,m;
    int a=numeric_limits<int>::max();

    cin>>n;
    cin>>m;
    vector<int>A(n);
    vector<int>B(m);
    vector<vector<int> >L;
    L.resize(n,vector<int>(m,a));
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }

    for(int i=0; i<m; i++)
    {
        cin>>B[i];
    }


    int i=n-1;
    int j=m-1;
    while(i>=0)
    {

        j=m-1;
        while(j>=0)
        {


            if((i==n-1)&&(j==m-1))
            {
                if(A[i]==B[j])
                {
                    L[i][j]=1;
                }
                else {}
            }
            if((i!=n-1)&&(j==m-1))
            {
                if(A[i]==B[j])
                {
                    L[i][j]=1;
                }
                else
                {
                    if(L[i+1][j]!=a)
                    {
                        L[i][j]=1+L[i+1][j];
                    }

                }
            }
            if((i==n-1)&&(j!=m-1))
            {
                //nothing bcoz infi is the initialised value}
            }
            if((i!=n-1)&&(j!=m-1))
            {
                if(A[i]==B[j])
                {
                    if(L[i+1][j+1]!=a)
                    {
                        L[i][j]=1+L[i+1][j+1];
                    }

                }
                else
                {
                    if(L[i+1][j]!=a)
                    {
                        L[i][j]=1+L[i+1][j];
                    }

                }
            }

            j=j-1;
        }
        i=i-1;

    }

    int temp=0,answer=a;
    for(int j=0; j<n; j++)
    {
        if(L[j][0] < answer)
        {
            answer=L[j][0];
            temp=j;
        }
    }
    cout<<endl;
    if(answer!=a)
    {cout<<answer<<" "<<temp+1;}
    else{cout<<"infinity";}
}
