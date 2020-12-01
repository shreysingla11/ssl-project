#include<iostream>
#include<map>
#include<set>
#include<string.h>
#include<stdio.h>
using namespace std;

map<string,int> account;
map<int, set<string> > bal;
map<int, set<string> >::iterator it1;
map<int, set<string> >::iterator it2;
set<string> temp;
set<string>::iterator its;
int main()
{
    string input ;
    char ch;
    int num1,num2,dep,with,inval_count=0;
        while(1)
        {
            cin>>ch;
            if(ch=='O')
            {
                cin>>input;
                //cout<<"a"<<endl;
                if(account.count(input)>0)
                {
                    inval_count++;
                }
                else
                {
                   //  cout<<"a"<<endl;
                    account[input]=0;
                    bal[0].insert(input);
                }
            }
            else if (ch=='D')
            {
                cin>>input;
                cin>>dep;
                if(account.count(input)==0)
                {
                    inval_count++;
                }
                else
                {
                    int val;
                    val=account[input];
                    account[input]=val+dep;

                    bal[val].erase(input);
                    bal[val+dep].insert(input);
                    if(bal[val].size()==0)
                    {
                        bal.erase(val);
                    }

                }

            }
            else if (ch=='W')
            {
                cin>>input;
                cin>>with;
                if(account.count(input)==0)
                {
                    inval_count++;
                }
                else
                {
                    int val;
                    val=account[input];
                    if(val<with)
                    {
                        inval_count++;
                    }
                    else
                    {
                        account[input]=val-with;
                        bal[val].erase(input);
                         bal[val-with].insert(input);
                        if(bal[val].size()==0)
                        {
                            bal.erase(val);
                        }

                    }
                }
            }
            else if(ch =='C')
            {
                cin>>input;
                if(account.count(input)==0)
                {
                    inval_count++;
                }
                else
                {
                    int val=account[input];
                    if(val>0)
                    {
                        inval_count++;
                    }
                    else
                    {
                    bal[val].erase(input);
                    if(bal[val].size()==0)
                    {
                            bal.erase(val);
                    }
                    account.erase(input);
                    }
                }
            }
            else if(ch=='P')
            {
                 scanf("%d",&num1);
                 scanf("%d",&num2);
                 it1=bal.upper_bound(num2);
                 it2=bal.lower_bound(num1);
                 for(map<int, set<string> >::iterator it=it2;it!=it1;it++)
                 {
                    printf("%d ",it->first);
                    temp=it->second;
                    for(its=temp.begin();its!=temp.end();its++)
                    {
                        cout<<*its<<" ";
                    }
                    cout<<endl;
                 }

            }
            else if(ch=='E')
            {
                break;
            }
        }
        cout<<inval_count<<endl;
}
