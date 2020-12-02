#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int lanes;
float width;
float uship;
float uferry;
int t1;
int t2;

int ships;
char dirn;

float start;
float length;

float hit1;
float hit2;

bool t1chk=false;
bool t2chk=false;

cin>>lanes>>width>>uship>>uferry>>t1>>t2;
vector<float> interstart;
vector<float> interend;
vector<float> newinter;
vector<float> newinterstart;
vector<float> newinterend;
interstart.push_back(t1);
interend.push_back(t2);
for(int i=0;i<lanes;i++){
cin>>dirn;
cin>>ships;
t1chk=false;
t2chk=false;
for(int j=0;j<ships;j++){
cin>>length;
cin>>start;
if(dirn=='E'&&(start-length)>0){continue;}
else{}
if(dirn=='W'&&(start+length)<0){continue;}
else{}
if(dirn=='W'&&(start+length)>0){
newinter.push_back(t1);
newinter.push_back(t2);
hit1=(start/uship)-i*(width/uferry);
hit2=(start+length)/uship-i*(width/uferry);
if(hit1<t1&&hit2<t1){continue;}
if(hit1>t2&&hit2>t2){continue;}
if(hit1<t1&&hit2>t1){t1chk=true;newinter.push_back(hit2);continue;}
if(hit1<t2&&hit2>t2){t2chk=true;newinter.push_back(hit1);continue;}
newinter.push_back(hit1);
newinter.push_back(hit2);
}
else{}
if(dirn=='E'&&(start-length)<0){
newinter.push_back(t1);
newinter.push_back(t2);
hit1=(-1*start/uship)-i*(width/uferry);
hit2=(-1*(start-length)/uship)-i*(width/uferry);
if(hit1<t1&&hit2<t1){continue;}
if(hit1>t2&&hit2>t2){continue;}
if(hit1<t1&&hit2>t1){t1chk=true;newinter.push_back(hit2);continue;}
if(hit1<t2&&hit2>t2){t2chk=true;newinter.push_back(hit1);continue;}
newinter.push_back(hit1);
newinter.push_back(hit2);
}
else{}
}
sort(newinter.begin(),newinter.end());
if(!t1chk&&!t2chk){
for(int l=0;l<newinter.size()/2;l++){
newinterstart.push_back(newinter[2*l]);
newinterend.push_back(newinter[2*l+1]);
}
}
if(!t1chk&&t2chk){
for(int m=0;m<newinter.size()/2-1;m++){
newinterstart.push_back(newinter[2*m]);
newinterend.push_back(newinter[2*m+1]);
}
newinterend.push_back(t2);
newinterstart.push_back(newinter[newinter.size()-2]);
}
if(t1chk&&!t2chk){
newinterstart.push_back(t1);
newinterend.push_back(newinter[1]);
for(int n=1;n<newinter.size()/2;n++){
newinterstart.push_back(newinter[2*n]);
newinterend.push_back(newinter[2*n+1]);
}
}
if(t1chk&&t2chk){
newinterstart.push_back(t1);
newinterend.push_back(newinter[1]);
for(int p=1;p<newinter.size()/2-1;p++){
newinterstart.push_back(newinter[2*p]);
newinterend.push_back(newinter[2*p+1]);
}
newinterend.push_back(t2);
newinterstart.push_back(newinter.size()-2);
}

newinter.clear();
newinterstart.clear();
newinterend.clear();
}

}
