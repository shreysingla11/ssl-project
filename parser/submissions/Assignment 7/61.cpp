#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int main()
{
    map<string, int> balances;
    map<int, set<string> >common_balance;
    string name;
    int illegal_count=0;
    bool ender = false;
    char character;
    int amount;
    int previous_amount;
    int new_amount;
    int start_amount;
    int end_amount;
    int sizer;
    map<int,set<string> >::iterator current;

    while(ender==false)
    {
        cin>>character;
        switch(character)
        {


        case 'O' :
            cin >> name;
            if(balances.count(name) > 0)
            {
                illegal_count++;
            }
            else
            {
                balances[name] = 0;
                common_balance[0].insert(name);
            }
            break;


        case 'C' :
            cin>>name;
            //cout<<"Yo";
            if(balances.count(name) > 0)
            {
                if(balances[name] == 0)
                {
                    balances.erase(name);
                    common_balance[0].erase(name);
                    if(common_balance[0].empty())
                    {
                        common_balance.erase(0);
                    }
                }
                else
                {
                    illegal_count++;
                }
            }
            else
            {
                illegal_count++;
            }
            break;


        case 'D' :
            cin>>name;
            cin>>amount;
            if(amount < 0)
            {
                illegal_count++;
            }
            else
            {
                if(balances.count(name) > 0)
                {
                    previous_amount = balances[name];
                    new_amount = previous_amount + amount;
                    balances[name] = new_amount;
                    common_balance[previous_amount].erase(name);
                    common_balance[new_amount].insert(name);
                    if(common_balance[previous_amount].empty())
                    {
                        common_balance.erase(previous_amount);
                    }

                }
                else
                {
                    illegal_count++;
                }
            }
            break;


        case 'W' :
            cin>>name;
            cin>>amount;
            if(amount < 0)
            {
                illegal_count++;
            }
            else
            {
                if(balances.count(name) > 0)
                {
                    previous_amount = balances[name];
                    if(previous_amount < amount)
                    {
                        illegal_count++;
                        //cout<<"W"<<endl;
                    }
                    else
                    {
                        new_amount = previous_amount - amount;
                        balances[name] = new_amount;
                        common_balance[previous_amount].erase(name);
                        common_balance[new_amount].insert(name);
                        if(common_balance[previous_amount].empty())
                        {
                            common_balance.erase(previous_amount);
                        }
                    }
                }
                else
                {
                    illegal_count++;
                    //cout<<"W"<<endl;
                }
            }
            break;

        case 'P' :
            cin >> start_amount;
            cin >> end_amount;
            current = common_balance.lower_bound(start_amount);
            while(current != common_balance.upper_bound(end_amount))
            {
                cout << current -> first;
                for(set<string>::iterator i=(current -> second).begin(); i!=(current -> second).end(); i++)
                {
                    //cout<<"YO"<<endl;
                    cout<<" "<<(*i);
                }
                cout<<endl;
                //cout<<"check"<<endl;
                current++;
                //cout<<current -> first;
            }
            break;

        case 'E' :
            ender = true;
            //cout<<ender;
            break;
        }

    }

    cout << illegal_count<<endl;
    return 0;
}
