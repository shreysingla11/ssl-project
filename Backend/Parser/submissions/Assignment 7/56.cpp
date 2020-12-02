#include<iostream>
using namespace std;
#include<set>
#include<map>
#include<cstring>
#include<string>
int main()
{
    char operation;
    int count=0;
    map<string,int>stringmap;
    map<int, set<string> >moneymap;
    while(true)
    {
        cin>>operation;
        if(operation=='E')
        {
            break;
        }
        if(operation=='O')
        {
            string name;
            cin>>name;
            map<string,int>::iterator it2;
            it2=stringmap.find(name);
            if(it2==stringmap.end())
            {
                stringmap[name]=0;
                moneymap[0].insert(name);
            }
            else
            {
                count++;
            }

        }
        if(operation=='C')
        {
            string name;
            cin>>name;
            if(stringmap[name]!=0)
            {
                count++;
            }
            else
            {
                stringmap.erase(name);
                if(moneymap[0].size()==1)
                {
                    moneymap[0].erase(name);
                    //if(moneymap[stringmap[name]].size()==0){moneymap.erase(stringmap[name])}
                    moneymap.erase(0);
                }
                else
                {
                    moneymap[0].erase(name);
                }
            }
        }
        if(operation=='D')
        {
            string name;
            cin>>name;
            int balance;
            cin>>balance;
            map<string,int>::iterator it2;
            it2=stringmap.find(name);
            if(it2==stringmap.end())
            {
                count++;
            }
            else
            {
                moneymap[stringmap[name]].erase(name);
                if(moneymap[stringmap[name]].size()==0){moneymap.erase(stringmap[name]);}
                stringmap[name]=balance;
                moneymap[balance].insert(name);
            }

        }
        if(operation=='W')
        {
            string name;
            cin>>name;
            int balance;
            cin>>balance;
            map<string,int>::iterator it2;
            it2=stringmap.find(name);
            if(it2==stringmap.end())
            {
                count++;
            }
            else
            {
                if(balance>stringmap[name])
                {
                    count++;
                }
                else
                {
                    moneymap[stringmap[name]].erase(name);
                    if(moneymap[stringmap[name]].size()==0){moneymap.erase(stringmap[name]);}
                    stringmap[name]=stringmap[name]-balance;
                    moneymap[stringmap[name]].insert(name);
                }

            }
        }
        if(operation=='P')
        {
            int lowerbound,upperbound;
            cin>>lowerbound;
            cin>>upperbound;
            map<int,set<string> >::iterator itlow,itup;
            itlow=moneymap.lower_bound(lowerbound);
            itup=moneymap.upper_bound(upperbound);
            for(map<int,set<string> >::iterator it3=itlow; it3!=itup; it3++)
            {
                cout << it3->first<<" ";
                set<string>::iterator ti2;
                for(ti2=it3->second.begin(); ti2!=it3->second.end(); ++ti2)
                {
                    cout <<*ti2<<" ";
                }
                cout<<endl;
            }

        }
    }
    cout<<count;
    /*map<string,int>::iterator it1;
    for (it1=stringmap.begin(); it1!=stringmap.end(); ++it1)
        cout << it1->first << " => " << it1->second<< '\n';
    map<int,set<string> >::iterator it;
    for (it=moneymap.begin(); it!=moneymap.end(); ++it)
    {
        set<string>::iterator ti;
        for(ti=it->second.begin(); ti!=it->second.end(); ++ti)
            cout << it->first << " => " << *ti<< '\n';
    }*/


}
