#include<iostream>
#include<map>
#include<set>
using namespace std;

class account
{
public:
//set<string> cust;
map<int,set<string> > mem;
map<string,int> bal;
int ill;
void reset(){
ill=0;}

void open(string name){
if(bal.find(name)==bal.end())
{
bal[name]=0;
mem[0].insert(name);
}
else{ill++;}
return;
}

void close(string name){
if(!(bal.find(name)==bal.end()))
{
if(bal[name]==0)
{
mem[bal[name]].erase(name);
bal.erase(name);
}
else{ill++;}
}
else{ill++;}
return;
}

void withdraw(string name,int amount){
if(bal.find(name)!=bal.end())
{
if(amount<=bal[name])
{
mem[bal[name]].erase(name);
bal[name]=bal[name]-amount;
mem[bal[name]].insert(name);
}
else{ill++;}
}
else{ill++;}
return;
}


void deposit(string name,int amount){
if(bal.find(name)!=bal.end())
{
mem[bal[name]].erase(name);
bal[name]=bal[name]+amount;
mem[bal[name]].insert(name);
}
else{ill++;}
return;
}

void print(int first,int last){
for(int i=first;i<=last;i++)
{
if(mem[i].empty()){continue;}
else{
set<string>::iterator it;
cout<<i;
for (it=mem[i].begin();it!=mem[i].end();it++)
{cout<<" "<<*(it);
}
cout<<endl;
}
}
return;
}

};

int main(){

char c;
account a;
a.reset();
while(true)
{
cin>>c;

if(c=='O')
{
string name;
cin>>name;
a.open(name);
}

if(c=='C')
{
string name;
cin>>name;
a.close(name);
}

if(c=='W')
{
int amount;
string name;
cin>>name>>amount;
a.withdraw(name,amount);
}

if(c=='D')
{
int amount;
string name;
cin>>name>>amount;
a.deposit(name,amount);
}

if(c=='P')
{
int first,last;
cin>>first>>last;
a.print(first,last);
}

if(c=='E')
{
break;
}
}
cout<<a.ill;
return 0;
}
