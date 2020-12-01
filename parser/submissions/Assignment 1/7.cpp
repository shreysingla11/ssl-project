#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(long long int i){

}

int main(){

 long long int n;

 cout<<"enter n : ";

 cin>>n;

 cout<<endl;

double maxf=f(1);
double fall=0;
double newfall;
double gradient=0;
double newgradient;

   for(int i=2;i<=n;i++){

   if(f(i-1)>maxf)maxf=f(i-1);

   newfall=maxf-f(i);

   if(newfall>fall)fall=newfall;

   newgradient=f(i)-f(i-1);

   if(gradient<newgradient)gradient=newgradient;

     }

 cout<<setprecision(12)<<"maximum fall is : "<<fall<<endl<<endl;

 cout<<setprecision(12)<<"maximum rate of fall : "<<gradient<<endl;

 return 0;

  }
