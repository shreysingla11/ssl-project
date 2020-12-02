#include<iostream>
#include<cmath>
using namespace std;
int main(){
int N;
cin>>N;
int C[N][N],distg[N],distb[N],good[N],bad[N];
//taking input
for(int i=0;i<N;i++){
distg[i] = INFINITY;
distb[i] = INFINITY;
good[i]=0;
bad[i]=0;
    for(int j=0;j<N;j++){
                         cin>>C[i][j];
                           }
                     }
   
distg[0]=0;
distb[0]=0;                     
//algo
for(int p = 0;p<N;p++){
           for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                         //relaxation for good paths
                        if(distg[j]>distg[i]+abs(C[i][j])){
                                    if((C[i][j]<0)&&(good[i]+1>=bad[i])){
                                            //updating
                                               distg[j]=distg[i]+abs(C[i][j]);
                                               good[j]=good[i]+1;
                                               bad[j]=bad[i];
                                                                          }
                                    if((C[i][j]>0)&&(good[i]>=bad[i]+1)){
                                            //updating
                                              distg[j]=distg[i]+abs(C[i][j]);
                                               good[j]=good[i];
                                               bad[j]=bad[i]+1;           
                                                                          }   
                                                                          
                                                                          
                                                                               
                                                         }
                                                         
                                       }
                                 }
           
                       }   
 //printing
for(int k=0;k<N;k++){
if(distg[k]==2147483647){cout<<"infinity"<<endl;}
else{cout<<distg[k]<<endl;}
                      }                                      
return 0;
           }
