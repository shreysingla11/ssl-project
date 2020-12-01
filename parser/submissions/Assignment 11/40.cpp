#include <unordered_map>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void func(int a,int c[]){
  for(int i=0;i<5;i++){
    c[i]=0;
  }
  int y=a;
  int j=0;
  while(y>0){
   if(y%2==1)c[j]=1;
   j++;
   y/=2;
  }
  int arr[5];
  for(int i=0;i<5;i++){
    arr[i]=c[i];
  }
  for(int i=0;i<5;i++){
    c[i]=arr[4-i];
  }
}

int main() {
    std::ios::sync_with_stdio(false);
    unordered_map <long long, char> hashmap;

    long long powers[45];
    long long tmp=1;
    for(int i=0;i<45;i++){
      powers[i]=tmp;
      tmp*=2;
    }

    int A[26][5];
    for(int i=0;i<26;i++){
      func(i,A[i]);
    }

    long long val[26];
    long long v=powers[9]-1;
    for(int i=0;i<26;i++){
      val[i]=0;
      for(int j=4;j>=0;j--){
        val[i]+=A[i][j]*(v*powers[(4-j)*9]);
      }
      //cout<<val[i]<<endl;
    }

    for(int it=0;it<26;it++){
      char tar='a'+it;
      for(int i=0;i<45;i++){
        for(int j=i+1;j<45;j++){
          for(int k=j+1;k<45;k++){
            for(int l=k+1;l<45;l++){
               int ind=4-(i/9);
               long long tmp=val[it];
               if(A[it][ind]==1){
                 tmp-=powers[i];
               }
               else{
                  tmp+=powers[i];
               }
               ///////////
               ind=4-(j/9);
               if(A[it][ind]==1){
                 tmp-=powers[j];
               }
               else{
                  tmp+=powers[j];
               }
               ///////////
               ind=4-(k/9);
               if(A[it][ind]==1){
                 tmp-=powers[k];
               }
               else{
                  tmp+=powers[k];
               }
               ///////////
               ind=4-(l/9);
               if(A[it][ind]==1){
                 tmp-=powers[l];
               }
               else{
                  tmp+=powers[l];
               }

               hashmap[tmp]=tar;
            }
          }
        }
      }
    }


    for(int it=0;it<26;it++){
      char tar='a'+it;
      for(int i=0;i<45;i++){
        for(int j=i+1;j<45;j++){
          for(int k=j+1;k<45;k++){
               int ind=4-(i/9);
               long long tmp=val[it];
               if(A[it][ind]==1){
                 tmp-=powers[i];
               }
               else{
                  tmp+=powers[i];
               }
               ///////////
               ind=4-(j/9);
               if(A[it][ind]==1){
                 tmp-=powers[j];
               }
               else{
                  tmp+=powers[j];
               }
               ///////////
               ind=4-(k/9);
               if(A[it][ind]==1){
                 tmp-=powers[k];
               }
               else{
                  tmp+=powers[k];
               }

               hashmap[tmp]=tar;
          }
        }
      }
    }


    for(int it=0;it<26;it++){
      char tar='a'+it;
      for(int i=0;i<45;i++){
        for(int j=i+1;j<45;j++){
               int ind=4-(i/9);
               long long tmp=val[it];
               if(A[it][ind]==1){
                 tmp-=powers[i];
               }
               else{
                  tmp+=powers[i];
               }
               ///////////
               ind=4-(j/9);
               if(A[it][ind]==1){
                 tmp-=powers[j];
               }
               else{
                  tmp+=powers[j];
               }

               hashmap[tmp]=tar;
        }
      }
    }

    for(int it=0;it<26;it++){
      char tar='a'+it;
      for(int i=0;i<45;i++){
               int ind=4-(i/9);
               long long tmp=val[it];
               if(A[it][ind]==1){
                 tmp-=powers[i];
               }
               else{
                  tmp+=powers[i];
               }

               hashmap[tmp]=tar;
      }
    }

    for(int it=0;it<26;it++){
      char tar='a'+it;
      long long tmp=val[it];
      hashmap[tmp]=tar;
    }

    //cout<<hashmap[15]<<endl;
    //cout<<hashmap[591]<<endl;
    //if(hashmap.count(527)==0)cout<<"?";


    int Te;
    cin>>Te;
    long long test;
    for(int te=0;te<Te;te++){
      cin>>test;
      if(hashmap.count(test)==0)printf("?");
      else{
        printf("%c",hashmap[test]);
      }
    }
    cout<<endl;
    return 0;
}
