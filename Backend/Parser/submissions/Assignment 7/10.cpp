#include<iostream>
#include<map>
#include<set>
#include<iterator>
using namespace std;

std:: map<string,int> ac_m;
std:: map<int, set<string> > b_m;

void open(string name){
 ac_m[name]=0;
  b_m[0].insert(name);}

  void close(string name){
   int temp;
   temp=ac_m[name];
   ac_m[name]=-1;
   b_m[temp].erase(name);
   }

  void deposit(string name, int amount)
  { int temp;
    temp= ac_m[name];
    ac_m[name]=ac_m[name]+amount;
    b_m[temp].erase(name);
    b_m[ ac_m[name]].insert(name);
    }


  void withdraw(string name, int amount)
  { int temp;
    temp= ac_m[name];
    ac_m[name]=ac_m[name]-amount;
    b_m[temp].erase(name);
    b_m[ ac_m[name]].insert(name);
    }


int main(){
char inp;
string name;
int amount,amount_1,amount_2;
set<string>::iterator it;
  while(!(inp=='E')){
cin>>inp;
if (inp=='O'){
  cin>>name;
  open(name);}
  else if(inp=='O')
  {cin>>name;
  close(name);}
   else if(inp=='D'){
   cin>>name;
   cin>>amount;
   deposit(name,amount);}
   else if(inp=='W'){
    withdraw(name,amount);}
    else if(inp=='P')
    {cin>>amount_1;
     cin>>amount_2;
     for(int a=amount_1;a<amount_2+1;a++){
      for(it = b_m[a].begin(); it != b_m[a].end(); it++)
    {
        cout << *it << endl;
    }
    }
     }
    else{}

  }
}
