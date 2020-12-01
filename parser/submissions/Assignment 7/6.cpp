#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int> bal_of;
    map<int,set<string> > name_with_bal;

    bool cont=true;
    int illegal=0;
    char operation;
    string name;
    while(cont)
    {
        cin>>operation;
        switch(operation)
        {
            case 'O':
            {
                cin>>name;
                if(bal_of.find(name)==bal_of.end())
                {
                    bal_of[name]=0;
                    name_with_bal[0].insert(name);
                    /*if( name_with_bal[0].empty() )
                    {
                        set<string> S;
                        S.insert(name);
                        name_with_bal[0].insert(name);
                    }
                    else
                    {
                        //used instd of name.find(0)->second.insert
                        name_with_bal[0].insert(name);
                    }*/
                }
                else
                {
                    illegal++;
                }
                break;
            }
            case 'C':
            {
                cin>>name;
                /*if(bal_of.find(name)==bal_of.end())
                {//closing non existent account
                    illegal++;
                }*/
                if(bal_of[name]!=0)
                {
                    illegal++;
                }
                else
                {
                    int bal=bal_of[name];
                    bal_of.erase(name);
                    name_with_bal[bal].erase(name);
                    if(name_with_bal[bal].empty())
                        name_with_bal.erase(bal);
                }
                break;
            }
            case 'D':
            {
                int bal;
                cin>>name;
                cin>>bal;
                if(bal_of.find(name)==bal_of.end())
                {
                    illegal++;
                }
                else
                {
                    int prev_bal=bal_of[name];
                    name_with_bal[prev_bal].erase(name);
                    if(name_with_bal[prev_bal].empty())
                        name_with_bal.erase(prev_bal);
                    bal_of[name]+=bal;
                    name_with_bal[bal_of[name]].insert(name);
                }
                break;
            }
            case 'W':
            {
                int bal;
                cin>>name;
                cin>>bal;
                if(bal_of.find(name)==bal_of.end())
                {
                    illegal++;
                }
                else if(bal_of[name]<bal)
                {
                    illegal++;
                }
                else
                {
                    int prev_bal=bal_of[name];
                    name_with_bal[prev_bal].erase(name);
                    if(name_with_bal[prev_bal].empty())
                        name_with_bal.erase(prev_bal);
                    bal_of[name]-=bal;
                    name_with_bal[bal_of[name]].insert(name);
                }
                break;
            }
            case 'P':
            {
                int lower,upper;
                cin>>lower>>upper;
                map<int,set<string> >::iterator it,it_low,it_up;
                it_low=name_with_bal.lower_bound(lower);
                it_up=name_with_bal.upper_bound(upper);

                for(it=it_low;it!=it_up;++it)
                {
                    cout<<it->first<<" ";
                    set<string>::iterator it_set=(it->second).begin();
                    for(;it_set!=(it->second).end();++it_set)
                        cout<<*it_set<<" ";
                    cout<<endl;
                }
                break;
            }
            case 'E':
            {
                cont=false;
                break;
            }
        }
    }

    /*cout<<"\nDisplaying..\n";
    for(map<string,int>::iterator it=bal_of.begin();it!=bal_of.end();++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    for(map<int,set<string> >::iterator it=name_with_bal.begin();it!=name_with_bal.end();++it)
    {
        cout<<endl<<it->first<<endl;
        for(set<string>::iterator it1=(it->second).begin();it1!=(it->second).end();++it1)
            cout<<*it1<<" ";
    }*/
    cout<<illegal;
    return 0;
}
