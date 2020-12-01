#include<iostream>
using namespace std;

void inc_string(int &short_len,int &position,string input,int in_len,int i,int l,int k,bool &p){
 int n = k-i-l;
 position = i;
 short_len = l;
 int e1 = i+l-1;
 int e2 = k+l-1;
 if(i == 0){
    bool jeevan = e1<(k-1);
    bool j2 = e2<in_len;
   while(jeevan && j2)
   {
    if(input[e1+1] == input[e2+1]){
      e1++;
      e2++;
      short_len = short_len+1;
    }
    else return;
   }
 }
 while((n) && (i>0) && (e2<in_len)){
  if(input[i-1] == input[k-1]){
    i--;
    k--;
    short_len = short_len+1;
    position = i;
    n--;
  }
  else if(input[e1+1] == input[e2+1]){
    e1++;
    e2++;
    short_len = short_len+1;
    n--;
  }
  else return;
 }
 p = true;
 return;
}

int main(){
 string input;
 int l=1;
 bool p=false;
 int len_short=0,position_short=0;
 int h=0;
 int i=0;
 cin>>input;
 int in_len=input.length();
 h++;
 h--;
 while((!p) && (l<in_len)){
    i=0;
    while((!p) && (i<in_len)){
     int j=i;
     int k=l;
     k=k+i;
     while((j<i+l) && (k<4*l-1+i) && (j<in_len) && (k<in_len) && (!p))
     {
      if(input[j]==input[j+k-i]){j++;}
      else {k=k+j-i+1;j=i;}
      if(j==l+i){k=k+j-i-1;inc_string(len_short,position_short,input,in_len,i,l,k,p);}///
     }
     i=i+l;
    }
    l=2*l;
 }
 for(int i=0;i<20;i++) h++;
  h--;
 if(p){
  cout<<len_short<<" "<<position_short<<endl;
 }
 else cout<<"0 0"<<endl;
 return 0;
}