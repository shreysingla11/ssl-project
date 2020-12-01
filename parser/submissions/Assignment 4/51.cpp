#include<iostream>
#include<list>
#include<vector>

using namespace std;
class counter{
private:
    list<list<int> > lis_lis;
    list<int>::iterator pl2;
    list<int> lis;
    vector<int> obj;
    vector<list<int>::iterator> obj_poin;
    vector<list<list<int> >::iterator > row_poin;
    //vector<list<list<int>::iterator>::iterator> count_sort;
    int n,i,j;
public:
    counter(int i){
    n=i;
    obj.resize(n);
    obj_poin.resize(n);
    row_poin.resize(n);
    for(int i=0;i<n;i++){
    lis.push_back(i);
    obj[i]=0;
    obj_poin[i]=--lis.end();
    }
    lis_lis.push_back(lis);
    for(int i=0;i<n;i++){
    row_poin[i]=lis_lis.begin();
    }
    }
    void increment(int i){
        //whether the maximum count increses or not
            list<list<int> >::iterator it=row_poin[i];++it;
    if(obj[i]==findMax()){
        lis.clear();
        //creates a new list with improved count and erases the previous pointers
        lis.push_back(i);
        lis_lis.push_back(lis);

                lis.clear();
        lis=*row_poin[i];
        pl2=obj_poin[i];
        lis.erase(pl2);
        if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
        list<list<int> >::iterator it=lis_lis.end();--it;
        row_poin[i]=(it);
        obj_poin[i]=(*row_poin[i]).begin();

    }
    //row_poin[i];
    //lis.clear();
    //lis=*(row_poin[i]);
    else if(obj[i]+1!=*((*it).begin())){
    lis.clear();
    lis=*row_poin[i];
    pl2=obj_poin[i];
    lis.erase(pl2);
    if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
    lis.clear();
    lis.push_back(i);
    lis_lis.insert(it,lis);
    row_poin[i]=row_poin[i]++;
    obj_poin[i]=lis.begin();
    }
    else{
    lis.clear();
    lis=*row_poin[i];
    pl2=obj_poin[i];
    lis.erase(pl2);
    if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
    row_poin[i]=row_poin[i]++;
    lis=*(row_poin[i]);
    lis.push_back(i);
    obj_poin[i]=(--lis.end());
    }
    obj[i]++;
    }

        void decrement(int i){
        if(obj[i]==0){return;}
            list<list<int> >::iterator it=row_poin[i];--it;
    if(obj[i]==1&&obj[(*((*(lis_lis.begin())).begin()))]!=0){
        lis.clear();
        lis.push_back(i);
        lis_lis.push_front(lis);
        lis.clear();
        lis=*row_poin[i];
        pl2=obj_poin[i];
        lis.erase(pl2);
        if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
        list<list<int> >::iterator it2=lis_lis.begin();
        row_poin[i]=(it2);
        obj_poin[i]=(*row_poin[i]).begin();

    }
    else if(obj[i]-1!=*((*it).begin())){
    lis.clear();
    lis=*row_poin[i];
    pl2=obj_poin[i];
    lis.erase(pl2);
    if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
    lis.clear();
    lis.push_back(i);
    lis_lis.insert(it,lis);
    row_poin[i]=row_poin[i]--;
    obj_poin[i]=lis.begin();
    }
    else{
    lis.clear();
    lis=*row_poin[i];
    pl2=obj_poin[i];
    lis.erase(pl2);
    if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
    row_poin[i]=row_poin[i]--;
    lis=*(row_poin[i]);
    lis.push_back(i);
    obj_poin[i]=(--lis.end());
    }
    obj[i]--;
    }


    void reset(int i){
  if(obj[(*((*(lis_lis.begin())).begin()))]==0){
    lis=*lis_lis.begin();
    lis.push_back(*obj_poin[i]);
    }
    else{
        lis.push_back(*obj_poin[i]);
        lis_lis.push_front(lis);
    }
    lis=*row_poin[i];
    pl2=obj_poin[i];
    lis.erase(pl2);
    if(lis.begin()==lis.end()){lis_lis.erase(row_poin[i]);}
    row_poin[i]=(lis_lis.begin());
    obj[i]=0;
    }

    int count(int i){return obj[i];}

    int findMax(){
        lis.clear();
        list<list<int> >::iterator it=lis_lis.end();--it;
        lis=*(it);
        list<int>::iterator it2=lis.begin();
    return *(it2);
    }

    int numMax(){
        lis.clear();
    lis=*(--lis_lis.end());
    return lis.size();
    }

    void printMax(){
    lis=*(--lis_lis.end());
    for(pl2=lis.begin();pl2!=lis.end();pl2++){
    cout<<*pl2<<endl;
    }

    }
};
