#include<iostream>
#include<map>
#include<set>
#include<iterator>
using namespace std;

class bank
{
public:

	map<string,int> mymap;
	map<int,set<string> > myset;
	int a,b;
	set<string>::iterator setit;
//	map<string,int>::iterator mapit = mymap.begin();




void openaccount(string name)
{
	mymap.insert(pair<string,int>(name,0));
	myset[0].insert(name);
}

void closeaccount(string name)
{
	a=mymap[name];
	myset[a].erase(name);
	mymap.erase(name);
}

void withdraw(string name,int amount)
{
	b=mymap[name];
	myset[b].erase(name);
	mymap[name]=mymap[name]-amount;
	a=mymap[name];
	myset[a].insert(name);

}

void deposit(string name,int amount)
{
	b=mymap[name];
	myset[b].erase(name);
	mymap[name]=mymap[name]+amount;
	a=mymap[name];
	myset[a].insert(name);
}

void print(int x,int y)
{

	for(int p=x;p<=y;p++)
	{
		if(!myset[p].empty()){
			cout<<p;
	for(setit=myset[p].begin();setit!=myset[p].end();setit++)
	{
		cout<<" "<<*setit;
	}
	 cout<<endl;
	}
							}
							
}

};
int main(){
	bank myclass;
	char letter;
	string name;
	int amount,initial,final;
	lab:
	cin>>letter;
	switch(letter){
		case 'O':
		cin>>name;
		myclass.openaccount(name);
		goto lab;
		case 'C':
		cin>>name;
		myclass.closeaccount(name);
		goto lab;
		case 'W':
		cin>>name>>amount;
		myclass.withdraw(name,amount);
		goto lab;
		case 'D':
		cin>>name>>amount;
		myclass.deposit(name,amount);
		goto lab;
		case 'P':
		cin>>initial>>final;
		myclass.print(initial,final);
		goto lab;

	}

	return 0;
}
