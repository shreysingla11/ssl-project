#include <iostream>
#include <string>
using namespace std;
int main(){
string a;
cin>>a;
int b=a.size();
bool flag='false';
int ans1=0;
int ans2=0;
for(int i=1;i<(b/2);i++){
for(int j=0;j<(b-2*i-1);j++){
if(a.substr(j,i)==a.substr(j+i,i)){flag='true';ans1=i;ans2=j;break;}
}
if(flag=='true'){break;}
}
cout<<ans1<<" "<<ans2<<endl;
return 0;
}
