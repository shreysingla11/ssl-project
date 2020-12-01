#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

extern double f(int i);

int main(){
    int n,x=1;
    int j=1;
    double p=0.0,q=0.0,r=0.0,s=0.0,tfall=0.0,tfrate=0.0;
    double tr=0.0,fofx=0.0;
    cout<<"give the value of n: ";
    cin>>n;
    while(x!=n){
        tfall=f(x)-f(x+1);
        q=q+tfall;
        if(q<tfall){
            q=tfall;
        }
        if(p<q){
            p=q;
        }

        tfrate=tfall;
        fofx=f(x+1);
        while(j!=x){
            tr=(f(j)-fofx)/(x+1-j);
            if(s<tr){s=tr;}
            j++;
        }
        if(s<tfrate){
            s=tfrate;
        }
        if(r<s){
            r=s;
        }
        x=x+1;
    }
    cout<<"max value of fall is: ";
    printf("%f",p);
    cout<<endl<<"max value of fall rate is: ";
    printf("%f",r);
    return 0;
}
