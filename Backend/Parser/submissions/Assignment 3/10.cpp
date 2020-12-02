#include<iostream>
#include<vector>
using namespace std;

int main()
{
int n,m,i,j;
cout<<"enter n,m"<<endl;
cin>>n>>m;
vector<int> a(n), b(m);
cout<<"enter the integers for a and b"<<endl;
for(i=0;i<n;i++){
    cin>>a[i];}


 for(i=0;i<m;i++)
 {cin>>b[i];}

 vector<vector<int> > L(n, vector<int> (m));


 for(i=0;i<m;i++)
 { L[n-1][i]=n;}


 if(a[n-1]==b[m-1])
 { L[n-1][m-1]=1; }

 else{L[n-1][m-1]=n;}



  for(i=n-2;i>-1;i--){

   if(a[i]==b[m-1])
     {L[i][m-1]=1;}

    else{L[i][m-1]=(1+L[i+1][m-1]);}

     }


  for(i=n-2;i>-1;i--){

      for(j=m-2;j>-1;j--){


         if (a[i]==b[j])
            {L[i][j]=(1+L[i+1][j+1]);}

         else{L[i][j]=(1+L[i+1][j]);}

          }
          }

   int min_1=L[0][0];
   int k=1;
   char t='n';
   for(i=0;i<n;i++)
   {
      if((L[i][0]<min_1)){
         min_1=L[i][0];
         k=i+1;
         }


         else{}


}
if (min_1==n){ cout<<"infinity"<<endl;}
 else{

    cout<<min_1<<" "<<k<<endl;}

    return 0;

             }

