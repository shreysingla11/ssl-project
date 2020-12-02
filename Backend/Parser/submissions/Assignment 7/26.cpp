#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

int main()
{
    map<string,int> accbal;
    map<int,set<string> > balinfo;
    pair< map<string,int> ::iterator,bool> newacc;
    int count_illegal=0;
    char choice;

    //set<string> szero;
    balinfo.insert( pair<int,set<string> >(0,set<string> ()));
    string acname;
    int amt;
    int oldbal,newbal;
    int lb,ub;
    map<int,set<string> >::iterator pos,pos2;
    map<string,int>::iterator findpos;
    set<string>::iterator it;

    do{
        cin>>choice;
        switch(choice)
        {
            case 'O':
                    cin>>acname;
                    newacc = accbal.insert ( pair<string,int>(acname,0) );
                    //open account
                    if(!newacc.second){  //Account name already existed
                        count_illegal++;break;}
                    balinfo[0].insert(acname);
                    break;
            case 'W':
                    cin>>acname;
                    cin>>amt;
                    if(accbal.find(acname)==accbal.end())//Account with acname does not exist
                        {count_illegal++;break;}
                    oldbal=accbal[acname];
                    if(oldbal<amt)
                        {count_illegal++;break;}

                    newbal=newbal-amt;

                    //it = balinfo[oldbal].find (acname);
                    balinfo[oldbal].erase (acname);
                    if(balinfo[oldbal].empty())
                        balinfo.erase(oldbal);

                    //balinfo[oldbal].erase(acname);//Removing acc name from previous balance

                    accbal[acname]=newbal;
                    pos=balinfo.find(newbal);
                    if(pos==balinfo.end())
                    {
                        set<string> strset;
                        strset.insert(acname);
                        balinfo.insert( pos,pair<int,set<string> >(newbal,strset));
                    }
                    else
                        (pos->second).insert(acname);
                    break;
            case 'D':
                    cin>>acname;
                    cin>>amt;
                    if(accbal.find(acname)==accbal.end())//Account with acname does not exist
                        {//cout<<"Does not exist"<<endl;
                        count_illegal++;break;}
                    //else if(accbal[acname]<amt)
                    //    {count_illegal++;break;}
                    oldbal=accbal[acname];
                    newbal=accbal[acname]+amt;

                    //it = balinfo[oldbal].find (acname);
                    balinfo[oldbal].erase (acname);
                    if(balinfo[oldbal].empty())
                        balinfo.erase(oldbal);

                    //balinfo[oldbal].erase(acname);//Removing acc name from previous balance

                    accbal[acname]=newbal;
                    pos=balinfo.find(newbal);
                    if(pos==balinfo.end())
                    {
                        set<string> strset;
                        strset.insert(acname);
                        balinfo.insert( pair<int,set<string> >(newbal,strset));
                    }
                    else
                        (pos->second).insert(acname);
                    break;
            case 'C':cin>>acname;
                    findpos=accbal.find(acname);
                    if(findpos==accbal.end())
                        {count_illegal++;break;}
                    oldbal=accbal[acname];
                    if(oldbal)
                        {count_illegal++;break;}
                    //accbal.erase(findpos);
                    //cout<<oldbal<<endl;
                    accbal.erase(findpos);
                    balinfo[oldbal].erase(acname);
                    if(balinfo[oldbal].empty())
                        balinfo.erase(oldbal);
                    break;
            case 'P':cin>>lb>>ub;
                    pos=balinfo.lower_bound(lb);
                    pos2=balinfo.upper_bound(ub);
                    while(pos!=pos2)
                    {
                        cout<<pos->first;
                        for(it=(pos->second).begin();it!=(pos->second).end();++it)
                            cout<<" "<<*it;
                        cout<<endl;
                        pos++;
                    }
                    break;
            case 'E':break;
            //default:cout<<"Wrong Input!"<<endl;
        }
    }while(choice!='E');
    cout<<count_illegal;
}
