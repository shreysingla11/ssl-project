#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
int n,w,u,v,t1,t2;
map<int, set<int> >lane;
cin>>n>>w>>u>>v>>t1>>t2;
int k,coun;k=0;
coun = w/v;
while(k<n){
int numship;
char dir;
cin>>dir>>numship;
coun = (k)*(w/v);
if (dir == 'E'){
     for(int i=1;i<=numship;i++){
              int pos,len,start,endt,prevend;
              cin>>len>>pos;
              start  = max(((0-pos)/u),0);
              start  = max((start-coun),0);
              pos = pos-len;
              endt  = max(((0-pos)/u),0);
              endt  = max((endt-coun),0);
              if(i==1) {prevend = 0;}
              lane[k].insert(prevend);
              lane[k].insert(start-(w/v));
                prevend = endt;
                                  }
                  }
if (dir == 'W'){
       for(int i=1;i<=numship;i++){
              int pos,len,start,endt,prevend;
              cin>>len>>pos;
              start  = max((pos/u),0);
              start  = max((start-coun),0);
              pos = pos-len;
              endt  = max((pos/u),0);
              endt  = max((endt-coun),0);
               if(i==1) {prevend = 0;}
              lane[k].insert(prevend);
              lane[k].insert(endt);
              prevend = endt;
                                  }
                 }
k = k+1;
           }

return 0;
                }
