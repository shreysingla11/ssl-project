#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

class Bank
{
    map<string, int> balance;
    map< int, set<string> > holders;
   public:
    int cnt;
    Bank()
    {
        cnt=0;
    }
    void Open(string s)
    {
        if(balance.count(s)==0)
        {
            balance[s]=0;
            holders[0].insert(s);
        }
        else
            cnt++;
    }
    void Deposit( string s, int bal)
    {
        if(balance.count(s)>0)
        {
            holders[balance[s]].erase(s);
            if(holders[balance[s]].empty())
                holders.erase(balance[s]);
            balance[s]+=bal;
            holders[balance[s]].insert(s);
        }
        else
            cnt++;
    }
    void Withdraw(string s, int bal)
    {
        if(balance.count(s)>0)
        {
            if(balance[s]>=bal)
            {
                holders[balance[s]].erase(s);
                if(holders[balance[s]].empty())
                    holders.erase(balance[s]);
                balance[s]-=bal;
                holders[balance[s]].insert(s);
            }
            else
                cnt++;
        }
        else
            cnt++;
    }
    void Close(string s)
    {
        if(balance.count(s)>0)
        {
            if(balance[s]==0)
            {
              balance.erase(s);
              holders[0].erase(s);
              if(holders[0].empty())
                holders.erase(0);
            }
            else
              cnt++;
        }
        else
            cnt++;
    }
    void Print(int lower, int upper)
    {
        map<int, set<string> >::iterator up_it;

        up_it=holders.find(lower);
        if(up_it==holders.end())
        {
            up_it=holders.upper_bound(lower);
        }

        while(up_it!=holders.end())
        {
            const int bal=(*up_it).first;
            if(bal>upper)
                break;
            else
            {   cout<<bal<<" ";
                set<string>::iterator it;
                set<string>::iterator end_it=((*up_it).second).end();
                for(it=((*up_it).second).begin();it!=end_it; ++it)
                {
                    cout<<(*it)<<" ";
                }
                cout<<endl;
            }
            up_it=holders.upper_bound(bal);
        }
    }
};

int main()
{
    char ch='y';
    string s;
    int bal, lower, upper;
    Bank B;
    while(ch!='E')
    {
        cin>>ch;
        switch(ch)
        {
            case 'D': cin>>s;
                      cin>>bal;
                      B.Deposit(s,bal);
                      break;
            case 'O': cin>>s;
                      B.Open(s);
                      break;
            case 'W': cin>>s;
                      cin>>bal;
                      B.Withdraw(s,bal);
                      break;
            case 'C': cin>>s;
                      B.Close(s);
                      break;
            case 'P': cin>> lower;
                      cin>>upper;
                      B.Print(lower,upper);
                      break;
        }

    }
    cout<<B.cnt<<endl;
    return 0;
}
