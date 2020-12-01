#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;


 map <string,int>  balance;
     map<string,int>::iterator it_balance;
     map<int,set<string> > account;
     map<int,set<string> >::iterator it_account;
     int illegal=0;


void open(string name)
    {
     it_balance=balance.find(name);
             if (it_balance!=balance.end()){illegal++;return;}
             else
                {
                 set<string> cost;
                 balance.insert (pair<string,int>(name,0));
                 it_account=account.find(0);
                 if (it_account==account.end())
                    {
                     cost.clear();
                     cost.insert(name);
                     account.insert (pair<int,set<string> > (0,cost));
                    }
                 else
                    {
                     it_account->second.insert(name);
                    }
               }
    }


void close(string name)
    {
     it_balance=balance.find(name);
             if (it_balance==balance.end()){illegal++;return;}
             else
                {
                 int temp;
                 set<string> cost;
                 temp=it_balance->second;
                 if (temp!=0){illegal++;return;}
                 else
                    {
                     it_account=account.find(temp);
                     it_account->second.erase(name);
                     balance.erase(name);
                     if (it_account->second.empty()){account.erase(temp);}

                    }
               }
    }

void deposit (string name, int money)
    {
     it_balance=balance.find(name);
     if (it_balance==balance.end()){illegal++;return;}
     else
        {
         int temp,temp1;
         set<string> cost;
         cost.clear();
         temp=it_balance->second;
         temp1=temp+money;
         it_balance->second=temp1;
         it_account=account.find(temp);
         it_account->second.erase(name);
         if (it_account->second.empty()){account.erase(temp);}

         it_account=account.find(temp1);
         if (it_account==account.end())
                    {
                     cost.clear();
                     cost.insert(name);
                     account.insert (pair<int,set<string> > (temp1,cost));
                    }
                 else
                    {
                     it_account->second.insert(name);
                    }
         }
    }


void withdraw(string name ,int money)
    {
     it_balance=balance.find(name);
     if (it_balance==balance.end()){illegal++;return;}
     else
        {
         int temp,temp1;
         set<string> cost;
         cost.clear();
         temp=it_balance->second;
         if (money>temp){illegal++;return;}
         temp1=temp-money;
         it_balance->second=temp1;
         it_account=account.find(temp);
         it_account->second.erase(name);
         if (it_account->second.empty()){account.erase(temp);}

         it_account=account.find(temp1);
         if (it_account==account.end())
                    {
                     cost.clear();
                     cost.insert(name);
                     account.insert (pair<int,set<string> > (temp1,cost));
                    }
                 else
                    {

                     it_account->second.insert(name);
                    }
        }
    }


void print(int range_start, int range_end)
    {
     int temp;
     set<string>::iterator it_set;

     it_account=account.lower_bound(range_start);
     for(;(it_account->first)<=range_end&&it_account!=account.end();it_account++)
        {

             cout<<it_account->first<<" ";
             it_set=it_account->second.begin();
             for (;it_set!=it_account->second.end();it_set++)
                {
                 cout<<*it_set<<" ";
                }
             cout<<"\n";
            }

    }

int main()
    {
     string input;
     int money;
     string name;
     int range_start;
     int range_end;

     while(true)
        {
         cin>>input;
         if (input=="O")
            {
             cin>>name;
             open(name);
            }
         else if (input=="C")
            {
             cin>>name;
             close(name);
            }
         else if (input=="D")
            {
             cin>>name;
             cin>>money;
             deposit(name,money);
            }
         else if (input=="W")
            {
             cin>>name;
             cin>>money;
             withdraw(name,money);
            }
         else if (input=="P")
            {
             cin>>range_start;
             cin>>range_end;
             print(range_start,range_end);
            }
         else if (input=="E")
            {
             cout<<illegal;
             break;
            }
        }

  return 0;
    }
