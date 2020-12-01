#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
class bank
{
    map<string,int> balance;
    map<int, set<string> > ranger;
    int illegal=0;
public:
    void create(string accname)
    {
        if(balance.find(accname)!=balance.end())
        {
            ++illegal;
            return;
        }
        balance[accname]=0;
        ranger[0].insert(accname);
        return;
    }
    void withdraw(string accname, int amount)
    {
        if(balance.find(accname)==balance.end())
        {
            ++illegal;
            return;
        }
        if(amount>balance[accname])
        {
            ++illegal;
            return;
        }
        ranger[balance[accname]].erase(accname);
        balance[accname]-=amount;
        ranger[balance[accname]].insert(accname);
        return;
    }
    void close(string accname)
    {
        if(balance.find(accname)==balance.end())
        {
            ++illegal;
            return;
        }
        if(balance[accname]!=0)
        {
            ++illegal;
            return;
        }
        ranger[balance[accname]].erase(accname);
        balance.erase(accname);
        return;
    }
    void deposit(string accname, int amount)
    {
        if(balance.find(accname)==balance.end())
        {
            ++illegal;
            return;
        }
        ranger[balance[accname]].erase(accname);
        balance[accname]+=amount;
        ranger[balance[accname]].insert(accname);
        return;
    }
    void printer(int l1, int l2)
    {
        set<string>::iterator roll;
        int i=l1;
        for(i; i<(l2+1); i++)
        {
            if(ranger[i].empty())
            {
                continue;
            }
            else
            {
                cout<<i<<" ";
                roll=ranger[i].begin();
            }
            for(roll; roll!=ranger[i].end(); roll++)
            {
                cout<<*roll<<" ";
            }
            if(!ranger[i].empty())
            {
                cout<<endl;
            }
        }
        return;
    }
    void printlegal()
    {
        cout<<illegal<<endl;
        return;
    }

};
int main()
{
    bank sbi;
    string operate;
    string accname;
    int amount;
    int l1;
    int l2;
    for(;;)
    {
        cin>>operate;
        if(operate=="O")
        {
            cin>>accname;
            sbi.create(accname);
        }
        if(operate=="W")
        {
            cin>>accname;
            cin>>amount;
            sbi.withdraw(accname,amount);
        }
        if(operate=="C")
        {
            cin>>accname;
            sbi.close(accname);
        }
        if(operate=="D")
        {
            cin>>accname;
            cin>>amount;
            sbi.deposit(accname,amount);
        }
        if(operate=="P")
        {
            cin>>l1;
            cin>>l2;
            sbi.printer(l1,l2);
        }
        if(operate=="E")
        {
            break;
        }
    }
    sbi.printlegal();
    return 0;
}
