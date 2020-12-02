#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
using namespace std;

struct lane{
    char dir;
    int nship;
    vector<double> len;
    vector<double> pos;
    vector<double> time;

    void maketime(double t1, double t2, int u, int t, int v, int w){
      if(dir=='W'){
        double f1,f2;
        for(int i=0;i<nship;i++){
            f1=pos[i]/u-t;
            f2=((pos[i])+len[i])/u;
            //cout<<f1<<"  "<<f2<<endl;
            if(f2<t1){continue;}
            if(f1<t1-t){
                if(f2>t1){
                    time.push_back(f2);
                    continue;
                }
            }
            if(f1>t2){break;}
            if(f2>t2){f2=t2;time.push_back(f1);time.push_back(t2);break;}
            time.push_back(f1);
            time.push_back(f2);
        }
      }
      else if(dir=='E'){
        double f1,f2;
        for(int i=nship-1;i>=0;i--){
            f1=-pos[i]/u;
            f1=f1-t;
            f2=-((pos[i])-len[i])/u;
            //f2=f2+t;
            if(f2<t1){continue;}
            if(f1<t1-t){
                if(f2>t1){
                    time.push_back(f2);
                    continue;
                }
            }
            if(f1>t2){break;}
            if(f2>t2){f2=t2;time.push_back(f1);time.push_back(t2);break;}
            time.push_back(f1);
            time.push_back(f2);
        }
      }
           /*for(int j=0;j<time.size();j++){
            cout<<time[j]<<endl;
        }*/
    return;
    }
};

int main(){
    multimap<double,int> m;
    multimap<double,int>::iterator it;
    int n,w,u,v;
    double t1,t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    lane l[n];
    double t=w/v;
    for(int i=0;i<n;i++){
        cin>>l[i].dir>>l[i].nship;
        double tem1,tem2;
        for(int j=0;j<l[i].nship;j++){
            cin>>tem1>>tem2;
            if(l[i].dir=='E'){
                tem2=tem2+1.0*i*t*u;
            }
            else if(l[i].dir=='W'){
                tem2=tem2-1.0*i*t*u;
            }
            l[i].len.push_back(tem1);
            l[i].pos.push_back(tem2);
        }
    }
    for(int i=0;i<n;i++){
        l[i].maketime(t1,t2,u,t,v,w);
    }

    for(int i=0;i<n;i++){
        double d1,d2;
        for(int j=0;j<l[i].time.size();j=j+2){
            d1=l[i].time[j];
            d2=l[i].time[j+1];
            it=m.end();
            m.insert(it,pair<double,int>(d1,1));
            it=m.end();
            m.insert(it,pair<double,int>(d2,-1));
        }
    }

    multimap<double,int>::iterator ite2=m.begin();
    double d=(ite2->first)-t1;
    double temp;
    int count=0;
    multimap<double,int>::iterator ti;
    for(multimap<double,int>::iterator ite=m.begin();ite!=m.end();ite++){

        ti=ite;
        ti++;
        if(ti==m.end()){
            temp=t2-(ite->first);
        }
        else{
            count=count+(ite->second);
            if(count==0){
                temp=(ti->first)-(ite->first);
            }
        }
        if(temp>d){d=temp;}
    }
    //d=d-t;
    printf("%.8lf \n",d);

return 0;
}

