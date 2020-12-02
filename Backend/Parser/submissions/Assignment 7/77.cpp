#include <iostream>
#include <map>
#include <string.h>
#include <set>
using namespace std;

map<string, int> account;
map<int, set<string> > balAccount;
int illCount;

void open (string name) {
    if (account.count(name) > 0) illCount++;
    else {
        account[name] = 0;
        balAccount[0].insert(name);
    }
}

void close (string name) {
    if (account.count(name) <=0) illCount++;
    else {
        if (account[name]!=0) illCount++;
        else {
            account.erase(name);
            balAccount[0].erase(name);
            if (balAccount[0].size() == 0) {
                balAccount.erase(0);
        }
        }
    }
}

void deposit (string name, int amount) {
    if (account.count(name) <=0) illCount++;
    else {
        balAccount[account[name]].erase(name);
        if (balAccount[account[name]].size() == 0) {
            balAccount.erase(account[name]);
        }
        account[name] = account[name] + amount;
        balAccount[account[name]].insert(name);
    }
}

void withdraw (string name, int amount) {
    if (account.count(name) <=0) illCount++;
    else {
        if(account[name] - amount < 0) illCount++;
        else {
            balAccount[account[name]].erase(name);
            if (balAccount[account[name]].size() == 0) {
                balAccount.erase(account[name]);
            }
            account[name] = account[name] - amount;
            balAccount[account[name]].insert(name);
        }
    }
}

void print (int amount, int amount1) {

    map<int, set<string> >::iterator itLow, itUp;
    itLow = balAccount.lower_bound(amount);
    itUp = balAccount.upper_bound(amount1);

    for(map<int, set<string> >::iterator it=itLow; it != itUp;++it) {
        set<string>::iterator it1;
        cout <<(*it).first<<" ";
        for (it1=((*it).second).begin(); it1!=((*it).second).end(); ++it1)
            cout<<*it1 <<' ';
        cout << '\n';
    }

    /*if (balAccount.count(amount)>0) {
        set<string>::iterator it;
        cout <<amount<<" ";
        for (it=(balAccount[amount]).begin(); it!=(balAccount[amount]).end(); ++it)
        cout<<*it <<' ';
        cout << '\n';
    }*/
}

int main() {

illCount = 0;

char oper;
string input;
int money,money1;
cin>>oper;

while(oper != 'E') {
switch (oper) {

case 'O':
    cin>>input;
    //cout<<input;
    open(input);
    break;

case 'C':
    cin>>input;
    close(input);
    break;

case 'D':
    cin>>input;
    cin>>money;
    deposit(input,money);
    break;

case 'W':
    cin>>input;
    cin>>money;
    withdraw(input,money);
    break;

case 'P':
    cin>>money;
    cin>>money1;
    print(money,money1);
    break;

default: break;
}

cin>>oper;
}

map<string, int>::iterator it;
//for (it=account.begin(); it!=account.end(); ++it)
//    std::cout << it->first << " " << it->second << '\n';
cout<<illCount<<endl;

return 0;
}
