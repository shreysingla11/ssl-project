#include<iostream>
#include<limits>
#include<vector>
using namespace std;
#define inf numeric_limits<int>::max()


int cal(int a[],int b[],int &,int& ,int i,int j);
vector<vector<int> > L;
int main()
{


int m=0,n=0;
cin>>n;
cin>>m;
int a[n];
int b[m];
for(int i=0;i<n;i++)
    L.push_back(vector<int>(1,0));
for(int i=0;i<n;i++)
        {
       cin>>a[i];
        }

for(int i=0;i<m;i++)
        {
       cin>>b[i];
        }

int min =cal(a,b,n,m,n-1,0);
int min_ind=n-1;
for(int i=n-1;i>=0;i--)
    {
        int x=cal(a,b,n,m,i,0);
        if(L[i][0]<=min)
            {
            min=L[i][0];
            min_ind=i;
            }
    }
if(min!=inf)
cout<<min<<" "<<min_ind+1;
else cout<<"infinity";
}


int cal(int a[],int b[],int&n,int&m,int i,int j)
    {

        if(j>=L[i].size())
            {
            for(int k=0;k<(j-L[i].size())+1;k++)
                L[i].push_back(0);
            }
        if(L[i][j]!=0)
            {
            return L[i][j];
            }
        if((i==n-1)&&(j==m-1))
            {
            //cout<<"x";
            if(a[i]==b[j])
                L[i][j]=1;
            else
                L[i][j]=inf;
            return L[i][j];
            }
        if(j==m-1)
            {
            if(a[i]==b[j])
                L[i][j]=1;
            else  if(i<n-1)
                    {
                    if(cal(a,b,n,m,i+1,j)==inf)
                    L[i][j]=inf;
                    else
                    L[i][j]=1+cal(a,b,n,m,i+1,j);
                    }

            return L[i][j];
            }
        if(i==n-1)
            {
            if(j<m-1)
                L[i][j]=inf;
            return L[i][j];
            }
        else
            {
            if(a[i]==b[j])
                {
                    if(cal(a,b,n,m,i+1,j+1)==inf)
                    L[i][j]=inf;
                    else
                    L[i][j]=1+cal(a,b,n,m,i+1,j+1);
                }
            else
                {
                if(cal(a,b,n,m,i+1,j)==inf)
                L[i][j]=inf;
                else
                L[i][j]=1+cal(a,b,n,m,i+1,j);
                }
            return L[i][j];
            }

    }
