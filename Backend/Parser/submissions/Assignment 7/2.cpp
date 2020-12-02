#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int main(){
string name;
char oprn;
cin>>oprn;
 int depval ,witval,l,u,illegal;
 illegal=0;
 map<string,int>account;
 map<int, set<string> >people;
 set<string>s;
 while(oprn != 'E'){
if(oprn=='O'){//opening account
      cin>>name;
      if(account.find(name)==account.end()){account[name]=0;people[0].insert(name);}
      else{illegal=illegal+1;}
              }
if(oprn=='C'){
       cin>>name;
       if(account.find(name)==account.end()){illegal=illegal+1;}
              else{
                   if(account[name]==0){
                                        account.erase(name);
                                        people[0].erase(name);
                                                             }
                   else{illegal=illegal+1;}
                   }
               }
if(oprn=='D'){
     cin>>name;cin>>depval;
     if(account.find(name)==account.end()){illegal=illegal+1;}
     else{
          int balance;balance=account[name];
          people[balance].erase(name);
          if(people[balance].empty()){people.erase(balance);}
          account[name]=account[name]+depval;
          balance=account[name];
          people[balance].insert(name);
           }

                }
if(oprn=='W'){
     cin>>name;cin>>witval;
      if(account.find(name)==account.end()){illegal=illegal+1;}
      else{
           if(account[name]<witval){illegal=illegal+1;}
           else{
                 int balance;balance=account[name];
                 people[balance].erase(name);
                 if(people[balance].empty()){people.erase(balance);}
                 account[name]=account[name]-witval;
                 balance=account[name];
                 people[balance].insert(name);
                }
        }
                }
if(oprn=='P'){
    cin>>l>>u;
  map<int, set<string> > :: iterator it;
  set<string> :: iterator st,stend;
  for(it=people.begin();it!=people.end();it++){
         if((it->first>=l)&&(it->first<=u)){
           cout<<it->first<<" ";
                 st = (it->second).begin(); stend= (it->second).end();
                                   while(st != stend){
                                            cout<< *st<<" ";st++;
                                                        }
                                                        cout<<endl;
                                            }
                                                }


               }
cin>>oprn;
                          }
cout<<illegal<<endl;
return 0;
            }
