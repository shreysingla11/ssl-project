#include <iostream>
#include <map>
#include <set>

using namespace std;

int ill;

struct bank{

  map<string,int> X;
  map<int,set<string> > Y;

  void open(string &str){
    if(X.find(str)!=X.end()){
      ill++; return;
    }
    X[str]=0;
    Y[0].insert(str);
  }

  void Deposit(string &str,int amt){
    if(X.find(str)==X.end()){
      ill++; return;
    }
    int val=X[str];
    Y[val].erase(str);
    if(Y[val].size()==0){
      Y.erase(val);
    }
    val+=amt;
    Y[val].insert(str);
    X[str]=val;
    return;
  }

  void withdraw(string &str,int amt){
    if(X.find(str)==X.end()){
      ill++; return;
    }
    int val=X[str];
    if(val<amt){
      ill++; return;
    }
    Y[val].erase(str);
    if(Y[val].size()==0){
      Y.erase(val);
    }
    val-=amt;
    Y[val].insert(str);
    X[str]=val;
    return;
  }

  void close(string &str){
    if(X.find(str)==X.end()){
      ill++; return;
    }
    int val=X[str];
    if(val!=0){
      ill++; return;
    }
    X.erase(str);
    Y[0].erase(str);
    if(Y[0].size()==0){
      Y.erase(val);
    }
    return;
  }

  void print(int lb,int ub){

    map<int,set<string> >::iterator it;
    it=Y.lower_bound(lb);
    map<int,set<string> >::iterator en;
    en=Y.end();
    while(it!=en){

      if(it->first > ub){
        break;
      }

      set<string>::iterator setit,seten;
      setit=(it->second).begin();
      seten=(it->second).end();

      cout<<it->first ;

      while(setit!=seten){
        cout<<" "<<*setit;
        setit++;
      }
      cout<<endl;
      it++;
    }

  }

};

int main(){


  ill=0;
  bank B;
  char ch;
  int amt;
  string str;
  int lb,ub;
  while(true){
    cin>>ch;
    if(ch=='E'){
      break;
    }
    if(ch=='O'){
      cin>>str;
      B.open(str);
    }
    if(ch=='C'){
      cin>>str;
      B.close(str);
    }
    if(ch=='D'){
      cin>>str;
      cin>>amt;
      B.Deposit(str,amt);
    }
    if(ch=='W'){
      cin>>str;
      cin>>amt;
      B.withdraw(str,amt);
    }
    if(ch=='P'){
      cin>>lb>>ub;
      B.print(lb,ub);
    }
  }

  cout<<ill<<endl;
  return 0;
}


