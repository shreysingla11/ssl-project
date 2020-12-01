#include<iostream>
using namespace std;

void extend(int i,int l,int k,bool &p,int &los,int &pos,string s,int n1)
{
 int n=k-i-l;pos=i;los=l;int e1,e2;
 e1=i+l-1;e2=k+l-1;
 //code for extending when i=0 to be written here
 if(i==0)
 {
   while((e1<k-1) && (e2<n1))
   {
    if(s[e1+1]==s[e2+1]){e1++;e2++;los=los+1;}
    else {return;}
   }
 }
 //code for extending the substring
 while((n) && (i>0) && (e2<n1))
 {
  if(s[i-1]==s[k-1]){i--;k--;los=los+1;pos=i;n--;}
  else if(s[e1+1]==s[e2+1]){e1++;e2++;los=los+1;n--;}
  else {return;}
 }
 p=true;return;
}

int main()
{
 string s;int l=1;bool p=false;int los=0,pos=0;int i=0;
 cin>>s;
 int n=s.length();
 int t1=0;
 while(t1<n-1)
 {
  if(s[t1]==s[t1+1]){cout<<1<<" "<<t1<<endl;return 0;}
 t1++;
 }
 //loop for checking each l
 while((!p) && (l<n))
 {
    //loop to check for each block of length l
    i=0;
    while((!p) && (i<n))
    {
     //this code should be done in o(l)
     int j=i,k=l+i;
     while((j<i+l) && (k<4*l-1+i) && (j<n) && (k<n) && (!p))
     {
      if(s[j]==s[j+k-i]){j++;}
      else {k=k+j-i+1;j=i;}
      if(j==l+i){extend(i,l,k,p,los,pos,s,n);}
     }
     i=i+l;
    }
    l=2*l;
 }
 if(p){cout<<los<<" "<<pos<<endl;}
 else {cout<<0<<" "<<0<<endl;}
 return 0;
}
