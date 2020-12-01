#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

extern double f(long long n);

double max(double a,double b){
  if(a>b)return a;
  else{
    return b;
  }
}

int main(){
  long long n;
  cin>>n;
  double r1=0;//result of part1 of problem
  double r2=0;//result of part2 of problem
  double Max=f(1);
  double num2=Max;
  double num1;

  for(long long i=2;i<=n;){
     num1=f(i);
     //num1=f(i) and num2=f(2)
     r1=max(r1,Max-num1);
     r2=max(r2,num2-num1);
     Max=max(Max,num1);
     num2=num1;
     i++;
  }

  printf("%.6lf",r1);
  cout<<endl;
  printf("%.6lf",r2);

  return 0;

}

