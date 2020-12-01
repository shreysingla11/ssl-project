#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct val{
  int v;
  int in;
};

bool func(val v1,val v2){
  if(v1.v!=v2.v)return v1.v<v2.v;
  if(v1.v==v2.v){
    return v1.in<v2.in;
  }
}

struct distinct{
   vector<val> S;
   vector<int> l;
   vector<vector<int> >A1;
   int n;

   distinct(vector<int> seq){
     n=seq.size();
     S.resize(n);
     l.resize(n);
     for(int i=0;i<n;i++){
       S[i].v=seq[i];
       S[i].in=i;
     }
     sort(S.begin(),S.end(),func);
     for(int i=0;i<n;i++){
       l[i]=-1;
     }
     for(int i=1;i<n;i++){
       if(S[i].v==S[i-1].v){
         l[S[i].in]=S[i-1].in;
       }
     }
     for(int i=0;i<n;i++){
       //cout<<l[i]<<" ";
     }
     int noflev=1;
     int num=1;
     while(num<=n){
       noflev++;
       num*=2;
     }
     vector<vector<int> > V1(noflev+1);
     vector<vector<int> > V2(noflev+1);
     for(int i=1;i<=noflev;i++){
        build(i,V1[i],V2[i]);
     }
     /*cout<<"---------------------------------"<<endl;
     for(int i=1;i<=noflev;i++){
        int sz=V1[i].size();
        for(int j=0;j<sz;j++){
          cout<<V1[i][j]<<" ";
        }
        cout<<endl;
     }
     cout<<"----------------------------------"<<endl;
     for(int i=1;i<=noflev;i++){
        int sz=V2[i].size();
        for(int j=0;j<sz;j++){
          cout<<V2[i][j]<<" ";
        }
        cout<<endl;
     }*/
   }

   void build(int i,vector<int> &A1,vector<int> &A2){//ith level
     A1.resize(n);//count
     A2.resize(n);//max index
     int den=1;//den=2^{i-1}
     for(int k=0;k<i-1;k++){
       den*=2;
     }
     vector<int> counts(den);//counts[k] stores no of elements between [k*n/den +n/2*den to (k+1)*n/den)
     vector<int> largestu(den);//largest[k] stores no of elements between [k*n/den+n/2*den to (k+1)*n/den)
     vector<int> largestd(den);//largest[k] stores no of elements between [k*n/den to (k)*n/den+n/2den)
     for(int y=0;y<den;y++){
       counts[y]=0;
       largestu[y]=-1;
       largestd[y]=-1;
     }
     for(int y=0;y<n;y++){
       if(l[y]==-1){
         A1[y]=0;
         A2[y]=-1;
         continue;
       }
       int k,hi=den*4;
       k=0;
       while(hi>k+1){
         int mid=(hi+k)/2;
         if(mid*(n/den)<=l[y]){
           k=mid;
         }
         else{
           hi=mid;
         }
       }
       /////////////now we have k
       if(l[y]>=k*(n/den)+(n/2*den)){
         counts[k]+=1;
         if(y>largestu[k]){
           largestu[k]=y;
         }
       }
       else{
         if(y>largestd[k]){
           largestd[k]=y;
         }
       }
       A1[y]=counts[k];
       if(l[y]>=k*(n/den)+(n/2*den)){
         A2[y]=largestd[k];
       }
       else{
         A2[y]=largestu[k];
       }

     }
   }

   int num_distinct(int i,int j){
     int count =0;
     for(int k=i;k<=j;k++){
       if(l[k]<i)count++;
     }
     return count;
   }

};
/*
int main(){

  vector<int> A;
  int n;
  cin >>n;
  for(int i=0;i<n;i++){
    int y;
    cin>>y;
    A.push_back(y);
  }
  distinct* D=new distinct(A);
  return 0;
}

*/
