#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
int n,w,u,v,t1,t2,ships,tships;
double maxinterval,interval;
char direction;
map<int ,vector<int> > pos1,pos2,len;
vector<int> pos_start,pos_end;
vector<map<int,bool> > pos;
map<int ,bool> x;
cin>>n>>w>>u>>v>>t1>>t2;
for(int i=0;i<n;i++){
    cin>>direction>>ships;
    tships=ships+tships;
    pos1[i].resize(ships);
    pos2[i].resize(ships);
    pos_start.resize(tships);
    pos_end.resize(tships);
    len[i].resize(ships);
    pos.resize(2*tships);
    if(direction=='W'){
        for(int j=0;j<ships;j++){
            cin>>len[i][j]>>pos2[i][j];
            pos1[i][j]=pos2[i][j]-len[i][j];
            x[pos1[i][j]]=false;
            pos_start[tships-ships+j]=pos1[i][j];
            pos_end[tships-ships+j]=pos2[i][j];
            pos.push_back(x);
            x[pos2[i][j]]=true;
            pos.push_back(x);
        }
    }
    else{
        for(int j=0;j<ships;j++){
            cin>>len[i][j]>>pos1[i][j];
            pos2[i][j]=pos1[i][j]-len[i][j];
            pos1[i][j]=-pos1[i][j];
            pos2[i][j]=-pos2[i][j];
            x[pos1[i][j]]=false;
            pos.push_back(x);
            x[pos2[i][j]]=true;
            pos.push_back(x);
            pos_start[tships-ships+j]=pos1[i][j];
            pos_end[tships-ships+j]=pos2[i][j];

        }
    }
}
//sort(pos_start.begin(),pos_start.end());
//sort(pos_end,begin(),pos_end.end());
//maxinterval=(*pos.begin()).begin()->first;
sort(pos_start.begin(),pos_start.begin()+tships);
sort(pos_end.begin(),pos_end.begin()+tships);
maxinterval=*pos_start.begin();
//maxinterval=(*pos.begin()).begin()->first;
vector<int >::iterator it=pos_start.begin(),it2=pos_end.begin();
//for(;it!=pos_start.end()||it2!=pos_end.end();it2++){
//    it++;
//    cout<<*it;
//    for(;*it2<*it||it2!=pos_end.end();it2++){
//    }
//    if(*it2>*it&&*(--it2)<=*(it)){
//        interval=*it-*it2;
//        if(maxinterval<interval){maxinterval=interval;}
//    }}
maxinterval=maxinterval/u;
it2=pos_end.end();
it2--;
if(t2-*it2/u>maxinterval){
    maxinterval=t2-*it2/u;
}
maxinterval=maxinterval-w/v;
if(maxinterval<0){
	maxinterval=0;
}
printf("%8f",maxinterval);
return 0;
}
