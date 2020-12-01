#include <iostream>
#include <cmath>
using namespace std;

extern double f(int i);

int main(){
    double fall=0.0,rate=0.0,temp=0.0,ti=0.0,tj=0.0,t1=0.0,minm=0.0,maxm=0.0,maxm1=0.0;
    int n,p,a,b,c,d,r=0;
    cout<<"Give the value of n :"<<endl;
    cin>>n;
    t1=f(1);
    if(n>1){
        int i, j=0;
        for(i=2;i<=n;i++,t1=ti){ti=f(i);
            if(ti<t1){j=j+1;temp=(t1-ti);
                if(j==1){maxm=t1;minm=ti;r=1;rate=temp;}
                if(t1>maxm){maxm1=maxm;maxm=t1;r=9;}
                if(ti<minm){minm=ti;r=1;}
                if((t1-ti)>temp){rate=temp;}
            }
        }
    }
    if(r==1){fall=maxm-minm;}
    if(r==9){fall=maxm1-minm;}
    cout<<fall<<endl;cout<<rate<<endl;
    return 0;
}
