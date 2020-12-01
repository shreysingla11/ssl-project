#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int> a;
    map<int, set<string> > b;
    string name;//o,c
    set<string> newset;//o,p,c
    map<int, set<string> > :: iterator mini;//p
    map<int, set<string> > :: iterator maxi;//p
    set<string> :: iterator strite;//p
    int initamt;//d
    int amt; //w,d
    int small;//p
    int large;//p
    int illegal = 0;
    while(true)
    {
        char op;
        cin>>op;
        if(op == 'E' || op == 'e')
        {
            break;
        }
        switch(op)
        {
        case 'O' :
        {

            //getline(cin,name);
            cin>>name;
            if(a.find(name) == a.end())
            {
                a[name] = 0;
                if(b.find(0) == b.end())
                {
                    newset.insert(name);
                    b[0] = newset;
                }
                else
                {
                    newset = b[0];
                    newset.insert(name);
                    b[0] = newset;
                }
            }
            else
            {
                illegal++;
                break;
            }
            break;
        }
        case 'C' :
        {

            cin>>name;
            if(a.find(name) == a.end())
            {
                illegal++;
                break;
            }
            else
            {
                if(a[name] != 0)
                {
                    illegal++;
                    break;
                }
                else
                {
                    //cout<<"pook"<<endl;
                    a.erase(name);
                    newset = b[0];
                    if(newset.size() == 1)
                    {
                        //cout<<"lamja"<<endl;
                        b.erase(0);
                    }
                    else
                    {
                        newset.erase(name);
                        b[0] = newset;
                    }
                }
            }
            break;
        }
        case 'D' :
        {
            cin>>name;
            cin>>amt;
            if(a.find(name) == a.end())//his account is not there
            {
                illegal++;
                break;
            }
            else
            {
                initamt = a[name];
                a[name] = initamt+amt;
                if(b[initamt].size() == 1)
                {
                    b.erase(initamt);
                }
                else
                {
                    b[initamt].erase(name);
                }
                b[initamt+amt].insert(name);
            }
            break;
        break;
        }
        case 'W' :
        {
            cin>>name;
            cin>>amt;
            if(a.find(name) == a.end())//his account is not there
            {
                illegal++;
                break;
            }
            else
            {
                initamt = a[name];
                if(initamt>=amt)
                {
                    a[name] = initamt-amt;
                    if(b[initamt].size() == 1)
                    {
                        b.erase(initamt);
                    }
                    else
                    {
                        b[initamt].erase(name);
                    }
                    b[initamt-amt].insert(name);
                }
                else
                {
                    illegal++;
                    break;
                }
            }
        break;
        }
        case 'P' :
        {
            cin>>small;
            cin>>large;
            mini=b.lower_bound(small);
            maxi = b.upper_bound(large);
            for(;mini!=maxi;mini++)
            {
                cout<<mini->first<<" ";
                newset = mini->second;
                for(strite = newset.begin();strite!=newset.end();strite++)
                {
                   // cout<<"poa";
                    cout<<*strite<<" ";
                    //cout<<"ass";
                }
                cout<<endl;
            }
            break;
        }
        }

    }
    cout<<illegal<<endl;
    map<string,int> :: iterator ite;
    for(ite=a.begin();ite!=a.end();ite++)
    {
        cout<<ite->first<<" "<<ite->second<<endl;
    }
    return 0;
}
