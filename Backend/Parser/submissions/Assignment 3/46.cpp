#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> A;
vector<int> B;

int check(int i,int tar){
   int j;
   for( j=i;j<A.size();){
     if(A[j]==tar)break;
     j++;
   }
   return j;
}

int main(){



  int n,m;
  cin>>n;
  cin>>m;
  A.resize(n+1);
  B.resize(m+1);

  for(int i=1;i<=n;i++){
    cin>>A[i];
  }
  for(int i=1;i<=m;i++){
    cin>>B[i];
  }


  int min=n+5,mini=-1;
  int in=1,t;
  while(in<=n){
     int start=check(in,B[1]);
     t=start;
     for(int i=2;i<=m;i++){
        if(t<=n){
          t=check(t+1,B[i]);
        }
     }
     if(t<=n){
       if(t-start+1<min){
         min=t-start+1;
         mini=start;
       }
     }
     in=start+1;
  }

  if(mini==-1){
     cout<<"infinity";
  }
  else{
    cout<<min<<" "<<mini;
  }

return 0;
}

