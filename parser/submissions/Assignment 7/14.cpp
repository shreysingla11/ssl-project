#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
class Data
{
    map < string , int > balance;
    map < int, set < string > > names;
public:
    int count;

    Data()
    {
        count=0;
        return;
    };
    void open(string s)
    {
        if ( balance.find(s) == balance.end() )
        {
            // not found
            balance[s]=0;
        names[0].insert(s);
        }
        else
        {
            // found
            count++;
            return;
        }
        return;
    };
    void close(string s)
    {
        if ( balance.find(s) == balance.end())
        {
            // not found
            count++;
            return;

        }
        else
        {
            // found
            if(balance[s]!=0)
            {
                count++;
                return;
            }
            else
            {
             names[balance[s]].erase(s);
             if(names[balance[s]].size()==0){
             names.erase(balance[s]);
             }
                balance.erase(s);
            }

        }
        return;
    };
    void deposit(string s,int a)
    {
         if ( balance.find(s) == balance.end() )
        {
            // not found
            count++;
            return;

        }
        else
        {
            names[balance[s]].erase(s);
            if(names[balance[s]].size()==0){
             names.erase(balance[s]);
             }
            balance[s]=balance[s]+a;
            names[balance[s]].insert(s);
        }


        return;
    };
    void withdraw(string s,int a)
    {
         if ( balance.find(s) == balance.end() )
        {
            // not found
            count++;
            return;

        }
        else
        {
            if(balance[s]<a){
            count++;
            return;
            }
            else{
             names[balance[s]].erase(s);
             if(names[balance[s]].size()==0){
             names.erase(balance[s]);
             }
            balance[s]=balance[s]-a;
            names[balance[s]].insert(s);
            }
        }
        return;
    };
    void print(int a,int b)
    {
for(map< int, set <string > >::const_iterator it = names.begin();
    it!=names.end(); ++it)
{
if((it->first)>b||(it->first)<a){
    break;
    }
    std::cout << it->first ;
    for( set <string> :: iterator sit= (it->second).begin(); sit!=(it->second).end(); sit++ )
    {
    cout <<" " << (*(sit));
    }
    cout<<endl;

}

        return;
    };
};
int main()
{
    Data d;
    char c;
    string s;
    int a;
    int b;
    //getline(cin,s);
    d.count=0;
    while(true)
    {
        cin>>c;

        ///cout<<s[0]<<"   "<<(s.substr(1,(s.size()-1)))<<endl;
        if(c=='O')
        {cin>>s;
            d.open(s);
        }
        if(c=='C')
        {cin>>s;
            d.close(s);
        }
        if(c=='W')
        {cin>>s>>a;

            d.withdraw(s,a);
        }
        if(c=='P')
        {cin>>a>>b;
            d.print(a,b);
        }
        if(c=='D')
        {
            cin>>s>>a;
            d.deposit(s,a);
        }
        if(c=='E'){
        cout<<d.count<<endl;
        break;
        }

    }

    return 0;
}
