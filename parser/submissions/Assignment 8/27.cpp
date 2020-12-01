#include<iostream>
#include<vector>
using namespace std;

class lane{
public:
char d;
int tot;
int s;
vector<int> l;
vector<int> p;
};

vector<float> inter(vector<float> &a,vector<float> &b){
int i=0,j=0;
vector<float> tm;
while(i<a.size()&&j<b.size())
{
if(a[i]<=b[j]){
 if(b[j+1]>a[i+1]){tm.push_back(b[j]);tm.push_back(a[i+1]);}
 if(b[j+1]<a[i+1]){tm.push_back(b[j]);tm.push_back(b[j+1]);}
 if(a[i+1]<b[j]){i=i+2;}
}
else{
if(b[j+1]>a[i+1]){tm.push_back(a[i]);tm.push_back(b[j]);}
 if(b[j+1]<a[i+1]){tm.push_back(a[i]);tm.push_back(b[j+1]);}
 if(a[i+1]<b[j]){j=j+2;}
 }
 return tm;
}

}

int main(){
float n,w,u,v,t1,t2;
cin>>n>>w>>u>>v>>t1>>t2;
vector<lane> lan(n);

for(int i=0;i<n;i++){
char tp1;
int tp2;
cin>>tp1>>tp2;
lan[i].d=tp1;
lan[i].tot=tp2;
if(lan[i].d=='E'){lan[i].s=-1;}
else{lan[i].s=1;}
for(int j=0;j<(lan[i].tot);j+2){
int tmp1,tmp2;
cin>>tmp1>>tmp2;
lan[i].p[j/2]=tmp2*(lan[i].s);
lan[i].l[j/2]=(tmp1);
cout<<lan[i].l[1];
}

}
vector<vector<float > > m(n);
vector<float> p;
float p1,p2,p3,p4;
for(int k=0;k<n;k++){
for(int i=0;i<(lan[k].tot);i++){
if(i==0){p1=0;p2=p1+lan[0].p[0]/u-w/v;}
else{p1=p2+lan[0].l[i-1]/u;p2=p1+(lan[0].p[i]-lan[0].p[i-1])/u;}
m[k].push_back(p1);
m[k].push_back(p2);
}
}
vector<float> A;
A=inter(m[0],m[0]);
for(w=1;w<n;w++){
A=inter(m[w],A);
}
float maxm=0;
for(int i=0;i<A.size();i+2){
if(maxm<=(A[i+1]-A[i])){maxm=(A[i+1]-A[i]);}
}
cout<<maxm;
return 0;
}




