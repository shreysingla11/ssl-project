#include<iostream>
#include<vector>
#include<list>
#include<cmath>
using namespace std;
class counter{

vector<int>k;
public:
counter(int n){
k.resize(n,0);
}

void increment(int i){
k[i]=k[i]+1;
}
void decrement(int i){
k[i]=k[i]-1;
}
void rest(int i){
k[i]=0;
}
int count(int i){
return k[i];
}
int findMax(){
int maxmum=0,i;
for(i=0;i<k.size();i++){
  if(k[i]>maxmum){maxmum=k[i];}
                      }
    return maxmum;
}
int numMax(){
int maxmum=0,i,num=0;
for(i=0;i<k.size();i++){
  if(k[i]>maxmum){
                 maxmum=k[i];
                 num=1;
  }
  else{
         if(k[i]=maxmum){num=num+1;}
  }
                      }
    return num;
}
void printmax(){
int maxmum=0,i;
for(i=0;i<k.size();i++){
  if(k[i]>maxmum){maxmum=k[i];}
                      }

for(i=0;i<k.size();i++){
  if(k[i]==maxmum){
     cout<<i<<" ";}

}
}

};










