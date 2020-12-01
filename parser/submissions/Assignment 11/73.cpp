#include <iostream>
#include<string>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include <unordered_map>
using namespace std;
typedef unordered_map<long long int,char> bitmap;

long long int finalans(string s){
    long long int i=0;
    for(int j=0;j<45;j++){
        i=i*2 + (s[j]-'0');
    }
};
int main ()
{
    bitmap mymap;
    string s;
    char ch;
    ch = 'a';
    long long int ans;
    for(int i=0;i<26;i++){
        string stat = "";
        bitset<5> a(i);
        string s =a.to_string();
        for(int j=0;j<5;j++){
            for(int k=0;k<9;k++){
                stat+=s[j];

            }
        }
for(int l=0;l<45;l++){

	for(int m=l+1;m<45;m++){
		for(int n=m+1;n<45;n++){
			for(int p=n+1;p<45;p++){
				s = stat;
	if(s[p]=='0'){
                       s[p]='1';
                     }
      else{
             s[p]='0';
             }
    if(s[n]=='0'){
                s[n]='1';
             }
      else{
             s[n]='0';
           }
      if(s[m]=='0'){
              s[m]='1';
              }
         else{
               s[m]='0';
              }
      if(s[l]=='0'){
               s[l]='1';
          }
            else{
           s[l]='0';
          }
       ans=finalans(s);
        mymap[ans]=ch;
         }}}}
for(int l=0;l<45;l++){
     for(int m=l+1;m<45;m++){
          for(int n=m+1;n<45;n++){

             s = stat;
              if(s[n]=='0'){
             s[n]='1';
            }
           else{
            s[n]='0';
           }
          if(s[m]=='0'){
            s[m]='1';
           }
          else{
           s[m]='0';
          }
          if(s[l]=='0'){
            s[l]='1';
          }
        else
          {
            s[l]='0';
             }
        ans=finalans(s);
          mymap[ans]=ch;
    }
      }
 }
for(int k=0;k<200;k++){
}
  for(int l=0;l<45;l++)
    {
     for(int m=l+1;m<45;m++)
      {
           s = stat;
         if(s[m]=='0')
             {
              s[m]='1';
           }
          else
           {
               s[m]='0';
        }
           if(s[l]=='0')
        {
              s[l]='1';
     }
          else
        {
             s[l]='0';
       }
           ans=finalans(s);
        mymap[ans]=ch;
    }
 }
 for(int l=0;l<45;l++)
  {
  s = stat;
    if(s[l]=='0') {
          s[l]='1';
        }
      else
      {
     s[l]='0';
      }
  ans=finalans(s);
   mymap[ans]=ch;
    }
  ch++;
   }


   int z;
   cin>>z;
   for(int p=0;p<z;p++)
   {
  long long int input;
  cin>>input;
  unordered_map<long long int,char>::iterator got = mymap.find(input);
  if(got==mymap.end()){
     cout<<"?";
     }
   else{
     cout<<got->second;
     }
    }
return 0;
}
