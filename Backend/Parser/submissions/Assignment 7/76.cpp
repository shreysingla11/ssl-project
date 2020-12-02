#include<iostream>
#include <map>
#include<set>
using namespace std;

map<string, int> account;
map<string,int>::iterator it;

map<int,set<string> > printer;
map<int,set<string> >::iterator gta;

void deposit(string name,int amount);
void withdraw(string name,int amount);
void printyo(int a, int b);

int main()
{
int b=0,c=0,illegal=0;
std::string line,a;
while (cin>>line)
{
    if(line[0]=='D'){cin>>a;
                    it=account.find(a);
                    if(it!=account.end())
                    {
                        printer[account[a]].erase(a);
                        cin>>b;
                        deposit(a,b);
                        printer[account[a]].insert(a);
                        }else illegal++;
                    }

    if(line[0]=='W'){cin>>a;
                    it=account.find(a);
                    if(it!=account.end())
                    {cin>>b;if(account[a]>=b){
                    printer[account[a]].erase(a);
                    if(printer[account[a]].empty()){printer.erase(account[a]);}
                    withdraw(a,b);
                    printer[account[a]].insert(a);}
                    else illegal++;
                    }else illegal++;
                    }
    if(line[0]=='O'){
                    cin>>a;
                    it=account.find(a);
                    if(it==account.end())
                    {account[a]=0;
                     gta=printer.find(0);
                     if(gta!=printer.end()){
                     printer[0].insert(a);
                     }
                     }else illegal++;
                    }
    if(line[0]=='C'){cin>>a;
                    it=account.find(a);
                    if(it!=account.end())
                        {
                        if(it->second==0){account.erase(a);
                                            printer[0].erase(a);

                                            }else illegal++;

                        }else illegal++;


                    }

    if(line[0]=='P'){cin>>b;cin>>c;
                     printyo(b,c);}
    if(line[0]=='E'){break;}
}
cout<<illegal<<endl;
return 0;
}

void deposit(string name,int amount)
{
account[name]+=amount;
return;
}

void withdraw(string name,int amount)
{
account[name]-=amount;
return;
}

void printyo(int a, int b)
{
for(gta=printer.lower_bound(a);gta!=printer.lower_bound(b+1);gta++)
{
gta--;
if(!printer[gta->first].empty()){
if(gta!=printer.end()){
cout<<gta->first;
for(set<string>::iterator iq=gta->second.begin();iq != gta->second.end();iq++)
{
cout<<" "<<*iq;
}
cout<<endl;
}
}}
return;
}
