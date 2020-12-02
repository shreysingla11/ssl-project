#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
           int a[6],n,m,u;char c;vector<int> t,b,y,z,d;vector<vector<int> > L,T;
           map<float,float> e,f;
    for(int i=0;i<6;i++)
                {
             cin>>a[i];
                }
                n=a[0];
    for(int i=0;i<n;i++)
                {
            cin>>c;b.push_back(c);
             cin>>m;
    if(c=='E'){y.push_back(1);
               for(int j=0;j<2*m;j++)
                     {
                     cin>>u;
                     y.push_back(u);
                     }
            L.push_back(y);
              }
    if(c=='W'){y.push_back(-1);
               for(int j=0;j<2*m;j++)
                      {
                      cin>>u;
                       y.push_back(u);
                       }
             L.push_back(y);
               }
            y.clear();
                 }
     for(int i=0;i<n;i++)
               {
               d=L[i];
               for(int j=0;j<d.size();j++)
                  {if(j==0){y.push_back(d[0]);}
                  else{if(j%2==1){y.push_back(-1.0*d[0]*d[j+1]/a[2]);
                                  y.push_back(-1.0*d[0]*(d[j+1]-d[0]*d[j])/a[2]);
                    e[-1.0*d[0]*d[j+1]/a[2]]=-1.0*d[0]*(d[j+1]-d[0]*d[j])/a[2];
                    e[-1.0*d[0]*(d[j+1]-d[0]*d[j])/a[2]]=-1.0*d[0]*d[j+1]/a[2];
                                  }
                       }
                    }
                    T.push_back(y);
                    y.clear();
               }
               float max_t=0;
        for (std::map<float,float>::iterator it=e.begin(); it!=f.end(); ++it)
                {
                if(it->second>it->first)
                 {if(it==e.begin()&&it->first>0)max_t=it->first-0;
                 map<float,float>::iterator iit=f.end();

                for(map<float,float>::iterator itt=it;itt!=f.end();++itt)
                {map<float,float>::iterator ds=itt;

                if(++ds!=f.end()&&ds->first>it->second){iit=ds;break;}
                else if(ds==f.end())break;}

                if(iit!=f.end())
                if((iit->first-it->second)>max_t){max_t=iit->first-it->second;}
                else if(1000000-it->second>max_t)max_t=1000000-it->second;
                }}
            cout.precision(8);
           cout<<max_t<<endl;
           }
