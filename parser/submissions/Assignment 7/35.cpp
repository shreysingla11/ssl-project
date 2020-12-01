#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

class bank
{
    map<string,int> acc;
    map<int, set<string> > balacc;
    set<string> N;
    map<int, set<string> >::iterator itb;
    set<string>::iterator itstr;
    int balc;
    public:
    bank()
    {
        N.clear();
    }
    bool open(string name)
    {
        if(acc.find(name)!=acc.end())return 1;
        acc[name]=0;
        if(balacc.find(0)==balacc.end())balacc[0]=N;
        balacc[0].insert(name);
        return 0;
    }
    bool close(string name)
    {
        if(acc.find(name)==acc.end())return 1;
        if(acc[name]!=0)return 1;
        acc.erase(name);
        balacc[0].erase(name);
        if(balacc[0].empty())balacc.erase(0);
        return 0;
    }
    bool deposit(string name,int bal)
    {
        if(acc.find(name)==acc.end())return 1;
        balc=acc[name];
        acc[name]+=bal;
        if(balacc.find(balc+bal)==balacc.end())balacc[balc+bal]=N;
        balacc[balc+bal].insert(name);
        balacc[balc].erase(name);
        if(balacc[balc].empty())balacc.erase(balc);
        return 0;
    }
    bool withdraw(string name,int bal)
    {
        if(acc.find(name)==acc.end())return 1;
        balc=acc[name];
        if(balc<bal)return 1;
        acc[name]-=bal;
        if(balacc.find(balc-bal)==balacc.end())balacc[balc-bal]=N;
        balacc[balc-bal].insert(name);
        balacc[balc].erase(name);
        if(balacc[balc].empty())balacc.erase(balc);
        return 0;
    }
    void print(int bal1,int bal2)
    {
        itb=balacc.begin();
        while(itb->first<bal1&&itb!=balacc.end())++itb;
        if(itb==balacc.end())return;
        while(itb->first<=bal2&&itb!=balacc.end())
        {
            cout<<itb->first;
            itstr=(itb->second).begin();
            while(itstr!=(itb->second).end())
            {
                cout<<" "<<*itstr;
                ++itstr;
            }
            cout<<endl;
            ++itb;
        }
    }
};

int main()
{
    bank b1;
    char inp;
    string name;
    int bal,ill=0;
    while(true)
    {
        cin>>inp;
        if(inp=='E')
        {
            cout<<ill;
            break;
        }
        switch(inp)
        {
            case 'O':cin>>name;ill+=b1.open(name);break;
            case 'C':cin>>name;ill+=b1.close(name);break;
            case 'D':cin>>name>>bal;ill+=b1.deposit(name,bal);break;
            case 'W':cin>>name>>bal;ill+=b1.withdraw(name,bal);break;
            case 'P':int bal1,bal2;cin>>bal1>>bal2;b1.print(bal1,bal2);break;
        }
    }
    return 0;
}
