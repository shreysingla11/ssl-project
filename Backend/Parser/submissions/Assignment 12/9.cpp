#include<iostream>
using namespace std;
int main()
{
int n,t,f,x,g=0;
cin>>n;
int data[n][n+3];
 for (int i=0;i<n;i++){
     for(int j=0; j<n+3; j++){
        data[i][j]= -1;
        }
        }

 for(int k=0;k<n;k++){
    cin>>t;
    data[k][n]=t;
    cin>>f;
    data[k][n+1]=f;
    for( int l=0;l<f;f++){
         cin>>x;
         data[k][x]= 1;
      }
      if(t==0){
      data[k][n+2]=1;
      g=g+1;}

       if(t>f){
       data[k][n+2]=0;}
        }

for(int i=0;i<5;i++){

   for(int k=0;k<n;k++){
   int people=0;
       for (int j=0;j<n;j++){
        if (data[k][j]==1){
            people=people+1;}
            }
            if (people> data[k][n]){
               data[k][n+2]=1;
               g=g+1;}
               }
               }

   cout<<g<<" "<<g<<endl;
   return 0;
        }


