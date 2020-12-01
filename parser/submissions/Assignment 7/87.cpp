#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <string>

using namespace std;

class bank
{
private:
    map<string,int> names;
    map<int, set<string>> balance;
    pair<map<string,int>::iterator,bool> ret1;
    set<string> setstr;

public:
        int inv_count = 0;
    bool openac(string s)
    {
        ret1 = names.insert( pair<string,int>(s,0) );
        if(ret1.second)
        {
            setstr = balance[0];
            setstr.insert(s);
            balance[0] = setstr;
        }
        else
        {
            inv_count++;
        }

        return ret1.second;
    }

    void closeac(string s)
    {
        if(names.count(s) <= 0 )
        {
            inv_count++;
            return;
        }
        else
        {
            if(names[s] != 0)
            {
                inv_count++;
                return;
            }
            names.erase(s);
            balance[0].erase(s);
        }
        return;
    }

    void deposit(string s , int amount)
    {
        int newbal;
        if(names.count(s) <= 0 )
        {
            inv_count++;
            return;
        }
        if (amount != 0)
        {
            balance[names[s]].erase(s);

            if(balance[names[s]].empty())
            {
                balance.erase(names[s]);
            }

            newbal = names[s] + amount;
            names[s] = newbal;

            setstr = balance[newbal];
            setstr.insert(s);
            balance[newbal] = setstr;
        }

    }

    void withdraw (string s , int amount)
    {
        int newbal;
        if(names.count(s) <= 0 )
        {
            inv_count++;
            return;
        }

        if(amount > names[s])
        {
            inv_count++;
            return;
        }
        else
        {
            balance[names[s]].erase(s);

            if(balance[names[s]].empty())
            {
                balance.erase(names[s]);
            }

            newbal = names[s] - amount;
            names[s] = newbal;

            setstr = balance[newbal];
            setstr.insert(s);
            balance[newbal] = setstr;
        }

    }

    void print(int a , int b)
    {
        map<int, set<string>>::iterator mit,it1,it2;
        it1 = balance.lower_bound(a);
        it2 = balance.upper_bound(b);
        for(mit = it1 ; mit != it2; ++mit)
        {
            cout <<endl<< mit->first << " ";
            copy(mit->second.begin(),mit->second.end(), ostream_iterator<string>(cout, " "));

        }
        cout<<endl;
    }

};

int main()
{
    bank mybank;
    vector<pair<int,int>> pr;
    string s;
    string s2;
    char x ;
    char y[100];
    int am = -1;
    int am2 = -10;

    while(true)
    {
        getline (cin,s);
        sscanf(s.c_str(),"%c %s %d",&x,y,&am);

        s2.assign(y);

        if(x == 'E')
        {
            break;
        }
        switch(x)
        {
        case 'O' :
            mybank.openac(s2);
            break;

        case 'C' :
            mybank.closeac(s2);
            break;

        case 'D' :
            mybank.deposit(s2,am);
            break;

        case 'W' :
            mybank.withdraw(s2,am);
            break;

        case 'P' :
            am2 = stoi(s2);
            pr.push_back(pair<int,int>(am2,am));

        }

    }
    vector<pair<int,int>>::iterator prit;
    for (prit = pr.begin(); prit != pr.end(); ++prit)
    {
        mybank.print(prit->first,prit->second);
    }
    cout<<mybank.inv_count<<endl;

    return 0;

}
