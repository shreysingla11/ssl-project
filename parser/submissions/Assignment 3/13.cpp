#include<iostream>
#include<limits>
#include<list>
#include<vector>
using namespace std;

int main()
{
int n,m,k;int i,j,index;
cin>>n>>m;
int min=1000000000;
int a[n];
int b[m];
int c[m];
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(j=0;j<m;j++)
{
cin>>b[j];
}
for(i=0;i<m;i++)
{
c[i]=0;
}
for(i=n;i>0;i--)
    {
    for(j=1;j<=m;j++)
        {
        if(j==(m))
        {
        if(i==(n)){
                    if(a[i-1]==b[j-1])c[j-1]=1;
                    else c[j-1]=min;
                   }
        else
            {
            if(a[i-1]==b[j-1])c[j-1]=1;
            else c[j-1]=1+c[j-1];
            }
        }

        else if(j<(m) && i==n){c[j-1]=min;}

        else if ( a[i-1]==b[j-1]){c[j-1]=1+c[j];}

        else c[j-1]=1+c[j-1];

   }


}
for(k=0;k<m;k++)
{
if(c[k]<min)
    {
    min=c[k];
    index=k+1;
    }
}
cout<<min-1<<" "<<index+1;
return 0;
}


