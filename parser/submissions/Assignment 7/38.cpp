#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int illegal;
map<string,int> nameBalance;
map <int , set<string> > balanceName;
map<string,int> :: iterator it1;

void open(string name)
{
    it1 = nameBalance.find(name);
    if(it1==nameBalance.end())
    {
        nameBalance[name] = 0;
        balanceName[0].insert(name);
        //cout<< name<< " created!"<<endl;

    }
    else
    {
        illegal++;
        //cout<< name<< " already existts!"<<endl;
    }
    return;
}
void close(string name)
{
    it1 = nameBalance.find(name);
    if(it1==nameBalance.end())
    {
        illegal++;
        //cout<< name<< " doesn't existts!"<<endl;
    }
    else
    {
        if (nameBalance[name]!=0)
        {
            illegal++;
            //cout<< name<< " non zero balance"<<endl;
        }
        else
        {
            nameBalance.erase(name);
            balanceName[0].erase(name);
            if (balanceName[0].empty()) balanceName.erase(0);
           // cout<< name<< " erased!"<<endl;

        }
    }
}
void deposit(string name, int amount)
{
    it1 = nameBalance.find(name);
    if(it1==nameBalance.end())
    {
        illegal++;
        //cout<< name<< " DOESN'T existts!"<<endl;
    }
    else
    {
        balanceName[nameBalance[name]].erase(name);
        if (balanceName[nameBalance[name]].empty()) balanceName.erase(nameBalance[name]);
        nameBalance[name]+=amount;
        balanceName[nameBalance[name]].insert(name);


    }
}
void withdraw(string name, int amount)
{
    it1 = nameBalance.find(name);
    if(it1==nameBalance.end())
    {
        illegal++;
        //cout<< name<< " DOESN'T existts!"<<endl;
    }
    else
    {
        if (nameBalance[name]<amount)
        {
            illegal++;
            //cout<<name<<" insufficient funds!"<<endl;
        }
        else
        {
            balanceName[nameBalance[name]].erase(name);
            if (balanceName[nameBalance[name]].empty()) balanceName.erase(nameBalance[name]);
            nameBalance[name]-=amount;
            balanceName[nameBalance[name]].insert(name);
        }
    }
}
void print(int start , int end)
{   map <int , set<string> > :: iterator it2;
    set<string> :: iterator it3;
    map <int , set<string> > ::iterator itlow = balanceName.lower_bound(start);
    for (it2 = itlow ;it2!=balanceName.end();it2++){
            if (it2->first > end) break;
            cout<< it2->first;
            for (it3=it2->second.begin();it3!=it2->second.end();it3++){
            cout<<" "<<(*it3);
            }
            cout<<endl;
    }
}
void printMap1()
{
    for(it1 = nameBalance.begin(); it1!=nameBalance.end(); it1++)
    {
        cout<< it1->first <<" "<< it1->second<<endl;
    }
}
void printMap2(){
    map <int , set<string> > :: iterator it2;
    set<string> :: iterator it3;
    for (it2 = balanceName.begin() ;it2!=balanceName.end();it2++){
            cout<< it2->first;
            for (it3=it2->second.begin();it3!=it2->second.end();it3++){
            cout<<" "<<(*it3);
            }
            cout<<endl;
    }
}
int main()
{
    string name;
    int amount;
    int start;
    int end;
    char c;
    do
    {
        cin>>c;
        switch(c)
        {
        case 'O' :
            cin>>name;
            open(name);
            break;
        case 'C' :
            cin>>name;
            close(name);
            break;
        case 'D' :
            cin>>name;
            cin>>amount;
            deposit(name,amount);
            break;
        case 'W' :
            cin>>name;
            cin>>amount;
            withdraw(name,amount);
            break;
        case 'P' :
            cin>>start;
            cin>>end;
            print(start,end);
            break;
        }
    }
    while (c!='E');
    //printMap1();
    //printMap2();
    cout <<illegal<<endl;




    return 0;
}
