
#include <iostream>
#include <vector>
#include <cmath>
#include<cstdio>
using namespace std;
int p,a,b,c,d,n;
extern double f(int i);
//{
//
//double ans=p * (sin(a*i+b) + cos(c*i+d) + 2);
//return ans;
//};


int main(){
cin>>n;

//double max=0;
//double MAX=0;
double max_rate=0;
//double a;
//double b;
//vector<double> * loc;
//loc=new vector<double>;
int i=1;
int j=1;
int k=1;
int m=1;
double ans=0;
while(m<n){
m++;
if(f(m)<=f(j)){

//k=j;
j=m;
i=k;

}
else{
//if(f(m)<f(k)){
if((f(i)-f(j))>(f(k)-f(m))){
}
else{
i=k;
j=m;
}
//}
//else{
//}
}

if(f(m)>=f(k)){
        if(m>=j){
k=m;}
}
}
//if(f(k))
//cout<<i<<" "<<j<<endl;
//cout<<n<<" "<<k<<endl;
if(ans<=(f(i)-f(j))){
ans=f(i)-f(j);
}
//n++;

for(long long i=1;i<=n;i++){
a=f(i);
b=f(i+1);
//cout<<a-b<<endl;
if(a>=b){
//cout<<a-b<<endl;
//cout<<"here"<<i<<endl;
//max+=a-b;
if((a-b)>max_rate)
{
max_rate=a-b;
}
}
else{
//if(max>MAX){
//MAX=max;
//loc->push_back(max);
//loc->push_back(b-a);
//}
//max=0;
}
}
//cout<<MAX<<endl;

printf("%.6f",ans);
cout<<endl;
printf("%.6f",max_rate);

return 0;
}
