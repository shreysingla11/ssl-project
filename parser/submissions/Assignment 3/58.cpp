#include <iostream>
#include <limits>
using namespace std;
int main (){
    int n,m;
    cin>>n>>m;
    int* a=new int[n+1];
    int* b=new int[m+1];
    for(int a1=1;a1<n+1;a1++){
        cin>>a[a1];
    }
    for(int a2=1;a2<m+1;a2++){
        cin>>b[a2];
    }
    int* e=new int[n+1];
    int* f=new int[n+1];
    int i,l;
    for(i=n;i>0;i--){
        if(i==n){
            if(a[i]==b[m]){f[i]=1;}
            else{f[i]=numeric_limits<int>::max();}
        }
        else{
            if(a[i]==b[m]){f[i]=1;}
            else{
                if(f[i+1]==numeric_limits<int>::max()){f[i]=numeric_limits<int>::max();}
                else{f[i]=1+f[i+1];}
            }
        }
    }
    for(int j=m-1;j>0;j--){
        e[n]=numeric_limits<int>::max();
        for(i=n-1;i>0;i--){
            if(a[i]==b[j]){
                if(f[i+1]!=numeric_limits<int>::max()){e[i]=1+f[i+1];}
                else{e[i]=numeric_limits<int>::max();}
            }
            else{
                if(e[i+1]!=numeric_limits<int>::max()){e[i]=1+e[i+1];}
                else{e[i]=numeric_limits<int>::max();}
            }
        }
        for(l=1;l<n+1;l++){f[l]=e[l];}

    }
    int minim=numeric_limits<int>::max(),v;
    for(l=1;l<n+1;l++){
        if(e[l]<minim){minim=e[l];v=l;}
    }
    if(minim==numeric_limits<int>::max()){cout<<"infinity"<<' '<<v;}
    else{cout<<minim<<' '<<v;}










    return 0;
}
