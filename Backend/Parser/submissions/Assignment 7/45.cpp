#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main ()
{
map<string,int> AccName;
map<int,set<string> > Balance;
char oper;
string name;
int num;
int pStart,pEnd,i,j;
int illegal=0;
map<string,int>:: iterator last = AccName.end();
map<string,int>:: iterator there;
map<int,set<string> >:: iterator zeroItr,startItr,endItr;
set<string> tempSet;
set<string>:: iterator setItr;
set<string>:: iterator settItr;

while(true)
{
    cin>>oper;
    if(oper=='E' || oper == 'e'){break;}
    switch(oper)
    {
        case 'O':
        {
            cin>>name;
            if(AccName.find(name)==AccName.end())
            {
                AccName.insert(AccName.begin(),pair<string,int>(name,0));
                //zeroItr=Balance.begin();
                if(Balance.find(0)!=Balance.end())
                {
                    //optimize
                    tempSet=Balance[0];
                    tempSet.insert(name);
                    Balance[0]=tempSet;
                }
                else
                {
                    tempSet.insert(name);
                    Balance[0]=tempSet;
                }
            }
            else{illegal++;}
            break;
        }
        case 'C':
        {
            cin>>name;
            there=AccName.find(name);
            if(there==AccName.end()){illegal++;}
            else if(AccName[name]!=0){illegal++;}
            else
            {
                AccName.erase(there);
                //optimize
                tempSet=Balance[0];
                tempSet.erase(name);
                if(tempSet.size()!=0){Balance[0]=tempSet;}
                else{Balance.erase(0);}

            }
            break;
        }
        case 'P':
        {
            cin>>pStart;
            cin>>pEnd;
            //optimize
            //Check pEnd equal or notand also for next pStart
            startItr=Balance.lower_bound(pStart);
            endItr=Balance.upper_bound(pEnd);
            zeroItr=endItr;
            zeroItr--;
            for(;startItr!=endItr;startItr++)
            {
                tempSet=startItr->second;
                if(settItr!=tempSet.end()){cout<<startItr->first;}
                tempSet=startItr->second;
                setItr=tempSet.begin();
                                settItr=setItr;
                while(setItr!=tempSet.end())
                {
                    cout<<" "<<(*setItr);
                    setItr++;
                }
                if(settItr!=tempSet.end()){cout<<endl;}
            }
            break;
        }
        case 'D':
        {
            cin>>name;
            cin>>num;
            there=AccName.find(name);
            if(there!=AccName.end())
            {
                if(tempSet.size()!=0){Balance[there->second].erase(name);}
                else{Balance.erase(there->second);}
                (there->second)=(there->second)+num;

                Balance[there->second].insert(name);

            }
            else{illegal++;}
            break;
        }
        case 'W':
        {
            cin>>name;
            cin>>num;
            there=AccName.find(name);
            if(there!=AccName.end())
            {
                if(num>there->second){illegal++;}
                else{

                    if(Balance[there->second].size()!=1){Balance[there->second].erase(name);}
                    else{Balance.erase(there->second);}
                    (there->second)=(there->second)-num;

                    Balance[there->second].insert(name);
                }
            }
            else{illegal++;}
            break;
        }
    }
}
cout<<illegal<<endl;
return 0;
}
