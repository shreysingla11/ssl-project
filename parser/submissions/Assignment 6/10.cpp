#include<iostream>
#include<string>
using namespace std;
int main()
{
 string s;
 int n,l,z,i,m,cnt=0,length=0,k,start=0;
 bool flag=true;
 cout<<"give the string"<<endl;
 cin>>s;
 n=s.size();

 for(l=1;l<n/2+1;l=l*2){


    for (z=0;z<n/l;z=z+l){

         for(i=0;i<l;i++){

             if(s[z+i]==s[z+i+l]){
              cnt++;

              m=z+i+l;}

              else{
                for(k=0;(k<=cnt)&&(m<n);){

                     if(s[z+k]==s[m]){
                        m=m+1;
                        k=k+1;
                     }
                     else {k=0;
                     m=m+1;}
                     }
              if((k==cnt)&&(cnt!=0)){
              start=z;
              length=cnt;
              flag=false;
              break;}

              else{}

               }
               if(flag==false){
               break;}
               else{}
               }
               if(flag==false){
               break;}
               else{}
        }if(flag==false){
               break;}
               else{}

        }
cout<<length<<start<<endl;
return 0;


 }
