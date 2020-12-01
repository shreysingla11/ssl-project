#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

map<string,int>account;
map<int,set<string> >range;
 set<string> temp;
int error_count=0;

void open(string name)
{
    map<string,int>::iterator it;
    it=account.find(name);
    if(it==account.end())
    {
        account[name]=0;
//        range[0]=name;
        range[0].insert(name);
        // range.insert(make_pair(0, name));
    }
    else
    {
        error_count++;
    }

}

void close(string name)
{
    map<string,int>::iterator it;
    it=account.find(name);
    if(it!=account.end())
    {
        if(account[name]==0)
        {
            account.erase(it);
//            range[]
            range[account[name]].erase(name);
        }
        else
        {
            error_count++;
        }

    }
    else
    {
        error_count++;
    }

}

void deposit(string name,int amount)
{
    map<string,int>::iterator it;
    it=account.find(name);
    if(it!=account.end())
    {
        range[account[name]].erase(name);
        account[name]+=amount;
        range[account[name]].insert(name);
    }
    else
    {
        error_count++;
    }
}

void withdraw(string name,int amount)
{
    map<string,int>::iterator it;
    it=account.find(name);
    if(it!=account.end())
    {
        if(account[name]>amount)
        {
            range[account[name]].erase(name);
            account[name]-=amount;
            range[account[name]].insert(name);
        }
        else
        {
            error_count++;
        }

    }
    else
    {
        error_count++;
    }


}


void print(int first,int last)
{
    set<string>::iterator it;
    map<int,set<string> >::iterator itr;
    for(itr=range.begin();itr!=range.end();itr++)
    {
        if(itr->first>=first&&itr->first<=last)
        {
            cout<<itr->first<<" ";
            for(it=itr->second.begin();it!=itr->second.end();it++)
            {
                if(it)
                cout<<(*it)<<" ";
            }
            cout<<endl;
        }
    }

    cout<<error_count<<endl;

}

void print()
{
    map<string,int>::iterator it;
    for(it=account.begin(); it!=account.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }


}


int main()
{
    char ch;
    string name;
    int amount,first,last;
    while(true)
    {

        cin>>ch;
        switch(ch)
        {
        case 'O':
            //open account
            cin>>name;
            open(name);

            break;
        case 'C':
            //close account
            cin>>name;
            close(name);
            break;
        case 'D':
            //deposit
            cin>>name;
            cin>>amount;
            deposit(name,amount);
            break;
        case 'W':
            cin>>name;
            cin>>amount;
            withdraw(name,amount);
            break;
        case 'P':
            //print elemts in range first,last
            cin>>first>>last;
            print(first,last);
            break;
        case 'p':
            print();
            break;

        case 'E':
            break;

        }
        if(ch=='E')
        {
            break;
        }
    }


}
