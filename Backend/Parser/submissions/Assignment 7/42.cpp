#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
int num=0;

void openAccount(string &s,map<string,int> &m1,map<int, set<string> > &m2){
    if(m1.count(s)==1){num++;return;}
    else{m1[s]=0;}
    if(m2.count(0)==0){
        set<string> temp;
        temp.insert(s);
        m2[0] = temp;
    }
    else{
        m2[0].insert(s);
    }
    return;
}

void closeAccount(string &s,map<string,int> &m1,map<int, set<string> > &m2){
    if(m1.count(s)==0){num++;}
    else{
        if(m1[s]!=0){num++;}
        else{
            int a=m1[s];
            set<string>::iterator it = m2[a].find(s);
            m2[a].erase(it);
            if(m2[a].empty()){m2.erase(a);}
            m1.erase(s);
        }
    }
    return;
}

void deposite(string &s,int a,map<string,int> &m1,map<int, set<string> > &m2){
    if(a<0){num++;return;}
    if(m1.count(s)==0){num++;return;}
    else{
        int b=m1[s];
        set<string>::iterator it = m2[b].find(s);
        m2[b].erase(it);
        if(m2[b].empty()){m2.erase(b);}
        if(m2.count(b+a)==0){
                set<string> temp;
                temp.insert(s);
                m2[b+a] = temp;
        }
        else{
            m2[b+a].insert(s);
        }
        m1[s] += a;
    }
    return;
}

void withdraw(string &s,int a,map<string,int> &m1,map<int, set<string> > &m2){
    if(a<0){num++;return;}
    if(m1.count(s)==0){num++;return;}
    else{
        if(m1[s]<a){num++;return;}
        else{
            int b=m1[s];
            set<string>::iterator it = m2[b].find(s);
            m2[b].erase(it);
            if(m2[b].empty()){m2.erase(b);}
            if(m2.count(b-a)==0){
                set<string> temp;
                temp.insert(s);
                m2[b-a] = temp;
            }
            else{
                m2[b-a].insert(s);
            }
            m1[s] -= a;
        }
    }
    return;
}

void print(int min1,int max1,map<string,int> &m1,map<int, set<string> > &m2){
    if(min1>max1){num++;return;}
    map<int, set<string> >::iterator itmin,itmax;
    itmin = m2.lower_bound(min1);
    itmax = m2.upper_bound(max1);
    if(itmin!=m2.end()){
        while(itmin!=(itmax)){
            set<string>::iterator it1,it2;
            it1 = (*itmin).second.begin();
            it2 = (*itmin).second.end();
            cout<<m1[(*it1)]<<" ";
            while(it1!=it2){
                cout<<(*it1)<<" ";
                it1++;
            }
            cout<<endl;
            itmin++;
        }
    }
    return;
}


int main(){
    char c;
    map<string,int> m1;
    map<int, set<string> > m2;
    while(true){
        cin>>c;
        switch(c){
            case 'O' :{
                    string s;
                    cin>>s;
                    openAccount(s,m1,m2);
                    break;
                }
            case 'C' :{
                    string s;
                    cin>>s;
                    closeAccount(s,m1,m2);
                    break;
                }
            case 'D' :{
                    int amount;
                    string s;
                    cin>>s;
                    cin>>amount;
                    deposite(s,amount,m1,m2);
                    break;
                }
            case 'W' :{
                    string s;
                    int amount;
                    cin>>s;
                    cin>>amount;
                    withdraw(s,amount,m1,m2);
                    break;
                }
            case 'P' :{
                    int min1,max1;
                    cin>>min1>>max1;
                    print(min1,max1,m1,m2);
                    break;
                }
            case 'E' :{
                    cout<<num<<endl;
                    return 0;
                }
            default:continue;
        }
    }
}
