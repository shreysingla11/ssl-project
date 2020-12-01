#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    int error=0;
    int rb;
    int re;
    map< string, int> A;
    map<int, set<string> > B;
    map<string,int>::iterator it;
    map<int, set<string> >::iterator it2;
    char command;
    string name;
    int value;
    while(true)
    {
        cin>>command;
        if(command=='E')
        {
        break;
        }
        if(command=='C')
        {
        cin>>name;
        it=A.find(name);
        if(it!=A.end())
        {
        if((it->second)>0){error++;continue;}
        it2=B.find(it->second);
        A.erase(it);
        set<string>::iterator it9;
        it9=(it2->second).find(name);
        (it2->second).erase(it9);
        if((it2->second).empty())
        {
                    B.erase(it2);
        }
        }
        else{
        error++;
        }
        }
        if(command=='O')
        {
            cin>>name;
            it=A.find(name);
            if (it==A.end())
            {
                A[name]=0;
                it2=B.find(0);
                if(it2!=B.end())
                {
                    B[0].insert(name);
                }
                else
                {
                    //string b[]={name};
                    set<string> tmp;
                    tmp.insert(name);
                    B[0]=tmp;
                }
            }
            else
            {
                error++;
            }
        }
        if(command=='P')
        {
            cin>>rb>>re;
            map<int, set<string> >::iterator it3;
            map<int, set<string> >::iterator it4;
            set<string> :: iterator it5;
            it3=B.begin();
            //it4=B.end();
            while(it3!=B.end())
            {
            if((it3->first)>=rb){break;}
            it3++;
            }
            it4=it3;
            while(it4!=B.end())
            {
            if((it4->first)>=re){break;}
            it4++;
            }
            while(it3!=it4)
            {
                cout<<((it3->first))<<" ";
                it5=(it3->second).begin();
                while(it5!=(it3->second).end())
                {
                    cout<<(*it5)<<" ";
                    it5++;
                }
                cout<<endl;
                it3++;
            }
        }
        if(command=='D')
        {
        cin>>name>>value;
            if(value!=0)
            {

                it=A.find(name);
                if(it!=A.end())
                {

                    it->second=(it->second)+value;
                    it2=B.find(((it->second)));
                    if(it2!=B.end())
                    {


                        (it2->second).insert(name);
                    }
                    else
                    {
                        set<string> tmp;
                        tmp.insert(name);
                        B[it->second]=tmp;
                    }
                    it2=B.find(it->second-value);
                    set<string>::iterator it6;
                    it6=(it2->second).find(name);
                    (it2->second).erase(it6);
                    if((it2->second).empty())
                    {
                    B.erase(it2);
                    }
                }
                else
                {
                    error++;
                }
            }
        }
                if(command=='W')
        {
        cin>>name>>value;
            if(value!=0)
            {

                it=A.find(name);
                if(it!=A.end())
                {if(value>(it->second)){error++;continue;}
                    it->second=(it->second)-value;
                    it2=B.find(((it->second)));

                    if(it2!=B.end())
                    {


                        (it2->second).insert(name);
                    }
                    else
                    {
                        set<string> tmp;
                        tmp.insert(name);
                        B[it->second]=tmp;
                    }
                    it2=B.find(it->second+value);
                    set<string>::iterator it6;
                    it6=(it2->second).find(name);
                    (it2->second).erase(it6);

                    if((it2->second).empty())
                    {
                    B.erase(it2);
                    }

                }
                else
                {
                    error++;
                }
            }
        }
    }
    cout<<error<<endl;
}
