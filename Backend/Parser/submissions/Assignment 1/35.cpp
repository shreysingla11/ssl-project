#include <iostream>
using namespace std;
extern double f (int i);
int main()
{
int n;
cout<<"give the no.of numbers in the sequence"<<endl;
cin>>n;
int k;
double max_rate=0,curr_rate;
for(k=1;k<n;k++){
if( f(k+1)<f(k)){curr_rate=f(k)-f(k+1);
if(max_rate<curr_rate){max_rate=curr_rate;};}
}

cout<<"maximum rate of fall is"<<max_rate<<endl;
return 0;
}
