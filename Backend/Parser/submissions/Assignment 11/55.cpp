#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string get_string(int j)
{
  string res,temp;
  res="000000000000000000000000000000000000000000000";
  temp="00000";
  for(int i=0;i<5;i++)
  {
    if(j%2==0){temp[4-i]='0';}
    else{temp[4-i]='1';}
    j=j/2;
    for(int o=0;o<9;o++)
      {res[44-9*i-o]=temp[4-i];}
    
  }
  return res;
}
long long int get_int(string a)
{
  long long int res=0,temp=1;
  for(int r=44;r>=0;r--)
  {
    if(a[r]=='1'){res=res+temp;}
    temp=2*temp;
  }
  return res;
}
void flip(string &a,int i)
{
 if(a[i]=='0'){a[i]='1';}
 else{a[i]='0';}
}
int main()
{
 int n;
 unordered_map<long long int,char> mymap;
 char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 int j=0;long long int i=0;
 for(j=0;j<26;j++)
 {
   string a=get_string(j);
   mymap[get_int(a)]=alp[j];
   for(int i1=0;i1<45;i1++)
   {
   	flip(a,i1);
    for(int i2=i1+1;i2<45;i2++)
   {
     flip(a,i2);
     for(int i3=i2+1;i3<45;i3++)
   {
     flip(a,i3);
     for(int i4=i3+1;i4<45;i4++)
   {
    flip(a,i4);
    mymap[get_int(a)]=alp[j];
    flip(a,i4);
   }
      mymap[get_int(a)]=alp[j];
      flip(a,i3);
   }
      mymap[get_int(a)]=alp[j];
      flip(a,i2);
   }
    mymap[get_int(a)]=alp[j];
    flip(a,i1);
   }
 }
 cin>>n;
 for(int i=0;i<n;i++)
 {long long int q;
  cin>>q;
  unordered_map<long long int,char>::const_iterator got = mymap.find(q);
  if(got == mymap.end()){cout<<"?";}
  else{
  cout<<got->second;}
 }
}
