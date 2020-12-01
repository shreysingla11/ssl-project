#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdio>
using namespace std;
class ship
{
public:
    double in;
    double out;

    ship()
    {
        in=0.0;
        out=0.0;

    }
};
class lane
{
public:
    vector <ship> Lane;
    bool E;
    lane()
    {
        E=true;
    }
};

/*class data
{
public:
    int n;
    int w;
    int u;
    int v;
    int t1;
    int t2;
    vector <lane> lanes;
    data()
    {
        cin>>n>>w>>u>>v>>t1>>t2;
        lanes.resize(n);
        char c;int m;
        for(int i=0; i<n; i++)
        {
            cin>>c;
            if(c=='W')
            {
                lanes[i].E=false;
            }
            cin>>m;
            ((lanes[i]).Lane).resize(m);
            int S;
            int P;
            for(int j=0;j<m;j++){
                cin>>S>>P;
               ((lanes[i]).Lane)[j].S=S;
               ((lanes[i]).Lane)[j].P=P;
            }
        }
    }
};*/
class interval{
public:
double left;
double right;

};
bool comp(interval i,interval j){
if(i.left < j.left){
return true;
}
else{
return false;
}
};
int main()
{
//data d;
    int n;
    int w;
    int u;
    int v;
    double t1;
    double t2;
    double d=0.000000;
    vector <lane> lanes;
    vector <interval> intervals;
    cin>>n>>w>>v>>u>>t1>>t2;
    double T =(w*1.000000)/(u*1.000000);
    lanes.resize(n);
    char c;
    int m;
    for(int i=0; i<n; i++)
    {
        cin>>c;
        if(c=='W')
        {
            lanes[i].E=false;
        }
        cin>>m;
        ((lanes[i]).Lane).resize(m);
        int S;
        int P;

        for(int j=0; j<m; j++)
        {
            cin>>S>>P;
            if(lanes[i].E==true)
            {
                P=-P;
            }
            //cout<<P<<" "<<S<<endl;
            ((lanes[i]).Lane)[j].in=((P*1.000000)/(v*1.000000))-((i+1)*1.000000*T);
            ((lanes[i]).Lane)[j].out=(((P+S)*1.000000)/(v*1.000000))-((i)*1.000000*T);
            //cout<<"["<<((lanes[i]).Lane)[j].in<<" , "<<((lanes[i]).Lane)[j].out<<"]"<<endl;
            interval * interp = new interval;
            (interp->left) = max(t1,((lanes[i]).Lane)[j].in);
            (interp->right) = min(t2,((lanes[i]).Lane)[j].out);
            if((interp->left) < t2 && (interp->right) > t1){
            intervals.push_back(*interp);}
            delete interp;
        }
    }


sort(intervals.begin(),intervals.end(),comp);
/*
for(int i=0;i<intervals.size();i++){
cout<<"["<<intervals[i].left<<" , "<<intervals[i].right<<"]"<<endl;
}*/
if(intervals.size()==0){
d=t2-t1;
}
else{
d=intervals[0].left-t1;
double b=intervals[0].right;

for(int i=1;i<intervals.size();i++){
if(intervals[i].left<b){
b=max(b,intervals[i].right);
}
else{
d= max(d,(intervals[i].left - b));
b= intervals[i].right;
}
//cout<<d<<endl;
}
d=max(d,(t2-intervals[intervals.size()-1].right));
}

printf("%0.8f",d);
cout<<endl;

    return 0;
}

