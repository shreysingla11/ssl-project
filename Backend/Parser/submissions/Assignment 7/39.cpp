#include<iostream>
#include<map>
#include<set>
using namespace std;
int deposit(map<int, set<string> > &accounts,map<string,int> &balance,string name,int deposit_value)
{
    if(balance.find(name)==balance.end())
    {
        return -1;
    }
    else
    {
        accounts[balance[name]].erase(name);
        if(accounts[balance[name]].size()==0)
        {
            accounts.erase(balance[name]);
        }
        balance[name]=balance[name]+deposit_value;
        accounts[balance[name]].insert(name);
        return 0;
    }
}
int withdraw(map<int, set<string> > &accounts,map<string,int> &balance,string name,int draw_value)
{
    if(balance.find(name)==balance.end())
    {
        return -1;
    }
    else
    {
        if(balance[name]<draw_value)
        {
            return -1;
        }
        else
        {
            accounts[balance[name]].erase(name);
            if(accounts[balance[name]].size()==0)
            {
                accounts.erase(balance[name]);
            }
            balance[name]=balance[name]-draw_value;
            accounts[balance[name]].insert(name);
            return 0;
        }
    }
}
int open(map<int, set<string> > &accounts,map<string,int> &balance,string name)
{
    if(balance.find(name)!=balance.end())
    {
        return -1;
    }
    else
    {
        balance[name]=0;
        accounts[0].insert(name);
        return 0;
    }
}
int close(map<int, set<string> > &accounts,map<string,int> &balance,string name)
{
    if(balance.find(name)==balance.end())
    {
        return -1;
    }
    else
    {
        if(balance[name]>0)
        {
            return -1;
        }
        else
        {
            accounts[0].erase(name);
            if(accounts[0].size()==0)
            {
                accounts.erase(0);
            }
            balance.erase(name);
            return 0;
        }
    }
}
void print(map<int, set<string> > &accounts,int a,int b)
{
    map<int, set<string> > :: iterator it1;
    set<string>::iterator it2;
    for(it1=accounts.begin(); it1!=accounts.end(); it1++)
    {

        if(it1->first>=a&&it1->first<=b)
        {
            cout<<it1->first;
            for(it2=it1->second.begin(); it2!=it1->second.end(); it2++)
            {
                cout<<" "<<*it2;
            }
            cout<<endl;
        }
    }
    return;
}
int main()
{
    map<string,int> balance;
    map<int, set<string> > accounts;
    int errors=0;
    char input;
    string name;
    int deposit_value;
    int draw_value;
    int a,b;
    while(true)
    {
        cin>>input;
        if(input=='O')
        {
            cin>>name;
            if(open(accounts,balance,name)==-1)
            {
                errors++;
            }
        }
        if(input=='C')
        {
            cin>>name;
            if(close(accounts,balance,name)!=0)
            {
                errors++;
            }
        }
        if(input=='D')
        {
            cin>>name;
            cin>>deposit_value;
            if(deposit(accounts,balance,name,deposit_value)!=0)
            {
                errors++;
            }
        }
        if(input=='W')
        {
            cin>>name;
            cin>>draw_value;
            if(withdraw(accounts,balance,name,draw_value)!=0)
            {
                errors++;
            }
        }
        if(input=='P')
        {
            cin>>a;
            cin>>b;
            print(accounts,a,b);
        }
        if(input=='E')
        {
            cout<<errors<<endl;
            break;
        }
    }
    return 0;
}
