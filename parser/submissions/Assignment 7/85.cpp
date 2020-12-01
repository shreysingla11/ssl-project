#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

class Bank
{
    map<string,int> b;
    map<int,set<string> > v;
    int count;
public:
    Bank()
    {
        count=0;
    }


    void open(string s)
    {
        if(b.find(s)!=b.end())
        {
            count++;
            return;
        }
        b[s]=0;
        v[b[s]].insert(s);
//add to set
//check if already exist
//else open it.
        return;
    }


    void close(string s)
    {
        map<string,int>::iterator it=b.find(s);
        if(it==b.end())
        {
            count++;
            return;
        }
        else if(b[s]!=0)
        {
         count++;
         return ;
        }
        v[b[s]].erase(s);
        b.erase(it);
//check whether exists or not
//check balance is zero or not.
        ;
    }


    void deposit(string s,int a)
    {
        if(b.find(s)==b.end())
        {
            count++;
            return;
        }

        b[s]+=a;
        v[b[s]].insert(s);
        v[b[s]-a].erase(s);
//change set
//check wether exist or not

        return;
    }


    void withdraw(string s,int a)
    {
        if(b.find(s)==b.end())
        {
            count++;
            return;
        }
        if(b[s]>=a)
        {
            b[s]-=a;
            v[b[s]].insert(s);
            v[b[s]+a].erase(s);
            //change set
        }
        else count++;
//check whether exists or not
//check if sufficient amount is there.
        return;
    }



    void print(int start,int end)
    {
//check set
//check wether exists or not.
        for(int i=start; i<=end; i++)
        {
            if(!v[i].empty())
            {
                cout<<i<<" ";
                set<string>::iterator it=v[i].begin();
                while(it!=v[i].end())
                {
                    cout<<(*it)<<" ";
                    it++;
                }
                cout<<endl;
            }

        }
        return;
    }

    int retcount()
    {
        return count;
    }
};
int main()
{
    Bank b;
    string s,n;
    int a,c;
    cin>>s;
    while(true)
    {
        if(s=="O")
        {
            cin>>n;
            b.open(n);
        }
        else if(s=="P")
        {
            cin>>a;
            cin>>c;
            b.print(a,c);
        }
        else if(s=="D")
        {
            cin>>n;
            cin>>a;
            b.deposit(n,a);
        }
        else if(s=="W")
        {
            cin>>n;
            cin>>a;
            b.withdraw(n,a);
        }
        else if(s=="C")
        {
            cin>>n;
            b.close(n);
        }
        else if(s=="E")
        {
            cout<<b.retcount();
            break;
        }
          cin>>s;
    }

return 0;
}
