#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
int equality(int &x1, int &y1, int &x2, int &y2, int &xt, int &yt);
void ihaterecursion(vector<vector<int> > &vred, vector<vector<int> > &vblue, int &eachone);
int main(){
int num;
int each;
int counter1;
cin>>num;
each=(num/2);
vector<vector<int> > pointsred(each, vector<int>(3));
vector<vector<int> > pointsblue(each, vector<int>(3));
for(counter1=0;counter1<each;counter1++){
scanf("%d %d",&pointsred[counter1][0], &pointsred[counter1][1]);
pointsred[counter1][2]=counter1;
//cout<<pointsred[i][0]<<" "<<pointsred[i][1]<<" "<<pointsred[i][2]<<endl;
}
for(int j=0;j<each;j++){
scanf("%d %d",&pointsblue[j][0], &pointsblue[j][1]);
pointsblue[j][2]=j;
//cout<<pointsblue[j][2]<<endl;
}
ihaterecursion(pointsred,pointsblue,each);
return 0;
}

int equality(int &x1, int &y1, int &x2, int &y2, int &xt, int &yt){
int p1=(yt-y1)*(x2-x1)-(xt-x1)*(y2-y1);
return p1;
}
void ihaterecursion(vector<vector<int> > &vred, vector<vector<int> > &vblue, int &eachone){
//cout<<"23"<<endl;
if(eachone==0){return;}
if(eachone==1){
cout<<vred[0][2]<<" "<<vblue[0][2]<<endl;
return;
}
else{}
//cout<<vred[0][2]<<endl;
int i=0;
int blueleft=0;
int blueright=0;
int redleft=0;
int redright=0;
vector<vector<int> > vrednewl(eachone, vector<int>(3));
vector<vector <int> > vbluenewl(eachone, vector<int>(3));
vector<vector<int> > vrednewr(eachone, vector<int>(3));
vector<vector <int> > vbluenewr(eachone, vector<int>(3));
int please;
int j=0;
int ib=0;
//cout<<"1"<<endl;
for(ib=0;ib<eachone;ib++){
for(j=0;j<eachone;j++){
if(j==ib){continue;}
int s1=equality(vred[0][0],vred[0][1],vblue[ib][0],vblue[ib][1],vblue[j][0],vblue[j][1]);
//if(s1==0){cout<<"7"<<endl;}
if(s1<0){
vbluenewl[blueleft][0]=vblue[j][0];
vbluenewl[blueleft][1]=vblue[j][1];
vbluenewl[blueleft][2]=vblue[j][2];
blueleft++;
//cout<<"2"<<endl;

}
else{
vbluenewr[blueright][0]=vblue[j][0];
vbluenewr[blueright][1]=vblue[j][1];
vbluenewr[blueright][2]=vblue[j][2];
blueright++;
//cout<<"3"<<endl;
}
}
//cout<<"6"<<endl;
for(int k=1;k<eachone;k++){
//if(j==i){continue;}
int s2=equality(vred[0][0],vred[0][1],vblue[ib][0],vblue[ib][1],vred[k][0],vred[k][1]);
if(s2<0){
vrednewl[redleft][0]=vred[k][0];
vrednewl[redleft][1]=vred[k][1];
vrednewl[redleft][2]=vred[k][2];
redleft++;
//cout<<"4"<<endl;
}
else{
vrednewr[redright][0]=vred[k][0];
vrednewr[redright][1]=vred[k][1];
vrednewr[redright][2]=vred[k][2];
redright++;
//cout<<"5"<<endl;
}
}
//cout<<vred[0][2]<<" "<<vblue[j][2]<<endl;
if(redleft==blueleft){please=ib;break;}
}
cout<<vred[0][2]<<" "<<vblue[please][2]<<endl;
ihaterecursion(vrednewl,vbluenewl,redleft);
ihaterecursion(vrednewr,vbluenewr,redright);
return;
}



