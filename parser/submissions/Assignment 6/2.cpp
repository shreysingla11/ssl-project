#include<iostream>
#include<string>
using namespace std;
int findoccurence(int k,string s,int l){
int i,j,m,q;
for(i=k+l;i<=k+3*l-1;i=i+1){
              q=0;
            for(j=k,m=i;(j<k+l)&&(m<i+l);){
                     if(s[j]==s[m]) { j=j+1;m=m+1;}
                          else { q=1;break; }
                                          }
           if(q==0){return i;}
                            }
              return -1;   //means no matching
                                         }

int main(){
string s;
int l,k,q,d,n,sql,le,found;
int i,j,pos;
pos=-1;
cin>>s;
n=s.size();
//q=findoccurence(2,s,1);cout<<"occurs at  "<<q<<endl;
for(l=1;l<n;l=l*2){
        found=0;
      for(k=0;k<(n/l);k=k+l){
           q=findoccurence(k,s,l);//cout<<"occurs at ... "<<q<<endl;
          if(q!=-1){//2nd occurence has been found
                d=q-k-l;
               sql=d+l;
                le=l;
            for(i=k,j=q ;(i>=k-d)&&(j>=q-d); ){//backwards
                     if(s[i-1]==s[j-1]) {pos=i;i=i-1;j=j-1;pos=i;le=le+1;}
                        else break;
                                                    }
             if(le==sql){found=1;break;}
        for(i=k+l,j=q+l ;(i<=k+l+d-1)&&(j<=q+l+d-1); ){ //forwards
                if(s[i]==s[j]) {
                                 i=i+1;j=j+1;le=le+1;
                                 }
                if(le==sql){break;}
                if(s[i]!=s[j]) break;
                                                        }

              if(le==sql){found=1;break;}

                      }
                               }

        if(found==1){ if(pos==-1){pos=k;};break;}

                }
    if(found==1){cout <<sql<<" "<<pos<<endl;}
    if(found==0){cout <<"0"<<" "<<"0"<<endl;}
return 0;
         }
