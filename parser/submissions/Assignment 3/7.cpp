#include <iostream>
#include <vector>

using namespace std;

int getl(int i,int n,int j,int m,vector <int> a,vector <int> b)
{
   int temp=100000000;

   if(i==n-1&&j==m-1){
       if(a[n-1]==b[m-1])temp=1;
        }
   if(i>=0&&i<n-1&&j==m-1){
       if(a[i]==b[m-1]) temp=1;
       else temp = 1+getl(i+1,n,j,m,a,b);
       }
   if(i==n-1&&j>=0&&j<m-1) temp=100000000;

   if(i>=0&&i<n-1&&j>=0&&j<m-1){
        if(a[i]==b[j])temp=1+getl(i+1,n,j+1,m,a,b);
        else temp=1+getl(i+1,n,j,m,a,b);
        }
   return temp;

}

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int> a(n),b(m);
   int L[n][m];
   for(int i=0;i<n;i++)
   {
     cin>>a[i];
   }

   for(int j=0;j<m;j++)
   {
    cin>>b[j];

   }

   for(int k=n-1;k>=0;k--)
   {
     for(int p=m-1;p>=0;p--)
     {
       L[k][p]=getl(k,n,p,m,a,b);
     }

   }


   int minimum=L[0][1];
   int indices=0;
   for(int l=0;l<n;l++)
   {
     if(L[l][1]<minimum)
       {
         minimum=L[l][1];
         indices=l;
       }
   }

   if(minimum<100000000) cout<<indices+1<<" "<<minimum<<endl;
   else  cout<<"infinity";
  return 0;
}
