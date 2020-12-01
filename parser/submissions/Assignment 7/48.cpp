#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
    map<string,int>accountName;
    map<int, set<string> > balance;
    int count;
    count=0;

    while(true)
    {
        char a;
        cin>>a;
        if(a=='O')
        {
            string name;
            cin>>name;
            if((accountName.count(name)>0))
            {
                count++;
                continue;
            }
            else
            {
                accountName[name]=0;
                balance[0].insert(name);
            }
        }
        if(a=='C')
        {
            string name;
            cin>>name;
            if((accountName.count(name))==0)
            {
                count++;
                continue;
            }
            else if(accountName[name]==0)
            {
                accountName.erase(name);
                balance[0].erase(name);
            }
            else
            {
                count++;
                continue;
            }
            if(balance[0].empty())
            {
                balance.erase(0);
            }
        }
        if(a=='D')
        {
            string newName;
            int bal;
            cin>>newName>>bal;
            if((accountName.count(newName))==0)
            {
                count++;
                continue;
            }
            else
            {
                balance[accountName[newName]].erase(newName);
                if(balance[accountName[newName]].empty())
                {
                    balance.erase(accountName[newName]);
                }
                accountName[newName]+=bal;
                balance[accountName[newName]].insert(newName);

            }
        }
        if(a=='W')
        {
            string newName;
            int amt;
            cin>>newName>>amt;
            if((accountName.find(newName))==accountName.end())
            {
                count++;
                continue;
            }
            else
            {
                if(accountName[newName]>=amt)
                {

                    balance[accountName[newName]].erase(newName);
                    if(balance[accountName[newName]].empty())
                    {
                        balance.erase(accountName[newName]);
                    }
                    accountName[newName]-=amt;
                    balance[accountName[newName]].insert(newName);
                }
                else
                {
                    count++;
                    continue;
                }

            }
        }
        if(a=='P')
        {
           int bal1,bal2;
            cin>>bal1>>bal2;
//            for(int i=bal1; i<=bal2; i++)
//            {
//                if(balance.count(i)==1)
//                {
//                    cout<<i<<" ";
//                    for(set<string>::iterator it=balance[i].begin(); it!=balance[i].end(); it++)
//                    {
//                        cout<<*it<<" ";
//                    }
//                    cout<<endl;
//                }
//            }
            map<int, set<string> >::iterator lower=balance.lower_bound(bal1);
            map<int, set<string> >::iterator upper=balance.upper_bound(bal2);
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
        if(a=='E')
        {
            cout<<count;
            return 0;
        }
    }


}
