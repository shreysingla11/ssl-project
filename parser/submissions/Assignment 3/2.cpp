#include<iostream>
#include<cmath>
using namespace std;
int L(int i,int j,int A[],int B[],int &m,int &n){
if((i==n)&&(j==m)){
               if(A[n]==B[m]) return 1;
               else return INFINITY;
                  }
if((i<n)&&(j==m)){
               if(A[i]==B[m]) return 1;
               else return abs(  (1+L(i+1,m,A,B,m,n)));
                  }
if((i==n)&&(j<m)){

                  return INFINITY;
                  }
if((i<n)&&(j<m)){

                if(A[i]==B[j]) {return abs( (1+L(i+1,j+1,A,B,m,n)));}

                else { return abs((1+L(i+1,j,A,B,m,n)));}

                  }



                                             }

int main(){

int n,m,i,mini,val,index;
index=0;
cin>>n>>m;
int A[n+1],B[m+1];
for(i=1;i<n+1;i++){
    cin>>A[i];
                }

 for(i=1;i<m+1;i++){
    cin>>B[i];
                }
                mini= +INFINITY;

for(i=n;i>0;i--){
    val=L(i,1,A,B,m,n);

    if((val>=0)&&(val<=mini) ) {mini=val;index=i;}

                  }
  if(mini== 2147483647)  cout<<"infinity"<<endl;
  else {cout<<mini<<"  "<<index<<endl;}


 return 0;

           }

