#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void openAccount(map<string, int> &account, map<int, set<string> > &balance, string name, int &errorCount)
{
    pair<map<string, int>::iterator, bool> ret;
    ret = account.insert ( pair<string,int>(name, 0) );

    if (ret.second==false)//element already present
    {
        errorCount++;
        return;
    }

    account.insert ( pair<string,int>(name, 0) );
    return;
}//end of openAccount()

void closeAccount(map<string, int> &account, map<int, set<string> > &balance, string name, int &errorCount)
{
    if(account[name]!=0)
    {
        errorCount++;
        return;
    }

    //code to remove an element
    map<string,int>::iterator it;
    it = account.find (name);
    account.erase (it);
    return;
}//end of closeAccount()

void depositAccount(map<string, int> &account, map<int, set<string> > &balance, string name,int amount, int &errorCount)
{
    if ( account.find(name) == account.end() )
    {
        // not found
        errorCount++;
        return;
    }

    if(balance[account[name]].size()==0)
    {
        map<int, set<string> >::iterator it;
        it=balance.find(account[name]);
        balance.erase (it);
    }

    account[name]=account[name]+amount;

    set<string>::iterator it;
    it=balance[account[name]].begin();
    balance[account[name]].insert (it, name);


    return;
}//end of depositAccount()

void withdrawAccount(map<string, int> &account, map<int, set<string> > &balance, string name,int amount, int &errorCount)
{
    if ( account.find(name) == account.end() )
    {
        // not found
        errorCount++;
        return;
    }

    if((account[name]-amount)>=0)
    {
        if(balance[account[name]].size()==0)
        {
            map<int, set<string> >::iterator it;
            it=balance.find(account[name]);
            balance.erase (it);
        }

        account[name]=account[name]-amount;
    }
    else
    {
        errorCount++;
        return;
    }

    set<string>::iterator it;
    it=balance[account[name]].begin();
    balance[account[name]].insert (it, name);

    return;
}//end of withdrawAccount()

void printAccount(map<string, int> &account, map<int, set<string> > &balance, string name,int begin, int end, string &output)
{
    typedef map<int, set<string> >::const_iterator MapIterator;
    for (MapIterator iter = balance.begin(); iter != balance.end(); iter++)
    {
        cout << iter->first;
        typedef set<string>::const_iterator setIterator;
        for (setIterator set_iter = iter->second.begin(); set_iter != iter->second.end(); set_iter++)
            cout << " " << *set_iter;
        cout<<endl;
    }

    return;
}

int main()
{
    map<string, int> account;
    map<int, set<string> > balance;

    string output;
    int errorCount=0;
    char ch;
    cin>>ch;//input choice
    while(ch!='E')
    {
        switch(ch)
        {
            case 'O' :
            {
                string name;
                cin>>name;
                openAccount(account, balance, name, errorCount);
             }
                break;
            case 'C':
              {  string name;
                cin>>name;
                closeAccount(account, balance, name, errorCount);
                }
            break;
            case 'D' :
            {
                string name;
                int amount;
                cin>>name;
                cin>>amount;
                depositAccount(account, balance, name, amount, errorCount);
                }
            break;
            case 'W' :
            {
                string name;
                int amount;
                cin>>name;
                cin>>amount;
                withdrawAccount(account, balance, name, amount, errorCount);
                }
            break;
            case 'P' :
            {
                string name;
                int begin, end;
                cin>>name;
                cin>>begin;
                cin>>end;
                printAccount(account, balance, name, begin, end, output);
                }
            break;
            default:
                //invalid choice
            break;
        }//end of switch case
        cin>>ch;
    }//end of while()

    cout<<errorCount;
    return 0;
}//end of main()
