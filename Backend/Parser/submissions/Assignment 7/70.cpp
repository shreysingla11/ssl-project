#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int> a;
    map<int, set<string> > b;
    int errors=0;
    char input;
    while(true)
    {
        cin>>input;
        switch(input)
        {
        case 'O' :
        {
            string temp;
            cin>>temp;
            if(a.count(temp)>0)
            {
                errors++;
                //cout<<"a"<<endl;
            }
            else
            {
                a[temp]=0;
                b[0].insert(temp);
                //cout<<"b"<<endl;
            }
            break;
        }
        case 'D' :
        {
            string account;
            int money;
            cin>>account;
            cin>>money;
            if(a.count(account)==0)
            {
                //cout<<"c"<<endl;
                errors++;
            }
            else
            {
                int balance;
                balance=a[account];
                b[balance].erase(account);
                if(b[balance].size()==0)
                {
                    b.erase(balance);
                }
                balance=balance+money;
                a[account]=balance;
                b[balance].insert(account);
                //cout<<"d"<<endl;
            }
            break;
        }
        case 'W' :
        {
            string account;
            int money;
            cin>>account;
            cin>>money;
            if(a.count(account)==0)
            {
                //cout<<"e"<<endl;
                errors++;
            }
            else
            {
                int balance;
                balance=a[account];
                balance=balance-money;
                if(balance<0)
                {
                    //cout<<"f"<<endl;
                    errors++;
                }

                else
                {
                    //cout<<"g"<<endl;
                    b[a[account]].erase(account);
                    if(b[a[account]].size()==0)
                    {
                        b.erase(a[account]);
                    }
                    a[account]=balance;
                    b[balance].insert(account);
                }
            }
            break;
        }
        case 'P' :
        {
            int low,high;
            cin>>low>>high;
            map<int, set<string> >::iterator m;
            map<int, set<string> >::iterator n;
            m=b.lower_bound(low);
            n=b.upper_bound(high);
            for(map<int, set<string> >::iterator c=m; c!=n ; c++ )
            {
                int val;
                val=c->first;
                cout<<val<<" ";
                set<string> accounts;
                accounts=c->second;
                for(set<string>::iterator iter=accounts.begin(); iter!=accounts.end(); iter++ )
                {
                    cout<<*iter<<" ";
                }
                cout<<endl;
            }
            break;
        }
        case 'C' :
        {
            string account;
            cin>>account;
            if(a.count(account)==0 || a[account] > 0)
            {
                //out<<"h"<<endl;
                errors++;
            }
            else
            {
                //cout<<"i"<<endl;
                b[a[account]].erase(account);
                if(b[a[account]].size()==0)
                {
                    b.erase(a[account]);
                }
                a.erase(account);
            }
            break;
        }
        }
        if(input=='E')
        {
            break;
        }

    }
    cout<<errors<<endl;
    return 0;

}

