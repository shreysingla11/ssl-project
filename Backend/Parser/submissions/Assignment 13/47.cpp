#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
    int n, v, node, length, goodness, w, lt, gt, inf;
    cin >> n;
    vector<map<int,int> > data;
    map<int,int> ord;
    map<int,int> temp;
    vector<vector<int> > ap;
    vector<int> ed;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> v;
            ed.push_back(v);
            if(i==0 && j!=0){
                ord[abs(v)]=j;

            }
        }
        ap.push_back(ed);
        ed.clear();
    }

    map<int,int> mymap;
    map<int,int>::iterator it;
    map<int,int>::iterator itpath;
    map<int,int>::iterator itnb;
    mymap[0]=0;
    if(ap[0][0] < 0){mymap[abs(ap[0][0])] = 1;}
    data.push_back(mymap);
    for(int i = 1 ; i < n ; i++){
        mymap.clear();
        if(ap[0][i] < 0){mymap[abs(ap[0][i])] = 1;}
        else{mymap[ap[0][i]] = -1;}
        data.push_back(mymap);
    }
    mymap.clear();

    for(it=ord.begin() ; it!=ord.end() ; ++it){
        node = it->second;
        for(int i1 = 0 ; i1 < n ; i1++){
            w=abs(ap[node][i1]);
            gt=-1;
            if(ap[node][i1] < 0){gt=1;}
            temp = data[node];
            for (map<int,int>::iterator itmp=temp.begin(); itmp!=temp.end(); ++itmp){
                length = itmp->first; goodness = itmp->second;
                lt = length + w ; gt = goodness + gt;
                itnb = temp.find(lt);
                if (itnb != temp.end()){
                    if(itnb->second < gt){
                        data[i1].insert ( pair<int,int>(lt,gt) );
                    }
                }
                else{
                    data[i1].insert ( pair<int,int>(lt,gt) );
                }
            }
            temp=map<int,int>();
        }
    }
    for(int j = 0 ; j < n ; j++){
    for(int i = 1 ; i < n ; i++){
        node = j;
        for(int i1 = 0 ; i1 < n ; i1++){
            w=abs(ap[node][i1]);
            gt=-1;
            if(ap[node][i1] < 0){gt=1;}
            temp = data[node];
            for (map<int,int>::iterator itmp=temp.begin(); itmp!=temp.end(); ++itmp){
                length = itmp->first; goodness = itmp->second;
                lt = length + w ; gt = goodness + gt;
                itnb = temp.find(lt);
                if (itnb != temp.end()){
                    if(itnb->second < gt){
                        data[i1].insert ( pair<int,int>(lt,gt) );
                    }
                }
                else{
                    data[i1].insert ( pair<int,int>(lt,gt) );
                }
            }
            temp=map<int,int>();
        }
    }}
    for(int i = 0 ; i < n ; i++){
        inf = 0;
        for (itpath=data[i].begin(); itpath!=data[i].end(); ++itpath){
            if(itpath->second >= 0){cout<<itpath->first<<endl;inf=1;break;}
        }
        if(inf==0){cout<<"infinity"<<endl;}
    }

  return 0;
}
