#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

double temp_function(int p,int a,int b,int c,int d,long long int n){
  }
  int main()
  {
  int p,a,b,c,d;
  long long int n,i,j;
  double fall,max_fall=0.0,max_rate=0.0, rate;

  cout<<"enter the value for p,a,b,c,d,n"<<endl;

  cin>>p>>a>>b>>c>>d>>n;

  for(i=1;i<n;i++){
     for(j=n;j>i;j--){

       if(temp_function(p,a,b,c,d,i)>temp_function(p,a,b,c,d,j)){

            fall=temp_function(p,a,b,c,d,i)-temp_function(p,a,b,c,d,j);
            rate=fall/(j-i);

            if (fall>max_fall){
            max_fall=fall;}
            else{}

            if (rate>max_rate){
                max_rate=rate;}
               else{}

            }
            else{}
        }
}

   cout<<"maximum fall is"<<endl;
   printf("%.6f",max_fall);
   cout<<"\n maximum fall rate is"<<endl;
   printf("%.6f",max_rate);

    return 0;
    }
