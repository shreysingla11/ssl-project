#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
map<int , set<string> > samebal;
map<int ,set<string> >::iterator it2;
map<int , set<string> >::iterator it3;
map<string,int> acc;
map<string,int>::iterator it;
int illegal=0;
set<string>::iterator itstring;


void deposit(string name , int amount)
{
it = acc.find(name);
if(it == acc.end())   //acc not ther
{
illegal++;return;
}
else
{
    itstring = samebal[it->second].find(name);  //deleting teh previous m,ap
    samebal[it->second].erase(itstring);
    if(samebal[it->second].empty())
    {
    samebal.erase(it->second);              //key diya jata hai
    }
    //amount increased
    it->second = it->second + amount;  // increasing amount
    int temp = it->second;
    it2 = samebal.find(temp);


    //checking if temp wala money exists

    if(it2!=samebal.end())
    {
    samebal[temp].insert(name);

    }
    else
    {
    set<string> a;
    a.insert(name);
        samebal.insert(pair<int,set<string> > (temp , a) );
    }

}

}

void withdraw(string name , int amount)
{
it = acc.find(name);
if(it == acc.end())   //acc not ther
{
illegal++;return;
}
else if( it->second - amount < 0)
{
illegal++;return;
}
else
{
    itstring = samebal[it->second].find(name);  //deleting teh previous m,ap
    samebal[it->second].erase(itstring);
    if(samebal[it->second].empty())
    {
    samebal.erase(it->second);
    }
    //amount increased
    it->second = it->second - amount;  // idecreasing amount
    int temp = it->second;
    it2 = samebal.find(temp);


    //checking if temp wala money exists

    if(it2!=samebal.end())
    {
    samebal[temp].insert(name);

    }
    else
    {
    set<string> a;
    a.insert(name);
    samebal.insert(pair<int, set<string> >  ( temp , a));
    }

}



}

void open(string name)
{

it = acc.find(name);

if(it != acc.end())
{
illegal++;return;
}
else {
acc.insert(pair<string,int>(name,0));
//updating the samebal map
it2 = samebal.find(0);
if(it2!= samebal.end())

{
samebal[0].insert(name);   //0exists
}

else{                       //) doesnt exist
set<string> a;
a.insert(name);
samebal.insert(pair<int, set<string> > (0 , a));

}

}

}

void close(string name)
{
it = acc.find(name);

if(it == acc.end())
    {
    illegal++;return ;
    }
else if(it->second!=0)
    {
    illegal++;return ;

    }

else {

itstring = samebal[0].find(name);

samebal[0].erase(itstring);

if(samebal[0].empty()){
samebal.erase(0);


}
acc.erase(it);



}
}

void print(int r1, int r2)
{
it2=samebal.lower_bound(r1);
set<string>::iterator itstring2;

for ( ;it2->first<=r2&& it2!=samebal.end(); ++it2)
{
    cout<< it2->first;

    for( itstring2 = it2->second.begin() ; itstring2!=it2->second.end(); itstring2++ )
    {
    cout<<" "<<*itstring2;

    }
    cout<<endl;

}





}


int main()
{
string purpose;
string name;
int amount;

int r1;
int r2;


while(true){
cin>>purpose;
if(purpose=="O")
    {
    cin>>name;
    open(name);

    }

else if (purpose=="C")
{
 cin>>name;
 close(name);
}



else if (purpose=="D")
{
cin>>name;
cin>>amount;
deposit(name,amount);
}


else if (purpose=="W")
{
cin>>name;
cin>>amount;
withdraw(name , amount);
}


else if (purpose=="P")
{
cin>>r1;
cin>>r2;
print(r1,r2);
}

else if (purpose=="E")
{
cout<<illegal;
return 0;
}

}


}

