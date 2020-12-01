#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
int n;
int mini=0,maxi=0,x=0,z=0,y=-1,w=-1;
queue<int> a,sw;
cin>>n;
maxi=n;
int threshold[n];
int thresh[n];
int going_movie[n];
bool inqueue[n];
bool deq[n];

vector< vector<int> > s,qw(n);
vector<int> t;

for(int i =0;i<n;i++){
threshold[i]=0;
inqueue[i]=false;

deq[i]=false;
going_movie[i]=-1;//going=1,notgoing=0;notdecided=-1
int t_i,n_i;
cin>>t_i;
if(t_i==0){
x=x+1;
going_movie[i]=1;
y=i;
}

cin>>n_i;
thresh[i]=n_i;
if(t_i>n_i){
z++;
w=i;
}

t.push_back(t_i);
t.push_back(n_i);

for(int j=0;j<n_i;j++){
int temp;
cin>>temp;
t.push_back(temp);
qw[temp].push_back(i);
}

s.push_back(t);
t.clear();
}
if(x==0){
mini=0;
}
if(x!=0){
a.push(y);
inqueue[y]=true;
int u=0;
while(!a.empty()){
//u++;cout<<u<<endl;
/*for(int i=0;i<n;i++){
for(int j=0;j<s[i][1];j++){
if(s[i][j+2]==y){
threshold[i]++;
}
}
}
*/
for(int i = 0;i<qw[y].size();i++)
{
    threshold[qw[y][i]]++;
}
a.pop();
mini++;
for(int i=0;i<n;i++){
if(threshold[i]>=s[i][0]&&inqueue[i]==false){
a.push(i);
y=i;
inqueue[i]=true;
break;
}
}
}
}
if(z==0){
maxi=n;}
if(z!=0){
sw.push(w);
deq[w]=true;
while(!sw.empty()){
/*for(int i=0;i<n;i++){
for(int j=0;j<s[i][1];j++){
if(s[i][j+2]==w){
threshold[i]--;
}
}
}*/
for(int i = 0;i<qw[w].size();i++)
{
    thresh[qw[w][i]]--;
}
sw.pop();
maxi--;
for(int i=0;i<n;i++){
if(thresh[i]<s[i][0]&&deq[i]==false){
sw.push(i);
//y=i;
deq[i]=true;
w=i;
break;
}
}

}
}
cout<<mini<<" "<<maxi;
}
