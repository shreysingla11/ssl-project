#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<cstring>
using namespace std;
class Bank_Account
{

 map<string,int>name_balance;
 map<int,set<string> >balance_name;

 void open_account(string s)
 {
   if(name_balance.count(s)>0)
   {
    count_wrong_op++;
    return;
   }
   name_balance[s]=0;
   set<string> ls;
   ls = balance_name[0];
   ls.insert(s);
   balance_name[0]=ls;
  return;
 }

 void deposit_amount(string s1,string s2)
 {
   if(name_balance.count(s1)==0)
   {
    count_wrong_op++;
    return;
   }
   int val,values=0;
   int a = name_balance[s1];
   istringstream buffer(s2);
    buffer >> val;
    values+=val;
   name_balance[s1] = name_balance[s1]+values;
   set<string> ls,lsn;
   ls = balance_name[a];
   ls.erase(ls.find(s1));
   balance_name[a]=ls;
   lsn = balance_name[( name_balance[s1])];
   lsn.insert(s1);
   balance_name[( name_balance[s1])] = lsn;
   return;

 }

 void withdraw_amount(string s1,string s2)
 {
   if(name_balance.count(s1)==0)
   {
    count_wrong_op++;
    return;
   }
   int val,values=0;
   int a = name_balance[s1];
   istringstream buffer(s2);
    buffer >> val;
    values+=val;
   name_balance[s1] = name_balance[s1]-values;

   if(name_balance[s1]<0)
   {
     count_wrong_op++;
     name_balance[s1] = name_balance[s1]+values;
     return;
   }
    set<string> ls,lsn;
   ls = balance_name[a];
   ls.erase(ls.find(s1));
   balance_name[a]=ls;
   lsn = balance_name[(name_balance[s1])];
   lsn.insert(s1);
   balance_name[( name_balance[s1])] = lsn;
   return;
 }

 void close_account(string s)
 {
  if(name_balance.count(s)==0)
   {
    count_wrong_op++;
    return;
   }
  if(name_balance[s]!=0)
  {
   count_wrong_op++;
   return;
  }
   set<string> ls;
   ls = balance_name[0];
   ls.erase(ls.find(s));
   balance_name[0]=ls;
  return;
 }

 void print_all(string s1,string s2)
 {
  int val1,val=0,values1,values=0;
   istringstream buffer(s1);
    buffer >> val1;
    istringstream buffer1(s2);
    buffer1 >> values1;
  values+=values1;
  val+=val1;
  map<int,set<string> >::iterator itlow,itup;
  itlow=balance_name.lower_bound(val);
  itup=balance_name.upper_bound(values);

  for(map<int,set<string> >::iterator itr=itlow;itr!=itup;itr++)
  {
   set<string> ls;
   ls=itr->second;
   if(!ls.empty())
   {
   cout<<(itr->first);
   for(set<string>::iterator it2=ls.begin();it2!=ls.end();it2++)
   {
    cout<<" "<<(*it2);
   }
   cout<<endl;
  }
  }
  return;
 }

 public:
  int count_wrong_op;
  Bank_Account()
 {
  count_wrong_op=0;
 }
 void get_operations(char c)
  {
    switch(c)
    {
    case 'O': {string s; cin>>s; open_account(s);
             break;}
    case 'D':{string s1,s2; cin>>s1;cin>>s2; deposit_amount(s1,s2);
             break;}
    case 'W':{ string s1,s2; cin>>s1;cin>>s2;withdraw_amount(s1,s2);break;}

    case 'P':{string s1,s2; cin>>s1;cin>>s2;print_all(s1,s2);break;}

    case 'C':{ string s;cin>>s;close_account(s);break;}
    }
    return;
  }
};
int main()
{
 Bank_Account a;

 while(true)
 {
  char c;
  cin>>c;
  if(c=='E')
  break;
  a.get_operations(c);
 }
cout<<a.count_wrong_op<<endl;
return 0;
}

