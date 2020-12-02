#include<iostream>
#include<cmath>
#include<cstdio>
//#include<check.cpp>
using namespace std;
 extern double f(long int k);
 //{
   //        return 200* (sin(411*k+433) + cos(922*k+805) + 2) ;
      //       }
               //finding minimum of rest of array
 double minimum(int i,int n){
       double mint;
       mint=f(i);i=i+1;
      for( ;i<n+1;i++){
             if(mint>f(i)) {mint=f(i);}
                   }
                   return mint;
                      }
int main(){
long int i,j,n;
cout<<"give value of n "<<endl;
cin>>n;
 double p,maxfall,maxrate;
 maxfall=0;maxrate=0;

 double maxi,mini,rate;
 maxi=0;
 mini=minimum(1,n);//initialise min to minimum of all;
 for(i=1;i<n;i++){
         if(maxi<f(i)) maxi=f(i);p=i;//finds maximum till i;
         if(mini==f(i)) mini=minimum(i+1,n) ;//assigm min of rest i+1 to n;
         if(maxi>=mini) maxfall=max(maxfall,maxi-mini);
                  }
cout<<"maximum fall is ";printf("%6f",maxfall)  ;cout<<endl;
return 0;
           }
