#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Time
{
    double t;
    bool start;
} ;

bool compare (Time x, Time y) {
if (x.t == y.t) {
    if (x.start == 1 ) return x.t<y.t;
    else return y.t<x.t;
}
return x.t<y.t; }

int main() {

double noLane, width, vShip, vFerry, t1, t2, interval,d;
cin>>noLane>>width>>vShip>>vFerry>>t1>>t2;
vector<Time> timeIntervals;
double N = noLane;
int c=0;

double tLane = width/vFerry;

while(noLane) {

char dir;
double noShips, length, pos;
cin>>dir>>noShips;

if (dir=='E') {
    for(int i = 1; i<=noShips; i++) {
        cin>>length>>pos;
        pos = -pos;
        Time tempS, tempE;
        tempS.start = 1;
        tempE.start = 0;
        tempS.t = (pos/vShip) - tLane - tLane*(N - noLane);
        tempE.t = (pos+length)/vShip - tLane*(N - noLane);
        if (tempS.t > t2 || tempE.t < t1) {continue;}
        if(tempS.t < t1) {
            tempS.t = t1;
        }
        if(tempE.t > t2) {
            tempE.t = t2;
        }
        timeIntervals.push_back(tempS);
        timeIntervals.push_back(tempE);
    }
}
else {
    for(int i = 1; i<=noShips; i++) {
        cin>>length>>pos;
        Time tempS, tempE;
        tempS.start = 1;
        tempE.start = 0;
        tempS.t = (pos/vShip) - tLane - tLane*(N - noLane);
        tempE.t = (pos+length)/vShip - tLane*(N - noLane);
        if (tempS.t > t2 || tempE.t < t1) {continue;}
        if(tempS.t < t1) {
            tempS.t = t1;
        }
        if(tempE.t > t2) {
            tempE.t = t2;
        }
        timeIntervals.push_back(tempS);
        timeIntervals.push_back(tempE);
    }
}
noLane--;
}

sort (timeIntervals.begin(),timeIntervals.end(),compare);

d = (*timeIntervals.begin()).t - t1;
for (int i=0; i<timeIntervals.size();i++) {
    //cout<<timeIntervals[i].t<<" "<<timeIntervals[i].start<<endl;
    if (timeIntervals[i].start == 1) c++;
    else c--;
    if (c==0) {
        if(i == timeIntervals.size() - 1) interval = t2 - timeIntervals[i].t;
        else interval = timeIntervals[i+1].t - timeIntervals[i].t;
        if (interval > d) d = interval;
    }
}

printf("%.8f",d);
cout<<endl;


return 0;
}
