#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int n,m,inf;
vector<int> A,B;
vector<int> MIN,col;
int main(){

    //Input
    cin>>n>>m;
    A.resize(n);
    B.resize(m);
    MIN.resize(n);
    col.resize(m);
    int l(int i,int j);
    //int inf = numeric_limits<int>::max();
    inf=100000000;
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>B[i];
    }

    //Processing
    int minimum=inf,min_index=0;
    /*for(int i=n-1;i>=0;i--)
    {
        if(MIN[i]==0)
        {
            p=l(i,0);
            MIN[i]=p;
        }
        else p=MIN[i];

        if(minimum>p)
        {
            minimum=p;
            min_index=i+1;
        }
    }
    */
    /*for(int i=(n-1);i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(i==(n-1) && j==(m-1))
            {
                if(A[i]==B[j])
                    col[j]= 1;
                else col[j]= inf;
            }

            else if(j==(m-1))
            {
                if(A[i]==B[j])
                    col[j]= 1;
                else
                {
                    col[j]= 1 + col[j];
                }
            }

            else if(i==(n-1) && j<(m-1))
            {
                col[j]= inf;
            }

            else if(A[i]==B[j])
                col[j]= 1 + col[j+1];
            else col[j]= 1 + col[j];

        }
        if(minimum>col[0])
        {
            minimum=col[0];
            min_index=i+1;
        }
    }
    */
    for(int i=(n-1);i>=0;i--)
    {
        for(int j=0;j<m && j<=i;j++)
        {
            if(i==(n-1) && j==(m-1))
            {
                if(A[i]==B[j])
                    col[j]= 1;
                else col[j]= inf;
            }

            else if(j==(m-1))
            {
                if(A[i]==B[j])
                    col[j]= 1;
                else
                {
                    col[j]= 1 + col[j];
                }
            }

            else if(i==(n-1) && j<(m-1))
            {
                col[j]= inf;
            }

            else if(A[i]==B[j])
                col[j]= 1 + col[j+1];
            else col[j]= 1 + col[j];

        }
        if(minimum>col[0])
        {
            minimum=col[0];
            min_index=i+1;
        }
    }
    //Output
    cout<<minimum<<" "<<min_index<<endl;
    return 0;
}

//Length of shortest prefix of a_i,a_{i+1}...a_n containing b_j,b_{j+1}...b_m
/*int l(int i, int j)
{
    if(i==(n-1) && j==(m-1))
    {
        if(A[i]==B[j])
            return 1;
        else return inf;
    }

    if(j==(m-1))
    {
        if(A[i]==B[j])
            return 1;
        else
        {
            return 1+l(i+1,m-1);
        }
    }

    if(i==(n-1) && j<(m-1))
    {
        return inf;
    }

    if(A[i]==B[j])
        return 1+l(i+1,j+1);
    else return 1+l(i+1, j);
}*/


