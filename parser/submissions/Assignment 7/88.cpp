#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
int IlCount=0;
map<string,int> Account;
map<int, set<string> > Balance;
void print();
void withdraw(string name);
void deposit(string name);
void close(string name);
void open(string name);
int main()
{
    char s;
    while ( true )
    {
        cin>>s;
        if(s=='E')
        {
            break;
        }
        switch(s)
        {
        case 'O' :
        {
            string name;
            cin>>name;
            open(name);
            break;
        }
        case 'C' :
        {
            string name;
            cin>>name;
            close(name);
            break;
        }
        case 'D' :
        {
            string name;
            cin>>name;
            deposit(name);
            break;
        }
        case 'W' :
        {
            string name;
            cin>>name;
            withdraw(name);
            break;
        }
        case 'P' :
        {
            print();
            break;
        }
        }
    }
    cout<<IlCount<<endl;
    return 0;
}
void open(string name)
{
    map<string,int> ::iterator it;
    it=Account.find(name);
    if( it == Account.end() )
    {
        Account[name]=0;
        Balance[0].insert(name);
    }
    else
    {
        IlCount++;
    }
    return;
}
void close(string name)
{
    map<string,int> ::iterator it;
    set<string> ::iterator it1;
    it=Account.find(name);
    if( it == Account.end() )
    {
        IlCount++;
    }
    else
    {
        it1=Balance[0].find(name);
        if( it1 != Balance[0].end())
        {
            Account.erase(name);
            Balance[0].erase(name);
        }
        else
        {
            IlCount++;
        }
    }
    return;
}
void deposit(string name)
{
    int money;
    cin>>money;
    map<string,int> ::iterator it;
    set<string> ::iterator it1;
    it=Account.find(name);
    if( it == Account.end() )
    {
        IlCount++;
    }
    else
    {
        Balance[Account[name]].erase(name);
        Account[name]=Account[name]+money;
        Balance[Account[name]].insert(name);
    }
    return;
}
void withdraw(string name)
{
    int money;
    cin>>money;
    map<string,int> ::iterator it;
    set<string> ::iterator it1;
    it=Account.find(name);
    if( it == Account.end() )
    {
        IlCount++;
    }
    else
    {
        if(Account[name]<money)
        {
            IlCount++;
            return;
        }
        Balance[Account[name]].erase(name);
        Account[name]=Account[name]-money;
        if(Account[name]==0)
        {
            Balance[0].insert(name);
        }
        Balance[Account[name]].insert(name);
    }
    return;
}
void print()
{
    int start,en;
    cin>>start;
    cin>>en;
    map<int, set<string> > :: iterator lower,upper,it;
    lower=Balance.lower_bound(start);
    upper=Balance.upper_bound(en);
    it=lower;
    if(it->first < Balance.begin()->first)
    {
        it++;
    }
    while(it!=upper)
    {
        set<string> ::iterator it1;
        it1=(lower->second).begin();
        cout<<it->first<<" ";
        while(it1 != (lower->second).end())
        {
            cout<<(*it1)<<" ";
            it1++;
        }
        cout<<endl;
        it++;
    }
    return;
}


