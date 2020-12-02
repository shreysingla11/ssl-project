#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct pos{
  double val;
  bool fl;//true if start otherwise end
};

bool func(pos p1,pos p2){
 /* if(p1.val<p2.val)return true;
  if(p1.val>p2.val)return false;
  if(p1.fl==true)return true;
  return false;*/

  if(p1.val==p2.val){
    if(p1.fl)return p1.val<p2.val;
    return p2.val<p1.val;
  }
  return p1.val<p2.val;
}

int main(){
  double n,w,u,v,t1,t2;
  cin>>n>>w>>v>>u>>t1>>t2;
  bool flag; char c; int m;
  double l,p;
  double hi,lo;
  double d0=w/u;
  vector<pos> A;
  //cout<<n<<endl;
  for(int i=0;i<n;i++){
    cin>>c;
    if(c!='E')flag=false;
    else{
      flag=true;
    }
    cin>>m;
    //cout<<m<<endl;
    for(int j=0;j<m;j++){
      cin>>l>>p;
      if(flag==true)p=(-1)*p;
      lo=((p/v)-d0)-i*d0;
      hi=((p+l)/v)-i*d0;
      //cout<<lo<<" "<<hi<<" "<<t1<<" "<<t2<<endl;
      if((hi<t1)||(lo>t2)){
        //cout<<"AYGDYU"<<endl;
        continue;
      }
      if(lo<=t1&&hi>=t1&&hi<=t2){
        lo=t1;
      }
      if(lo>=t1&&lo<=t2&&hi>=t2){
        hi=t2;
      }
      if(lo<=t1&&hi>=t2){
        lo=t1; hi=t2;
      }
      pos pt;
      pt.val=lo;
      pt.fl=true;
      A.push_back(pt);
      pt.val=hi;
      pt.fl=false;
      A.push_back(pt);
    }

  }

  sort(A.begin(),A.end(),func);

  int size=A.size();
  /*for(int i=0;i<A.size();i++){
    cout<<A[i].val;
    if(A[i].fl)cout<<" Start"<<endl;
    else{
      cout<<" end"<<endl;
    }
  }*/

  int count=0;
  double max=A[0].val-t1;
  pos ptl;
  ptl.val=t2;
  A.push_back(ptl);
  for(int i=0;i<size;i++){
    if(A[i].fl==true){
      count++;
    }
    else{
      count--;
    }
    if(count==0){
      if(A[i+1].val-A[i].val>max)max=A[i+1].val-A[i].val;
    }
  }
  if(t2-A[size-1].val>max)max=t2-A[size-1].val;

  printf("%.8f",max);

  return 0;
}
