#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Time{
public:
    bool isItStarting;
    double value;
};

bool cmp(Time a,Time b){
    if(a.value==b.value){
        if(a.isItStarting==true){
            return true;
        }
        else{return false;}
    }
    else{return a.value<b.value;}
}

int main(){
    double n,w,u,v,t1,t2,N;
    cin>>n>>w>>u>>v>>t1>>t2;
    vector<Time> v1;
    N=n;
    double t3 = w/v;
    while(n){
        char c;
        int nship;
        cin>>c>>nship;
        if(c=='E'){
            for(int j=0;j<nship;j++){
                double p,l;
                cin>>l>>p;
                Time s,e;
                s.value = ((-p)/u) - (t3*(N-n+1));
                e.value = (-p+l)/u - (t3*(N-n));
                s.isItStarting = true;
                e.isItStarting = false;
                if(s.value>t2 || e.value<t1){continue;}
                if(s.value<t1){s.value=t1;}
                if(e.value>t2){e.value=t2;}
                v1.push_back(s);
                v1.push_back(e);
            }
        }
        else{
            for(int j=0;j<nship;j++){
                double p,l;
                cin>>l>>p;
                Time s,e;
                s.value = (p/u) - (t3*(N-n+1));
                e.value = (p+l)/u - (t3*(N-n));
                s.isItStarting = true;
                e.isItStarting = false;
                if(s.value>t2 || e.value<t1){continue;}
                if(s.value<t1){s.value=t1;}
                if(e.value>t2){e.value=t2;}
                v1.push_back(s);
                v1.push_back(e);
            }
        }
        n--;
    }
    sort(v1.begin(),v1.end(),cmp);
    double d = (*v1.begin()).value -t1;
    int count1=0;
    int p = v1.size();
    for(int i=0;i<p;i++){
        if(v1[i].isItStarting==true){count1++;}
        else{count1--;}
        if(count1==0){
            double temp;
            if(i==p-1){temp = t2 - v1[i].value;}
            else{temp = v1[i+1].value - v1[i].value;}
            if(temp>d){d=temp;}
        }
    }
    printf("%.8f",d);
    return 0;
}
