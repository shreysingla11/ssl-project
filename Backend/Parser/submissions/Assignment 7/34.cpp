#include<iostream>
#include<set>
#include<map>
using namespace std;

class Bank
{
    map<string,int> accName;
    map<int, set<string> > Bal;
public:
    int errors;
    Bank()
    {
        errors=0;
    }
    void Deposit (int money, string account)
    {
        if(accName.count(account)==0)
        {
            errors++;
            return;
        }
        Bal[accName[account]].erase(account);
        if(Bal[accName[account]].empty())
        {
            Bal.erase(accName[account]);
        }
        accName[account]+=money;
        Bal[accName[account]].insert(account);
    }
    void Withdraw (int money, string account)
    {
        if(accName.count(account)==0)
        {
            errors++;
            return;
        }
        if(money>accName[account])
        {
            errors++;
            return;
        }
        Bal[accName[account]].erase(account);
        if(Bal[accName[account]].empty())
        {
            Bal.erase(accName[account]);
        }
        accName[account]-=money;
        Bal[accName[account]].insert(account);
    }
    void Open (string account)
    {
        if(accName.count(account)>0)
        {
            errors++;
            return;
        }

        accName[account]=0;

        Bal[0].insert(account);
    }
    void Close (string account)
    {
        if(accName.count(account)==0)
        {
            errors++;
            return;
        }
        if(accName[account]!=0)
        {
            errors++;
            return;
        }
        accName.erase(account);
        Bal[0].erase(account);
        if(Bal[0].empty())
        {
            Bal.erase(0);
        }
    }
    void Print(int first,int second)
    {
//        int i=first;
//        for(int i=first; i<=second; i++)
//        {
//            if(Bal.count(i)!=0)
//            {
//                for(set<string>::iterator it=(Bal[i]).begin(); it!=(Bal[i]).end(); it++)
//                {
//                    cout<<*it<<" ";
//                }
//            }
//        }
//        cout<<i<<endl;
//        if(i==second+1)
//        {
//            return;
//        }
//        map<int, set<string> >::iterator itmain=Bal.find(i);
//
//        for(; itmain!=Bal.end()&&itmain->first<=second; itmain++)
//        {
//            cout<<itmain->first;
//            for(set<string>::iterator it=(itmain->second).begin(); it!=(itmain->second).end(); it++)
//            {
//                cout<<*it<<" ";
//            }
//            cout<<endl;
//        }

        map<int, set<string> >::iterator lower=Bal.lower_bound(first);
        map<int, set<string> >::iterator upper=Bal.upper_bound(second);
        for(map<int, set<string> >::iterator itmain=lower; itmain!=upper; itmain++)
        {
            cout<<itmain->first<<" ";
            for(set<string>::iterator it=(itmain->second).begin(); it!=(itmain->second).end(); it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }

    }
    void Printtemp()
    {
        cout<<errors;
        for(map<string,int>::iterator it=accName.begin(); it!=accName.end(); it++)
        {
            cout<<it->first<<" "<<it->second<<" ";
        }
        cout<<endl;
        map<int, set<string> >::iterator itmain=Bal.begin();
        for(; itmain!=Bal.end(); itmain++)
        {
            cout<<itmain->first;
            for(set<string>::iterator it=(itmain->second).begin(); it!=(itmain->second).end(); it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Bank myBank;
    while(true)
    {
        char s;
        cin>>s;
        if(s=='O')
        {
            string val;
            cin>>val;
            myBank.Open(val);
        }
        else if(s=='C')
        {
            string val;
            cin>>val;
            myBank.Close(val);
        }
        else if(s=='W')
        {
            int val2;
            string val1;
            cin>>val1>>val2;
            myBank.Withdraw(val2,val1);
        }
        else if(s=='D')
        {
            int val2;
            string val1;
            cin>>val1>>val2;
            myBank.Deposit(val2,val1);
        }
        else if(s=='P')
        {
            int val1,val2;
            cin>>val1>>val2;
            myBank.Print(val1,val2);
        }
        else if(s=='E')
        {
            cout<<myBank.errors;
            return 1;
        }
    }

}
