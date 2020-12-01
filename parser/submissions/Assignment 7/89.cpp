#include <iostream>
#include <map>
#include <set>
using namespace std;

void open(map<string, int> &map1, map<int, set<string> > &map2, int &numillegal){
    string name;
    cin>>name;
    if(map1.count(name)!=0){numillegal++;return;}
    else {
        map1[name]=0;
        map2[0].insert(name);
        return;
    }
}

void close(map<string, int> &map1, map<int, set<string> > &map2, int &numillegal){
    string name;
    cin>>name;
    if(map1.count(name)==0){numillegal++;return;}
    else if (map1[name]!=0){numillegal++;return;}
    else    {
        map1.erase(name);
        map2[0].erase(name);
    }
    return;
}

void deposit(map<string, int> &map1, map<int, set<string> > &map2, int &numillegal){
    string name;
    int amount;
    cin>>name>>amount;
    if(map1.count(name)==0){numillegal++;return;}
    else    {
        int temp;
        temp=map1[name];
        map1[name]=amount+temp;
        map2[temp].erase(name);
        map2[amount+temp].insert(name);
    }
    return;
}

void withdraw(map<string, int> &map1, map<int, set<string> > &map2, int &numillegal){
    string name;
    int amount;
    cin>>name>>amount;
    if(map1.count(name)==0){numillegal++;return;}
    else if(map1[name]<amount){numillegal++;return;}
    else {
        int temp;
        temp=map1[name];
        map1[name]=temp-amount;
        map2[temp].erase(name);
        map2[temp-amount].insert(name);
    }
    return;
}

void print(map<string, int> &map1, map<int, set<string> > &map2, int &numillegal){
    int initpos,finpos;
    cin>>initpos>>finpos;
    for(int pos=initpos; pos<=finpos; pos++)    {
        if(!map2[pos].empty())  {
            cout<<pos<<" ";
            set<string>::iterator iter;
            for(iter=map2[pos].begin(); iter!=map2[pos].end(); ++iter)   {
                cout<<*iter<<" ";
            }
            cout<<endl;
        }
    }
    return;
}


int main()  {
    map<string, int> map1;
    map<int, set<string> > map2;
    int numillegal=0;

    char opratr;
    cin>>opratr;
    while (opratr=='O'||opratr=='C'||opratr=='D'||opratr=='W'||opratr=='P') {
        if(opratr=='O') {open(map1,map2,numillegal);}
        if(opratr=='C') {close(map1,map2,numillegal);}
        if(opratr=='D') {deposit(map1,map2,numillegal);}
        if(opratr=='W') {withdraw(map1,map2,numillegal);}
        if(opratr=='P') {print(map1,map2,numillegal);}
        cin>>opratr;
    }
    cout<<numillegal;
}
