#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
int m,n,p,q=0,k=0,r=0;
int length=0,num=0;
int a[1000000],b[1000000];

cin>>m; //length of the first sequence
cin>>n; //length of the second sequence
for(int i=0;i<m;i++){
cin>>a[i];
}

for(int j=0;j<n;j++){
cin>>b[j];
}
for(p=0;p<n;p++){
    k=0;

    for(;((q<m) && (k==0));q++){

        if(a[q]==b[p]){
            k=1;
            num++;
            length++;
            if(length==1){
                r=q+1;
            }
        }
        else if(length>0 && length<m && a[q]!=b[p]){
            length++;
        }


    }

}
if((num!=n) || (length==0)){
    cout<<"infinity"<<endl;
}

else{
    cout<<length<<" "<<r<<endl;
}
return 0;
}
