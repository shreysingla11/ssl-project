#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()
{
    map<string,int> balance;
    map<int, set<string> > acnames;
    int i=0;
    while(1)
    {
        string s;
        //getline(cin,s);
        char c;
        cin>>c;

        if(c=='E')
        {
            break;
        }

        if(c=='O')
        {
            cin>>s;
            //search in set of strings if present false and i++
            //else should enter in map
            if(balance.find(s)==balance.end())
            {
                balance[s]=0;
                acnames[0].insert(s);
            }
            else
            {
                i++;
            }
            //and update in acnames[0];
        }
        if(c=='C')
        {
            cin>>s;
            //balance of c is!0 then i++;
            //else erase from map;
            // remove element from sets with balance 0;
            if(balance.find(s)==balance.end())
            {
                i++;
            }
            else
            {
                if(balance[s]==0)
                {
                    acnames[balance[s]].erase(s);
                    balance.erase (s);
                }
                else
                {
                    i++;
                }
            }

        }
        if(c=='D')
        {
            int money;
            cin>>s;
            cin>>money;
            //same condition as in open
            //if present add to balance
            // and update in set of strings
            if(balance.find(s)==balance.end())
            {
                i++;
            }
            else
            {
                acnames[balance[s]].erase(s);
                balance[s]=balance[s]+money;
                acnames[balance[s]].insert(s);
            }
        }
        if(c=='W')
        {
            int money;
            cin>>s;
            cin>>money;
            //same condition as in open
            //if present subtract if amount >present  to balance
            // and update in set of strings
            if(balance.find(s)==balance.end())
            {
                i++;
            }
            else
            {
                if(balance[s]<money)
                {
                    i++;
                }
                else
                {
                    acnames[balance[s]].erase(s);
                    balance[s]=balance[s]-money;
                    acnames[balance[s]].insert(s);
                }
            }
        }
        if(c=='P')
        {
            int m,n;
            cin>>m;
            cin>>n;
            // should take two arguments
            //print all the values in the elements of set
            for(int j=m; j<=n; j++)
            {
                if(!acnames[j].empty())
                {
                    cout<<j<<" ";
                    set<string>::iterator it=acnames[j].begin();
                    while(it!=acnames[j].end())
                    {
                        cout<<(*it)<<" ";
                        it++;
                    }
                    cout<<endl;
                }

            }

        }
    }
    cout<<i;

    return 0;
}


