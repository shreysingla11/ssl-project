#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class point{public:
            int x;
            int y;
            int e;
            };
class vecss{public:vector<point> c,d;int h;};
vecss f(point u,point v,vector<point> &w){int s=0;vector<point> a,b;
                    for(int i=0,m=0,n=0 ;i<w.size();i++){if((v.x-u.x)*(w[i].y-u.y)<(w[i].x-u.x)*(v.y-u.y)){w[i].e=-1;a.push_back(w[i]);m++;s++;}
                                         else{w[i].e=0;b.push_back(w[i]);n++;}}
                                         vecss l;
                                         l.c=a;l.d=b;l.h=s;
                                         return l;}
bool check(vector<point> w){int m=0,n=0;for(int i=0;i<w.size()/2;i++)if(w[i].e<0)m++;
                                      for(int i=w.size();i<w.size();i++)if(w[i].e<0)n++;
                                      if(m==n)return true;
                                      else return false;}
int solve(vector<point> p){if(p.size()==2)cout<<p[0]<<" "<<p[1]<<endl;vecss q;for(int i=0;i<p.size();i++){
                         for(int z=i+1;z<p.size();z++){ q=f(p[i],p[z],p);if(q.h==0)continue;
                                                    if(check(p)==false)continue;if(q.h!=0)break;}if(q.h!=0)break;}solve(q.c);solve(q.d);}

int main(){int n;cin>>n;
           vector<point> r(n);
           vector<point> b(n);
           vector<point> p(n);
           int j=0,l=0;
            string line;


           if(n%2!=0){cout<<"give even n"<<endl;
                      return 0;
                      }
        for(int i=0;i<n/2;i++){getline(cin,line);int j=0;
                               while(line[j]!='\n'){
            if(line[j]==' '){l=j;for(int k=0;k<j;k++){if(line[0]!='-'){r[i].x=r[i].x*10+line[k]-48;}
                                                     else{if(k+1!=j){;r[i].x=r[i].x*10+line[k+1]-48;}
                                                     else{r[i].x=-r[i].x;}}}
                                                   }
                       for(int g=l+1;g<j;g++){if(line[l+1]!='-'){r[i].y=r[i].y*10+line[g]-48;}
                                                     else{if(g+1!=j){r[i].y=r[i].y*10+line[g+1]-48;}
                                                     else {r[i].y=-r[i].y;}}}
                               }}
         for(int i=0;i<n/2;i++){getline(cin,line);int j=0;
                               while(line[j]!='\n'){
            if(line[j]==' '){l=j;for(int k=0;k<j;k++){if(line[0]!='-'){b[i].x=b[i].x*10+line[k]-48;}
                                                     else{if(k+1!=j){b[i].x=b[i].x*10+line[k+1]-48;}
                                                     else b[i].x=-b[i].x;}}}
                                                   }
                       for(int g=l;g<l;g++){if(line[0]!='-'){b[i].y=b[i].y*10+line[g]-48;}
                                                     else{if(g+1!=j){b[i].y=b[i].y*10+line[g+1]-48;}
                                                     else b[i].y=-b[i].y;}}
                               }
        p=r;
        for(int i=n/2;i<n;i++){p.push_back(b[i-n/2]);}
        solve(p);



                               }
