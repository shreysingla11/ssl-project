#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<int> len(2);
  vector<int> v1,v2;
  vector<int> l2;
  vector<int> l1;
  int col2,col1,m,n;
  for(int i=0;i<2;i++){
   cin>>len[i];
  }
  v1.resize(len[0]);
  v2.resize(len[1]);
  for(int j=0;j<len[0];j++){
   cin>>v1[j];
  }
  for(int k=0;k<len[1];k++){
   cin>>v2[k];
  }
  l1.resize(len[0]);
  l2.resize(len[0]);
  for(col2=len[1];col2>1;col2--){
    m=len[1]-1;
    n=len[0]-1;
    if(col2==(len[1])){
        int r=n;
        if(v1[n]==v2[m]){
          l2[r]=1;
        }
        else{
          l2[r]=len[0]+1;
        }
        for(r=n-1;r>=0;r--){
          n=n-1;
          if(v1[n]==v2[m]){
            l2[r]=1;
          }
          else{
            l2[r]=1+l2[r+1];
          }
        }
    }
    else{
        l2.swap(l1);
    }
    col1=col2-1;
    {
        n=len[0]-1;
        m=col1-1;
        int r=n;
        l1[r]=len[0]+1;
        for(r=n-1;r>=0;r--){
          n=n-1;
          if(v1[n]==v2[m]){
            l1[r]=1+l2[r+1];
          }
          else{
            l1[r]=1+l1[r+1];
          }
        }
    }
  }
  int least=l1[0],index=1;
  for(int i=1;i<len[0];i++){
    if(l1[i]<least){least=l1[i];index=i+1;}
  }
  if(least>len[0]){
    cout<<"infinity"<<endl;
  }
  else{
    cout<<least<<" "<<index<<endl;
  }
return 0;
}

