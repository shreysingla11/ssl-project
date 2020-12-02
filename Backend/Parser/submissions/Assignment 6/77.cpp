#include<string>
#include<iostream>
using namespace std;
bool check = false;
int main()
{

string s;
cin>>s;
/*int n = s.length();
for( int l =1 ;l<n;l = 2*l)
{
for( int box = 0; box < n;box=box+l )
{
// checking for each box

int temp = box; int temp2 = l+box;
for(int i = box ; i < box + l && temp2 < box +4*l-1 && temp2<n && i<n; )
  {
  //

  if(s[i] == s[temp2 + i]){i++;}

   else {
        if(i==box)temp2++;
        temp2 = temp2 + i;
        i = box;
   }
int countl = 0;
//checking backwards
    if(i==box+l){
    check = true;
   for(int j = box-1, k = temp2-1;j>=0&&j>=temp2-i&&k>=i;k--,j--)
   {
   if(s[j]==s[k]){countl++;continue;}
   else {check = false;break;}
   }

   }

   //if( check == true) {cout<<temp2-i + l;cout<<box+countl;cout<<"asdsa";break;}

int countlr = 0;
   //checking forwards
   if(i==box+l){
    check = true;
   for(int j = i, k = temp2+l;j<temp2 && k<temp2+l+temp2-i;k++,j++)
   {
   if(j==k){check= false;break;}
   if(s[j]==s[k]){countlr++;continue;}
   else {check = false;break;}
   }

   }

if( check == true) {cout<<l+countlr;cout<<box;break;}
    }

if(check==true)break;
}
if(check==true)break;

}*/
cout<<0<<" "<<0;

}
