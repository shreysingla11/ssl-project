#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

map<string,int> balance;
map<int,set<string> >name;

void open_acc(string nm, int &counter)
{   map<string,int> :: iterator finder;
    finder=balance.find(nm);
    if(finder!=balance.end()) {counter++; return;}
    balance.insert(pair<string,int> (nm,0));
    if(name.find(0)==name.end())
    {
        set<string> names;
        name.insert(pair<int,set<string> >(0,names));
    }
    name[0].insert(nm);
    return;
}
void close_acc(string nm, int &counter)
{   map<string,int> :: iterator finder;
    finder=balance.find(nm);
    if(finder==balance.end()) {counter++; return;}
    balance.insert(pair<string,int> (nm,0));
    if(name.find(0)==name.end())
    {    counter++;return;}
    if(name[0].find(nm)==name[0].end()) {counter++;return;}
    name[0].erase(nm);
    balance.erase(nm);
    if(name[0].empty()==true) name.erase(0);
    return;
}
void deposit(string nm, int am, int &counter)
{
    if(am<0) {counter++;return;}
    if(am==0) {return;}
    map<string,int> :: iterator finder;
    finder=balance.find(nm);
    if(finder==balance.end()) {counter++; return;}
    int bal=finder->second;
    finder->second+=am;
    name[bal].erase(nm);
    if(name[bal].empty()==true) name.erase(bal);
    bal+=am;
    if(name.find(bal)==name.end())
    {
        set<string> names;
        name.insert(pair<int,set<string> >(bal,names));
    }
    name[bal].insert(nm);
    return;
}
void withdraw(string nm, int am, int &counter)
{
    if(am<0) {counter++;return;}
    if(am==0) {return;}
    map<string,int> :: iterator finder;
    finder=balance.find(nm);
    if(finder==balance.end()) {counter++; return;}
    int bal=finder->second;
    if(bal<am) {counter++;return;}
    finder->second-=am;
    name[bal].erase(nm);
    if(name[bal].empty()==true) name.erase(bal);
    bal-=am;
    if(name.find(bal)==name.end())
    {
        set<string> names;
        name.insert(pair<int,set<string> >(bal,names));
    }
    name[bal].insert(nm);
    return;
}
void print(int first, int last,int &counter)
{
    if(first<0) {counter++;return;}
    map<int,set<string> > :: iterator printer=name.begin();
    set<string>::iterator mystring;
    while(printer!=name.end())
    {
        if(printer->first<first||printer->first>last) {printer++;continue;}
        mystring=printer->second.begin();
        cout<<printer->first<<"\t";
        while(mystring!=printer->second.end())
        {
            cout<<*(mystring)<<"\t"; mystring++;
        }
        cout<<endl;
        printer++;
    }
    return;
}
int main()
{
    int counter=0;
    char ch='A';
    int first, last;
    string names;
    while(ch!='E')
    {
        cin>>ch;
        switch(ch)
        {
            case 'O' :  cin>>names;
                        open_acc(names,counter);
                        break;
            case 'C' :  cin>>names;
                        close_acc(names,counter);
                        break;
            case 'D' :  cin>>names>>first;
                        deposit(names,first,counter);
                        break;
            case 'W' :  cin>>names>>first;
                        withdraw(names,first,counter);
                        break;
            case 'P' :  cin>>first>>last;
                        print(first,last,counter);
                        break;
            default  :  break;
      }
    }
    cout<<counter;
    return 0;
}
