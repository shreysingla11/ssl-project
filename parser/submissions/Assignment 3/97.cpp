#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;
vector<int> a;
vector<int> b;
int func(int i,int j);

int main()
    {
     int n,m,temp,min,temp1,index;
     scanf("%d %d",&n,&m);

     for (int i=0;i<n;i++)
        {
         scanf("%d",&temp);
         a.push_back(temp);
        }

     for (int i=0;i<m;i++)
        {
         scanf("%d",&temp);
         b.push_back(temp);
        }
    //cout<<a[1]<<"\n";
    min=INT_MAX;
    //cout<<min<<"\n";
    for (int i=1;i<=n+1-m;i++)
        {

         temp1=func(i,1);
         if (temp1<min){min=temp1;index=i;}
        }
    if (min!=INT_MAX){cout<<min<<" "<<index;}
    else{cout<<"infinite";}
    }


int func(int i,int j)
    {
     int n=a.size();
     int m=b.size();
     //cout<<n<<" "<<m<<"\n";
     if(i==n&&j!=m){return INT_MAX;}
     if(j==m&&i!=n)
        {
         if (a[i-1]==b[j-1]){return 1;}
         else{if (func(i+1,j)!=INT_MAX){return 1+func(i+1,j);}
              else {return INT_MAX;}
             }
        }
    if(i==n&&j==m)
        {
         if(a[i-1]==b[j-1]){return 1;}
         else {return INT_MAX;}
        }
    if(i!=n&&j!=m)
        {
         if(a[i-1]==b[j-1]){if (func(i+1,j+1)!=INT_MAX){return 1+func(i+1,j+1);}
                            else {return INT_MAX;}
                           }
         else {if (func(i+1,j)!=INT_MAX){return 1+func(i+1,j);}
               else {return INT_MAX;}
              }
        }
    }
