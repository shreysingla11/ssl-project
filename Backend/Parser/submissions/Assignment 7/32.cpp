#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class bank
{
private :

    map<string,int> account ;
    map<int, set<string> > bal;
    int ill;

public:
    bank ()
    {
        account.clear();
        bal.clear();
        ill=0;
    }
    void open(string name)
    {
        //if account name doesnt exist
        if (account.find(name)==account.end())
        {
            account[name]=0;
            bal[0].insert(name);
        }
        //else ill++
        else
        {
            ill++;
        }
        return;
    }

    void close(string name)
    {
        //if account exists and balance is zero
        if ((account.find(name)!=account.end())&&(account[name]==0))
        {
            bal[account[name]].erase(name);
            account.erase(name);
        }
        //else ill++
        else
        {
            ill++;
        }
        return;
    }

    void deposit(string name, int amt)
    {
        //if account exists
        if (account.find(name)!=account.end())
        {
            bal[account[name]].erase(name);
            account[name]=account[name]+amt;
            bal[account[name]].insert(name);
        }
        //else ill++
        else
        {
            ill++;
        }
        return;
    }

    void withdraw(string name, int amt)
    {
        //if account exists and balance>=amt
        if ((account.find(name)!=account.end())&&(account[name]>=amt))
        {
            bal[account[name]].erase(name);
            account[name]=account[name]-amt;
            bal[account[name]].insert(name);
        }
        //else ill++
        else
        {
            ill++;
        }
        return;
    }

    void print(int amt1, int amt2)
    {

        map < int, set <string> > :: iterator it1,i1,i2;
        set < string > :: iterator it2;


        i1=bal.end();
        for( map< int, set<string> >::iterator it=bal.begin(); it!= bal.end(); it++ )
        {
            if(it->first >= amt1)
            {
                i1=it;
                break;
            }
        }

        i2=bal.end();
        for( map< int, set<string> >::iterator it=bal.begin(); it!= bal.end(); it++ )
        {
            if(it->first > amt2)
            {
                i2=it;
                break;
            }
            //else if(it->first == maxRange){maxIterator=it; break;}
        }

        it1=i1;

        while (it1!=i2)
        {
            //if bal[temp] exists
            it2=((*it1).second).begin();
            cout<<(*it1).first;
            while (it2!=((*it1).second).end())
            {
                cout<<" "<<*(it2);
                it2++;
            }
            cout<<endl;
            it1++;
        }

        return;
    }

    int get_ill()
    {
        return ill;
    }

};

int main()
{
    char oprn='#';
    string name;
    int amt=0,amt1=0,amt2=0, i=0;
    bank B;

    while (true)
    {
        cin>>oprn;
        if (oprn=='E')
        {
            break;
        }
        if (oprn=='O')
        {
            cin>>name;
            B.open(name);
        }
        if (oprn=='C')
        {
            cin>>name;
            B.close(name);
        }
        if (oprn=='D')
        {
            cin>>name;
            cin>>amt;
            B.deposit(name,amt);
        }
        if (oprn=='W')
        {
            cin>>name;
            cin>>amt;
            B.withdraw(name,amt);
        }
        if (oprn=='P')
        {
            cin>>amt1;
            cin>>amt2;
            B.print(amt1, amt2);
        }
    }

    cout<<B.get_ill();
    return 0;
}
