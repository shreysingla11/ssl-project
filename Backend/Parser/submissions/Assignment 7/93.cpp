#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)

using namespace std;


int main()
{
    /**Declarations**/
    bool valid;
    char op;
    int bal,dep,a,b,illegal;
    string name,str;
    map<string,int> accounts;
    map<int,set<string> > same_bal;


    illegal=0;
    /**operations**/
    while(true)
    {

        /**Inputing the operation**/
        cin>>op;

        valid=true;
        /**code for OPEN operation**/
        if(op=='O')
        {

            cin>>name;

            /**check for existance**/
            if(accounts.find(name)!=accounts.end())
            {
                /**If already present then**/
//cout<<"already present"<<endl;
                illegal++;
            }
            else
            {
                accounts[name]=0;
                same_bal[0].insert(name);
            }
        }




        /**code for DEPOSIT operation**/
        if(op=='D')
        {

            cin>>name;

            /**check for existance**/
            if(accounts.find(name)!=accounts.end())
            {

                /**If already present then**/
                cin>>dep;
                /**dep must be positive**/
                if(dep<0)
                {
                    illegal++;
                    dep=0;
                    /**inv**/
                    valid=false;
                }
                if(valid)
                {
                    bal=accounts[name];
                    accounts[name]+=dep;
                    same_bal[bal].erase(name);
                    if(same_bal[bal].size()==0)
                    {
                        /**if no members of bal remove the set**/
                        same_bal.erase(bal);
                    }
                    same_bal[bal+dep].insert(name);

                }
            }
            else
            {
                illegal++;
            }

        }

        /**code for WITHDRAW operation**/
        if(op=='W')
        {

            cin>>name;

            /**check for existance**/
            if(accounts.find(name)!=accounts.end())
            {

                /**If already present then**/
                cin>>dep;
                /**dep must be positive**/
                if(dep<0)
                {
                    illegal++;
                    dep=0;
                    /**inv**/
                    valid=false;
                }
                if(valid)
                {
                    bal=accounts[name];
                    if(dep<=bal)
                    {
                        /**negative deposit is withdrawal**/
                        dep=(-1*dep);
                        accounts[name]+=dep;
                        same_bal[bal].erase(name);
                        if(same_bal[bal].size()==0)
                        {
                            /**if no members of bal remove the set**/
                            same_bal.erase(bal);
                        }
                        same_bal[bal+dep].insert(name);
                    }
                    else
                    {
                        illegal++;
                    }
                }
            }

            else
            {
                illegal++;
            }

        }

        /**working**/

        /**code for CLOSE operation**/
        if(op=='C')
        {

            cin>>name;

            /**check for existance**/
            if(accounts.find(name)!=accounts.end())
            {
                /**If already present then**/
                bal=accounts[name];
                if(bal==0)
                {
                    accounts.erase(name);
                    same_bal[0].erase(name);
                    if(same_bal[0].size()==0)
                    {
                        /**if no members of bal remove the set**/
                        same_bal.erase(0);
                    }
                }
                else
                {
                    illegal++;
                }

            }
            else
            {
                illegal++;
            }
        }

        /**code for PRINT operation**/
        if(op=='P')
        {
            cin>>a>>b;
            for(map<int,set<string> >::iterator it=same_bal.begin(); it!=same_bal.end(); it++)
            {
                if(a<=(*it).first&&(*it).first<=b)
                {
                    cout<<(*it).first;
                    for(set<string>::iterator jt=(*it).second.begin(); jt!=(*it).second.end(); jt++)
                    {
                        cout<<" "<<(*jt);
                    }
                    cout<<endl;
                }
            }
        }

        if(op=='E')
        {
            break;
        }

    }

    cout<<illegal<<endl;

    return 0;
}
