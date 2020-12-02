#include<iostream>
using namespace std;
int main()
{
int n,m;

cin>>n;

cin>>m;
if(m>n){cout<<"infinite"<<endl;
        return 0;}
int A[n],B[m];
int L[n][m];
int i=0,j=0;
for(i=0;i<n;i++)
    {

    cin>>A[i];
    }
for(i=0;i<m;i++)
    {

    cin>>B[i];
    }

if(A[n-1]==B[m-1]){L[n-1][m-1]=1;}
else{L[n-1][m-1]=n+1;}

for(i=n-2;i>=0;i--)
    {
        if(A[i]==B[m-1])
        {
            L[i][m-1]=1;
        }
        else
        {
            L[i][m-1]=1+L[i+1][m-1];
        }
    }
for(j=0;j<m-1;j++)
    {
        L[n-1][j]=n+1;
    }
 for(j=m-2;j>-1;j--)
    {
   for(i=n-2;i>-1;i--)
        {
            if(A[i]==B[j])
        {
            L[i][j]=1+L[i+1][j+1];
        }
    else
        {
            L[i][j]=1+L[i+1][j];
        }
        }
    }

if((i==-1)&&(j!=-1)){cout<<"infinite"<<endl;
return 0;}
int k=n-1,p=n-1;
int mini=L[n-1][0];

while(p>-1)
    {
        if(mini<=L[p][0])
    {
        p--;
    }
    else
    {
        mini=L[p][0];
        k=p;
        p--;
    }
    }
if(mini!=n+1)
{
    cout<<mini<<" "<<k+1<<endl;
}
else
{
    cout<<"infinite"<<endl;
}
return 0;
}
