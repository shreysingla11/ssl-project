#include<iostream>
#include<set>
#include<map>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
map<string,int> balance;
    map<int, set<string> > eqbalance;
    vector<int>s;
    vector<vector<string> >v;
void f(int &first,int &last,int &count);
int main()
{

    int illegal=0;
    int count=0;
    while(true)
    {
        char op;
        cin>>op;
        if(op=='O')
        {
            string newacnt;
            cin>>newacnt;
            if(balance.find(newacnt)==balance.end())/////check if an error
            {
                balance[newacnt]=0;
                (eqbalance[0]).insert(newacnt);
            }
            else
            {
                illegal++;
            }
        }
        else
        {
            if(op=='C')
            {
                ////////check if an account is not existing
                string closeacnt;
                cin>>closeacnt;
                if(balance.find(closeacnt)!=balance.end() && balance[closeacnt]==0)/////check if an error
                {
                    int temp=balance[closeacnt];
                    (eqbalance[temp]).erase(closeacnt);
                    balance.erase(closeacnt);
                }
                else
                {
                    illegal++;
                }
            }
            else
            {
                if(op=='W')
                {
                    string draw;
                    cin>>draw;
                    int amnt;
                    cin>>amnt;
                    if(balance.find(draw)!=balance.end())/////check if an error
                    {
                        if(balance[draw]<amnt)
                        {
                            illegal++;
                            continue;
                        }
                        else
                        {
                            (eqbalance[balance[draw]]).erase(draw);
                            balance[draw] =balance[draw]- amnt;

                            (eqbalance[balance[draw]]).insert(draw);
                        }
                    }
                    else
                    {
                        illegal++;
                    }
                }
                else
                {
                    if(op=='D')
                    {
                        string deposit;
                        cin>>deposit;

                        int amnt;
                        cin>>amnt;
                        if(balance.find(deposit)!=balance.end())/////check if an error
                        {
                            (eqbalance[balance[deposit]]).erase(deposit);
                            balance[deposit] =balance[deposit]+amnt;
                            (eqbalance[balance[deposit]]).insert(deposit);
                        }
                        else
                        {
                            illegal++;
                        }
                    }


                    else
                    {
                        if(op=='P') {
                           int first,last;
                           cin>>first;cin>>last;
                           for(int i=first;i<=last;i++){
                              if((eqbalance.find(i)==eqbalance.end()))/////check if an error
                        {continue;}
                        else{if(eqbalance[i].begin()!=eqbalance[i].end()){
                                 cout<<i<<" ";
                            std::set<string>::iterator it = (eqbalance[i]).begin();
                            for( ;it != (eqbalance[i]).end();it++){cout<<*it<<" ";}
                            cout<<endl;
                        }
                           }
                        }
                        }
                        else
                        {
                            if(op=='E')
                            {
                                break;
                            }
                            else {}

                        }
                    }
                }
            }
        }
    }
    cout<<illegal;
    return 0;
}

void f(int &first,int &last,int &count){
vector<string>tr;
for(int i=first;i<=last;i++){
                              if((eqbalance.find(i)==eqbalance.end()))/////check if an error
                        {continue;}
                        else{if(eqbalance[i].begin()!=eqbalance[i].end())
                        s.push_back(i);cout<<s.back()<<endl;v.push_back(tr);
                            std::set<string>::iterator it = (eqbalance[i]).begin();
                            for( ;it != (eqbalance[i]).end();it++){v[count].push_back(*it);}
                        }
                           }
}
