#include<iostream>
#include<string>
#include<utility>
#include<stdio.h>
#include<map>
#include<set>
#include<sstream>
using namespace std;
bool open(map<string,int>&, map<int,set<string> >&, string);
bool close(map<string,int>&, map<int,set<string> >&, string);
bool withdraw(map<string,int>&, map<int,set<string> >&, string, int);
bool deposit(map<string,int>&, map<int,set<string> >&, string, int);
bool print(map<int,set<string> >&, int, int, string& store);
void display(map<string,int>&, map<int,set<string> >&, int counter);
int main()
{
    int value1,value2,counter;
    value1 = 0;
    value2 = 0;
    counter = 0;
    char input;
    string name,store;
    bool return_value = false;
    map<string,int> accounts;
    set<string> equal_deposit;
    map<int,set<string> > deposits;
    while(true)
    {
        scanf("%c",&input);
        if(input == '\n')
        {
            scanf("%c",&input);
        }
        switch(input)
        {
            case 'O':cin>>name;
                     //open an account
                     return_value = open(accounts,deposits,name);
                     if(!return_value)
                     {
                        counter++;
                     }
                     //display(accounts,deposits,counter);
                     break;
            case 'C':cin>>name;
                     //close the account
                     return_value = close(accounts,deposits,name);
                     if(!return_value)
                     {
                        counter++;
                     }
                     //display(accounts,deposits,counter);
                     break;
            case 'W':cin>>name;
                     cin>>value1;
                     //withdraw the amount
                     return_value = withdraw(accounts,deposits,name,value1);
                     if(!return_value)
                     {
                        counter++;
                     }
                     //display(accounts,deposits,counter);
                     break;
            case 'D':cin>>name;
                     cin>>value1;
                     //deposit the amount
                     return_value = deposit(accounts,deposits,name,value1);
                     if(!return_value)
                     {
                        counter++;
                     }
                     //display(accounts,deposits,counter);
                     break;
            case 'P':cin>>value1;
                     cin>>value2;
                     //print the accounts with values inside the range
                     return_value = print(deposits,value1,value2,store);
                     if(!return_value)
                     {
                        counter++;
                     }
                     //display(accounts,deposits,counter);
                     break;
            case 'E'://display(accounts,deposits,counter);
                     cout<<store;
                     cout<<counter<<"\n";
                     //cout<<"End of Input \n";
                     return 1;
            default :break;
        }
        input = '!';
    }
    return 0;
}

bool open(map<string,int>& accounts, map<int,set<string> >& deposits, string name)
{
    if(accounts.count(name) == 1)
    {
        return false;
    }
    else
    {
        accounts.insert(make_pair(name,0));
        if(deposits.count(0)  == 0)
        {
            set<string> a;
            deposits.insert(pair<int,set<string> >(0,a));
            deposits[0].insert(name);
        }
        else
        {
            deposits[0].insert(name);
        }
    }
    return 1;
}
bool close(map<string,int>& accounts, map<int,set<string> >& deposits, string name)
{
    if(accounts.count(name) == 0)
    {
        return false;
    }
    else
    {
        deposits[accounts[name]].erase(name);
        if(deposits[accounts[name]].size() == 0)
        {
            deposits.erase(accounts[name]);
        }
        accounts.erase(name);
    }
    return 1;
}
bool withdraw(map<string,int>& accounts, map<int,set<string> >& deposits, string name, int value1)
{
    if(accounts.count(name) == 0 || accounts[name] < value1)
    {
        return false;
    }
    else
    {
        deposits[accounts[name]].erase(name);
        if(deposits[accounts[name]].size() == 0)
        {
            deposits.erase(accounts[name]);
        }
        accounts[name] -= value1;
        if(deposits.count(accounts[name])  == 0)
        {
            set<string> a;
            deposits.insert(pair<int,set<string> >(accounts[name],a));
            deposits[accounts[name]].insert(name);
        }
        else
        {
            deposits[accounts[name]].insert(name);
        }
    }
    return 1;
}
bool deposit(map<string,int>& accounts, map<int,set<string> >& deposits, string name, int value1)
{
    if(accounts.count(name) == 0)
    {
        return false;
    }
    else
    {
        deposits[accounts[name]].erase(name);
        if(deposits[accounts[name]].size() == 0)
        {
            deposits.erase(accounts[name]);
        }
        accounts[name] += value1;
        if(deposits.count(accounts[name])  == 0)
        {
            set<string> a;
            deposits.insert(pair<int,set<string> >(accounts[name],a));
            deposits[accounts[name]].insert(name);
        }
        else
        {
            deposits[accounts[name]].insert(name);
        }
    }
    return true;
}
bool print(map<int,set<string> >& deposits, int value1, int value2, string& store)
{
    map<int,set<string> >::iterator it;
    set<string>::iterator it_set;
    for(it = deposits.begin();it != deposits.end();it++)
    {
        if(it->first >= value1)
        {
            break;
        }
    }
    for(;it != deposits.end();it++)
    {
        if(it->first > value2)
        {
            break;
        }
        stringstream convert;
        convert<<it->first;
        store += convert.str();
        for(it_set = it->second.begin();it_set != it->second.end();it_set++)
        {
            store += ' ';
            store += *it_set;
        }
        store += '\n';
    }
    return true;
}
void display(map<string,int>& accounts, map<int,set<string> >& deposits, int counter)
{
    map<string,int>::iterator it1;
    cout<<"ACCOUNTS----------------------------------------\n";
    for(it1 = accounts.begin();it1 != accounts.end();it1++)
    {
        cout<<it1->first<<"-"<<it1->second<<"\n";
    }
    map<int,set<string> >::iterator it2;
    set<string>::iterator it_set;
    cout<<"DEPOSITS-----------------------------------------\n";
    for(it2 = deposits.begin();it2 != deposits.end();it2++)
    {
        cout<<it2->first;
        for(it_set = it2->second.begin();it_set != it2->second.end();it_set++)
        {
            cout<<" "<<*it_set;
        }
        cout<<"\n";
    }
    cout<<"COUNTER -- "<<counter<<"\n";
}
