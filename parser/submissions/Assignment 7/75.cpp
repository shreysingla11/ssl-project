#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>

using namespace std;

vector<string> printoutput;
vector<string>::iterator lol;
int intemp;
string temp;

class bank{

map<string, int> accs;
map<int, set<string> > balaccs;
int illegals;

public:

bank(){
illegals=0;
}

void open(string name){
if(accs.count(name)==1) {
    illegals++;
    }
else {
    accs[name]=0;
    balaccs[0].insert(name);
    }
}

void close(string name){
if(accs[name]!=0) {
    illegals++;
    }
else {
    accs.erase(name);
    balaccs[0].erase(name);
    }
}

void deposit(string name, int amt){
if(accs.count(name)!=1) {
    illegals++;
    }
else {
    balaccs[accs[name]].erase(name);
    accs[name]=accs[name]+amt;
    balaccs[accs[name]].insert(name);
    }
}

void withdraw(string name, int amt){
if(accs.count(name)!=1||accs[name]<amt) {
    illegals++;
    }
else {
        balaccs[accs[name]].erase(name);
        accs[name]=accs[name]-amt;
        balaccs[accs[name]].insert(name);
    }
}

void print(int amtlow, int amthi){
map<int, set<string> >::iterator low;
map<int, set<string> >::iterator hi;
map<int, set<string> >::iterator curr;
set<string>::iterator currstr;
low=balaccs.lower_bound(amtlow);
hi=balaccs.lower_bound(amthi);
for(curr=low;curr!=hi;curr++){
    stringstream convert;
    convert << curr->first;
    temp = convert.str();
    printoutput.push_back(temp);
    for(currstr=curr->second.begin();currstr!=curr->second.end();currstr++){
    lol=printoutput.end();
    lol--;
    *(lol)+=" ";
    *(lol)+=*(currstr);
        }
    }
}

void getillegals() {
    if(illegals==0) cout<<illegals<<endl;
    else {
        illegals--;
        cout<<illegals<<endl;
        }
    }

};

int main() {
bank Bank;
char o; string name; int amt;
int amtlow,amthi;
while(true) {
cin>>o;
if(o=='O') {
    cin>>name;
    Bank.open(name);
    }
if(o=='C') {
    cin>>name;
    Bank.close(name);
    }
if(o=='D') {
    cin>>name>>amt;
    Bank.deposit(name,amt);
    }
if(o=='W') {
    cin>>name>>amt;
    Bank.withdraw(name,amt);
    }
if(o=='P') {
    cin>>amtlow>>amthi;
    Bank.print(amtlow,amthi);
    }
if(o=='E') {
    break;
    }
}

for(vector<string>::iterator it=printoutput.begin();it!=printoutput.end();it++) {
cout<<(*it)<<endl;
}
Bank.getillegals();
return 0;
}
