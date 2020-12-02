#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
map<string,int> Accountnames;
map<int, set<string> > Accountbalance;
int invalidcount=0;
void Deposit()
    {
        string name;
        cin>>name;
        map<string,int> :: iterator it=Accountnames.find(name);
        if(it==Accountnames.end())
            {
                invalidcount++;
                return;
            }
        else
        {
            int currBal=it->second;
            int depAmount=0;
            cin>>depAmount;
            Accountbalance[currBal].erase(name);
            Accountbalance[currBal+depAmount].insert(name);
            it->second+=depAmount;
        }


    }
void Withdraw()
    {
        string name;
        int withAmount;
        cin>>name;
        map<string,int> :: iterator it=Accountnames.find(name);
        if(it==Accountnames.end())
            {
                //cout<<"invalid name";
                invalidcount++;
                return;
            }
        else
            {
                cin>>withAmount;
                int currBal=it->second;
                //cout<<"currbal="<<currBal<<" "<<"withAmount"<<withAmount<<endl;
                if(currBal<withAmount)
                    {
                        //cout<<"invalid withamount";
                        invalidcount++;
                        return;
                    }
                else
                    {

                        Accountbalance[currBal].erase(name);
                        Accountbalance[currBal-withAmount].insert(name);
                        it->second-=withAmount;
                    }

            }

    }
void Close()
    {
        string name;
        cin>>name;
        map<string,int> :: iterator it=Accountnames.find(name);
        if(it==Accountnames.end())
            {
                invalidcount++;
                return;
            }
        else
            {
                if(it->second!=0)
                {
                    invalidcount++;
                    return;
                }
                else
                    {

                        //map<int, set<string> > :: iterator it1=Accountbalance.find(it->second);
                         int currBal=it->second;
                         Accountbalance[currBal].erase(name);
                         Accountnames.erase(name);


                    }
            }

    }
void Open()
    {
        string name;
        cin>>name;
        map<string,int> :: iterator it=Accountnames.find(name);
        if(it!=Accountnames.end())
            {
                invalidcount++;
                return;
            }
        else
            {
                int startBal=0;
                //cin>>startBal;
                //pair<string,int>* newpair;

                Accountnames.insert(pair<string,int>(name,startBal));
                Accountbalance[startBal].insert(name);
            }

    }
void Print()
    {
        int beginrange,endrange;
        cin>>beginrange;
        cin>>endrange;
        set<string> currSet;
        for(int i=beginrange;i<=endrange;i++)
            {
                currSet=Accountbalance[i];
                if(currSet.empty()==false)
                    {
                        cout<<i<<" ";
                        set<string> :: iterator it=currSet.begin();
                        while(it!=currSet.end())
                            {
                                cout<<*it<<" ";
                                it++;
                            }
                        cout<<endl;
                    }
            }
    }
int main()
{


char input1;
cin>>input1;
while(input1!='E')
    {
        switch(input1)
            {
                case 'D':
                    Deposit();
                    break;
                case 'W':
                    Withdraw();
                    break;
                case 'O':
                    Open();
                    break;
                case 'C':
                    Close();
                    break;
                case 'P':
                    Print();
                    break;
            }
        cin>>input1;
    }

cout<<invalidcount;

}

