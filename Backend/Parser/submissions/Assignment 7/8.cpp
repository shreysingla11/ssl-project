#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
class bank
{
	map<string,int> accounts;
	map<int,set<string> > accountholder;
	int invalid;
public:
	bank()
	{
		invalid=0;
	}
	void open(string &name)
	{
		if(accounts.count(name)>0)
		{
			invalid++;
			return;
		}
		accounts[name]=0;
		accountholder[0].insert(name);
	}

	void close(string &name)
	{
		if(accounts.count(name)==0)
		{
			invalid++;
			return;
		}
		if(accounts[name]==0)
		{	
			accountholder[0].erase(name);
			if(accountholder[0].empty())
			{
				accountholder.erase(0);
			}
			accounts.erase(name);
		}
		else
		{
			invalid++;
		}
	}

	void deposit(string &name, int amount)
	{
		if(accounts.count(name)==0)
		{
			invalid++;
			return;
		}
		accountholder[accounts[name]].erase(name);
		if(accountholder[accounts[name]].empty())
		{
			accountholder.erase(accounts[name]);
		}
		accounts[name]+=amount;
		accountholder[accounts[name]].insert(name);
	}
	void withdraw(string &name, int amount)
	{
		if(accounts.count(name)==0)
		{
			invalid++;
			return;
		}
		if(accounts[name]<amount)
		{
			invalid++;
			return;
		}
		accountholder[accounts[name]].erase(name);
		if(accountholder[accounts[name]].empty())
		{
			accountholder.erase(accounts[name]);
		}
		accounts[name]-=amount;
		accountholder[accounts[name]].insert(name);
	}
	void printac(int val1,int val2)
	{
		map<int,set<string> >::iterator curit,endit;
		set<string>::iterator iter;
		curit=accountholder.lower_bound(val1);
		if(curit==accountholder.end())
		{
			return;
		}
		endit=accountholder.upper_bound(val2);
		for(;curit!=endit;curit++)
		{
			cout<<curit->first;
			for(iter=curit->second.begin();iter!=curit->second.end();iter++)
			{
				cout<<" "<<*iter;
			}
			cout<<endl;
		}

	}
	void printinvalid()
	{
		cout<<invalid<<endl;
	}

};

int main()
{
	bank B;
	char op;
	int val1,val2;
	string name;
	bool endinput=true;
	while(endinput)
	{
		cin>>op;
		switch(op)
		{
			case 'O' : 	cin>>name;
						B.open(name);
						break;
			case 'C' : 	cin>>name;
						B.close(name);
						break;
			case 'D' :	cin>>name;
						cin>>val1;
						B.deposit(name,val1);
						break;
			case 'W' :	cin>>name;
						cin>>val1;
						B.withdraw(name,val1);
						break;
			case 'P' :	cin>>val1;
						cin>>val2;
						B.printac(val1,val2);
						break;
			case 'E' :	endinput=false;
						break;
		}
	}
	B.printinvalid();
	return 0;
}