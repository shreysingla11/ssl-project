#include <iostream>
#include <vector>
using namespace std;
class distinct{
vector<int> main;
public:
distinct(vector<int> a){
main=a;
}
int num_distinct(int i,int j){
if(i>j){return 0;}
else{}
if(i==j){return 1;}
else{};
int dec=0;
for(int a=i;a<j;a++){
for(int b=a+1;b<=j;b++){
if(main[a]==main[b]){dec++;break;}
else{}
}
}
return j-i+1-dec;
}
};
