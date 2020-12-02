#include <iostream>
#include<map>
#include<string>
#include<set>

using namespace std;

int main()
{
    map<string,int> Accounts;
    map<int,set<string> > Balances;
    int error=0;
    char command;

    for( ; ; )
    {


        cin>>command;

        if(command=='O')
        {
            string name;
            cin>>name;
            //cout<<name;

            if(Accounts.find(name)==Accounts.end())
            {
                Accounts[name]=0;
                //set<string> temp;
                //temp.insert(name);
                Balances[0].insert(name);
                //cout<<Accounts[name];
                //cout<<*(Balances[0].begin());
            }

            else
            {
                error++;

            }
        }

        else if(command=='C')
        {
            string name;
            cin>>name;

            int balance;

            if(Accounts.find(name)==Accounts.end())
            {
                error++;
            }

            else
            {
                if(Accounts[name]!=0)
                {
                    error++;
                }

                balance=Accounts[name];

                Accounts.erase(name);

                Balances[balance].erase(name);
            }

        }

        else if(command=='D')
        {
            int balance;
            string name;
            cin>>name;
            int ammount;
            cin>>ammount;

            if(Accounts.find(name)==Accounts.end())
            {
                error++;
            }

            else
            {
                balance=Accounts[name];

                Accounts[name]+=ammount;
                Balances[balance].erase(name);
                    if(Balances[balance].empty())
                    {
                        Balances.erase(balance);
                    }
                balance+=ammount;

                if(Balances.find(balance)==Balances.end())
                {
                    set<string> newnames;
                    newnames.insert(name);
                    Balances[balance]=newnames;
                }

                else
                {
                    Balances[balance].insert(name);
                    balance-=ammount;

                }
            }
        }

        else if(command=='W')
        {
            int balance;
            string name;
            cin>>name;
            int ammount;
            cin>>ammount;

            if(Accounts.find(name)==Accounts.end())
            {
                error++;
            }

            else
            {
                if(Accounts[name]<ammount)
                {
                    error++;
                }

                else
                {
                    balance=Accounts[name];

                    Accounts[name]-=ammount;


                    Balances[balance].erase(name);
                        if(Balances[balance].empty())
                        {

                            Balances.erase(balance);
                        }
                    balance-=ammount;
                    if(Balances.find(balance)==Balances.end())
                    {
                        set<string> newnames;
                        newnames.insert(name);
                        Balances[balance]=newnames;
                    }

                    else
                    {
                        Balances[balance].insert(name);
                        balance+=ammount;

                    }
                }
            }
        }

        else if(command=='E')
        {
            cout<<error;
            break;
        }

        else if(command=='P')
        {
            int lowlim,uplim;
            cin>>lowlim;
            cin>>uplim;

            map<int,set<string> >::iterator poslowlim,posuplim;

            poslowlim=Balances.lower_bound(lowlim);
            posuplim=Balances.upper_bound(uplim);
            //cout<<*((poslowlim->second).begin());

            while(poslowlim!=posuplim)
            {
                //cout<<"ankur";
                cout<<poslowlim->first<<" ";
                for(set<string>::iterator it=(poslowlim->second).begin(); it!=(poslowlim->second).end(); ++it)
                {
                    cout<<*it<<" ";
                }
                cout<<endl;
                poslowlim++;
            }

        }
        //cout<<"loop khatam";
    }
    return 0;
}

