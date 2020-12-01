#include<iostream>
#include<queue>
using namespace std;

int main(){
int n;
queue<pair<int,int> > q;
cin>>n;
int c[n][n];
int dis[n][2*n-1];
bool enter[n];
int mins[n];

for(int i=0;i<n;i++){
 enter[i]=false;
 mins[i]=-2;
for(int j=0;j<n;j++){
cin>>c[i][j];}}

for(int i=0;i<n;i++){
for(int j=0;j<2*n-1;j++){
if(i==0){dis[i][j]=0;}
else{dis[i][j]=-1;}
}}
pair<int,int> p(0,0);
q.push(p);
pair<int,int> v;

while(!q.empty()){

v=q.front();
q.pop();
for(int i=0;i<n;i++){
if(i!=v.first){

if((-(n-1)<=v.second<=(n-1))&&(c[v.first][i]<0)){
if(dis[v.first][v.second+(n-1)-1]!=-1){
dis[i][v.second+(n-1)]=dis[v.first][v.second+(n-1)+1]-c[v.first][i];
if(!enter[i]){
v.first=i;v.second=v.second+1;
q.push(v);}
}
}

if((-(n-1)<=v.second<=(n-1))&&(c[v.first][i]>0)){
if(dis[v.first][v.second+(n-1)-1]!=-1){
dis[i][v.second+(n-1)]=dis[v.first][v.second+(n-1)-1]+c[v.first][i];
if(!enter[i]){
v.first=i;v.second=v.second-1;
q.push(v);}
}
}

}
}
}

for(int i=0;i<n;i++){
int counts=0;
for(int j=0;j<2*n-1;j++){
if(dis[i][j]!=-1){mins[i]=dis[i][j];break;}
}
for(int j=0;j<2*n-1;j++){
if((dis[i][j]<mins[i])&&(dis[i][j]!=-1)){mins[i]=dis[i][j];}
}
if(mins[i]!=-2){cout<<mins[i]<<endl;}
else{cout<<"infinity"<<endl;}
}


return 0;
}
