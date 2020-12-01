#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
 vector<string>st;
    vector<string>::iterator it;
    string temp;
class Account
{
    map<string,int>namba;
    map<int, set<string> >banam;
    int noil;

public:
    Account()
    {
        noil=0;
    }
    void open (string name)
    {
        if(namba.count(name)==1)
        {
            noil++;
        }
        else
        {
            namba[name]=0;
            banam[0].insert(name);
        }
    }
    void close (string name)
    {
        if(namba[name]!=0)
        {
            noil++;
        }
        else
        {
            namba.erase(name);
            banam[0].erase(name);
        }
    }
    void deposit (string name,int k)
    {
        if(namba.count(name)!=1)
        {
            noil++;
        }
        else
        {
            banam[namba[name]].erase(name);
            namba[name]=namba[name]+k;
            banam[namba[name]].insert(name);
        }


    }
    void withdraw (string name,int k)
    {
        if(namba.count(name)!=1)
        {
            noil++;
        }
        else
        {
            if ( namba[name]<k)
            {
                noil++;
            }
            else
            {
                banam[namba[name]].erase(name);
                namba[name]=namba[name]-k;
                banam[namba[name]].insert(name);
            }
        }
    }
    void print(int l,int u)
    {
        map<int, set<string> >:: iterator itlow,ithigh,curr;
        itlow=banam.lower_bound(l);
        ithigh=banam.lower_bound(u);
        set<string> :: iterator currstr;
        for(curr=itlow; curr!=ithigh; curr++)
        {   stringstream convert;
            convert << curr->first;
            temp=convert.str();
            st.push_back(temp);
            for(currstr=(curr)->second.begin(); currstr!=curr->second.end(); currstr++)
            {
            it =st.end();
            it--;
            *(it)+=" ";
            *(it)+=*(currstr);

            }

        }
    }
    void illegal()
    {if (noil==0){}
     else {noil=noil-1;}
        cout<<noil;
    }
};
int main()
{
    Account a;
    char in;
    string name;
    int amount;
    int l;
    int u;
    while(cin)
    {
        cin>>in;
        if (in=='O')
        {
            cin>>name;
            a.open(name);
        }
        if (in=='C')
        {
            cin>>name;
            a.close(name);
        }
        if (in=='D')
        {
            cin>>name;
            cin>>amount;
            a.deposit(name,amount);
        }
        if (in=='W')
        {
            cin>>name;
            cin>>amount;
            a.withdraw(name,amount);
        }
        if (in=='P')
        {
            cin>>l;
            cin>>u;
            a.print(l,u);
        }
        if (in=='E')
        {
            break;
        }
    }
    for(vector<string>::iterator it=st.begin();it!=st.end();it++){
    cout<<*it<<endl;
    }
    a.illegal();
    return 0;
}
