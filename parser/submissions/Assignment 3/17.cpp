#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n=0,m=0;
int L(int i,int j, vector<int>& a, vector<int>& b,vector<vector<int> >& rem)
{
    if(rem[i][j]!=0) // to not call the same value again and again,"rem" vector stores these values.
    {
        return rem[i][j];
    }
    else
    {
        if(i==(n-1) && j==(m-1))
        {
            if( a[n-1] == b[m-1])
            {
                rem[i][j]=1;
                return 1;
            }
            else
            {
                rem[i][j]=n+1;
                return n+1;
            }

        }
        if(j==(m-1) && i<(n-1))
        {
            if(a[i]== b[m-1])
            {
                rem[i][j]=1;
                return 1;
            }
            else
            {
                int t=L(i+1,m-1,a,b,rem);
                rem[i][j]=1+t;
                return 1+t;
            }
        }
        if(i==(n-1) && j<(m-1))
        {
            rem[i][j]=1+n;
            return n+1;
        }
        if(i<(n-1) && j<(m-1))
        {
            if(a[i]==b[j])
            {
                int t=L(i+1,j+1,a,b,rem);
                rem[i][j]=1+t;

                return 1+t;
            }
            else
            {
                int t=L(i+1,j,a,b,rem);
                rem[i][j]=1+t;
                return 1+t;
            }
        }
    }
}
int main()
{

    cin>>n>>m;
    vector< vector <int> > rem(n,vector<int>(m));
    vector<int> a(n);
    vector<int> b(m);
    for(size_t i=0; i<a.size(); i++)
    {
        cin>>a[i];
    }
    for(size_t i=0; i<b.size(); i++)
    {
        cin>>b[i];
    }
    int index=0,sub=n+1;
    int curr=0;
    for(int i=0; i<n; i++)
    {
        curr=L(i,0,a,b,rem);
        if(sub!=curr)
        {
            if(sub>curr)
            {
                index=i+1;
                sub=curr;
            }

        }
    }
    if(sub>=n)
    {
        cout<<"infinity";
    }
    else
    {
        cout<<sub<<" "<<index;
    }
    return 0;
}
