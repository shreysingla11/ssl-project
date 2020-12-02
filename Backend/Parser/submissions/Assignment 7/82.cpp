# include <iostream>
# include <string>
# include <set>
# include <map>
# include <cstdio>
using namespace std;
class bankaccount
{
    //define the maps
    //map from name to balance
    std::map<string,int> name_bal;
    //map from balance to names
    std::map<int ,std::set<string> > bal_name;
    int illegal_ops;

public:

    bankaccount()
    {
        illegal_ops=0;

    }

    void openaccount(string name,int  balance=0)
    {
        if(name_bal.find(name)!=name_bal.end())
        {
            //account already existsadd it
            illegal_ops++;

        }
        else
        {
            //add it
            name_bal[name]=balance;
            if(bal_name.find(balance)==bal_name.end())
            {
                set<string> temp;
                temp.insert(name);
                bal_name[balance]=temp;

            }
            else
            {
                bal_name[balance].insert(name);
            }


        }
        return;
    }
    void closeaccount(string name)
    {
        if(name_bal.find(name)==name_bal.end() )
        {
            //account does not exists existsadd it
            illegal_ops++;

        }
        else
        {
            //account exists
            if(name_bal[name]==0)
            {
                //empty account
                bal_name[0].erase(name);
                name_bal.erase(name);
            }
            else
            {
                illegal_ops++;
                //tried to remove non zero balance

            }
        }

        return;
    }

    void withdraw(string name,int bal)
    {
        if(name_bal.find(name)==name_bal.end() )
        {
            //account does not exists return
            illegal_ops++;

        }
        else if(name_bal[name]<bal)
        {

            illegal_ops++;

        }
        else
        {
            //decrease theblance
            int prevbal=name_bal[name];
            int newbal=prevbal-bal;
            //std::set<string>::iterator it=bal_name[prevbal].find(name);
            bal_name[prevbal].erase(name);
            if(bal_name[prevbal].empty()){
            bal_name.erase(prevbal);
            }
            name_bal[name]=newbal;
            //find if new bal exists and put it into new postion

            if(bal_name.find(newbal)==bal_name.end())
            {
                set<string> temp;
                temp.insert(name);
                bal_name[newbal]=temp;

            }
            else
            {
                bal_name[newbal].insert(name);
            }


            return;
        }


        return;
    }

    void deposit(string name,int bal)
    {
        if(name_bal.find(name)==name_bal.end() )
        {
            //account does not exists return
            illegal_ops++;

        }
        else
        {
            //decrease theblance
            int prevbal=name_bal[name];
            int newbal=prevbal+bal;
            //std::set<string>::iterator it=bal_name[prevbal].find(name);
            bal_name[prevbal].erase(name);
            if(bal_name[prevbal].empty()){
            bal_name.erase(prevbal);
            }
            name_bal[name]=newbal;
            //find if new bal exists and put it into new postion

            if(bal_name.find(newbal)==bal_name.end())
            {
                set<string> temp;
                temp.insert(name);
                bal_name[newbal]=temp;

            }
            else
            {
                bal_name[newbal].insert(name);
            }



        }


        return;
    }

    void printrange(int Strt,int End)
    {
        std::map<int,std::set<string> >::iterator itlow,itup,tempit;
        itlow=bal_name.lower_bound(Strt);
        itup=bal_name.upper_bound(End);
        if(itlow!=bal_name.end())
        {
            tempit=itlow;
            while(tempit!=itup)
            {
                int bal=tempit->first;
                cout<<bal;
                std::set<string>::iterator nit=bal_name[bal].begin();
                while(nit!=bal_name[bal].end())
                {
                    cout<<" "<<*nit;
                    nit ++;
                }
                cout<<endl;
                tempit++;
            }

        }


        return;
    }

    void printillegal()
    {
        cout<<illegal_ops<<endl;
        return;
    }

};

int main()
{

    bankaccount bank;
    string input,name;
    cin>>input;
    //scanf("%s",input);
    int a ,b;
    while(input!="E")
    {
        if( input=="O")
        {
            //open account
            cin>>name;
            //scanf("%s",name);
            bank.openaccount(name);
        }
        else if(input =="C")
        {
            cin>>name;
            //scanf("%s",name);
            bank.closeaccount(name);
        }
        else if(input=="W")
        {
            cin>>name;
            scanf("%d",&a);
            bank.withdraw(name,a);
        }
        else if(input=="D")
        {
            cin>>name;
            scanf("%d",&a);
            bank.deposit(name,a);
        }
        else if(input=="P")
        {
            //cin>>a>>b;
            scanf("%d %d",&a,&b);
            bank.printrange(a,b);
        }
        cin>>input;
    //scanf("%s",input);
    }
    bank.printillegal();
    return 0;

}
