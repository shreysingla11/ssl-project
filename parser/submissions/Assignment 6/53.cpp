#include<string>
#include<iostream>

using namespace std;

int main(){
string main;
cin>>main;
int l,min_len,min_pos,length_w,i,j,m,a,n,b;
n=main.size();
//cout<<n;
l=1;
min_len=n;
min_pos=n;
a=0;b=0;
for(l=1;l<n;l=2*l){
    for(m=0;m+l<n;){
    //cout<<"2\n";
        for(i=m,j=m+l-1;i<m+l&&j<m+4*l-1;){
         //cout<<i;
            if(main[i]==main[l+j]){i++;j++;}
            else{i=m;j=l+j;}//if(j>3*l-1){break;}}
        }
        //cout<<i;
        if(i==m+l){
        //cout<<"abc";
            length_w=j-i+1;
            //cout<<length_w<<endl;
            if(length_w>0){
            for(i=m+l;a<length_w&&a<3*l-2;){//cout<<"4\n";
                if(main[i]==main[l+j]){i++;j++;a++;}
                else if(main[i-length_w]==main[l+j-length_w]){i++;j++;a++;}
                else{break;}
            }
            if(a==length_w){
                if(min_pos>(m)){min_pos=m;}//min_pos=i-length_w;}
                if(min_len>length_w){min_len=length_w;}
                //cout<<"found it!";
            }
            }
            else if(n/2==length_w){
                if(min_pos>0){min_pos=0;}
                if(min_len>length_w){min_len=length_w;}
                //cout<<"found it!";

            }

        }
        //cout<<min_len<<" "<<min_pos<<endl;
        a=0;
        b=0;
        m=l+m;
        //cout<<m<<endl;
        }
        //cout<<l<<endl;
}

if(n==2&&main[0]==main[1]){min_len=1;min_pos=0;}
if(min_pos==n&&min_len==n){cout<<"0 0";}
else{cout<<min_len<<" "<<min_pos;}
return 0;
}
