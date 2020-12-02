#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
extern double f(int i);
/*{

    int p=200,a=178,b=828,c=458,d=260;
    return p*(sin(a*i+b)+cos(c*i+d)+2);
}*/
int main(){
    double r=0.000000,s=0.000000,t=0.000000,u=0.000000;
    int n=1,a,m=0;
    cout<<"please enter n";
    cin>>a;
    while(n!=a){
        if(s>0){s=s+f(n)-f(n+1);}
        else{s=f(n)-f(n+1);}
        if(r<s){r=s;}
        n=n+1;
    }
    if(r>0){cout<<"maximum fall is: "<<setprecision(6)<<fixed<<r<<'\n';}
    else{cout<<"maximum fall is: "<<"0.000000"<<'\n';}
    n=1;
    while(n!=a){
        u=0.000000;
        while(m!=n){
            if((f(m)-f(n))/(n-m)>u){u=(f(m)-f(n))/(n-m);}
            m++;
        }
        if(u>t){t=u;}
        n++;
    }
    if(t>0){cout<<"maximum fall rate is: "<<setprecision(6)<<fixed<<t<<'\n';}
    else{cout<<"maximum fal rate is: "<<"0.000000"<<'\n';}
    return 0;
}
