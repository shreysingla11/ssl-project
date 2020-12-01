#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

int open(map<int , set<string> > &s, map<string,int> &b, string name){
    map<string,int>::iterator ite;
    set<string> tset;
    ite = b.find(name);
    if(ite==b.end()){
        b[name]=0;
        s[0].insert(name);
        return 0;
    }
    else{
        return 1;
    }
}

int close(map<int , set<string> > &s, map<string,int> &b, string name){
    map<string,int>::iterator ite;
    map<int, set<string> >::iterator ite2;
    ite = b.find(name);
    if(ite!=b.end()){
        if(b[name]>0){
            return 1;
        }
        s[b[name]].erase(name);
        if(s[b[name]].empty()){
            ite2 = s.find(b[name]);
            s.erase(ite2);
        }
        b.erase(ite);
        return 0;
    }
    else{
        return 1;
    }
}

int deposit(map<int , set<string> > &s, map<string,int> &b, string name, int dep){
    map<string,int>::iterator ite;
    map<int, set<string> >::iterator ite2;
    ite = b.find(name);
    if(ite!=b.end()){
        s[b[name]].erase(name);
        if(s[b[name]].empty()){
            ite2 = s.find(b[name]);
            s.erase(ite2);
        }
        b[name]=b[name]+dep;
        s[b[name]].insert(name);
        return 0;
    }
    else{
        return 1;
    }
}

void print(map<int , set<string> > &s, map<string,int> &b, int start, int end) {
     std::map<int , set<string> >::iterator itlow,itup,it;
     set<string>::iterator iter;
     itlow = s.lower_bound (start);
     itup = s.upper_bound (end);
     for(it=itlow;it!=itup;it++){
        cout<<it->first<<" ";
        for(iter=(it->second).begin(); iter!=(it->second).end();++iter){
            cout<<(*iter)<<" ";
        }
        cout<<endl;
    }
    return;
}

int withdraw(map<int , set<string> > &s, map<string,int> &b, string name, int wd){
    map<string,int>::iterator ite;
    map<int, set<string> >::iterator ite2;
    ite = b.find(name);
    if(ite!=b.end()){
        if(b[name]<wd){
            return 1;
        }
        s[b[name]].erase(name);
        if(s[b[name]].empty()){
            ite2 = s.find(b[name]);
            s.erase(ite2);
        }
        b[name]=b[name]-wd;
        s[b[name]].insert(name);
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int ill_oprns=0;
    map<string,int> balance;
    map<int, set<string> > sets;
    char c;
    string name;
    int money,ran1,ran2;
    while(true){
       cin>>c;
       if(c=='E'){
            break;
       }
       else if(c=='D'){
          while(cin >> name >> money){
            break;
          }
          ill_oprns=ill_oprns+deposit(sets,balance,name,money);
       }
       else if(c=='W'){
          while(cin >> name >> money){
            break;
          }
          ill_oprns=ill_oprns+withdraw(sets,balance,name,money);
       }
       else if(c=='P'){
          while(cin >> ran1 >> ran2){
            break;
          }
          print(sets,balance,ran1,ran2);
          cout<<ill_oprns<<endl;
       }
       else if(c=='O'){
          while(cin >> name){
            break;
          }
          ill_oprns=ill_oprns+open(sets,balance,name);
       }
       else if(c=='C'){
          while(cin >> name){
            break;
          }
          ill_oprns=ill_oprns+close(sets,balance,name);
       }
    }
return 0;
}
