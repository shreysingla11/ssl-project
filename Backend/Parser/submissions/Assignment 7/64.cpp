#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

int main()
{
    map<string,int> ind_balance;
    map<int,set<string> > grp_balance;
    string name;
    int amount,prev_amount;
    int range_begin,range_end;
    map<string,int> ::iterator it;
    map<int,set<string> >::iterator grp_it,begin_it,end_it;
    set<string>::iterator set_it;
    set<string> temp_set;
    int illegal=0;
    char c;
    bool end1=false;
    while(!end1)
    {
        cin>>c;
        switch(c)
        {
            case 'O':
                cin>>name;
                it=ind_balance.find(name);
                grp_it=grp_balance.find(0);
                if(it==ind_balance.end())
                {
                    ind_balance[name]=0;
                    grp_balance[0].insert(name);
                }
                else illegal++;
                break;
            case 'C':
                cin>>name;
                it=ind_balance.find(name);
                if(it!=ind_balance.end())
                {
                    if(ind_balance[name]==0)
                    {
                        grp_balance[0].erase(name);
                        if(grp_balance[0].empty())
                            grp_balance.erase(0);
                        ind_balance.erase(name);
                    }
                    else illegal++;
                }
                else illegal++;
                break;
            case 'D':
                cin>>name;
                cin>>amount;
                it=ind_balance.find(name);
                if(it!=ind_balance.end() && amount>=0)
                {
                    prev_amount=ind_balance[name];
                    grp_balance[prev_amount].erase(name);
                    if(grp_balance[prev_amount].empty())
                        grp_balance.erase(prev_amount);
                    ind_balance[name]+=amount;
                    grp_balance[amount+prev_amount].insert(name);
                }
                else illegal++;
                break;
            case 'W':
                cin>>name;
                cin>>amount;
                it=ind_balance.find(name);
                if(it!=ind_balance.end() && amount>=0)
                {
                    prev_amount=ind_balance[name];
                    if(prev_amount>=amount)
                    {
                        grp_balance[prev_amount].erase(name);
                        if(grp_balance[prev_amount].empty())
                            grp_balance.erase(prev_amount);
                        ind_balance[name]-=amount;
                        grp_balance[prev_amount-amount].insert(name);
                    }
                    else illegal++;
                }
                else illegal++;
                break;
            case 'P':
                cin>>range_begin>>range_end;
                if(range_begin<=range_end)
                {
                    begin_it=grp_balance.lower_bound(range_begin);
                    end_it=grp_balance.upper_bound(range_end);
                    while(begin_it!=end_it)
                    {
                        cout<<begin_it -> first<<" ";
                        set_it=(begin_it->second).begin();
                        while(set_it!=(begin_it->second).end())
                        {
                            cout<<(*set_it)<<" ";
                            set_it++;
                        }
                        cout<<endl;
                        begin_it++;
                    }
                }
                else illegal++;
                break;
            case 'E': end1=true; break;
        }
    }

    //Output
    cout<<illegal<<endl;

    return 0;
}
