#include<iostream>
#include<map>
using namespace std;

bool balance (char bal1, char bal2) {return bal1<bal2;}

class Bank{
	string name;
	int balance;
	
};



int main ()
{
  std::map<char,int> first;

  first['a']=1000;
  first['b']=30000;
  first['c']=5000;
  first['d']=70000;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  std::map<char,int,Bank> fourth;                

  bool(*fn_pt)(char,char) = balance;
  std::map<char,int,bool(*)(char,char)> fifth (fn_pt); 

  return 0;
  
  
  
}
