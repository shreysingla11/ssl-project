#include<iostream>
using namespace std;
extern double f(int a){
                       }
int g(int i,int n){int k=f(i);int j;
             for(j=i+1;j<n+1;j++){if(k>f(j))k=f(j);}return f(i)-f(j);}
int main(){int n,m;double max1=0,max2=0;
           cout<<"enter the number"<<endl;
           cin>>n;


           for(int i=1;i<n+1;i++){if(max1<g(i,n))max1=g(i,n);

                                 }
            int x1=max1*1000000,x2=max2*1000000;max1=x1/1000000.0;max2=x2/1000000.0;
            cout<<"maximum fall is "<<max1<<endl;
            cout<<"maximum rate of fall is "<<max2<<endl;

           }
