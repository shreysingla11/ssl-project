#include <iostream>
using namespace std;
struct point{
int x,y;
char c;};
int main(){
int n;
cout<<"enter the total number of points"<<endl;
cin>>n;
if (n%2!=0||n<0){cout<<"invalid input"<<endl;}
else {n=n/2;}
point red[n],blue[n];
for(int i=0;i<n;i++){
cin>>red[i].x>>red[i].y;
}
for(int i=0;i<n;i++){
cin>>blue[i].x>>blue[i].y;
}
return 0;
}

















