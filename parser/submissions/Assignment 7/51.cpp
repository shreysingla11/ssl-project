#include<iostream>
#include<set>
#include<map>
using namespace std;

int illegal;

int main(){
map<string ,int > account;
map<string ,int >::iterator ita;
map<int , set<string> > balance;
set<string>::iterator it;
map<int , std::set<string> >::iterator itb,itb1,itb2;
int money,ran1,ran2,a,illegal,exit;
string name;
char op;
illegal=0;a=0;exit=0;
for(int i=0;exit!=1;){
cin>>op;
switch(op){
case 'O':
    cin>>name;
    ita=account.find(name);
    itb=balance.find(0);
    if (ita != account.end()){
    illegal++;
    }
    else{
        account[name]=0;
        balance[0].insert(name);
    }
    break;
case 'C':
    cin>>name;if(itb != balance.end()){
if(itb != balance.end()){

    account.erase(name);
    balance[0].erase(name);
    }
    else{illegal++;}
    }
    else{illegal++;}
    break;
case 'P':
    cin>>ran1>>ran2;
    /* itb1=balance.begin();
    itb2=balance.end();
    for(itb1;itb1 != balance.end();itb1++){
        if((*itb1)>=ran1){itb=itb1;a=1;break;}
        else{}
    } 
    for(itb2;itb2 != balance.begin();itb2--){
        if((*itb2)<=ran2){itb=itb2;b=1;break;}
    }
    if(itb1 != balance.end()){
        for(itb=itb1;itb!=itb2;itb++){
            cout<<(*itb)
            for(it=(*itb).begin();it!=(*itb).begin();it++){
                cout<<(*it)<<" ";
            }
            cout<<"\n";
        }
    }
    else{illegal++;} */
    /*itb=balance.find(0);
    it=balance[0].begin();
            for(it=balance[0].begin();;it++){
                cout<<*it<<" ";
            }
            cout<<"\n";*/
            itb=balance.begin();
            if(!balance[itb->first].empty()){
            cout<<itb->first<<" ";
            for(it=balance[itb->first].begin();it!=balance[itb->first].end();it++){
                cout<<*it<<" ";
}
            cout<<"\n";

            }
            itb++;
    for(itb;itb!=balance.end();itb++){
        if((itb->first)>=ran1&&ran2>=(itb->first)){
            cout<<itb->first<<" ";
            for(it=balance[itb->first].begin();it!=balance[itb->first].end();it++){
                cout<<*it<<" ";
            }
            cout<<"\n";
        }
    }
    break;
case 'W':
    cin>>name>>money;
    ita=account.find(name);
    if(ita != account.end()){
    if(account[name]>=money){
        balance[account[name]].erase(name);
        if(balance[account[name]].empty()){balance.erase(account[name]);}
        else{}
        account[name]=account[name]-money;
        balance[account[name]].insert(name);
    }
    else{illegal++;}
    }
    else{illegal++;}
    break;
case 'D':
    cin>>name>>money;
    ita=account.find(name);
    if(ita != account.end()){
        balance[account[name]].erase(name);
        if(balance[account[name]].empty()){balance.erase(account[name]);}
        else{}
        account[name]=account[name]+money;
        balance[account[name]].insert(name);
    }
    else{illegal++;}
    break;
    case 'E':
    exit=1;
default:
    break;
}
}
cout<<illegal<<endl;
return 0;
}
