#include <iostream>
#include <map>
#include <set>
using namespace std;
class bank
{
public:
    int illegal;
    map<string,int> bal;
    map<int,set<string> > print;
    void start()
    {
        illegal=0;
    }
    void open(string s)
    {
        if(!(bal.find(s)==bal.end()))
        {
            illegal++;
        }
        else
        {
            bal[s]=0;
            print[0].insert(s);
        }
    }
    void close(string s)
    {
        if(!(bal.find(s)==bal.end()))
        {
            if(bal[s]==0)
            {
                print[0].erase(s);
                bal.erase(s);
            }
            else
            {
                illegal++;
            }
        }
        else
        {
            illegal++;
        }
    }
    void deposit(string s,int x)
    {
        if(!(bal.find(s)==bal.end()))
        {
            print[bal[s]].erase(s);
            bal[s]=bal[s]+x;
            print[bal[s]].insert(s);
        }
        else
        {
            illegal++;
        }

    }
    void withdraw(string s,int x)
    {
        if(!(bal.find(s)==bal.end()))
        {
            if(bal[s]>=x)
            {
                print[bal[s]].erase(s);
                bal[s]=bal[s]-x;
                print[bal[s]].insert(s);
            }
            else
            {
                illegal++;
            }

        }
        else
        {
            illegal++;
        }
    }
    void pri(int x,int y)
    {
        for(int i=x; i<=y; i++)
        {
            if(print[i].empty()) {}
            else
            {
                cout<<i<<" ";
                set<string>::iterator it;
                it=print[i].begin();
                for(; it!=print[i].end(); it++)
                {
                    cout<<*it<<" ";
                }
                cout<<endl;
            }
        }
    }
};
int main()
{
    bank a;
    char c;
    a.start();
    while(true)
    {
        cin>>c;
        string s;
        if(c=='D')
        {
            cin>>s;
            int x;
            cin>>x;
            a.deposit(s,x);
        }
        if(c=='W')
        {
            cin>>s;
            int x;
            cin>>x;
            a.withdraw(s,x);
        }
        if(c=='O')
        {
            cin>>s;
            a.open(s);
        }
        if(c=='C')
        {
            cin>>s;
            a.close(s);
        }
        if(c=='P')
        {
            int x,y;
            cin>>x>>y;
            a.pri(x,y);
        }
        if(c=='E')
        {
            break;
        }

    }
    cout<<a.illegal;
    return 0;
}
