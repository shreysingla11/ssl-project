#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<set>
#include<string>
#include<map>

using namespace std;

map<string,int> money;
map<int, set<string> > person;
map<string,int>::iterator it_money;
map<int, set<string> > ::iterator it_person;

int illegal=0;

void open(string name)
{
    set<string> junta;
    it_money=money.find(name);
    if(it_money != money.end()){illegal++;return;}
    else money.insert ( pair<string,int>(name,0) );
    it_person=person.find(0);
    if(it_person != person.end())
    {
        junta.clear();
        junta=it_person->second;
        junta.insert(name);
        it_person->second=junta;
    }
    else
    {
        junta.clear();
        junta.insert(name);
        person.insert(pair<int, set<string> >(0,junta) );
    }

}

void close(string name)
{
    set<string> junta;
    it_money=money.find(name);
    if(it_money == money.end()){illegal++;return;}
    else if(it_money->second != 0){illegal++;return;}
    else
    {
        junta.clear();
        it_person=person.find(0);
        money.erase(name);
        junta=it_person->second;
        junta.erase(name);
        it_person->second=junta;
        junta.clear();
        it_person=person.find(0);
        junta=it_person->second;
        if(junta.empty())
        {
            person.erase(0);
        }
    }
}

void deposit(string name,int paisa)
{
    set<string> junta;
    int temp;
    it_money=money.find(name);
    if(it_money==money.end()){illegal++;return;}
    else
    {
        temp=money[name];
        it_person=person.find(temp);
        junta.clear();
        junta=it_person->second;
        junta.erase(name);
        it_person->second=junta;
        junta.clear();
        it_person=person.find(temp);
        junta=it_person->second;
        if(junta.empty())
        {
            person.erase(temp);
        }
        money[name]+=paisa;
        temp=money[name];
        junta.clear();
        it_person=person.find(temp);
        if(it_person!=person.end())
        {
            junta=it_person->second;
            junta.insert(name);
            it_person->second=junta;
        }
        else
        {
            junta.clear();
            junta.insert(name);
            person.insert(pair<int, set<string> >(temp,junta) );
        }
    }
}

void withdraw(string name,int paisa)
{
    set<string> junta;
    int temp;
    it_money=money.find(name);
    if(it_money==money.end()){illegal++;return;}
    else
    {
        temp=money[name];
        if(paisa>temp){illegal++;return;}
        else
        {
            it_person=person.find(temp);
            junta.clear();
            junta=it_person->second;
            junta.erase(name);
            it_person->second=junta;
            junta.clear();
            it_person=person.find(temp);
            junta=it_person->second;
            if(junta.empty())
            {
                person.erase(temp);
            }
            money[name]-=paisa;
            temp=money[name];
            junta.clear();
            it_person=person.find(temp);
            if(it_person!=person.end())
            {
                junta=it_person->second;
                junta.insert(name);
                it_person->second=junta;
            }
            else
            {
                junta.clear();
                junta.insert(name);
                person.insert(pair<int, set<string> >(temp,junta) );
            }
        }
    }
}

void print(int start,int ending)
{
    set<string> junta;
    set<string>::iterator it_junta;
    it_person=person.begin();
    while(it_person != person.end())
    {
        if(it_person->first >= start && it_person->first<=ending )
        {
            junta=it_person->second;
            it_junta=junta.begin();
            cout<<it_person->first<<" ";
            while(it_junta != junta.end())
            {
                cout<<*it_junta<<" ";
                it_junta++;
            }
            cout<<endl;
        }
        it_person++;
    }
}

int main()
{
    char oper='a';
    string aadmi;
    int rupya;
    int start,ending;
    while(oper!='E')
    {
        cin>>oper;
        switch(oper)
        {
            case 'O' :
                cin>>aadmi;
                open(aadmi);
                break;

            case 'C' :
                cin>>aadmi;
                close(aadmi);
                break;

            case 'D' :
                cin>>aadmi>>rupya;
                deposit(aadmi,rupya);
                break;

            case 'W' :
                cin>>aadmi>>rupya;
                withdraw(aadmi,rupya);
                break;

            case 'P' :
                cin>>start>>ending;
                print(start,ending);

        }
    }
    cout<<illegal<<endl;
}
