#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
int invalid=0;
map<string,int>bal;
map<int,set<string> >all;
void o(string name)
{
    if(bal.find(name)==bal.end())
    {
        bal[name]=0;
        all[bal[name]].insert(name);
    }
    else
    {
        invalid+=1;
    }
}

void c(string name)
{
    if(bal.find(name)==bal.end())
    {
        invalid++;
    }
    else
    {
        if(bal[name]!=0)
        {
            invalid++;
        }
        else
        {
            all[bal[name]].erase(name);
            bal.erase(name);
        }
    }
}

void d(string name,int deposit)
{
    if(bal.find(name)==bal.end())
    {
        invalid++;
    }
    else
    {
        all[bal[name]].erase(name);
        bal[name]+=deposit;
        all[bal[name]].insert(name);
    }
}

void w(string name,int withdraw)
{
    if(bal.find(name)==bal.end())
    {
        invalid++;
    }
    else
    {
        if(withdraw>bal[name])
        {
            invalid++;
        }
        else
        {
            all[bal[name]].erase(name);
            bal[name]-=withdraw;
            all[bal[name]].insert(name);
        }
    }
}

void p(int lbound,int ubound)
{
    for(int i=lbound; i<=ubound; i++)
    {
        if(all[i].empty())
        {
            continue;
        }
        else
        {
            cout<<i<<" ";
            set<string> :: iterator it=all[i].begin();
            for(; it!=all[i].end(); it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
    return;
}

int main()
{
    string name;
    char first;
    int deposit,withdraw,lbound,ubound;

    while(true)
    {
        cin>>first;
        if(first=='E')
        {
            break;
        }
        else if(first=='O')
        {
            cin>>name;
            o(name);
        }
        else if(first=='C')
        {
            cin>>name;
            c(name);
        }
        else if(first=='D')
        {
            cin>>name;
            cin>>deposit;
            d(name,deposit);
        }
        else if(first=='W')
        {
            cin>>name;
            cin>>withdraw;
            w(name,withdraw);
        }
        else if(first=='P')
        {
            cin>>lbound;
            cin>>ubound;
            if(lbound>ubound)
            {
                continue;
            }
            p(lbound,ubound);
        }
    }
    cout<<invalid<<endl;
    return 0;
}
