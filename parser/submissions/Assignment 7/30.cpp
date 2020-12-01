#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int count = 0;

void open(string name,map<string,int> &account,map<int, set<string> > &balance)
{
    if(account.find(name) != account.end())
    {
        count++;
    }
    else
    {
        account[name] = 0;
        balance[0].insert(name);
        return;
    }
}

void deposit(string name,map<string,int> &account,map<int, set<string> > &balance,int amount)
{
    if(account.find(name) != account.end())
    {
        balance[account[name]].erase(name);
        if(balance[account[name]].size()==0)
        {
            balance.erase(account[name]);
        }
        account[name]=account[name]+amount;
        balance[account[name]].insert(name);
        return;
    }
    else
    {
        count++;
        return;
    }
}

void withdraw(string name,map<string,int> &account,map<int, set<string> > &balance,int amount)
{
    if(account.find(name) != account.end())
    {
        if((account[name]<amount))
        {
            count++;
            return;
        }
        else
        {
            balance[account[name]].erase(name);
            if(balance[account[name]].size()==0)
            {
                balance.erase(account[name]);
            }
            account[name]=account[name]-amount;
            balance[account[name]].insert(name);
            return;
        }
    }
    else
    {
        count++;
        return;
    }
}

void close(string name,map<string,int> &account,map<int, set<string> > &balance)
{
    if(account.find(name) == account.end())
    {
        count++;
        return;
    }
    else
    {
        if(account[name]>0)
        {
            count++;
            return;
        }
        else
        {
            balance[0].erase(name);
            if(balance[0].size()==0)
            {
                balance.erase(0);
            }
            account.erase(name);
            return;
        }
    }
}

void print(map<string,int> &account,map<int, set<string> > &balance,int lrange,int rrange)
{
    set<string>::iterator itset;
    map<int,set<string> >::iterator itmapset;
    for(itmapset=balance.begin();itmapset!=balance.end();itmapset++)
    {
        if((itmapset->first>=lrange)&&(itmapset->first<=rrange))
        {
            cout<<itmapset->first;
            for(itset=itmapset->second.begin();itset!=itmapset->second.end();itset++)
            {
                cout<<" "<<*itset;
            }
            cout<<endl;
        }
    }
}

int main()
{
    map<string,int> account;
    map<string,int>::iterator accountcheck;
    map<int, set<string> > balance;
    string name;
    int amount;
    int lrange,rrange;
    char input;
    for(;;)
    {
        cin>>input;
        if(input=='E')
        {
            cout<<count<<endl;
            break;
        }
        if((input=='O')||(input=='C'))
        {
            cin>>name;
        }
        if((input=='D')||(input=='W'))
        {
            cin>>name;
            cin>>amount;
        }
        if(input=='P')
        {
            cin>>lrange;
            cin>>rrange;
        }
        if(input=='O')
        {
            open(name,account,balance);
        }
        if(input=='D')
        {
            deposit(name,account,balance,amount);
        }
        if(input=='W')
        {
            withdraw(name,account,balance,amount);
        }
        if(input=='C')
        {
            close(name,account,balance);
        }
        if(input=='P')
        {
            print(account,balance,lrange,rrange);
        }
    }
    return 0;
}
