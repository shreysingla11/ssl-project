#include<iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


class Node{
public:
int id,t_i,n_i;
int* f;
vector<int> mates;
bool go;
bool go1;
int count;
Node(){
count=0;
go=false;
go1=false;
}
};

int main(){
int n;
cin>>n;
vector<Node> v(n);
stack<int> g;
stack<int> ng;

for(int i=0;i<n;i++){

v[i].id=i;
cin>>v[i].t_i;
cin>>v[i].n_i;
if(v[i].t_i==0){v[i].go=true;g.push(v[i].id);}
if(v[i].t_i>v[i].n_i){ng.push(v[i].id);v[i].go1=true;}
int a[v[i].n_i];
for(int j=0;j<v[i].n_i;j++){
cout<<"wfw";
cin>>a[j];}
v[i].f=new int[v[i].n_i];
v[i].f=a;

}
cout<<"hi";
for(int i=0;i<n;i++){
for(int j=0;j<v[i].n_i;j++){
(v[(v[i].f)[j]].mates).push_back(i);}
}
int mins=0;
while(!g.empty())
{
int m=g.top();
g.pop();
mins++;
v[m].go = true;
vector<int>::iterator it;
for(it=(v[m].mates).begin();it!=(v[m].mates).end();it++)
{v[*it].t_i--;
if(v[*it].t_i==0 & !(v[*it].go)){g.push(v[*it].id);}
}
}

int maxs=0;
while(!ng.empty())
{
int m=ng.top();
ng.pop();
maxs++;
v[m].go1 = true;
vector<int>::iterator it;
for(it=(v[m].mates).begin();it!=(v[m].mates).end();it++)
{v[*it].n_i--;
if((v[*it].t_i>v[*it].n_i) & !(v[*it].go)){g.push(v[*it].id);}
}
}

cout<<mins<<" "<<n-maxs;
return 0;}












