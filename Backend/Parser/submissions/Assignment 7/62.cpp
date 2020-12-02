#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    map<string,int> balances;
    map<int,set<string> > names;
    map<int,set<string> >::iterator iterl;
    map<int,set<string> >::iterator iteru;
    int illegal=0;
    while(true)
    {
    int i,j;
    char c;
    string s;
    cin>>c;
    if(c=='E')
    {
        cout<<illegal<<endl;
        return 0;
    }
    if(c=='O')
    {
        cin>>s;
        if(balances.find(s)==balances.end())
        {
            balances[s]=0;
            names[0].insert(s);
        }
        else
        {
            illegal++;
        }
    }
    if(c=='W')
    {
        cin>>s>>i;
        if(i!=0)
        {
            if(balances[s]>=i)
            {
            balances[s]=balances[s]-i;
            names[balances[s]].insert(s);
            names[balances[s]+i].erase(s);
            if(names[balances[s]+i].empty())
            {
                names.erase(balances[s]+i);
            }
            }
            else
            {
            illegal++;
            }
        }
    }
    if(c=='C')
    {
        cin>>s;
        if(balances[s]==0)
        {
        names[0].erase(s);
        balances.erase(s);
        }
        else
        {
            illegal++;
        }
    }
    if(c=='D')
    {
        cin>>s>>i;
        if(balances.find(s)==balances.end())
        {
            illegal++;
        }
        else
        {
            balances[s]=balances[s]+i;
            names[balances[s]].insert(s);
            names[balances[s]-i].erase(s);
            if(names[balances[s]-i].empty())
            {
                names.erase(balances[s]-i);
            }
            //cout<<balances[s]<<endl;
        }

    }
    if(c=='P')
    {
        cin>>i>>j;
        iterl=names.lower_bound(i);
        iteru=names.upper_bound(j);
        map<int,set<string> >::iterator iter;
        for(iter=iterl;iter!=iteru;iter++)
        {
            set<string>::iterator xyzs;
            xyzs=iter->second.begin();
            cout<<iter->first<<" ";
            for(xyzs;xyzs!=iter->second.end();xyzs++)
            {
                cout<<*xyzs<<" ";
            }
            cout<<endl;
        }
    }
    }
}


