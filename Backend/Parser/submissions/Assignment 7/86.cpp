#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
int main()
{
    map<string,int>accts;
    map<int, set<string> >bal;
    int illcalls=0;
    char input;
    cin>>input;
    while(input!='E')
    {
        if(input=='O')
        {
            string name;
            cin>>name;
            bool check;
            check=(accts.insert(pair<string,int>(name,0))).second;
            if(!check)
            {
                illcalls++;
                cin>>input;
                continue;
            }
            map<int, set<string> >::iterator endit=bal.end();
            map<int, set<string> >::iterator it=bal.find(0);
            if(it!=endit)
            {
                (it->second).insert(name);
            }
            else
            {
                (bal[0]).insert(name);
            }
        }
        if(input=='C')
        {
            string name;
            cin>>name;
            map<string,int>::iterator endit=accts.end();
            map<string,int>::iterator it=accts.find(name);
            if(it!=endit)
            {
                if(it->second==0)
                {
                    bal[0].erase(name);
                    if(bal[0].empty())
                    {
                        bal.erase(0);
                    }
                    accts.erase(it);
                }
                else
                {
                    illcalls++;
                    cin>>input;
                    continue;
                }
            }
            else
            {
                illcalls++;
                cin>>input;
                continue;
            }
        }
        if(input=='D')
        {
            string name;
            cin>>name;
            int dbal;
            cin>>dbal;
            map<string,int>::iterator endit=accts.end();
            map<string,int>::iterator it=accts.find(name);
            if(it!=endit)
            {
                bal[it->second].erase(name);
                if(bal[it->second].empty())
                {
                    bal.erase(it->second);
                }
                (it->second)+=dbal;
                map<int, set<string> >::iterator sendit=bal.end();
                map<int, set<string> >::iterator sit=bal.find(it->second);
                if(sit!=sendit)
                {
                    (sit->second).insert(name);
                }
                else
                {
                    (bal[it->second]).insert(name);
                }

            }
            else
            {
                illcalls++;
                cin>>input;
                continue;
            }
        }
        if(input=='W')
        {
            string name;
            cin>>name;
            int wbal;
            cin>>wbal;
            map<string,int>::iterator endit=accts.end();
            map<string,int>::iterator it=accts.find(name);
            if(it!=endit)
            {
                if((it->second)<wbal)
                {
                    illcalls++;
                    cin>>input;
                    continue;
                }
                bal[it->second].erase(name);
                if(bal[it->second].empty())
                {
                    bal.erase(it->second);
                }
                (it->second)-=wbal;
                map<int, set<string> >::iterator sendit=bal.end();
                map<int, set<string> >::iterator sit=bal.find(it->second);
                if(sit!=sendit)
                {
                    (sit->second).insert(name);
                }
                else
                {
                    set<string>dummyset;
                    dummyset.insert(name);
                    bal[it->second]=dummyset;
                }

            }
            else
            {
                illcalls++;
                cin>>input;
                continue;
            }
        }
        if(input=='P')
        {
            int low,high;
            cin>>low;
            cin>>high;
            if(bal.empty())
            {
                cin>>input;
                continue;
            }
            map<int, set<string> >::iterator lastit=bal.upper_bound(high);
            map<int, set<string> >::iterator startit=bal.begin();
            if((startit->first)>low)
            {
                for(map<int, set<string> >::iterator lit=bal.begin();lit!=lastit  ;lit++)
                {
                    cout<<(lit->first)<<" ";
                    for(set<string>::iterator setit=(lit->second).begin();setit!=(lit->second).end();setit++)
                    {
                        cout<<*setit<<" ";
                    }
                    cout<<endl;
                }
            }
            else
            {
                map<int, set<string> >::iterator firstit=bal.lower_bound(low);
                if((firstit->first)<low)
                {
                    firstit++;
                }
                for(map<int, set<string> >::iterator lit=firstit; lit!=lastit ;lit++)
                {
                    cout<<(lit->first)<<" ";
                    for(set<string>::iterator setit=(lit->second).begin();setit!=(lit->second).end();setit++)
                    {
                        cout<<(*setit)<<" ";
                    }
                    cout<<endl;
                }
            }

        }
        cin>>input;

    }
    cout<<illcalls<<endl;
    return 0;


}
