#include<iostream>
#include<string>
#include <set>
#include <map>
using namespace std;
int main()
{
    string s,oper;
    int count=0,amount=0,range1=0,range2=0;
//char oper1;
//We use two maps, one which maps the account name to the current balance and
//another that maps the balance to a set of names that have that balance.
    map<string,int> bank; // maps a string to an int.

//map<string,int>::iterator b;

    map<int, set<string> > detbank; // maps an int to a set of strings.
    // map<int, set<string> >::iterator db;


    while(true)
    {  getline(cin,oper,' ');

        if (oper=="O")
        {
            getline(cin,s);
            map<string,int>::iterator b=bank.find(s);
            if(b!=bank.end())
            {
                //illegal operation
                count=count+1;
            }
            else
            {
                bank[s]=0;
                //map<std::string, set<double> >::iterator iter = myMap.find(myString);
                map<int, set<string> >::iterator db = detbank.find(0);
                if(db != detbank.end())
                {
                    db->second.insert(s);
                }
                else
                {
                    detbank[0].insert(s);
                }
            }

        }
        else if (oper=="C")
        {
            getline(cin,s);
            map<string,int>::iterator b=bank.find(s);
            if(b!=bank.end())
            {
                //checks if the account is present or not
                if(b->second==0) //checks if the account has zero balance
                {
                    bank.erase(b);
                    map<int, set<string> >::iterator db = detbank.find(0);
                    if(db != detbank.end())
                    {
                        //set<string>::iterator st;
                        db->second.erase(s);
                    }
                }
                else
                {
                    count=count+1;
                }

            }
            else
            {
                count=count+1;
            }
        }
        else if (oper=="D")
        {
            getline(cin,s,' ');
            map<string,int>::iterator b=bank.find(s);
            if(b!=bank.end())  //check if the acount is present or not
            {
                cin>>amount;
                map<int, set<string> >::iterator db = detbank.find(bank[s]);
                if(db != detbank.end())
                {
                    db->second.erase(s);
                }
                bank[s]=bank[s]+amount;
                db=detbank.find(bank[s]);
                if(db != detbank.end())
                {
                    db->second.insert(s);
                }
                else if(db == detbank.end())
                {
                    detbank[bank[s]].insert(s);
                }
            amount=0;
            }
            else
            {
                count=count+1;
            }
        }
        else if (oper=="W") {
         getline(cin,s,' ');
            map<string,int>::iterator b=bank.find(s);
            if(b!=bank.end())  //check if the acount is present or not
            {
                cin>>amount;
                if((b->second)>=amount){
                    map<int, set<string> >::iterator db = detbank.find(bank[s]);
                    if(db != detbank.end())
                    {
                        db->second.erase(s);
                    }
                    bank[s]=bank[s]-amount;
                    db=detbank.find(bank[s]);
                    if(db != detbank.end())
                    {
                        db->second.insert(s);
                    }
                    else if(db == detbank.end())
                    {
                        detbank[bank[s]].insert(s);
                    }
                amount=0;
                }
                else {count=count+1;}
            }
            else
            {
                count=count+1;
            }
        }
        else if (oper=="P") {
        cin>>range1;
        cin>>range2;
        map<int, set<string> >::iterator db1 = detbank.find(range1);
        map<int, set<string> >::iterator db2 = detbank.find(range2);
         if(db1 != detbank.end()){
          if(db2 != detbank.end()){
          map<int, set<string> >::iterator end2=++db2;
          for( map<int, set<string> >::iterator it=db1;it!=end2;++it){
          cout<<it->first<<" ";
          for(set<string>::iterator st=it->second.begin();st!=it->second.end();++st){
          cout<<*st<<" ";
          }
          cout<<endl;
            }
          }
          else if(db2 == detbank.end()){
          for( map<int, set<string> >::iterator it=db1;it != detbank.end();++it){
          cout<<it->first<<" ";
          for(set<string>::iterator st=it->second.begin();st!=it->second.end();++st){
          cout<<*st<<" ";
          }
          cout<<endl;
            }
          }

         }

        }
        else if(oper=="E"){break;}
    }
    cout<<count<<endl;
//switch(oper1){
//case 'A':cout<<"asa:";
//
//}
return 0;
}
